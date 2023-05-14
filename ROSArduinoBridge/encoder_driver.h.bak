/* *************************************************************
   Encoder driver function definitions - by James Nugen
   ************************************************************ */


#ifdef ARDUINO_ENC_COUNTER
  // in arduino nano (atmega328), only P2 and P3 can be used for interrupts
  //
  //below can be changed, but should be PORTD pins;
  //otherwise additional changes in the code are required
  #define LEFT_ENC_PIN_A 2 // PD2, D2, E1A
  #define RIGHT_ENC_PIN_A 3 // PD3, D3, E2A

  //below can be changed, but should be PORTC pins
  #define LEFT_ENC_PIN_B 17 // PC3, A3, E1B
  #define RIGHT_ENC_PIN_B 16 // PC2, A2, E2B
#endif

void initEncoders();
long readEncoder(int i);
void resetEncoder(int i);
void resetEncoders();
