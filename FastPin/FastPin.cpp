#include "FastPin.h"

FastPin::FastPin(byte id, bool isOutput, bool isHigh)
  :
  _pinId(id),
  _bitmask(digitalPinToBitMask(_pinId)),
  _notBitmask(~_bitmask),
  _ddr(portModeRegister(digitalPinToPort(_pinId))),
  _port(portOutputRegister(digitalPinToPort(_pinId))),
  _pin(portInputRegister(digitalPinToPort(_pinId)))
{
  if (isOutput)
    output();
  else
    input();

  if (isHigh)
    high();
  else
    low();
};

void FastPin::changePin(byte id, bool isOutput, bool isHigh)
{
  _pinId = id;
  _bitmask = digitalPinToBitMask(_pinId);
  _notBitmask = ~_bitmask;
  _ddr = portModeRegister(digitalPinToPort(_pinId));
  _port = portOutputRegister(digitalPinToPort(_pinId));
  _pin = portInputRegister(digitalPinToPort(_pinId));

  if (isOutput)
    output();
  else
    input();

  if (isHigh)
    high();
  else
    low();
};

byte FastPin::pinId() const
{
  return _pinId;
};

byte FastPin::bitmask() const
{
  return _bitmask;
};

volatile byte * FastPin::ddr() const
{
  return _ddr;
};

volatile byte * FastPin::port() const
{
  return _port;
};

volatile byte * FastPin::pin() const
{
  return _pin;
};