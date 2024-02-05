#pragma once

#include_next <mcuconf.h>

#undef STM32_PWM_USE_TIM16
#define STM32_PWM_USE_TIM16 TRUE
#define WS2812_PWM_CHANNEL 1

#undef STM32_GPT_TIM16_IRQ_PRIORITY
#define STM32_GPT_TIM16_IRQ_PRIORITY 2