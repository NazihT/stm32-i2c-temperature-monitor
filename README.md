# STM32 Custom I2C Temp-Humidity Monitor with Climate Control

## 📖 Description
This project uses the AS2320 I2C temperature and humidity sensor to measure environmental conditions. I wrote a custom I2C driver to interface with the sensor. The data is displayed on an I2C LCD and sent via UART to a terminal. Depending on the temperature:

- A **red LED** is turned on if the temperature exceeds 30°C .
- A **green LED** is turned on if the temperature is between 15 and 30 .
- A **blue LED** is turned on if the temperature is below 15 .
- A fan controlled by the L298N  with varying duty cycle depending on temperature .

The project is developed using HAL and CubeIDE, with future plans to implement  an SPI data logger for saving the temperature and humidity data to an SD card.

## 🛠️ Technologies Used
- STM32 HAL
- CubeIDE
- AS2320 I2C sensor
- Custom I2C driver (written from scratch)
- I2C LCD
- L298N motor driver with PWM for fan speed control
- UART Communication
- Future plans to implement:
  - PWM for fan speed control (added!)
  - SPI data logger for SD card storage

## ⚙️ Features
- **Temperature and humidity readings** from AS2320 sensor using a custom I2C driver.
- **UART communication** to send data to a terminal.
- **I2C LCD** to display temperature and humidity values.
- **Fan control** based on temperature:
  - **Red LED** and fan on if temperature is above 25°C.
  - **Blue LED** and fan off if temperature is below 25°C.
- **Future updates**:
  - Implementing **PWM motor control** for fan speed. (Updated ! )
  - Adding **SPI SD card logging** for data storage.

## 🎬 Demo
Check out the demo of the project below:



You can also view the demo by following this [link](https://github.com/NazihT/stm32-i2c-temperature-monitor/blob/885cf963f26c966cc1af5b5fea932741de42f63d/DEMO.gif)
