
#include <TM1637Display.h>
// Module 1 connection pins (Digital Pins)
#define CLK1 2
#define DIO1 3

// Module 2 connection pins (Digital Pins)
#define CLK2 4
#define DIO2 5

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   5000


TM1637Display display1(CLK1, DIO1);// define dispaly 1 object
TM1637Display display2(CLK2, DIO2);// define dispaly 1 object

   uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 };  // all segments clear    
   
void setup()
{
  // Robojax.com two or more TM1637 Display 20181029  
  display1.setBrightness(0x0f);// set brightness of dispaly 1
  display2.setBrightness(0x0f);// set brightness of dispaly 1  

 
  display1.setSegments(data);// fill display 1 with whatever data[] array has
  display2.setSegments(data);// // fill display 2 with whatever data[] array has  
// Robojax.com two or more TM1637 Display 20181029  
}

void loop()
{
 // Robojax.com two or more TM1637 Display 20181029
/////////////////////////////////////////////////
  display1.setSegments(data); // fill(clear) display with data[] array    
  display1.showNumberDec(23, false, 2,0);

  display2.setSegments(data);// fill(clear) display with data[] array
  display2.showNumberDec(34, false, 2,0);
  delay(TEST_DELAY);// wait for TEST_DELAY miliseconds
  
/////////////////////////////////////////////////
  display1.setSegments(data); // fill(clear) display with data[] array    
  display1.showNumberDec(23, false, 2,1);

  display2.setSegments(data);// fill(clear) display with data[] array
  display2.showNumberDec(34, false, 2,1);
  delay(TEST_DELAY);// wait for TEST_DELAY miliseconds
/////////////////////////////////////////////////
  display1.setSegments(data); // fill(clear) display with data[] array    
  display1.showNumberDec(23, false, 2,2);

  display2.setSegments(data);// fill(clear) display with data[] array
  display2.showNumberDec(34, false, 2,2);
  delay(TEST_DELAY);// wait for TEST_DELAY miliseconds
/////////////////////////////////////////////////
  display1.setSegments(data); // fill(clear) display with data[] array    
  display1.showNumberDec(23, false, 2,3);

  display2.setSegments(data);// fill(clear) display with data[] array
  display2.showNumberDec(34, false, 2,3);
  delay(TEST_DELAY);// wait for TEST_DELAY miliseconds    
/////////////////////////////////////////////////
  display1.setSegments(data);// fill(clear) display with data[] array
  display1.showNumberDec(741);// display 1

  display2.setSegments(data);// fill(clear) display with data[] array  
  display2.showNumberDec(1562);// display 2
  delay(TEST_DELAY);// wait for TEST_DELAY miliseconds

// Robojax.com two or more TM1637 Display 20181029 
/////////////////////////////////////////////////
   display1.setSegments(data);// fill(clear) display 1 with data[] array
   display2.setSegments(data);// fill(clear) display 2 with data[] array   
  for(int i=0; i<=1273; i++)
  {
    display1.showNumberDec(i);// display from 0 to 1273 to diasplay 1
    display2.showNumberDec(i);// display from 0 to 1273 to diasplay 2    
  }
  delay(TEST_DELAY);// wait for TEST_DELAY miliseconds


// Robojax.com two or more TM1637 Display 20181029
  
}// loop en
