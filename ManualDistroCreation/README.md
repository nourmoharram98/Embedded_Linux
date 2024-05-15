# Manual Distribution Creation

## Project Overview

The "Manual Distribution Creation" project facilitates the creation of a customized Linux distribution for ARM Cortex-A9 architecture target. It involves configuring a development environment, building essential components such as U-Boot, the Linux kernel, BusyBox initialization manager, and creating a root file-system. The resulting image can be run on QEMU Emulator for testing and development purposes.

## Project Objectives

1. **Configure Cross-Tool Chain:** Set up a cross-tool chain to build applications for ARM Cortex-A9 architecture targets.
2. **Build U-Boot:** Configure and build the U-Boot bootloader using the cross-tool chain.
3. **Build Kernel:** Configure and build the Linux kernel for the target architecture using the cross-tool chain.
4. **Build BusyBox:** Configure and build BusyBox for the initialization system and essential utilities within the root filesystem.
5. **Create Root File System:** Construct a minimal root filesystem containing BusyBox utilities and necessary configuration files.
6. **Run Image Over QEMU Emulator:** Execute the generated image on the QEMU Emulator to validate functionality and behavior.

## Getting Started

### Prerequisites

- Linux-based development environment 
- Internet connection for downloading tools and source code

### Installation and Usage

1. **Configure Cross-Tool Chain:** Follow the instructions provided by the toolchain provider to install and configure it for ARM Cortex-A9 architecture.
2. **Build U-Boot:** Obtain the U-Boot source code, configure it for the target architecture, and build it using the installed cross-tool chain.
3. **Build Kernel:** Obtain the Linux kernel source code, configure it for the target architecture and peripherals, and build it using the cross-tool chain.
4. **Build BusyBox:** Download the BusyBox source code, configure it to include necessary utilities, and build it using the cross-tool chain.
5. **Create Root File System:** Construct a root filesystem structure with BusyBox utilities and additional configuration files as needed.
6. **Run Image Over QEMU Emulator:** Launch QEMU emulator with the compiled U-Boot, kernel image, and root filesystem. Verify the functionality of the system within the emulator environment.
