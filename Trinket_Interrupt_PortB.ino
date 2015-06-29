/* 
  PIN CHANGE INTERRUPT PORT B PCIE0
  BOARD    PCINT0  PORT    PCIE0/PSMSK0  BIT
    09        8     PB1        PCINT1    B00000010
    10        9     PB2        PCINT2    B00000100
    11        10    PB3        PCINT3    B00001000
    12        11    PB4        PCINT4    B00010000
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Declaring Variables
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int rcPin09_prev, rcPin10_prev, rcPin11_prev, rcPin12_prev;
int rcPin09, rcPin10, rcPin11, rcPin12;
volatile unsigned long timer1, timer2, timer3, timer4, now;
byte highByte, lowByte;
int led = 13;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Setup routine
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup(){ Serial.begin(115200);
 pinMode(led, OUTPUT);
 pinMode(9, INPUT); digitalWrite(9, HIGH);
 pinMode(10, INPUT);digitalWrite(10, HIGH);
 pinMode(11, INPUT);digitalWrite(11, HIGH);
 pinMode(12, INPUT);digitalWrite(11, HIGH);
//ARDUINO PRO TRINKET 328
//TIMSK0 &= ~_BV(TOIE0);                                       //Disable Timer0, for gitter free against interrupt.
  PCICR  |= (1 << PCIE0);                                      //Set PCIE0 to enable PCMSK0 scan.
  PCMSK0 |= (1 << PCINT1);                                     //Set PCINT1 (digital input 8)to trigger an interrupt on state change.
  PCMSK0 |= (1 << PCINT2);                                     //Set PCINT2 (digital input 9) to trigger an interrupt on state change.
  PCMSK0 |= (1 << PCINT3);                                     //Set PCINT3 (digital input 10)to trigger an interrupt on state change.
  PCMSK0 |= (1 << PCINT4);                                     //Set PCINT4 (digital input 11)to trigger an interrupt on state change.                                   //Set PCINT7 (digital input 11)to trigger an interrupt on state change.
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
ISR(PCINT0_vect){
  now = micros();
  //Channel 1==AIL  PORT PB3=====================================
  if(PINB & B00000010){                                      //Is input 3 high? 
    if(rcPin09_prev == 0){                                   //Input 3 changed from 0 to 1
      rcPin09_prev = 1;                                      //Remember current input state
      timer1 = now;                                          //Set timer1 to current_time
    }
  }
  else if(rcPin09_prev == 1){                                //Input 3 is not high and changed from 1 to 0
    rcPin09_prev = 0;                                        //Remember current input state
    rcPin09 = now - timer1;                                  //Channel 1 is current_time - timer_1
  }
  //Channel 2==ELE  PORT PB4====================================
  if(PINB & B00000100 ){                                     //Is input 4 high?
    if(rcPin10_prev == 0){                                   //Input 4 changed from 0 to 1
      rcPin10_prev = 1;                                      //Remember current input state
      timer2 = now;                                          //Set timer2 to current_time
    }
  }
  else if(rcPin10_prev == 1){                                //Input 4 is not high and changed from 1 to 0
    rcPin10_prev = 0;                                        //Remember current input state
    rcPin10 = now - timer2;                                  //Channel 2 is current_time - timer2
  }
  //Channel 3==THR  PORT PB5====================================
  if(PINB & B00001000 ){                                     //Is input 5 high?
    if(rcPin11_prev == 0){                                   //Input 5 changed from 0 to 1
      rcPin11_prev = 1;                                      //Remember current input state
      timer3 = now; //Serial.println(rcPin11);              //Set timer3 to current_time
    }
  } 
  else if(rcPin11_prev == 1){                                //Input 5 is not high and changed from 1 to 0
    rcPin11_prev = 0;                                        //Remember current input state
    rcPin11 = now - timer3;                                  //Channel 3 is current_time - timer3

  }
  //Channel 4==RUD  PORT PB6====================================
  if(PINB & B00010000 ){                                     //Is input 6 high?
    if(rcPin12_prev == 0){                                   //Input 6 changed from 0 to 1
      rcPin12_prev = 1;                                      //Remember current input state
      timer4 = now;                                          //Set timer4 to current_time
    }
  }
  else if(rcPin12_prev == 1){                                //Input 6 is not high and changed from 1 to 0
    rcPin12_prev = 0;                                        //Remember current input state
    rcPin12 = now - timer4;                                  //Channel 4 is current_time - timer4
  }
}


