#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>

static dev_t first;

static int __init ofcd_init(void)
{
  printk( KERN_INFO "OFCD registeration ");
  if ( alloc_chrdev_region(&first, 0, 3, "selva") < 0 ){
      return -1;
  }
  printk(KERN_INFO "<Major, Minor > : < %d,%d>\n", MAJOR(first), MINOR(first));
  return 0;
}

static void __exit ofcd_exit(void) 
{
  unregister_chrdev_region(first,3);
  printk( KERN_INFO "ofcd unregister ");
}

module_init(ofcd_init);
module_exit(ofcd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Selva");
MODULE_DESCRIPTION("First character driver");
