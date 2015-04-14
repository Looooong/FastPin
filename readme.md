# Arduino - FastPin

This library provide a quick way for digital port manipulation - an alternative to `pinMode`, `digitalWrite` and `digitalRead` - where speed is crucial.

This is **FAST** pin.

## Installation

Copy **FastPin** folder to Arduino library folder

## Usage

- `FastPin(byte id, bool isOutput = false, bool isHigh = false)` constructor, initialize `FastPin` object with `id` of the pin and initial states (optional).
- `void changePin(byte id, bool isOutput = false, bool isHigh = false)` change pin.
- `inline void input()` equavilent to `pinMode(pinId, INPUT)`.
- `inline void output()` equavilent to `pinMode(pinId, OUTPUT)`.
- `inline void high()` equavilent to `digitalWrite(pinId, HIGH)`.
- `inline void low()` equavilent to `digitalWrite(pinId, LOW)`.
- `inline byte read()` equavilent to `digitalRead(pinId)`.
- `byte pinId() const` get id of the pin.
- `byte bitmask() const` get bitmask of the pin, is used with DDR, PORT and PIN.
- `volatile byte * ddr() const` get DDR register of the pin.
- `volatile byte * port() const` get PORT register of the pin.
- `volatile byte * pin() const` get PIN register of the pin.