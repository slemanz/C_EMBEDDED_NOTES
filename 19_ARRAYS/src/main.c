/**********************************************************************************
*                                                                                 *
*                                     ARRAYS                                      *
*                                                                                 *
***********************************************************************************/
#include <stdio.h>
#include <stdint.h>

// the declaration:
uint8_t studentsAge[100];
void array_display(uint8_t const *const pArray, uint32_t nItems);

int main()
{	
	// to print the base address of the array:
	printf("The addres of the array: %p\n", studentsAge);

	int len = 10;
	uint8_t someData[10] = {0xff, 0xff, 0xff};
	uint8_t someOther[len]; // take care with older compilers (this is a new way to declare)


	// READ/WRITE in an array
	printf("Before: 2nd data item = %X\n", *(someData+1));
	*(someData+1) = 0x9;
	printf("After: 2nd data item = %X\n", *(someData+1));

	for(uint8_t i = 0; i < 3;  i++)
	{
		printf("%X ", someData[i]);
	}
	printf("\n\n");

	uint8_t dataTest[10] = {0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07};
	uint32_t nItem = sizeof(dataTest) / sizeof(uint8_t);
	for(int i = 0; i < nItem; i++){dataTest[i] = i+1;}
	array_display(dataTest, nItem);
	array_display(&dataTest[2], nItem-2);


	return 0;
}

//passing array to a function -> array_display()
void array_display(uint8_t const *const pArray, uint32_t nItems)
{
	for(uint32_t i = 0; i < nItems; i++)
	{
		printf("%X\t", pArray[i]); // or can use: *(pArray + i)
	}
	printf("\n");
}
