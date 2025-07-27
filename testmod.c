#include <linux/module.h>

static int __init testmod_init(void) {
	printk("The module is now loaded\n");
	return 0;
}

static void __exit testmod_exit(void) {
	printk("The module is now unloaded\n");
}

module_init(testmod_init);
module_exit(testmod_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Debu Patra");
