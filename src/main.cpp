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

#define LOOP_DELAY  10
#define TIME_PRINT  200

// setting PWM properties
#define FREQ            5000
#define LED_CHANNEL     0
#define RESOLUTION      12      //  Same as ADC pote resolution !!

/*
 *  Public functions
 */


int time_print;


void
setup(void)
{
    Serial.begin(SERIAL_BAUD);
    ledcSetup(LED_CHANNEL, FREQ, RESOLUTION);
    ledcAttachPin(LED, LED_CHANNEL);    // attach the channel to the GPIO to be controlled
    time_print = TIME_PRINT/LOOP_DELAY;
}

void
loop(void)
{
    int sensorValue;

    sensorValue = analogRead(ANAIN);
    ledcWrite(LED_CHANNEL, sensorValue);
    if( time_print-- == 0 )             //  print only after TIME_PRINT ms
    {
        time_print = TIME_PRINT/LOOP_DELAY;
        Serial.println(sensorValue);
    }

    delay(LOOP_DELAY);
}
