#include <linux/module.h>

static int __init f_init(void)
{
	return 0;
}

static void __exit f_exit(void)
{
	return;
}

module_init(f_init);
module_exit(f_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Debu Patra");
