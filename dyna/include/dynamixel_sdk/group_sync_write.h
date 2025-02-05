
#ifndef DYNAMIXEL_SDK_INCLUDE_DYNAMIXEL_SDK_GROUPSYNCWRITE_C_H_
#define DYNAMIXEL_SDK_INCLUDE_DYNAMIXEL_SDK_GROUPSYNCWRITE_C_H_

#include "robotis_def.h"
#include "port_handler.h"
#include "packet_handler.h"

WINDECLSPEC int     groupSyncWrite              (int port_num, int protocol_version, uint16_t start_address, uint16_t data_length);

WINDECLSPEC uint8_t groupSyncWriteAddParam      (int group_num, uint8_t id, uint32_t data, uint16_t data_length);
WINDECLSPEC void    groupSyncWriteRemoveParam   (int group_num, uint8_t id);
WINDECLSPEC uint8_t groupSyncWriteChangeParam   (int group_num, uint8_t id, uint32_t data, uint16_t data_length, uint16_t data_pos);
WINDECLSPEC void    groupSyncWriteClearParam    (int group_num);

WINDECLSPEC void    groupSyncWriteTxPacket      (int group_num);


#endif /* DYNAMIXEL_SDK_INCLUDE_DYNAMIXEL_SDK_GROUPSYNCWRITE_C_H_ */
