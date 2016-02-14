/*
 * My first kernel module that loads and unloads successfully
 * with a message in the system log file present in /var/log/syslog
*/

#include <linux/init.h>
#include <linux/module.h>

//this function loads the module in the kernel space
int myModule(void)
{
    printk (KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    return 0;       //no errors, if 0 is returned
}

//this function removes the module from the kernel space
void myModuleExit(void)
{
    printk (KERN_ALERT "Exiting the %s function\n", __FUNCTION__);
}

//macro for initialising the module 
module_init(myModule);

//macro for removing and exiting the module
module_exit(myModuleExit);
