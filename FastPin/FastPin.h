#ifndef FAST_PIN_H_
#define FAST_PIN_H_

#include "Arduino.h"

class FastPin {
  public:
    // Contruct with initial state
    FastPin(byte id, bool isOutput = false, bool isHigh = false);
    // Changing pin if needed
    void changePin(byte id, bool isOutput = false, bool isHigh = false);
    // Port manipulation functions
    // 'Inline' would double the speed but increase code size
    // However, this is what FastPin is for...
    inline void input();
    inline void output();
    inline void high();
    inline void low();
    inline byte read(); // The result of bitwise operation is byte, so...
    // Getters don't need to be 'inline' to be fast
    // However, port manipulation with getters is a bit slower than those functions above...
    byte pinId() const;
    byte bitmask() const;
    volatile byte * ddr() const;
    volatile byte * port() const;
    volatile byte * pin() const;

  private:
    byte _pinId;
    byte _bitmask;
    byte _notBitmask; // Bitwise NOT of _bitmask, a trick for faster manipulation
    volatile byte * _ddr;
    volatile byte * _port;
    volatile byte * _pin;
};

void FastPin::input()
{
  *_ddr &= _notBitmask;
};

void FastPin::output()
{
  *_ddr |= _bitmask;
};

void FastPin::high()
{
  *_port |= _bitmask;
};

void FastPin::low()
{
  *_port &= _notBitmask;
};

byte FastPin::read()
{
  return *_pin & _bitmask;
};

#endif//FAST_PIN_H_