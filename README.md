# ArduinoTrinket PRO (3v/12Mhz)
# Applicable to (5v/16Mhz) 

On Trinket PRO (5v or 3v Logic), there are 3 Ports (Port B, C, and D) which can be utilized for pin change interrupt.
Take note that some pins on each port are multifunction so care shall be taken in using a multifunction pin. Example is the physical board's pin 10, 11, 12, and 13 can be use as SPI pins.

Definition:
BOARD PIN - The pin number labeled on the physical Trinket Pro board.
PBx       - The chip designated port pin number eg. Port B there are pins PB0, PB1, PB2...PB7
PCIBTx    - The Pin Change Interrupt Number corresponding to Port's pin
PCIEx     - Pin change interrupt number for the port...i.e. PORT B as PCIE0, PORT C as PCIE1, PORT D as PCIE2

  PIN CHANGE INTERRUPT PORT B PCIE0
  BOARD    PCINT0  PORT    PCIE0/PSMSK0  BIT              Other Function          NOTE
    08        7     PB0        PCINT0    B00000001          Free                  -
    09        8     PB1        PCINT1    B00000010          Free                  -
    10        9     PB2        PCINT2    B00000100          SPI SS
    11        10    PB3        PCINT3    B00001000          SPI MOSI
    12        11    PB4        PCINT4    B00010000          SPI MISO
    13        12    PB5        PCINT5    B00100000          SPI SCK, LED 13       Only 6 pins for PORT B

  PIN CHANGE INTERRUPT PORT C PCIE1
  BOARD    PCINT1  PORT    PCIE1/PSMSK1  BIT              Other Function          NOTE
    A0        0     PC0        PCINT0    B00000001          Free                  -
    A1        1     PC1        PCINT1    B00000010          Free                  -
    A2        2     PC2        PCINT2    B00000100          Free                  -
    A3        3     PC3        PCINT3    B00001000          Free
    A4        4     PC4        PCINT4    B00010000          I2C SDA               Use one function at a time
    A5        5     PC5        PCINT5    B00100000          I2C SCL               Use one function at a time
    A6        6     PC6        PCINT6    B01000000          Free                  -
    A7        7     PC7        PCINT7    B10000000          Free                  -
    
    
  PIN CHANGE INTERRUPT PORT D PCIE2
  
