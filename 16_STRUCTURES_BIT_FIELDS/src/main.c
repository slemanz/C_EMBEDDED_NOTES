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

// using bitfields to choice how many bits in uint32_t 
// will be used (less memory consumption)
struct Packet{
	uint32_t crc		:2;
	uint32_t status		:1;
	uint32_t payload	:12;
	uint32_t bat		:3;
	uint32_t sensor		:3;
	uint32_t longAddr	:8;
	uint32_t shortAddr	:2;
	uint32_t addMode	:1;
};

int main()
{	
	uint32_t packetValue;
	printf("Enter the 32bit packet value: ");
	scanf("%i", &packetValue);
	printf("0x%X\n", packetValue);

	struct Packet packetStruct;
	
	uint32_t mask = (1 << 2) - 1; // crc
	packetStruct.crc = packetValue & mask;

	mask = (1 << 1) - 1; // status
	packetStruct.status = (packetValue >> 2) & mask;

	mask = (1 << 12) - 1; // payload
	packetStruct.payload = (packetValue >> 3) & mask;

	mask = (1 << 3) - 1; // bat
	packetStruct.bat = (packetValue >> 15) & mask;

	mask = (1 << 3) - 1; // sensor
	packetStruct.sensor = (packetValue >> 18) & mask;

	mask = (1 << 8) - 1; // longAddr
	packetStruct.longAddr = (packetValue >> 21) & mask;
	
	mask = (1 << 2) - 1; // shorAddr
	packetStruct.shortAddr = (packetValue >> 29) & mask;

	mask = (1 << 1) - 1; // addrMode
	packetStruct.addMode = (packetValue >> 31) & mask;


	printf("crc      : %d\n", packetStruct.crc);
	printf("status   : %d\n", packetStruct.status);
	printf("payload  : %d\n", packetStruct.payload);
	printf("sensor   : %d\n", packetStruct.sensor);
	printf("longAddr : %d\n", packetStruct.longAddr);
	printf("shortAddr: %d\n", packetStruct.shortAddr);
	printf("addrMode : %d\n", packetStruct.addMode);
	printf("The size of the struct is %d\n", (int)sizeof(packetStruct));
}