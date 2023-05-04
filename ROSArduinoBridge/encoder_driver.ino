/* *************************************************************
   Encoder definitions

   Add an "#ifdef" block to this file to include support for
   a particular encoder board or library. Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.

   ************************************************************ */

#ifdef USE_BASE

#ifdef ROBOGAIA
  /* The Robogaia Mega Encoder shield */
  #include "MegaEncoderCounter.h"

  /* Create the encoder shield object */
  MegaEncoderCounter encoders = MegaEncoderCounter(4); // Initializes the Mega Encoder Counter in the 4X Count mode

  /* Wrap the encoder reading function */
  long readEncoder(int i) {
    if (i == LEFT) return encoders.YAxisGetCount();
    else return encoders.XAxisGetCount();
  }

  /* Wrap the encoder reset function */
  void resetEncoder(int i) {
    if (i == LEFT) return encoders.YAxisReset();
    else return encoders.XAxisReset();
  }
#elif defined(ARDUINO_ENC_COUNTER)
  volatile long left_enc_pos = 0L;
  volatile long right_enc_pos = 0L;

  void initEncoders() {
    pinMode(LEFT_ENC_PIN_B, INPUT);
    pinMode(LEFT_ENC_PIN_A, INPUT);
    pinMode(RIGHT_ENC_PIN_B, INPUT);
    pinMode(RIGHT_ENC_PIN_A, INPUT);
    attachInterrupt(digitalPinToInterrupt(LEFT_ENC_PIN_A),readEncoder1,RISING);
    attachInterrupt(digitalPinToInterrupt(RIGHT_ENC_PIN_A),readEncoder2,RISING);
  }

  // Wrap the encoder reading function
  long readEncoder(int i) {
    long encVal = 0L;
    if (i == LEFT) {
      noInterrupts();
      encVal = left_enc_pos;
      interrupts();
    }
    else {
      noInterrupts();
      encVal = right_enc_pos;
      interrupts();
    }
    return encVal;
  }

  // Wrap the encoder reset function
  void resetEncoder(int i) {
    long encVal = 0L;
    if (i == LEFT) {
      noInterrupts();
      left_enc_pos = 0L;
      interrupts();
    }
    else {
      noInterrupts();
      right_enc_pos = 0L;
      interrupts();
    }
    return;
  }

  void readEncoder1(){
    int b = digitalRead(LEFT_ENC_PIN_B);
    if(digitalRead(LEFT_ENC_PIN_B) > 0){
      left_enc_pos++;
    }
    else {
      left_enc_pos--;
    }
  }

  void readEncoder2(){
    int b = digitalRead(RIGHT_ENC_PIN_B);
    if(digitalRead(RIGHT_ENC_PIN_B) > 0){
      // right_enc_pos++;
      right_enc_pos--;
    }
    else {
      // right_enc_pos--;
      right_enc_pos++;
    }
  }

#else
  #error A encoder driver must be selected!
#endif

/* Wrap the encoder reset function */
void resetEncoders() {
  resetEncoder(LEFT);
  resetEncoder(RIGHT);
}

#endif
