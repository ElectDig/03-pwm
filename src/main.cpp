/*
 *      Project 03-pwm
 *      Using a potentiometer connected to the A/D converter, changes LED brightness (PWM)
 *
 *      main.cpp
 */

#include <Arduino.h>

/*
 *     Definiciones
 */

/*
 *  Definitions in platformio.ini
 *  LED1        GPIO for LED
 *  ANAIN       A/D converter GPIO
 *  SERIAL_BAUD Serial port baud rate
 */

#define LOOP_DELAY 250

// setting PWM properties
#define FREQ            5000
#define LED_CHANNEL     0
#define RESOLUTION      12

/*
 *  Public functions
 */

void
setup(void)
{
    Serial.begin(SERIAL_BAUD);
    ledcSetup(LED_CHANNEL, FREQ, RESOLUTION);
    // attach the channel to the GPIO to be controlled
    ledcAttachPin(LED1, LED_CHANNEL);
}

void
loop(void)
{
    int sensorValue;

    sensorValue = analogRead(ANAIN);
    ledcWrite(LED_CHANNEL, sensorValue);
    Serial.println(sensorValue);

    delay(LOOP_DELAY);
}
