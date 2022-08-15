/*
 * usbhook.c - Hook to the usb core
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
#include <linux/notifier.h>

static int usb_notify(struct notifier_block *self, unsigned long action, void *dev)
{
	printk(KERN_INFO "USB device added n");
	switch (action) {
	case USB_DEVICE_ADD:
		printk(KERN_INFO "USB device added n");
		break;
	case USB_DEVICE_REMOVE:
		printk(KERN_INFO "USB device removed n");
		break;
	case USB_BUS_ADD:
		printk(KERN_INFO "USB Bus added n");
		break;
	case USB_BUS_REMOVE:
		printk(KERN_INFO "USB Bus removed n");
	}
	return NOTIFY_OK;
}

static struct notifier_block usb_nb = {
	 .notifier_call = usb_notify,
};

int init_module(void)
{
	printk(KERN_INFO "Init USB hook.n");
	/*
    * Hook to the USB core to get notification on any addition or removal of USB devices
	*/
	usb_register_notify(&usb_nb);

	return 0;
}

void cleanup_module(void)
{
	/*
	 * Remove the hook
	*/
	usb_unregister_notify(&usb_nb);

	printk(KERN_INFO "Remove USB hookn");
}

MODULE_LICENSE("GPL");
