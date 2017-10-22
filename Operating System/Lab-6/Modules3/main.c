#include<stdio.h>
#include<fcntl.h>
#include<string.h>
main()
{
char p[] = "Hello";
int fd,n;
fd=open("/dev/simple",O_WRONLY);
n=write(fd,p,strlen(p));
printf("%d",n);
close(fd);
}
