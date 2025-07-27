#include <linux/kernel.h>
#include <linux/module.h>
#include <asm/atomic.h>

atomic_t val = ATOMIC_INIT(0);

static int __init driver_init(void)
{
	pr_info("%s: Value after initialization: %d\n", __func__, atomic_read(&val));

	atomic_set(&val, 4);
	atomic_dec(&val);
	atomic_inc(&val);
	atomic_add(3, &val);
	atomic_sub(2, &val);

	pr_info("%s: Value after initialization: %d\n", __func__, atomic_read(&val));

	return 0;
}

static void __exit driver_exit(void)
{
	pr_info("Exiting Atomic operations module\n");
}

module_init(driver_init);
module_exit(driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Debu Patra");
	
