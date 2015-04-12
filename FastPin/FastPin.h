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
    inline bool read();
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
    volatile byte * _ddr;
    volatile byte * _port;
    volatile byte * _pin;
};