/*
Copyright (c) 2013-2014 Ben Croston

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "Python.h"
#include "c_gpio.h"
#include "common.h"
#include "odroid.h"

const int pin_to_gpio_rev1[MAXPINCOUNT+1];
const int pin_to_gpio_rev2[MAXPINCOUNT+1];
const int pin_to_gpio_rev3[MAXPINCOUNT+1];
const int (*pin_to_gpio)[MAXPINCOUNT+1];
int gpio_direction[MAXGPIOCOUNT+1];  //odroid change 54->255 to accommodate XU4 gpio numbers as index
rpi_info rpiinfo;
int module_setup;

int gpio_mode = MODE_UNKNOWN;
const int pin_to_gpio_rev1[41] = {-1, -1, -1, 0, -1, 1, -1, 4, 14, -1, 15, 17, 18, 21, -1, 22, 23, -1, 24, 10, -1, 9, 25, 11, 8, -1, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
const int pin_to_gpio_rev2[41] = {-1, -1, -1, 2, -1, 3, -1, 4, 14, -1, 15, 17, 18, 27, -1, 22, 23, -1, 24, 10, -1, 9, 25, 11, 8, -1, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
const int pin_to_gpio_rev3[41] = {-1, -1, -1, 2, -1, 3, -1, 4, 14, -1, 15, 17, 18, 27, -1, 22, 23, -1, 24, 10, -1, 9, 25, 11, 8, -1, 7, -1, -1, 5, -1, 6, 12, 13, -1, 19, 16, 26, 20, -1, 21 };
int setup_error = 0;
int module_setup = 0;

int check_gpio_priv(void)
{
    // check module has been imported cleanly
    if (setup_error)
    {
        PyErr_SetString(PyExc_RuntimeError, "Module not imported correctly!");
        return 1;
    }

    // check mmap setup has worked
    if (!module_setup)
    {
        PyErr_SetString(PyExc_RuntimeError, "No access to /dev/mem.  Try running as root!");
        return 2;
    }
    return 0;
}

//In original odroidc port, bcm_gpio gets bcm rpi specific
//value and gpio gets odroid gpio value
//bcm_gpio was used only as index to gpio_direction array
//I have expanded gpio direction to allow for indexing using
//native gpio numbers and used native gpio as index exerywhere

int get_gpio_number(int channel, unsigned int *gpio)
{
    // check setmode() has been run
    if (gpio_mode != BOARD && gpio_mode != BCM)
    {
        PyErr_SetString(PyExc_RuntimeError, "Please set pin numbering mode using GPIO.setmode(GPIO.BOARD) or GPIO.setmode(GPIO.BCM)");
        return 3;
    }

    // check channel number is in range
    if ( (gpio_mode == BCM && (channel < 0 || channel > 53))
      || (gpio_mode == BOARD && (channel < 1 || channel > 26) && rpiinfo.p1_revision != 3)
      || (gpio_mode == BOARD && (channel < 1 || channel > 40) && rpiinfo.p1_revision == 3) )
    {
        PyErr_SetString(PyExc_ValueError, "The channel sent is invalid on a Raspberry Pi");
        return 4;
    }

    // convert channel to gpio
    if (gpio_mode == BOARD)
    {
        if (*(*pin_to_gpio+channel) == -1)
        {
            PyErr_SetString(PyExc_ValueError, "The channel sent is invalid on a Raspberry Pi");
            return 5;
        } else {
            *gpio = *(*pin_to_gpio+channel);
        }
    }
    else // gpio_mode == BCM
    {
        *gpio = *(*bcm_to_odroidgpio+channel);
    }

    return 0;
}

