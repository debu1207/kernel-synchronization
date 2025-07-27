#include <linux/module.h>
#include <linux/sched.h>

static int errval = 0;
module_param(errval, int, 0644);
static int __init showerr_init(void) {
	printk("errval=%d\n", errval);
	return errval;
}

static void __exit showerr_exit(void) {
	printk("The module is unloaded\n");
}

module_init(showerr_init);
module_exit(showerr_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Debu Patra");
