/**********************************************************************************
*                                                                                 *
*                            STRUCTURES BIT FIELD                                 *
*                                                                                 *
***********************************************************************************/
#include <stdio.h>
#include <stdint.h>

// write a program to decode a given 32bit packet information and print the values
// of differnt fields:
// crc 			[0:1]
// status 		[2]
// payload		[3:14]
// bat 			[15:17]
// sensor 		[18:20]
// long_addr 	[21:28]
// short_addr   [29:30]
// addr_mode 	[31]

struct Packet{
	uint8_t crc;
	uint8_t status;
	uint16_t payload;
	uint8_t bat;
	uint8_t sensor;
	uint8_t longAddr;
	uint8_t shortAddr;
	uint8_t addMode;
};

int main()
{	
	uint32_t packetValue;
	printf("Enter the 32bit packet value: ");
	scanf("%x", &packetValue);
	printf("0x%X\n", packetValue);
}