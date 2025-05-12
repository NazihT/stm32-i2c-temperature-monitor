

#include "am2320.h"
#include "stm32f407xx.h"
#include "main.h"
#include "stm32f4xx_hal.h"

uint8_t Read_AM2320(float* temperature, float* humidity) {
    uint8_t dummy = 0x00;

    // Step 1: Wake it up
    HAL_I2C_Master_Transmit(&hi2c3, 0xB8, &dummy, 0, 100);
    HAL_Delay(2);

    // Step 2: Send read command
    uint8_t cmd[3] = {0x03, 0x00, 0x04};
    if (HAL_I2C_Master_Transmit(&hi2c3, 0xB8, cmd, 3, 100) != HAL_OK)
        return 1;

    HAL_Delay(2);

    // Step 3: Read 8 bytes
    uint8_t data[8];
    if (HAL_I2C_Master_Receive(&hi2c3, 0xB8, data, 8, 100) != HAL_OK)
        return 2;

    // Step 4: Parse
    uint16_t hum = (data[2] << 8) | data[3];
    uint16_t temp_raw = (data[4] << 8) | data[5];

    // Handle negative temps

        *temperature = ((float)temp_raw / 10.0);


    *humidity = ((float)hum / 10.0);
    return 0;
}

void DisplayTemperatureAndHumidity(float temperature, float humidity, uint8_t err, UART_HandleTypeDef* huart) {
    char lcd_str1[16], lcd_str2[16];

    LCD_Send_Cmd(0x01);  // Clear LCD
    HAL_Delay(2);
    char c ;

    if (temperature < 15)
    {
    	c='C';

    }
    else if (temperature >=15 && temperature <30)
    {
    	c='M';
    }

    else c='H';

    if (err == 0) {
        sprintf(lcd_str1, "Temp: %.1fC : %c" , temperature,c);
        sprintf(lcd_str2, "Humidity: %.1f%%", humidity);
    } else {
        sprintf(lcd_str1, "Sensor Failed");
        sprintf(lcd_str2, "Code: %d", err);
    }

    LCD_Send_String(lcd_str1);
    HAL_UART_Transmit(huart, (uint8_t*)lcd_str1, strlen(lcd_str1), 1000);
    HAL_UART_Transmit(huart, (uint8_t*)"\n", 1, 1000);

    LCD_Send_Cmd(0xC0);  // Second row
    LCD_Send_String(lcd_str2);
    HAL_UART_Transmit(huart, (uint8_t*)lcd_str2, strlen(lcd_str2), 1000);
    HAL_UART_Transmit(huart, (uint8_t*)"\n\n", 2, 1000);
}

