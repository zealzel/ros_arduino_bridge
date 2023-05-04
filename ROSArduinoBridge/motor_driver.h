/***************************************************************
   Motor driver function definitions - by James Nugen
   *************************************************************/

#ifdef L298_MOTOR_DRIVER
  #define RIGHT_MOTOR_BACKWARD 5
  #define LEFT_MOTOR_BACKWARD  6
  #define RIGHT_MOTOR_FORWARD  9
  #define LEFT_MOTOR_FORWARD   10
  #define RIGHT_MOTOR_ENABLE 12
  #define LEFT_MOTOR_ENABLE 13
#elif defined(TB6612)
  #define PWMA 11
  #define AIN2 4
  #define AIN1 5
  #define STBY 7
  #define BIN1 8
  #define BIN2 9
  #define PWMB 10
  // =============================
  #define RIGHT_MOTOR_BACKWARD BIN1
  #define RIGHT_MOTOR_FORWARD  BIN2
  #define RIGHT_MOTOR_ENABLE   PWMB
  #define LEFT_MOTOR_BACKWARD  AIN1
  #define LEFT_MOTOR_FORWARD   AIN2
  #define LEFT_MOTOR_ENABLE    PWMA
#endif

//#define STBY 11

void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int leftSpeed, int rightSpeed);
