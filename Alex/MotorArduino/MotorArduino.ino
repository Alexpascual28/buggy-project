// Final firmware on the Motor Control Arduino

// Loop delay
const int wait = 10; // Delay time in milliseconds

// Define the outputs for each of the motors
const int LmotPWM = 6;
const int LmotDIG = 7;
const int RmotPWM = 9;
const int RmotDIG = 10;

// Create the arrays to reference each of the motors
const int lMotor[2] = {LmotPWM, LmotDIG};
const int rMotor[2] = {RmotPWM, RmotDIG};

// Initialize the output motor function
int motVel(signed char vel, int pwm =lMotor[0], int dig =lMotor[1]);

// Initialize the motor velocity variables
int Lvel = 0;
int Rvel = 0;


// UART Settings
const byte checkByte = 0x80; // Byte used to verify meaningful transmission (Must match Transmit)

// Three communication variables
signed char Lcomms;
signed char Rcomms;
byte SW;


void setup() {
  // Initialize the output pins
  pinMode(lMotor[1], OUTPUT);
  pinMode(rMotor[1], OUTPUT);

  // Initialize UART Communications:
  Serial.begin(115200); // Begin communications with the ESP (Note: Data sent over the TX line is meant to be read over usb)
}

void loop() {
  // Receive communications
  if(Serial.read()==0x80){ // Check for the check byte, if correct: set the desired variables to the received values
    Lcomms = Serial.read();
    Rcomms = Serial.read();
    SW = Serial.read();
  } 
  else { // Check byte is incorrect
    Serial.flush(); // Flush all serial values
  }
  
  // Input the velocity desired to the motor outputs
  Lvel = Lcomms; // set the left velcity
  Rvel = Rcomms; // set the right velocity
  
  // Set the motor's velocities
  motVel(Lvel, lMotor[0], lMotor[1]);
  motVel(Rvel, rMotor[0], rMotor[1]);

  // Print ALL values for debugging
  Serial.print("Lcomms: ");
  Serial.println(Lcomms);
  Serial.print("Rcomms: ");
  Serial.println(Rcomms);
  Serial.print("Switch: ");
  Serial.println(SW);
//  Serial.print("Lvel:   ");
//  Serial.println(Lvel);
//  Serial.print("Rvel:   ");
//  Serial.println(Rvel);
//  Serial.println("");

  delay(wait);
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
  return vel;
}
