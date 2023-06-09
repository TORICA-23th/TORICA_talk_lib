#pragma once

class AquesTalkPico {
 public:
  AquesTalkPico();
  ~AquesTalkPico();

  virtual int    Send(const char* msg) = 0;
  virtual size_t Recv(char* res, size_t res_size) = 0;
  virtual bool   Busy() = 0;

  int ShowRes(int res_length_to_show = 1);
  int DumpEeprom();
  int WriteEeprom(int address, int data);
  int WritePresetMsg(const char* msg[], int num_of_msg);
  int WriteSerialSpeed(int serial_speed);
  int WriteI2cAddress(int i2c_address);

 private:
  char HexChar(int n);
};