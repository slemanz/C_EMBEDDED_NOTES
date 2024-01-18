#include <stdio.h>
#include <stdint.h>

// toggle led with bit field

typedef struct
{
	uint32_t gpioa_en		:1;
	uint32_t gpiob_en		:1;
	uint32_t gpioc_en		:1;
	uint32_t gpiod_en		:1;
	uint32_t gpioe_en		:1;
	uint32_t reserved1		:2;
	uint32_t gpioh_en		:1;
	uint32_t reserved2		:4;
	uint32_t crc_en			:1;
	uint32_t reserved3		:8;
	uint32_t dma1_en		:1;
	uint32_t dma2_en		:1;
	uint32_t reserved4		:9;
}RCC_AHB1ENR_t;


typedef struct
{
	uint32_t pin_0			:2;
	uint32_t pin_1			:2;
	uint32_t pin_2			:2;
	uint32_t pin_3			:2;
	uint32_t pin_4			:2;
	uint32_t pin_5			:2;
	uint32_t pin_6			:2;
	uint32_t pin_7			:2;
	uint32_t pin_8			:2;
	uint32_t pin_9			:2;
	uint32_t pin_10			:2;
	uint32_t pin_11			:2;
	uint32_t pin_12			:2;
	uint32_t pin_13			:2;
	uint32_t pin_14			:2;
	uint32_t pin_15			:2;
}GPIOx_MODE_t;


typedef struct
{
	uint32_t pin_0			:1;
	uint32_t pin_1			:1;
	uint32_t pin_2			:1;
	uint32_t pin_3			:1;
	uint32_t pin_4			:1;
	uint32_t pin_5			:1;
	uint32_t pin_6			:1;
	uint32_t pin_7			:1;
	uint32_t pin_8			:1;
	uint32_t pin_9			:1;
	uint32_t pin_10			:1;
	uint32_t pin_11			:1;
	uint32_t pin_12			:1;
	uint32_t pin_13			:1;
	uint32_t pin_14			:1;
	uint32_t pin_15			:1;
	uint32_t reserved		:16;
}GPIOx_ODR_t;


int main(void) {
	// creating a abstraction: the user dont have to think which bit he have to touch
	RCC_AHB1ENR_t volatile *const pClkCtrl    = (RCC_AHB1ENR_t*)(0x40023800 + 0x30);
	GPIOx_MODE_t  volatile *const pGPIOC_mode   = (GPIOx_MODE_t*)(0x40020800 + 0x00);
	GPIOx_ODR_t   volatile *const pGPIOC_output = (GPIOx_ODR_t*)(0x40020800 + 0x14);


	// pin 8 as output
	pClkCtrl->gpioc_en = 1;
	pGPIOC_mode->pin_8 = 1;
	pGPIOC_output->pin_8 = 1;

	while(1){
		pGPIOC_output->pin_8 = 1;
		for(uint32_t i = 0; i < 500000; i++);
		pGPIOC_output->pin_8 = 0;
		for(uint32_t i = 0; i < 500000; i++);
	}

	return 0;
}
