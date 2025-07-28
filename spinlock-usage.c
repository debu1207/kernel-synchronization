#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/spinlock.h>
#include <linux/kthread.h>
#include <linux/sched.h>

unsigned int counter;
DEFINE_SPINLOCK(cnt_lock);
struct task_struct *read_thread, *write_thread;

static int writer(void *data)
{
	while (!kthread_should_stop()) {
		spin_lock(&cnt_lock);
		counter++;
		spin_unlock(&cnt_lock);
		msleep(500);
	}
	return 0;
}

static int reader(void *data)
{
	while (!kthread_should_stop()) {
		spin_lock(&cnt_lock);
		pr_info("Counter: %d\n", counter);
		spin_unlock(&cnt_lock);
		msleep(500);
	}
	return 0;
}

static int __init driver_init(void)
{
	counter = 0;
	read_thread = kthread_run(reader, NULL, "reader");
	pr_info("reader thread started\n");
	write_thread = kthread_run(writer, NULL, "writer");
	pr_info("writer thread started\n");

	return 0;
}
static void __exit driver_exit(void)
{
	kthread_stop(read_thread);
	kthread_stop(write_thread);
}

module_init(driver_init);
module_exit(driver_exit);
MODULE_LICENSE("GPL");
	
	
