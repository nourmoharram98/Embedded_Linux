# Custom Raspberry Pi Image using YOCTO Project

## Overview

This project aims to create a tailored Raspberry Pi image for the Raspberry Pi 3B+ model using the Yocto Project's auto build tool. The customized image includes specific configurations such as network settings, auto-login functionality, and essential packages.

## Prerequisites

- Raspberry Pi 3B+ model
- Yocto Project
- Clone of the necessary meta-layers from the OpenEmbedded Layer Index

## Steps to Create Custom Image

1. **Clone Required Meta-Layers**: Clone the following meta-layers from the OpenEmbedded Layer Index:

   - meta-openembedded/meta-oe
   - meta-openembedded/meta-networking
   - meta-openembedded/meta-multimedia
   - meta-openembedded/meta-python
   - meta-raspberrypi

2. **Create Custom Layer**: Create a custom layer named `meta-rpicustom` and add the necessary recipes:

   - `customnetworkconfigs`: Configures the network settings for the Raspberry Pi, including static IP for Ethernet interface and Wi-Fi configuration.
   - `autologin`: Enables auto-login functionality on the Raspberry Pi.
   - `rpi-image`: Recipe containing essential packages, distribution features, and machine features, inheriting from the Core-image class in Yocto.

3. **Configuration**:

   - Navigate to `/poky` directory and source the `oe-init-build-env`.

   - Update bblayers.conf

      to include the newly created meta-rpicustom layer and other necessary layers:

     ```bash
     BBLAYERS ?= " \
       /path/to/meta \
       /path/to/meta-poky \
       /path/to/meta-yocto-bsp \
       /path/to/meta-openembedded/meta-oe \
       /path/to/meta-openembedded/meta-networking \
       /path/to/meta-openembedded/meta-multimedia \
       /path/to/meta-openembedded/meta-python \
       /path/to/meta-raspberrypi \
       /path/to/meta-rpicustom \
       "
     ```

   - in the local.conf file

     - Set `INIT_MANAGER` variable to `systemd`.
     - Set the `machine` to `raspberrypi3-64`.

4. **Build Recipes**:

   - Execute the following BitBake commands to build the recipes:

     ```bash
     bitbake autologin
     bitbake customnetworkconfigs
     bitbake rpi-image
     ```

5. **Deployment**:

   - Navigate to `/build/temp/deploy/images/raspberrypi3-64`.

   - Use bmaptool to copy the generated image (rpi-image-wic.bz2) to the SD card:

     ```bash
     bmaptool copy rpi-image-wic.bz2 /dev/mmcblk0 "sd card"
     ```

6. **Usage**:

   - Mount the SD card to the Raspberry Pi.
   - Connect the Raspberry Pi to power and start using the custom image.

## Notes

- Ensure that all dependencies are properly installed before executing the build commands.
- Customize the configurations and packages according to specific project requirements.

------

Remember to replace `/path/to/` with the appropriate path where you have cloned these layers in your project directory structure.