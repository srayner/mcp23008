#include <Wire.h>

void setup()
{
    Wire.begin(); // creates a Wire object

    // set I/O pins to outputs
    Wire.beginTransmission(0x21); // begins talking to the slave device
    Wire.write(0x00); // selects the IODIR register
    Wire.write(0x00); // this sets all GP pins to outputs
    Wire.endTransmission(); // stops talking to device
}

void loop()
{
  delay(500);
  output(0x21, 0x09, B00000001);

  delay(250);
  output(0x21, 0x09, B00000000);
}

/**
 * Writes a value to a register on a slave device
 */
 void output(byte addr, byte reg, byte val)
 {
    Wire.beginTransmission(addr);
    Wire.write(reg);
    Wire.write(val);
    Wire.endTransmission();
 }
