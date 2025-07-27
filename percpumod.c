#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/percpu.h>


DEFINE_PER_CPU(int, counter);

static int __init percpumod_init(void)
{
	int num_cpus = num_online_cpus();
	int i = 0;

	pr_info("Number of cpus available: %d\n", num_cpus);
	for_each_online_cpu(i) {
		int value = per_cpu(counter, i);
		pr_info("Value of counter is %d at processor: %d\n", value, i);
	}

	get_cpu_var(counter) = 10;
	pr_info("Counter value of all processor after updating current processor: %d\n", smp_processor_id());

	put_cpu_var(counter);
	
	for_each_online_cpu(i) {
		int value = per_cpu(counter, i);
		pr_info("Value of counter is %d at processor: %d\n", value, i);
	}
	return 0;
}

static void __exit percpumod_exit(void)
{
	pr_info("Exit percpumod\n");
}

module_init(percpumod_init);
module_exit(percpumod_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Debu Patra");

