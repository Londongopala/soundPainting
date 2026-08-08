#include "driver/gpio.h"

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define BUTTON GPIO_NUM_9 //ALL caps for good practiec

#define SOUND_PIN GPIO_NUM_10 //Define the pin for sound output

extern "C" void app_main{
    //extern "C" is the esp framwwork telling main that we are using C
    //Void is retrun nothing (typical)
    // App_main is neccesary as it is the 'entry point for paplication as defined by esp-idf

    
    gpio_set_direction(BUTTON, GPIO_MODE_INPUT);
    //standard pin gpio fucntion 
    //This one initializes the pin 'BUTTON' as a pin taking inputs

    gpio_set_pull_mode(BUTTON, GPIO_PULLUP_ONLY);
    //“Keep this pin HIGH by default using an internal pull-up resistor.” 
    //This means that the button is pulled high (1) then goes to 0 at press
    //neccary to stop accidental floating 

 

    gpio_set_direction(SOUND_PIN, GPIO_MODE_OUTPUT);
    //speaker is an output
    gpio_set_level(SOUND_PIN, 0);

while (true)
    {
        if (gpio_get_level(BUTTON) == 0) //pulled down/pressed
        {
            //ESP_LOGI("BUTTON", "Hello World"); //log info(rmational mesage)


            gpio_set_level(SOUND_PIN, 1);

            
        }


        //vTaskDelay(pdMS_TO_TICKS(20));//prevents cpu from reading million times

        vTaskDelay(pdMS_TO_TICKS(200)); //(longer sound ) */
        gpio_set_level(SOUND_PIN, 0);
    }
}