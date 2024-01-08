# Embedded_Linux_Tasks



## Task 6 : SD Emulator Configuration README



This guide outlines the steps to create and configure an SD emulator image, attach it to a loop device, and perform various operations on its partitions.

## Step 1: Create SD Emulator Image

```bash
dd if=/dev/zero of=sd.img bs=1M count=1024
```

## Step 2: Configure Partitions using cfdisk

```bash
cfdisk sd.img
```

1. Choose DOS partitioning scheme.
2. Create partition 1 (FAT16, 200M, boot flag).
3. Create partition 2 (Linux, 823M).

## Step 3: Attach Partitions to Loop Device

```bash
sudo losetup -f --show --partscan sd.img
export DISK=/dev/loop27
```

* -f : Find the first unused loop device.
* --show : display the name of the assigned loop device
* --partscan : force the kernel to scan the partition table on a newly created loop device
* losetup : used to create a block device that allow a file to be accessed as if it was a physical disk

## Step 4: Format Partitions

```bash
sudo mkfs.vfat -F 16 -n boot ${DISK}p1
sudo mkfs.ext4 -L rootfs ${DISK}p2
```

* -F : FAT SIZE : used to specify the type of File allocation table (fat) in our case 16
* n : set the volume name (label) of the file system
* -L : set the volume name (label) of the file system

## Mount and Manage Partitions

### Mount Partitions:

```bash
sudo mount -t vfat /dev/loop27p1 <path to destination directory>
sudo mount -t ext4 /dev/loop27p2 <path to destination directory>
```

* t : determine type of partition to be mounted

### Add File to Root File System:

```bash
cd <path to destination directory>
sudo touch file.txt
sudo chmod o+w file.txt
```

### Unmount Partitions:

```bash
sudo umount <path to destination directory>
```



## Automated Mount/Unmount Functions (Optional)

Add the following functions to your .bashrc file:

```bash
mount_partition(){
    partition_number=$1
    if [ "$partition_number" -eq 1 ]; then
        sudo mount -t vfat /dev/loop27p1 /home/nourmoharram/mount_point/mountp_boot
    elif [ "$partition_number" -eq 2 ]; then
        sudo mount -t ext4 /dev/loop27p2 /home/nourmoharram/mount_point/mountp_rfs
    else
        echo "Invalid partition number. Supported values: 1, 2."
    fi
}

unmount_partition(){
    partition_number=$1
    if [ "$partition_number" -eq 1 ]; then
        sudo umount /home/nourmoharram/mount_point/mountp_boot
    elif [ "$partition_number" -eq 2 ]; then
        sudo umount /home/nourmoharram/mount_point/mountp_rfs
    else
        echo "Invalid partition number. Supported values: 1, 2."
    fi
}
```

### Usage:

```bash
mount_partition 1  # Mount partition 1
unmount_partition 1  # Unmount partition 1
```

## Detach and Reattach Emulator

### Detach Loop Device:

```bash
sudo losetup -d /dev/loop27
```

* d : detach the file or loop device

### Reattach Loop Device:

```bash
sudo losetup --partscan /dev/loop27 <image directory>
```
