/*
 * test2.c:
 *      Simple test program to test the wiringPi functions
 *      PWM test
 */

#include <wiringPi.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main (void)
{
  int pin ;
  int l ;

  printf ("Raspberry Pi wiringPi PWM test program\n") ;

  if (wiringPiSetup () == -1)
    exit (1) ;

  for (pin = 0 ; pin < 8 ; ++pin)
  {
    pinMode (pin, OUTPUT) ;
    digitalWrite (pin, LOW) ;
  }

  pinMode (1, PWM_OUTPUT) ;

  for (;;)
  {
    for (l = 0 ; l < 1024 ; ++l)
    {
      pwmWrite (1, l) ;
      delay (1) ;
    }

    for (l = 1023 ; l >= 0 ; --l)
    {
      pwmWrite (1, l) ;
      delay (1) ;
    }
  }

  return 0 ;
}