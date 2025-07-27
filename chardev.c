#include <linux/module.h>

#define NUMDEV 2

static int dp_major;
static struct cdev *dp_cdev;

static int dp_release(struct inode *inode, struct file *filp)
{
	module_put(THIS_MODULE);
	return 0;
}

static ssize_t dp_read(struct file *file, char __user *buf,
		size_t count, loff_t *ppos)
{
	return 0;
}

static ssize_t dp_write(struct file *file, const char __user *buf,
		size_t count, loff_t *ppos)
{
	return count;
}

static loff_t dp_lseek(struct file *file, loff_t offset, int orig)
{
	return file->f_pos = 0;
}

static const struct file_operations dp_fops = {
        .owner          = THIS_MODULE,
        .release        = dp_release,
        .read           = dp_read,
        .write          = dp_write,
	.llseek		= dp_lseek,
};

static int __init dp_init(void)
{
	static const char name[] = "dp";
	struct cdev *cdev = NULL;
	dev_t dp_dev = 0;
	int res;

	res = alloc_chrdev_region(&dp_dev, 0, NUMDEV, name);
	if (res)
		goto out;

	res = -ENOMEM;
	cdev = cdev_alloc();

	if (!cdev)
		goto out_unregister;

	cdev->owner = THIS_MODULE;
	cdev->ops = &dp_fops;
	kobject_set_name(&cdev->kobj, "%s", name);

	res = cdev_add(cdev, dp_dev, NUMDEV);
	if (res)
		goto out_put;

	dp_major = MAJOR(dp_dev);
	dp_cdev = cdev;
	return 0;
out_put:
	kobject_put(&cdev->kobj);
out_unregister:
	unregister_chrdev_region(dp_dev, NUMDEV);
out:
	return res;
}

static void __exit dp_exit(void)
{
	return;
}

module_init(dp_init);
module_exit(dp_exit);
MODULE_DESCRIPTION("Sample testing character driver");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Debu Patra");
