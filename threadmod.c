#include <linux/slab.h>
#include <linux/module.h>
#include <linux/kthread.h>
#include <linux/uaccess.h>
#include <linux/sched.h>
#include <linux/delay.h>

static struct task_struct *mythread;

int thread_func(void *pv)
{
	int i = 0;
	while (!kthread_should_stop()) {
		printk(KERN_INFO "Processor id: %d\t in thread function %d\n", smp_processor_id(), i++);
		msleep(1000);
	}
	return 0;
}

static int __init driver_init(void)
{
	printk(KERN_INFO "%s: processor id: %d\n", __func__, smp_processor_id());
	
	mythread = kthread_create(thread_func, NULL, "myThread");
	
	if (mythread) {
		wake_up_process(mythread);
		return 0;
	}
	else {
		printk(KERN_ERR "Cannot create kthread\n");
		return -1;
	}
}

static void __exit driver_exit(void)
{
	kthread_stop(mythread);
	printk(KERN_INFO "%s: Device driver Remove ... Done\tProcessor Id: %d\n", __func__, smp_processor_id());
}

module_init(driver_init);
module_exit(driver_exit);
MODULE_LICENSE("GPL");
