#include <stdint.h>
#include "stm32g070xx.h"
#include "gpio/gpio.h"
#include "uart/uart.h"
#include "systick/systick.h"
#include "timer/timer.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

GPIO_Config_t LED_PIN = {
	.port = GPIOA,
	.pin = 5,
	.mode = GPIO_MODE_OUTPUT,
	.otype = GPIO_PUSH_PULL,
	.speed = GPIO_SPEED_HIGH,
	.pull = GPIO_NO_PULL,
	.alternate = GPIO_AF0
};


void init()
{
	gpio_init(&LED_PIN);
	systick_init(16000);
}

int main(void)
{
	init();

	while (1)
	{
		gpio_toggle_pin(&LED_PIN);
		systick_delay_ms(500);
	}
}
