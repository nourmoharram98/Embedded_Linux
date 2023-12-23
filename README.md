# Embedded_Linux_Tasks



### By Eng. Nour Alaa-Eldin Hanafy Moharram

## Task 3:

### Sysroot:

The "sysroot" is the location the cross compiler will look for header files and libraries. The sysroot directory acts as if it is the root of the system,. So, for example, header files go in `$SYSROOT/usr/include/` and library files go in `$SYSROOT/usr/lib/`, etc.

​	Here's why sysroot is used in cross-compilation:

1. **Isolation from the Host System:**
   - Cross-compilation involves building software on one system (host) for another system (target), which might have a different architecture or operating system. The sysroot helps isolate the build process from the host system by providing a controlled environment for the cross-compiled binaries.
2. **Target System Libraries and Headers:**
   - The sysroot includes libraries and header files from the target system. This is crucial because during the compilation process, the cross-compiler needs access to the target system's libraries and headers to generate binaries that are compatible with the target environment.
3. **Cross-Compiler Compatibility:**
   - The sysroot ensures that the cross-compiler uses the correct versions of libraries and headers for the target system. This is important for generating binaries that can run on the target without issues related to library versions or compatibility.
4. **Portability:**
   - By using a sysroot, developers can create a more portable build environment. This allows them to distribute the sysroot along with the cross-compiler, making it easier for others to build software for the target system without having to set up the entire target environment on their host systems.

### Binutil

* ld : the GNU Linker
* nm: list symbols from object files
* ar: create, modify and extract from archives
* readelf: display information about ELF files
* objdump: display information from object files
* objcopy: copy and translate object files

* as: the portable GNU assembler
