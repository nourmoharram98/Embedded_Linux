# Embedded_Linux_Tasks



### By Eng. Nour Alaa-Eldin Hanafy Moharram

## Task2: 

Create cross compiler for avr using crosstool-ng :

Commands to run the crosstool-ng:

* git clone the repository of crosstool-ng:
  * git clone https://github.com/crosstool-ng/crosstool-ng
  * cd crosstool-ng
  * git checkout 25f6dae8
* run command below to install all essential dependencies for cross tool: 
  * sudo apt install build-essential git autoconf bison flex texinfo help2man gawk \
    libtool-bin libncurses5-dev unzip
* run ./bootstrap
* run ./configure --enable-local
* run make
* run ./ct-ng list-samples
* run ./ct-ng avr
* run ./ct-ng menuconfig and apply this changes:
  * ```
    ───────────────────── Paths and misc options ─────────────────────
    [*] Debug crosstool-NG
    [ ]   Pause between every steps
    [*]   Save intermediate steps
    [*]     gzip saved states
    [*]   Interactive shell on failed commands
    ```

* run ./ct-ng build

* ![1](/home/nourmoharram/GIT_REPO/Embedded_Linux/README.assets/avr-gcc-cross-compiler.png)

* ![2](/home/nourmoharram/GIT_REPO/Embedded_Linux/README.assets/x-tools.png)