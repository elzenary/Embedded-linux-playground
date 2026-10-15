#include<linux/module.h>

static int __init helloKernel(void);
static void __exit byeKernel(void);

static int __init helloKernel(void){
    printk(KERN_INFO "init module\n" );
    pr_debug("init debug msg\n");
    pr_err("init error test\n");
    return 0;
}

static void __exit byeKernel(void){
    printk(KERN_INFO "exit module\n" );
    pr_debug("exit debug msg\n");
    pr_err("exit err test\n");
}


module_init(helloKernel);
module_exit(byeKernel);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ahmed");
MODULE_DESCRIPTION("Hello kernel modules");