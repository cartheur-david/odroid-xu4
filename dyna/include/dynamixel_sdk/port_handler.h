
#ifndef DYNAMIXEL_SDK_INCLUDE_DYNAMIXEL_SDK_PORTHANDLER_C_H_
#define DYNAMIXEL_SDK_INCLUDE_DYNAMIXEL_SDK_PORTHANDLER_C_H_

#define WINDECLSPEC


#ifdef __GNUC__
#define DEPRECATED __attribute__((deprecated))
#elif defined(_MSC_VER)
#define DEPRECATED __declspec(deprecated)
#else
#pragma message("WARNING: You need to implement DEPRECATED for this compiler")
#define DEPRECATED
#endif

#include "robotis_def.h"

static const int DEFAULT_BAUDRATE = 57600;

int     g_used_port_num;
uint8_t    *g_is_using;

WINDECLSPEC int     portHandler             (const char *port_name);

WINDECLSPEC uint8_t openPort                (int port_num);
WINDECLSPEC void    closePort               (int port_num);
WINDECLSPEC void    clearPort               (int port_num);

WINDECLSPEC void    setPortName             (int port_num, const char* port_name);
WINDECLSPEC char   *getPortName             (int port_num);

WINDECLSPEC uint8_t setBaudRate             (int port_num, const int baudrate);
WINDECLSPEC int     getBaudRate             (int port_num);

#if defined(__linux__) || defined(__APPLE__)
WINDECLSPEC int     getBytesAvailable       (int port_num);
#endif

WINDECLSPEC int     readPort                (int port_num, uint8_t *packet, int length);
WINDECLSPEC int     writePort               (int port_num, uint8_t *packet, int length);

WINDECLSPEC void    setPacketTimeout        (int port_num, uint16_t packet_length);
WINDECLSPEC void    setPacketTimeoutMSec    (int port_num, double msec);
WINDECLSPEC uint8_t isPacketTimeout         (int port_num);

#endif /* DYNAMIXEL_SDK_INCLUDE_DYNAMIXEL_SDK_PORTHANDLER_C_H_ */
