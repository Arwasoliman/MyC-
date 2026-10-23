// >> MyC/Problems
// by Soliman - UniversityofFlorida

//This is a LED control simulation exercice in C 
//Simualtes an 8-LED bank driven by a single 8-bit "GPIO output register"


#include <stdint.h>
#include <stdio.h>
#include <time.h>

#define NUM_LEDS 8

static volatile uint8_t GPIO_OUT = 0x00;

static void set(int led_number) {
  int index = led_number-1;
  if ( index >= 0 && index < NUM_LEDS)
  {
    GPIO_OUT |= (uint8_t)(1<<index);
    printf("LED %d is ON \n", led_number);
  }
}

static void clear(int led_number) {
  int index = led_number-1;
  if ( index >= 0 && index < NUM_LEDS)
  {
    GPIO_OUT &= (uint8_t)~(1<<index);
    printf("LED %d is OFF \n", led_number);
  }
}

static void toggle(int led_number) {
  int index = led_number-1;
  if ( index >= 0 && index < NUM_LEDS)
  {
    GPIO_OUT ^= (uint8_t)(1<<index);
    printf("LED %d toggled \n", led_number);
  }
}

static void write_all(uint8_t value) {
  GPIO_OUT = value;
  printf("LED value is %x \n", value);
}

static void display(int led_number) {
  int index = led_number-1;
  printf("LED %d value is %s \n",index, (GPIO_OUT)? "ON" : "OFF");

}

int main () {
  int led_number;
  int command;
  
  while (1) {
    printf("\n=== LED Control Simulator ===\n");
    printf("1. Turn LED ON\n");
    printf("2. Turn LED OFF\n");
    printf("3. Toggle LED\n");
    printf("4. Write ALL LEDs\n");
    printf("5. Display LED status\n");
    printf("0. Exit\n");
    
    printf("Enter command: ");
    if (scanf("%d", &command) != 1) {
        printf("Invalid input. Exiting.\n");
        break;
    }

    if (command == 0) {
            printf("Exiting simulator.\n");
            break;
    }
    
    printf("Enter LED number (1-%d): ", NUM_LEDS);
    if(scanf("%d", &led_number) != 1)
    {
      printf("Invalid input. Exiting.\n");
      break;
    }
    
    if (led_number < 1 || led_number > NUM_LEDS) {
            printf("Invalid LED number.\n");
            continue;
    }

    switch (command) {
      case 0 : 
        printf("Exiting simulator.\n");
        break;
      case 1 :
        printf("Turn LED ON\n");
        set(led_number);
        break;
      case 2 :
        printf("Turn LED OFF\n");
        clear(led_number);
        break;
      case 3 :
        printf("Toggle LED\n");
        toggle(led_number);
        break;
      case 4 :
        printf("change all LEDs\n");
        write_all(0xFF);
        break;
      case 5 :
        printf("Display LED status\n");
        display(led_number);
        break;
      default : break;
    }
  }
}
