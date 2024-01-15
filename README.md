# Embedded_Linux_Tasks



### By Eng. Nour Alaa-Eldin Hanafy Moharram



## Task 8 Run U-boot and send dtb file using TFTP communication Protocol:



### TFTP (Trivial File Transfer Protocol):

* Simple file transfer protocol for lightweight data exchange.
* Operates over UDP (User Datagram Protocol) for reduced complexity.
* Commonly used in network booting and firmware updates.
* Lacks advanced features but offers minimal resource consumption.
* Primarily employed in scenarios requiring quick and straightforward file transfers.



### Steps to Install TFTP Communication Interface:

```bash
#Switch to root
sudo su
#Download tftp protocol
sudo apt-get install tftpd-hpa
#Change the configuration of tftp
vim /etc/default/tftpd-hpa
#write inside the file
tftp_option = “--secure –-create”
#Restart the protocal
Systemctl restart tftpd-hpa
#Make sure the tftp protocol is running
Systemctl status tftpd-hpa
#Change the file owner
cd /srv
chown tftp:tftp tftp 
#Move your image or file to the server
sudo cp [File name] /srv/tftp
```

Create a virtual TFTP Interface for QEMU

* check your tftp ip address using this command below

```bash
ip addr 
```

![1](/home/nourmoharram/GIT_REPO/Embedded_Linux/README.assets/ip_address.png)

from the Image above we can get the ip address for the host machine which is in our case in wlp2s0 at inet section:

* 172.20.10.6

and the inet mask = 28

* create script named qemu-ifup and put the tftp ip address and inet mask as input to the command ip

```bash
#!/bin/sh
ip a add <172.20.10.6/28> dev $1
ip link set $1 up

```

* change the permissions of the file to be executable

```bash
chmod +x qemu-ifup
```

* put the qemu-ifup file in the same directory where the sd image is found. also we can but the u_boot, sd image and qemu-ifup file all at the same directory before running qemu

### When the u-boot run we can add some environment variables and edit other environment variables using commands below

* setenv
* editenv
* printenv
* saveenv

```bash
#used to edit the autoboot delay time
bootdelay=5 
#carry the start address of ddram bank 
fdt_addr_r=0x60000000 
#carry the start address of ddram bank
kernel_addr_r=0x60100000 
#environment variables to carry the start address of ddram bank
DTB_ADDRESS=0x60000000 
#environment variables to carry the start address of ddram bank
KERNEL_ADDRESS=0x60100000 
#tftp server ip for the host machine
serverip=10.145.9.154 
#tftp client ip for qemu
ipaddr=10.145.9.156 

#environment variables that will be used to execute commands to load data from fat partition
load_from_fat=fatload mmc 0:1 0x60100000 Zimage;fatload mmc 0:1 0x60000000 dtb.txt
#environment variables that will be used to execute commands to load data from tftp server
load_from_tftp=tftp 0x60100000 Zimage;tftp 0x60000000 dtb.txt

#bootcmd command is the first command run after bootdelay is finished 
bootcmd=echo Hello U_boot from Nour; if run load_from_fat; then echo load from fat success; elif run load_from_tftp; then echo load from tftp success; else echo no load success; fi

```

### in the created environment variables we have used some commands like below:

* bdinfo: used to display system information
* fatls : used to list the content of fat partition
* fatload : used to load the content of fat partition to start at specific memory location in RAM
* tftp : used to load the content received through TFTP server
* md : used to display the content in ram at specific memory address

Run the QEMU emulation tool to test the u-boot using tftp communication

```bash
sudo qemu-system-arm -M vexpress-a9 -m 128M -nographic -kernel u-boot -sd sd.img -net tap,script=./qemu-ifup -net nic 
```

![2](/home/nourmoharram/GIT_REPO/Embedded_Linux/README.assets/RESULT.png)
