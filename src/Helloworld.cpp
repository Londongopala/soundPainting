#include "driver/gpio.h"

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define BUTTON GPIO_NUM_9 //ALL caps for good practiec



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

while (true)
    {
        if (gpio_get_level(BUTTON) == 0)
        {
            ESP_LOGI("BUTTON", "Hello World");
            
        }

        vTaskDelay(pdMS_TO_TICKS(20));
    }
}
