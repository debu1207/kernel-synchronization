#include <linux/module.h>
#include <asm/atomic.h>
#include <asm/bitops.h>

unsigned long addr = 0x50;

static int __init driver_init(void)
{
	pr_info("Value: %02lx\n", addr);
	set_bit(0, &addr);
	pr_info("Value: %02lx\n", addr);
	clear_bit(4, &addr);
	pr_info("Value: %02lx\n", addr);
	change_bit(0, &addr);
	pr_info("Value: %02lx\n", addr);
	return 0;
}
	
static void __exit driver_exit(void)
{
	pr_info("Exiting atomic bitwise operations\n");
}

module_init(driver_init);
module_exit(driver_exit);
MODULE_LICENSE("GPL");
