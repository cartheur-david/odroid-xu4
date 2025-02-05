## Building dynamixel for SBC (Pi and odroid)

### Requirements

GNU gcc ver. 5.4.0 20160609 or higher. To check the version of your gcc compiler:

`gcc -v` 

### Builder

`sudo apt install build-essential`

### Building

In the `linux_sbc` directory, type `make`.

### Multiple deefintions error

Since GCC 10+, changes are required to get this to work, although fixed, still is done manually accroding to [this](https://github.com/ROBOTIS-GIT/DynamixelSDK/pull/616).