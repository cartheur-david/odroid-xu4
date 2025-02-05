
#include "port_handler.h"
#include "port_handler_linux.h"

static const int DEFAULT_BAUDRATE = 57600;

int g_used_port_num;
uint8_t *g_is_using;

int     portHandler         (const char *port_name) { return portHandlerLinux(port_name); }

uint8_t openPort            (int port_num) { return openPortLinux(port_num); }
void    closePort           (int port_num) { closePortLinux(port_num); }
void    clearPort           (int port_num) { clearPortLinux(port_num); }

void    setPortName         (int port_num, const char *port_name) { setPortNameLinux(port_num, port_name); }
char   *getPortName         (int port_num) { return getPortNameLinux(port_num); }

uint8_t setBaudRate         (int port_num, const int baudrate) { return setBaudRateLinux(port_num, baudrate); }
int     getBaudRate         (int port_num) { return getBaudRateLinux(port_num); }

int     getBytesAvailable   (int port_num) { return getBytesAvailableLinux(port_num); }

int     readPort            (int port_num, uint8_t *packet, int length) { return readPortLinux(port_num, packet, length); }
int     writePort           (int port_num, uint8_t *packet, int length) { return writePortLinux(port_num, packet, length); }

void    setPacketTimeout    (int port_num, uint16_t packet_length) { setPacketTimeoutLinux(port_num, packet_length); }
void    setPacketTimeoutMSec(int port_num, double msec) { setPacketTimeoutMSecLinux(port_num, msec); }
uint8_t isPacketTimeout     (int port_num) { return isPacketTimeoutLinux(port_num); }
