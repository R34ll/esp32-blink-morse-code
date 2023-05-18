#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/gpio.h"
#include "esp_log.h"

#define LED_GPIO_PIN 2 // LED_GPIO_PIN

#define LED_ON(delay_time) gpio_set_level(LED_GPIO_PIN,1); vTaskDelay(delay_time)
#define LED_OFF(delay_time) gpio_set_level(LED_GPIO_PIN,0); vTaskDelay(delay_time)


#define BLINK_DOT LED_ON(100);LED_OFF(100)
#define BLINK_DASH LED_ON(300);LED_OFF(100)


static const char* morseCode[] = {".-",   "-...", "-.-.",
								"-..",  ".",    "..-.",
								"--.",  "....", "..",
								".---", "-.-",  ".-..", 				 
								"--",   "-.",   "---",
								".--.", "--.-", ".-.",
								"...",  "-",    "..-",
								"...-", ".--",  "-..-",
								"-.--", "--.."};


void morseCodeInterpreter(const char* text){

	for (int i = 0; i< strlen(text); i++ ){
		char c = toupper(text[i]);

		if(c >= 'A' && c <= 'Z'){
            int index = c-'A';

            for (int j = 0; morseCode[index][j] != '\0'; j++){
                if (morseCode[index][j] == '.'){
                    BLINK_DOT;

                }else if(morseCode[index][j] == '-'){
                    BLINK_DASH;
                }

            }
		}
	}
}


void app_main(void){
	const char* morse_code_message = "SOS";

	gpio_reset_pin(LED_GPIO_PIN);
    	gpio_set_direction(LED_GPIO_PIN, GPIO_MODE_OUTPUT);


    	while(1){
		morseCodeInterpreter(morse_code_message);
    	}

}

