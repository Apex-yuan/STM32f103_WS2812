#include "stm32f10x.h"

#include "usart.h"
#include "delay.h"
#include "../BOARD/ws2812/ws2812.h"


const char s[5];
int8_t i;

int main(void)
{
  usart1_init(115200);
  delay_init();

  ws281x_init();
 
  while(1)
  {
     // Some example procedures showing how to display to the pixels:
  ws281x_colorWipe(ws281x_color(255, 0, 0), 50); // Red
  ws281x_colorWipe(ws281x_color(0, 255, 0), 50); // Green
  ws281x_colorWipe(ws281x_color(0, 0, 255), 50); // Blue
//colorWipe(strip.Color(0, 0, 0, 255), 50); // White RGBW
  // Send a theater pixel chase in...
  ws281x_theaterChase(ws281x_color(127, 127, 127), 50); // White
  ws281x_theaterChase(ws281x_color(127, 0, 0), 50); // Red
  ws281x_theaterChase(ws281x_color(0, 0, 127), 50); // Blue

  //ws281x_rainbow(20);
  ws281x_rainbowCycle(20);
  ws281x_theaterChaseRainbow(200);
    
    for(i = 0; i < PIXEL_NUM; ++i)
  {
    ws281x_setPixelColor(i, ws281x_color(0,250,0));
    ws281x_show();
    delay_ms(500);
  }
  }
}
