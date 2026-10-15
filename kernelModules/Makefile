obj-m += helloKernel.o

KER_DIR = /lib/modules/${shell uname -r}/build

PWD = ${shell pwd}

all:
	make -C $(KER_DIR) M=$(PWD) modules

clean:
	make -C /lib/modules/${shell uname -r}/build M=$(PWD) clean
