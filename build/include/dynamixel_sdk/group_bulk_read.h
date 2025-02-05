
#ifndef DYNAMIXEL_SDK_INCLUDE_DYNAMIXEL_SDK_GROUPBULKREAD_C_H_
#define DYNAMIXEL_SDK_INCLUDE_DYNAMIXEL_SDK_GROUPBULKREAD_C_H_


#include "robotis_def.h"
#include "port_handler.h"
#include "packet_handler.h"

WINDECLSPEC int         groupBulkRead               (int port_num, int protocol_version);

WINDECLSPEC uint8_t     groupBulkReadAddParam       (int group_num, uint8_t id, uint16_t start_address, uint16_t data_length);
WINDECLSPEC void        groupBulkReadRemoveParam    (int group_num, uint8_t id);
WINDECLSPEC void        groupBulkReadClearParam     (int group_num);

WINDECLSPEC void        groupBulkReadTxPacket       (int group_num);
WINDECLSPEC void        groupBulkReadRxPacket       (int group_num);
WINDECLSPEC void        groupBulkReadTxRxPacket     (int group_num);

WINDECLSPEC uint8_t     groupBulkReadIsAvailable    (int group_num, uint8_t id, uint16_t address, uint16_t data_length);
WINDECLSPEC uint32_t    groupBulkReadGetData        (int group_num, uint8_t id, uint16_t address, uint16_t data_length);

#endif /* DYNAMIXEL_SDK_INCLUDE_DYNAMIXEL_SDK_GROUPBULKREAD_C_H_ */
