# this is a minimal makefile for demo purposes, keep it that way...
obj-m:=queueOut.o
queueOut-objs:=queue_message.o
V?=0
KDIR?=/lib/modules/$(shell uname -r)/build
# in an embedded system:
#KDIR:=[where the system maker gave me kernel headers+makefile or the kernel itself which has a makefile]
#ARCH:=arm
#CROSS_COMPILE:=[path+common prefix to where the toolchain is]
# You could also use W=2 and W=3 for more warnings but most kernel headers
# fail those...
W?=1
.PHONY: modules
modules:
	$(MAKE) -C $(KDIR) M=$(CURDIR) V=$(V) W=$(W) modules

.PHONY: clean
clean:
	$(MAKE) -C $(KDIR) M=$(CURDIR) V=$(V) clean
	rm -f *.stamp

.PHONY: putget
putget: putGet.c
	gcc -pthread -o $@ $<
	./putget

.PHONY: insrmmod
VARIABLE := number

insrmmod:
	for number in $$(seq 1 100);\
	do \
	sudo insmod queueOut.ko;\
	sleep 0.1;\
	(number=number+1);\
	sudo rmmod queueOut;\
	echo $$number;\
	done

.PHONY: test
test: 	insrmmod insmod putget

.PHONY: 	insmod
insmod: 
	sudo insmod queueOut.ko
	sleep 1
	sudo chmod 666 /dev/queueOut*

.PHONY: rmmod
rmmod: 
	sudo rmmod queueOut

.PHONY: remod

remod: 	
	rmmod insmod
