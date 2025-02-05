
#ifndef DYNAMIXEL_SDK_INCLUDE_DYNAMIXEL_SDK_GROUPBULKWRITE_C_H_
#define DYNAMIXEL_SDK_INCLUDE_DYNAMIXEL_SDK_GROUPBULKWRITE_C_H_

#include "robotis_def.h"
#include "port_handler.h"
#include "packet_handler.h"

WINDECLSPEC int     groupBulkWrite              (int port_num, int protocol_version);

WINDECLSPEC uint8_t groupBulkWriteAddParam      (int group_num, uint8_t id, uint16_t start_address, uint16_t data_length, uint32_t data, uint16_t input_length);
WINDECLSPEC void    groupBulkWriteRemoveParam   (int group_num, uint8_t id);
WINDECLSPEC uint8_t groupBulkWriteChangeParam   (int group_num, uint8_t id, uint16_t start_address, uint16_t data_length, uint32_t data, uint16_t input_length, uint16_t data_pos);
WINDECLSPEC void    groupBulkWriteClearParam    (int group_num);

WINDECLSPEC void    groupBulkWriteTxPacket      (int group_num);

#endif /* DYNAMIXEL_SDK_INCLUDE_DYNAMIXEL_SDK_GROUPBULKWRITE_C_H_ */
