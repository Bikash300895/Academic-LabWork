obj-m += Driver1.o

KDIR = /usr/src/linux-headers-3.13.0-32-generic

all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
