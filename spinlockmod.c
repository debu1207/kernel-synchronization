#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/spinlock.h>

DEFINE_SPINLOCK(dp_lock);

static int __init driver_init(void)
{
	spin_lock(&dp_lock);
	pr_info("Starting critical region\n");
	pr_info("Ending critical region\n");
	spin_unlock(&dp_lock);

	return 0;
}

static void __exit driver_exit(void)
{
	pr_info("Spinlock methods and declaration\n");
}

module_init(driver_init);
module_exit(driver_exit);
MODULE_LICENSE("GPL");


