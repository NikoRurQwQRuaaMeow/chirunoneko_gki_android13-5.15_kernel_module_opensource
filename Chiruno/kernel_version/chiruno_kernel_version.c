/*
 * Chiruno Kernel Version Module
 * Create /proc/chiruno_kernel_version node to display custom kernel version
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/uaccess.h>

#define PROC_NAME "chiruno_kernel_version"
#define KERNEL_VERSION_STRING "version-code\n"

static struct proc_dir_entry *proc_entry;

static int version_show(struct seq_file *m, void *v)
{
    seq_printf(m, KERNEL_VERSION_STRING);
    return 0;
}

static int version_open(struct inode *inode, struct file *file)
{
    return single_open(file, version_show, NULL);
}

static const struct proc_ops version_proc_ops = {
    .proc_open = version_open,
    .proc_read = seq_read,
    .proc_lseek = seq_lseek,
    .proc_release = single_release,
};

static int __init chiruno_version_init(void)
{
    proc_entry = proc_create(PROC_NAME, 0444, NULL, &version_proc_ops);
    if (!proc_entry) {
        pr_err("Failed to create /proc/%s\n", PROC_NAME);
        return -ENOMEM;
    }

    pr_info("Chiruno kernel version module loaded: %s\n", KERNEL_VERSION_STRING);
    return 0;
}

static void __exit chiruno_version_exit(void)
{
    proc_remove(proc_entry);
    pr_info("Chiruno kernel version module unloaded\n");
}

module_init(chiruno_version_init);
module_exit(chiruno_version_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("NikoRur_QwQRuaa");
MODULE_DESCRIPTION("Custom kernel version display module");
MODULE_VERSION("1.0");
