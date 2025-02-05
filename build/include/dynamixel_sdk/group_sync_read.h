
#ifndef DYNAMIXEL_SDK_INCLUDE_DYNAMIXEL_SDK_GROUPSYNCREAD_C_H_
#define DYNAMIXEL_SDK_INCLUDE_DYNAMIXEL_SDK_GROUPSYNCREAD_C_H_

#include "robotis_def.h"
#include "port_handler.h"
#include "packet_handler.h"

WINDECLSPEC int         groupSyncRead               (int port_num, int protocol_version, uint16_t start_address, uint16_t data_length);

WINDECLSPEC uint8_t     groupSyncReadAddParam       (int group_num, uint8_t id);
WINDECLSPEC void        groupSyncReadRemoveParam    (int group_num, uint8_t id);
WINDECLSPEC void        groupSyncReadClearParam     (int group_num);

WINDECLSPEC void        groupSyncReadTxPacket       (int group_num);
WINDECLSPEC void        groupSyncReadRxPacket       (int group_num);
WINDECLSPEC void        groupSyncReadTxRxPacket     (int group_num);

WINDECLSPEC uint8_t     groupSyncReadIsAvailable    (int group_num, uint8_t id, uint16_t address, uint16_t data_length);
WINDECLSPEC uint32_t    groupSyncReadGetData        (int group_num, uint8_t id, uint16_t address, uint16_t data_length);


#endif /* DYNAMIXEL_SDK_INCLUDE_DYNAMIXEL_SDK_GROUPSYNCREAD_C_H_ */
