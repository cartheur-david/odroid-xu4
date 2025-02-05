## odroid-xu4 (hardkernel)

Code repository for the XU4 computer that drives the robot and is installed into the head.

### Background

This board was chosen due primarily to the long-term survivability of the XU4. It is no longer manufactured and is an ARMv7 32-bit device, but since it still supports dotnet 9.0, I will keep it working.

### Components

First step is to get the MPU6050 talking to the GPIO.

* Library is [here](/gpio/README.md)
* Build for dynamixel [here](/build/)
