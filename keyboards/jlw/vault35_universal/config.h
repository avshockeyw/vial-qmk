#pragma once

#define RGB_MATRIX_LED_COUNT 12

#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#define RGB_TRIGGER_ON_KEYDOWN
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_ALL
#define RGB_MATRIX_DEFAULT_VAL 32
#define RGB_MATRIX_DEFAULT_SPD 32

#define WS2812_PWM_DRIVER PWMD15
#define WS2812_PWM_CHANNEL 1
#define WS2812_PWM_PAL_MODE 5
#define WS2812_PWM_COMPLEMENTARY_OUTPUT
#define WS2812_DMA_STREAM STM32_DMA1_STREAM5
#define WS2812_DMA_CHANNEL 5
