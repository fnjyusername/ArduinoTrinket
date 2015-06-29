# ArduinoTrinket PRO (3v/12Mhz or 5v/16Mhz)

On Trinket PRO (5v or 3v Logic), there are 3 Ports (Port B, C, and D) which can be utilized for pin change interrupt.
Take note that some pins on each port are multifunction so care shall be taken in using a multifunction pin. Example is the physical board's pin 10, 11, 12, and 13 can be use as SPI pins.

Definition:
BOARD PIN - The pin number labeled on the physical Trinket Pro board.
PBx       - The chip designated port pin number eg. Port B there are port pins PB0, PB1, PB2...PB7
PCINTx    - The Pin Change Interrupt Number corresponding to Port's pin
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
    A0        0     PC0        PCINT8    B00000001          Free                  -
    A1        1     PC1        PCINT9    B00000010          Free                  -
    A2        2     PC2        PCINT10   B00000100          Free                  -
    A3        3     PC3        PCINT11   B00001000          Free
    A4        4     PC4        PCINT12   B00010000          I2C SDA               Use one function at a time
    A5        5     PC5        PCINT13   B00100000          I2C SCL               Use one function at a time

    A6        6     PC0        PCINT8    B00000001          Free                  Duplicate of A0
    A7        7     PC1        PCINT9    B00000010          Free                  Duplicate of A1
    
    
  PIN CHANGE INTERRUPT PORT D PCIE2
  BOARD    PCINT1  PORT    PCIE1/PSMSK1   BIT              Other Function          NOTE
     0        0     PD0        PCINT16    B00000001         RX0                   Serial RX
     1        1     PD1        PCINT17    B00000010         TX0                   Serial TX
     X        2     PD2        PCINT18    B00000100         N/A                   Not Available
     3        3     PD3        PCINT19    B00001000         INT1                  Interrupt 1
     4        4     PD4        PCINT20    B00010000         Free                  -
     5        5     PD5        PCINT21    B00100000         Free                  -
     6        6     PD6        PCINT22    B01000000         Free                  -
     x        7     PD7        PCINT23    B10000000         N/A                   Not Available
