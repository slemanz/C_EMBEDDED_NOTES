/**********************************************************************************
*                                                                                 *
*                                 PRE-PROCESSOR                                   *
*                                                                                 *
***********************************************************************************/
#include <stdio.h>
#include <stdint.h>

// Are used to create macros used as textual replacemant for numbers and other things
// begin with "#" symbol
// also used to affect compilation


// Directives:
// Macros: #define <identifier> <value>
// File inclusion: #include <std lib> or #include "user define file"
// Conditional compilation: #ifdef #endif #if #else $ifdef #ifndef #undef
// Others: #error #pragma

// examples
#define MIN_VALUE 10
#define XTAL_SPEED 80000000UL // unsinged long
// warning: isnt a variable, is just a text replacement


// function macro
#define PI_VALUE 3.1415
#define AREA_OF_CIRCLE(r)	((PI_VALUE)*(r)*(r))
// use parenthesis to all operands!

#define TEST_COMPILE 0
#define TEST_COMPILE2 

int main()
{	
	int radius = 4;
	printf("The area of circle with radius %d is %f\n", radius, AREA_OF_CIRCLE(radius));


	// conditional compilation
#if TEST_COMPILE //value 
		printf("Test compile\n");
#else
		printf("Test compile else\n");
#endif

#ifdef TEST_COMPILE // define
		printf("Test compile\n");
#else
		printf("Test compile else\n");
#endif

#ifdef TEST_COMPILE2
		printf("Test compile 2222\n");
#else
		printf("Test compile else\n");
#endif

#undef TEST_COMPILE2

#ifdef TEST_COMPILE2
		printf("Test compile 2222\n");
#else
		printf("Test compile else2\n");
#endif

#define TEST_COMPILE2

#if defined(TEST_COMPILE) && defined(TEST_COMPILE2)
		printf("Test two compile \n");
#else
		#error "no macro defined"
		#warning "no macro defined"
#endif

	return 0;
}
