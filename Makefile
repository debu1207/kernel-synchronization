
all:
	make -C /lib/modules/`uname -r`/build M=$(PWD) modules
	#make -C /home/dp1207/linux-dev/linux-6.8/ M=$(PWD) modules

#obj-m += testmod.o
#obj-m += showerr.o
#obj-m += logger.o
#obj-m += chardev.o
#obj-m += numcpu.o
#obj-m += threadmod.o
#obj-m += percpumod.o
#obj-m += dynamic_percpu.o
#obj-m += atomic.o
#obj-m += atomicbits.o
#obj-m += spinlockmod.o
obj-m += dynamic_spinlock.o

clean:
	rm -rf *.o *.ko *.mod.c .an* .lab* .tmp_versions Module.symvers Module.markers modules.order .*.cmd *.mod
