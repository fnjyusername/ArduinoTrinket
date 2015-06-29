# ArduinoTrinket PRO (3v/12Mhz or 5v/16Mhz)

On Trinket PRO (5v or 3v Logic), there are 3 Ports (Port B, C, and D) which can be utilized for pin change interrupt.
Take note that some pins on each port are multifunction so care shall be taken in using a multifunction pin. Example is the physical board's pin 10, 11, 12, and 13 can be use as SPI pins.

Definition:
BOARD PIN - The pin number labeled on the physical Trinket Pro board.
PBx       - The chip designated port pin number eg. Port B there are port pins PB0, PB1, PB2...PB7
PCINTx    - The Pin Change Interrupt Number corresponding to Port's pin
PCIEx     - Pin change interrupt number for the port...i.e. PORT B as PCIE0, PORT C as PCIE1, PORT D as PCIE2
CHIPx     - Pin number as labelled on ATMEGA328 Chip

  PIN CHANGE INTERRUPT PORT B PCIE0
  BOARD     CHIP    PORT    PCIE0/PSMSK0  BIT              Other Function          NOTE
    08        8     PB0        PCINT0    B00000001          Free                  -
    09        9     PB1        PCINT1    B00000010          Free                  -
    10        10    PB2        PCINT2    B00000100          SPI SS
    11        11    PB3        PCINT3    B00001000          SPI MOSI
    12        12    PB4        PCINT4    B00010000          SPI MISO
    13        13    PB5        PCINT5    B00100000          SPI SCK, LED 13       Only 6 pins for PORT B

  PIN CHANGE INTERRUPT PORT C PCIE1
  BOARD     CHIP    PORT    PCIE1/PSMSK1  BIT              Other Function          NOTE
    A0       23     PC0        PCINT8    B00000001          Free                  -
    A1       24     PC1        PCINT9    B00000010          Free                  -
    A2       25     PC2        PCINT10   B00000100          Free                  -
    A3       26     PC3        PCINT11   B00001000          Free
    A4       27     PC4        PCINT12   B00010000          I2C SDA               Use one function at a time
    A5       28     PC5        PCINT13   B00100000          I2C SCL               Use one function at a time

    
  PIN CHANGE INTERRUPT PORT D PCIE2
  BOARD     CHIP    PORT    PCIE1/PSMSK1   BIT              Other Function          NOTE
     0        2     PD0        PCINT16    B00000001         RX0                   Serial RX
     1        3     PD1        PCINT17    B00000010         TX0                   Serial TX
     X        4     PD2        PCINT18    B00000100         N/A                   Not Available (Used as Interrupt 0)
     3        5     PD3        PCINT19    B00001000         INT1                  Interrupt 1
     4        6     PD4        PCINT20    B00010000         Free                  -
     5        11    PD5        PCINT21    B00100000         Free                  -
     6        12    PD6        PCINT22    B01000000         Free                  -
     x        13    PD7       PCINT23     B10000000         N/A                   Not 
     
     
