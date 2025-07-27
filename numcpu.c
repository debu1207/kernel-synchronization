#include <linux/module.h>
#include <linux/delay.h>

static int __init numcpu_init(void)
{
	printk(KERN_INFO "%s: In init NR_CPUs=%d\n", __func__, NR_CPUS);
	printk(KERN_INFO "Number of cpus available: %d\n", num_online_cpus());
	printk(KERN_INFO "Module is running on processor: %d\n", smp_processor_id());

	msleep(60000L);

	return 0;
}

static void __exit numcpu_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
	return;
}

module_init(numcpu_init);
module_exit(numcpu_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Debu Patra");
