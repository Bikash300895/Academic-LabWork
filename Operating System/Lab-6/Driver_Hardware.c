#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/fs.h> /* For the character driver support */
#include <linux/uaccess.h>
#include <linux/file.h>
#include <asm/io.h>
#include <linux/unistd.h>
#include <linux/kernel.h>
#include <linux/delay.h>
MODULE_LICENSE("Dual BSD/GPL");

#define NAME "parlp"
#define DEVICE_NAME "SimpleDriver"
#define BASEPORT 0x0378

char *mybuffer;
int hello_open(struct inode *pinode, struct file *pfile)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);

    return 0;
}

ssize_t hello_read(struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
	int nbytes;
	int maxbytes;
	int bytes_to_do;

	printk(KERN_ALERT "Length %d \n",length);

	maxbytes = 1 - *offset;
	
	if(maxbytes > length)
		bytes_to_do = length;
	else
		bytes_to_do = maxbytes;
	
	printk(KERN_ALERT "BEF BTR: %d, nbytes: %d, offset: %d \n",bytes_to_do, nbytes, *offset);

	nbytes = bytes_to_do - copy_to_user(buffer, mybuffer + *offset, bytes_to_do);
	*offset += nbytes;
	printk(KERN_ALERT "AFT BTR: %d, nbytes: %d, offset: %d \n",bytes_to_do, nbytes, *offset);
	printk(KERN_ALERT "Sent %s \n",mybuffer);
    return nbytes;
}

ssize_t hello_write(struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
	/*int nbytes;
	nbytes = length - copy_from_user(mybuffer + *offset, buffer, length);
	*offset += nbytes;
	printk(KERN_ALERT "Received %s \n",mybuffer);
        outb(*mybuffer, BASEPORT);*/


	char pbuffer, *ptr;
        int len;
	int i;

	ptr = buffer + length - 1;
	len = copy_from_user(&pbuffer, ptr, 1);
	if (len) return -EFAULT;
	//pbuffer = 'F';
	/* output the data to parallel port */
	printk(KERN_ALERT "Sent %c \n",pbuffer);
	
	if(pbuffer == 'F')
	{
	for(i=0;i<20;i++)
	{
	outb(1, BASEPORT);
	msleep(1000);
	outb(2, BASEPORT);
	msleep(1000);
	outb(4, BASEPORT);
	msleep(1000);
	
	}
	}
	else
	outb(0, BASEPORT);
	return 1;



    //return nbytes;
}

int hello_close(struct inode *pinode, struct file *pfile)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);

    return 0;
}

/* To hold the file operations performed on this device */

struct file_operations hello_file_operations = {
    .owner = THIS_MODULE,
    .open  = hello_open,
    .read  = hello_read,
    .write = hello_write,
    .release = hello_close,       
};

static int hello_init(void){
     
     printk(KERN_ALERT "TEST: Hello world\n");

/* Register with the kernel and indicate that we are registering a character device driver */

     register_chrdev(240 /* Major number */,
                      "SimpleDriver" /* Driver name */,
                       &hello_file_operations/* File operations */);

    if (!(request_region(BASEPORT, 1, DEVICE_NAME))){ printk(KERN_WARNING "Winbond error request region: %X\n", BASEPORT);
    release_region(BASEPORT, 1);}

	mybuffer=kmalloc(1,GFP_KERNEL);
	memset(mybuffer,'\0',1);
     
     return 0;
}

static void hello_exit(void){

     printk(KERN_ALERT "TEST: Good bye\n"); 

/* Unregister the character device driver */
	outb(0, BASEPORT);
     release_region(BASEPORT, 1);

     unregister_chrdev(240,"SimpleDriver");
if(mybuffer){
kfree(mybuffer);
}
}

module_init(hello_init);
module_exit(hello_exit);
