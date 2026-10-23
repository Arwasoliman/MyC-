// >> MyC/Problems
// by Soliman - UniversityofFlorida

//This is a LED control simulation exercice in C 
//Simualtes an 8-LED bank driven by a single 8-bit "GPIO output register"


#include <stdint.h>
#include <stdio.h>
#include <time.h>

#define NUM_LEDS 8

static volatile uint8_t GPIO_OUT = 0x00;

static void led_set(int index)
{
  if ( index >= 0 && index < NUM_LEDS)
  {
    GPIO_OUT |= (uint8_t)(1<<index);
    printf("LED %d is ON \n", index);
  }
}

static void led_clear(int index)
{
  if ( index >= 0 && index < NUM_LEDS)
  {
    GPIO_OUT &= (uint8_t)~(1<<index);
    printf("LED %d is OFF \n", index);
  }
}

static void led_toggle(int index)
{
  if ( index >= 0 && index < NUM_LEDS)
  {
    GPIO_OUT ^= (uint8_t)(1<<index);
    printf("LED %d toggled \n", index);
  }
}

int main () {
  int led_index;
  
  while (1) {
    printf("\n=== LED Control Simulator ===\n");

    printf("Enter LED number (1-%d): ", NUM_LEDS);
    if(scanf("%d", &led_index) != 1)
    {
      printf("Invalid input. Exiting.\n");
      break;
    }
    
    printf("Turn LED ON\n");
    led_set(led_index);
    printf("Turn LED OFF\n");
    led_clear(led_index);
    printf("Toggle LED\n");
    led_toggle(led_index);

    break;
  }
}
