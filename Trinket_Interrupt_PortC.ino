/* 
  PIN CHANGE INTERRUPT PORT C PCIE1
  BOARD     CHIP    PORT    PCIE1/PSMSK1  BIT              Other Function          NOTE
  14/A0       23     PC0        PCINT8    B00000001          Free                  Pin 14 as Digital A0(Analog)
  15/A1       24     PC1        PCINT9    B00000010          Free                  Pin 15 as Digital A1(Analog)
  16/A2       25     PC2        PCINT10   B00000100          Free                  Pin 16 as Digital A2(Analog)
  17/A3       26     PC3        PCINT11   B00001000          Free                  Pin 17 as Digital A3(Analog)
  18/A4       27     PC4        PCINT12   B00010000          I2C SDA               Pin 18 as Digital A4(Analog) or I2C
  19/A5       28     PC5        PCINT13   B00100000          I2C SCL               Pin 19 as Digital A5(Analog) or I2C
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Declaring Variables
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int rcPin14_prev, rcPin15_prev, rcPin16_prev, rcPin17_prev;
int rcPin14, rcPin15, rcPin16, rcPin17;
volatile unsigned long timer1, timer2, timer3, timer4, now;
byte highByte, lowByte;
int led = 13;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Setup routine
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup(){ Serial.begin(115200);
 pinMode(led, OUTPUT);
 pinMode(14, INPUT); digitalWrite(14, HIGH);
 pinMode(15, INPUT); digitalWrite(15, HIGH);
 pinMode(16, INPUT); digitalWrite(16, HIGH);
 pinMode(17, INPUT); digitalWrite(17, HIGH);
//ARDUINO PRO TRINKET 328
//TIMSK0 &= ~_BV(TOIE0);                                       //Disable Timer0, for gitter free against interrupt.
  PCICR  |= (1 << PCIE1);                                      //Set PCIE0 to enable PCMSK0 scan.
  PCMSK1 |= (1 << PCINT8);                                     //Set PCINT3 (digital input 11)to trigger an interrupt on state change.
  PCMSK1 |= (1 << PCINT9);                                     //Set PCINT4 (digital input 8) to trigger an interrupt on state change.
  PCMSK1 |= (1 << PCINT10);                                     //Set PCINT5 (digital input 9)to trigger an interrupt on state change.
  PCMSK1 |= (1 << PCINT11);                                     //Set PCINT6 (digital input 10)to trigger an interrupt on state change.                                   //Set PCINT7 (digital input 11)to trigger an interrupt on state change.
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Main program loop
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop()
{
/*  */
Serial.print(":");Serial.print(rcPin09);
Serial.print(";");Serial.print(rcPin10);
Serial.print("<");Serial.print(rcPin11);
Serial.print("=");Serial.println(rcPin12); 
delay(20);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//This routine is called every time input 8, 9, 10 or 11 changed state
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ISR(PCINT1_vect){
  now = micros();
  //Channel 1==AIL  PORT PB3=====================================
  if(PINC & B00000001){                                      //Is input 14/A8 high? 
    if(rcPin14_prev == 0){                                   //Input 14 changed from 0 to 1
      rcPin14_prev = 1;                                      //Remember current input state
      timer1 = now;                                          //Set timer1 to current_time
    }
  }
  else if(rcPin14_prev == 1){                                //Input 3 is not high and changed from 1 to 0
    rcPin14_prev = 0;                                        //Remember current input state
    rcPin14 = now - timer1;                                  //Channel 1 is current_time - timer_1
  }
  //Channel 2==ELE  PORT PB4====================================
  if(PINC & B00000010 ){                                     //Is input 15 high?
    if(rcPin15_prev == 0){                                   //Input 15 changed from 0 to 1
      rcPin15_prev = 1;                                      //Remember current input state
      timer2 = now;                                          //Set timer2 to current_time
    }
  }
  else if(rcPin15_prev == 1){                                //Input 15 is not high and changed from 1 to 0
    rcPin15_prev = 0;                                        //Remember current input state
    rcPin15 = now - timer2;                                  //Channel 2 is current_time - timer2
  }
  //Channel 3==THR  PORT PB5====================================
  if(PINC & B00000100 ){                                     //Is input 16 high?
    if(rcPin16_prev == 0){                                   //Input 16 changed from 0 to 1
      rcPin16_prev = 1;                                      //Remember current input state
      timer3 = now; //Serial.println(rcPin11);               //Set timer3 to current_time
    }
  } 
  else if(rcPin16_prev == 1){                                //Input 16 is not high and changed from 1 to 0
    rcPin16_prev = 0;                                        //Remember current input state
    rcPin16 = now - timer3;                                  //Channel 3 is current_time - timer3

  }
  //Channel 4==RUD  PORT PB6====================================
  if(PINC & B00001000 ){                                     //Is input 17 high?
    if(rcPin17_prev == 0){                                   //Input 17 changed from 0 to 1
      rcPin17_prev = 1;                                      //Remember current input state
      timer4 = now;                                          //Set timer4 to current_time
    }
  }
  else if(rcPin17_prev == 1){                                //Input 17 is not high and changed from 1 to 0
    rcPin17_prev = 0;                                        //Remember current input state
    rcPin17 = now - timer4;                                  //Channel 4 is current_time - timer4
  }
}

