/************************************************
*                                               *
*           DATA TYPES AND VARIABLES            *
*                                               *
*************************************************/
#include <stdio.h>


void main()
{
	// In C we have TWO signicant data types:
	//   |----Integer and Float

	char var_char = 'C'; // consumes 1 byte of memory always
	unsigned char var_char2; // exemple of initialization
	var_char2 = 67;

	printf("Char Format: %c \n", var_char2);
	printf("Intenger Format: %d \n", var_char2); // Could be also %u for unsigned
}
