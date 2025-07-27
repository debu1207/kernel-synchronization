#include <linux/module.h>

static int __init logger_init(void)
{
	printk(KERN_EMERG "EMERGENCY\n");
	printk(KERN_ERR "error\n");
	printk(KERN_NOTICE "notice\n");
	printk(KERN_DEBUG "debug\n");
	return 0;
}

static void __exit logger_exit(void)
{
	printk(KERN_INFO "The module is unloaded\n");
}

module_init(logger_init);
module_exit(logger_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("DEBU PATR");
