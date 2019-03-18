#include<stdio.h>
#include<wiringPi.h>
#define GAS_PIN 27
int main(void)
{
wiringPiSetupGpio();
pinMode(GAS_PIN,INPUT);

while(1)
{
if(digitalRead(GAS_PIN)==LOW)
{
printf("FIRE/SMOKE/GAS DETECTED!!");

printf("\n");
}
else
{
printf("Normal Environment Condition");

printf("\n");
}
delay(2000);
}
return 0;
}