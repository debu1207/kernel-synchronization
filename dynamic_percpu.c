#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/percpu.h>

static int *dynamic_counter;

static int __init driver_init(void)
{
	int cpu = get_cpu();
	int i;

	dynamic_counter = alloc_percpu(int);
	pr_info("cpu: %d\n", cpu);

	*per_cpu_ptr(dynamic_counter, cpu) = 1000;

	put_cpu();

	for_each_online_cpu(i)
		pr_info("cpu: %d\tcounter: %d\n", i, *per_cpu_ptr(dynamic_counter, i));

	free_percpu(dynamic_counter);
	return 0;
}

static void __exit driver_exit(void)
{
	pr_info("Dynamic percpu variable allocation\n");
}

module_init(driver_init);
module_exit(driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Debu Patra");
