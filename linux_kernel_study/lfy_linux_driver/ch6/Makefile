#makefile 

# if KERNELRELEASE is define , we've been invoked from 
# the kernel build system and can use its language.
ifneq (${KERNELRELEASE},)
	obj-m := ch6.o
#Otherwise we were called directly from the command line
# Involke the kernel build system
else
	KERNEL_SOURCE := /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)

default:
	${MAKE} -C ${KERNEL_SOURCE} SUBDIRS=${PWD} modules

clean:
	${MAKE} -C ${KERNEL_SOURCE} SUBDIRS=${PWD} clean

endif
