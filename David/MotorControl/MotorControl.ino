// Output values to the motors

// Define the outputs for each of the motors
const int LmotPWM = 6;
const int LmotDIG = 7;
const int RmotPWM = 9;
const int RmotDIG = 10;

// Create the arrays to reference each of the motors
int lMotor[2] = {LmotPWM, LmotDIG};
int rMotor[2] = {RmotPWM, RmotDIG}; // Left Motor Pins

// Initialize the output motor function
int motVel(signed char vel, int pwm =lMotor[0], int dig =lMotor[1]);


void setup() {
  Serial.begin(115200);

  pinMode(lMotor[1], OUTPUT);
  pinMode(rMotor[1], OUTPUT);

  signed char vel = -50;
  motVel(vel);
  
}

void loop() {
  // Input the velocity desired to the motor outputs
  Serial.println(analogRead(A0));
  int vel = analogRead(A0);
  //int vel = 125;
  vel = map(vel, 0, 766, -127, 127);
  Serial.println(vel);
    
  // Set the motor's velocities
  motVel(vel, lMotor[0], lMotor[1]);
  motVel(vel, rMotor[0], rMotor[1]);
  delay(10);
}


int motVel(signed char vel, int pwm, int dig) { // Set the correct outputs for each of the motor's pins as defined in the program
  /* signed char vel: (-127 to 127): Value controls velocity, negative values control reverse movement
     int pwm: (PWM Capable pin):     Value for the pwm input of the motor
     int dig: (Digital pin):         Value for the dig input of the motor 
   */
  int pwmVal;  // The value written to the pwm pin (must be intverted if in reverse)

  // Determine the direction of the motor
  if(vel < 0){  // The velocity is negative
    digitalWrite(dig, HIGH); // Digital pin must be turned on
    pwmVal = 129 + vel; // Invert the velocity (Reverse velocity)
  }
  else {
    digitalWrite(dig, LOW); // Digital pin must be turned off
    pwmVal = vel; // Forward velocity
  }
  
  // Map the motor velocity (7 - bit) to the pwm duty cycle (8 - bit)
  pwmVal = map(vel, 0, 127, 0, 255);
  analogWrite(pwm, pwmVal);

//  Serial.print("Velocity: ");
//  Serial.println(vel);
//  Serial.print("Digital Pin: ");
//  Serial.println(dig);
//  Serial.print("PWM Pin: ");
//  Serial.println(pwm);
//  Serial.print("PWM Value: ");
//  Serial.println(pwmVal);
//  Serial.print("Digital Pin Status: ");
//  Serial.println(digitalRead(dig));

  return vel;
}
