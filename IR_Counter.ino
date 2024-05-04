#include <TM1637Display.h> // header file for TM.. LED display.
#define CLK 10  //syntax for dec the pins of dis
#define DIO 11  //syntax for dec the pins of dis

int sensor = 4;  // declaring the i/p of the IR sensor.
int count = 0;   // declaring the count variable with initial value -1.
 
TM1637Display display(CLK, DIO); // object creation of type TM... named display with intial values clk & dio (cons.)

void setup()//this code will run only one singal time.
{
 Serial.begin(9600);         // BAUD rate (no. of bits of data per second.)
 display.setBrightness(0x0f);  //for  Set  the  brightness (MF) ( 0 to 7 )
 display.clear();              //for clear the screen (MF)
}

void loop()//this code will run until the power is given to uno.
{
display.showNumberDec(count,true); //for display the number on screen (MF) {which accepts two values, 1 variable of int type & one bool type , ture=with leading zero ,false=without leading zero}
 if (digitalRead(sensor)==LOW) //when obj. is in the front of ir sensor,then it produces the low signal otherwise...
  {
     count++;
     display.showNumberDec(count,true); //display the the number on the led scr with the leading zero.
     Serial.println("Count Value:" + String(count)); //for print the line (on the comp. screen)& converting the count into string type of data & conc. them.
     while (digitalRead(sensor)==LOW)  {} //until the obj is in the front of the ir sensor do nothing.
  }
 
}
