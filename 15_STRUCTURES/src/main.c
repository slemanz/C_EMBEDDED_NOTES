/**********************************************************************************
*                                                                                 *
*                                 STRUCTURES                                      *
*                                                                                 *
***********************************************************************************/
#include <stdio.h>
#include <stdint.h>

// structures is a data structure used to create user-defined data types in c (allow
// us to combine data of different types)


// example of a structure
struct CarModel
{
	unsigned int carNumber;
	uint32_t     carPrice;
	uint16_t     carMaxSpeed;
	float		 carWeight;
};
// WARNING: structure definition doesn't consume any memory. its just a description
// or a record.

int main()
{	
	// memory will be consumed when you create structure variables:
	struct CarModel CarBMW = {2021, 15000, 220, 1330}; // C89: order is important
	struct CarModel CarFord = {.carNumber=4031, .carPrice=35000, .carMaxSpeed=160, .carWeight=1900.90}; // C99: order is NOT important

	// accessing structure member elements:
	// use a .(dot) operator to access the member elements

	printf("Details of car BMW:\n");
	printf("Number: %u\n",CarBMW.carNumber);
	printf("Price: %u\n",CarBMW.carPrice);
	printf("Max speed: %u\n",CarBMW.carMaxSpeed);
	printf("Weight: %.2f\n\n",CarBMW.carWeight);


	CarFord.carNumber = 4200;
	printf("Details of car Ford:\n");
	printf("Number: %u\n",CarFord.carNumber);
	printf("Price: %u\n",CarFord.carPrice);
	printf("Max speed: %u\n",CarFord.carMaxSpeed);
	printf("Weight: %.2f\n\n",CarFord.carWeight);


	return 0;
}
