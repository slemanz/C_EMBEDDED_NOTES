/**********************************************************************************
*                                                                                 *
*                                     UNIONS                                      *
*                                                                                 *
***********************************************************************************/
#include <stdio.h>
#include <stdint.h>

// union have the same initial address of all member
// the size is the biggest element

// use unions instead structure to save memory when access to its member elements is
// mutually exclusive

union example
{
	uint16_t shortAddr;
	uint32_t longAddr;
};

union Packet{
	uint32_t packetValue;

	struct
	{
		uint32_t crc		:2;
		uint32_t status		:1;
		uint32_t payload	:12;
		uint32_t bat		:3;
		uint32_t sensor		:3;
		uint32_t longAddr	:8;
		uint32_t shortAddr	:2;
		uint32_t addrMode	:1;
	}packetFields;
};


int main()
{	
	union example examp;

	examp.shortAddr = 0xABCD;
	examp.longAddr = 0xFFFFCCCC;

	printf("short addr: 0x%X\n", examp.shortAddr);
	printf("long addr: 0x%X\n\n", examp.longAddr);

	// the applicability of unions in embedded system code
	// 1. bit extraction
	// 2. storing mutually data thus saving memory

	// for bit field example in section 16:
	union Packet packet;
	packet.packetFields.payload = 400;
	printf("test payload     : %d from %d\n\n", packet.packetFields.payload, packet.packetValue);

	printf("Enter a 32bit packet value: ");
	scanf("%i", &packet.packetValue);

	printf("Packet value: 0x%X\n", packet.packetValue);
	printf("crc      : %d\n", packet.packetFields.crc);
	printf("status   : %d\n", packet.packetFields.status);
	printf("payload  : %d\n", packet.packetFields.payload);
	printf("sensor   : %d\n", packet.packetFields.sensor);
	printf("longAddr : %d\n", packet.packetFields.longAddr);
	printf("shortAddr: %d\n", packet.packetFields.shortAddr);
	printf("addrMode : %d\n", packet.packetFields.addrMode);
	printf("the size of the union: %d\n", (int)(sizeof(packet)));

	return 0;
}
