#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/cdev.h>
#include <linux/fs.h>

static dev_t first;
static struct cdev c_dev;
static struct class *dev_class;

static int my_open(struct inode* i , struct file* f)
{
	printk(KERN_INFO "opened file");
	return 0;
}

static int my_close(struct inode* i, struct file* f)
{
	printk(KERN_INFO "close file");
	return 0;
}

static ssize_t my_read(struct file* f, char __user * buf, size_t sz , loff_t* off)
{
	char ch = 'a';
	static char count = 0; //not an reentrant code

	printk(KERN_INFO "read file");

	if (buf == NULL)
		return -1;

	if (count != 0)  return 0; // return EOF 

	//buf[0] = 'a';
	//direct access to the user buffer will cause problem , since 
	//user space buffer will be swapped out. copy_to_user() wil 
	//protect the user buffer access

	if ( copy_to_user(buf,&ch,1) != 0 )
	{
		return -EFAULT;
	}
	count++;

	return 0;
}

static ssize_t my_write(struct file* f, const char __user *  buf , size_t sz, loff_t* off)
{
	printk(KERN_INFO "write file");
	return 0;
}

struct file_operations fops = {
	.open = my_open,
	.release = my_close,
	.write = my_write,
	.read = my_read
};

static int __init mfd_init(void) /* Constructor */
{	
	int ret = 0;

	printk(KERN_INFO "mfd registered");

	if ((ret = alloc_chrdev_region(&first, 0, 3, "ofd")) < 0 ) {
		return ret;		
	}
	printk(KERN_INFO"<Major> major number ");

	cdev_init(&c_dev, &fops);
	if ( cdev_add(&c_dev, first,3) < 0) {
		printk(KERN_ERR"Failed to register");
		return -1;
	}

	/*Creating struct class*/
	if((dev_class = class_create(THIS_MODULE,"ofd_class")) == NULL){
		pr_err("Cannot create the struct class\n");
		return -1;
	}

	/*Creating device*/
	if((device_create(dev_class,NULL,first,NULL,"ofd_device")) == NULL){
		pr_err("Cannot create the Device 1\n");
		return -1;
	}

	return 0;
}

static void __exit mfd_exit(void) /* Destructor */
{
	printk(KERN_INFO "mfd unregistered");
}

module_init(mfd_init);
module_exit(mfd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pradeep Tewani");
MODULE_DESCRIPTION("My First Driver");
