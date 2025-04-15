


#ifndef INC_AM2320_H_
#define INC_AM2320_H_


#include "stm32f4xx_hal.h"  // Include HAL to use the I2C handler type
#include "liquidcrystal_i2c.h"

extern I2C_HandleTypeDef hi2c3;  // Declare it as external
extern UART_HandleTypeDef huart2;

uint8_t Read_AM2320(float* temperature, float* humidity);


void DisplayTemperatureAndHumidity(float temperature, float humidity, uint8_t err, UART_HandleTypeDef* huart) ;


#endif /* INC_AM2320_H_ */
