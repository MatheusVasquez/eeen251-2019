/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#include <asf.h>

#define LED_AZUL (1<<19)
#define Button (1<<3)

int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */

	sysclk_init();

	board_init();
	PIOA->PIO_PER |= LED_AZUL;
	PIOA->PIO_OER |= LED_AZUL;
	PIOB->PIO_PER |= Button;
	PIOB->PIO_ODR |= Button;
	
	while(1)
{
	if ((PIOB->PIO_PDSR & Button) == 0)
	{
		PIOA->PIO_CODR |= LED_AZUL;
	}

	else
	{
		PIOA->PIO_SODR |= LED_AZUL;
	}
}
}