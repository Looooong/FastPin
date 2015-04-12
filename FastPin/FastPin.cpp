FastPin::FastPin(byte id, bool isOutput, bool isHigh)
  :
  _pinId(id),
  _bitmask(digitalPinToBitMask(_pinId)),
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

void FastPin::input()
{
  *_ddr &= ~_bitmask;
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
  *_port &= ~_bitmask;
};

bool FastPin::read()
{
  return *_pin & _bitmask;
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