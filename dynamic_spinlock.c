#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/spinlock.h>

spinlock_t *lock;

static int __init driver_init(void)
{
	lock = kmalloc(sizeof(spinlock_t), GFP_KERNEL);
	spin_lock_init(lock);

	spin_lock(lock);
	pr_info("Start critical region\n");
	pr_info("End critical region\n");
	spin_unlock(lock);

	kfree(lock);
	return 0;
}

static void __exit driver_exit(void)
{
	pr_info("Dynamic spinlock init\n");
}

module_init(driver_init);
module_exit(driver_exit);
MODULE_LICENSE("GPL");
