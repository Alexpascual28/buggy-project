// Final firmware on the Motor Control Arduino

//Pins for the components of the ultrasonic sensor
const int trigger = 3;
const int echo = 4;
const int led_rojo = 13;
const int led_amarillo = 12;

//values used to measure data from the ultrasonic sensor
float tiempo;
float distancia;
float velocidad = 0.034;
float Collision_Medium = 25.0;
float Collision_High = 10.0;

// Value to turn on collision
bool SWprevious =0;
bool enable = 0;

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
  // Initializes the output pins
  pinMode(lMotor[1], OUTPUT);
  pinMode(rMotor[1], OUTPUT);

  // Initializes the ultrosonic sensor pins
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(led_rojo,OUTPUT);
  pinMode(led_amarillo,OUTPUT);

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

  // Initiates collision detection
  if(SW == 0 && SWprevious !=0) {
    if(enable) {
      enable =0;
    }
    else {
      enable =1;
    }
  }
  SWprevious = SW;

  if(enable) {
    ultrasonic();
    Serial.println("Ultra");
  }

  // Print ALL values for debugging
  Serial.print("Lcomms: ");
  Serial.println(Lcomms);
  Serial.print("Rcomms: ");
  Serial.println(Rcomms);
  Serial.print("Switch: ");
  Serial.println(SW);
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
  pwmVal = map(vel, 0, 130, 0, 255);
  analogWrite(pwm, pwmVal);
  return vel;
}

//Reads data from the ultrasonic sensor and produces warnings depending on distance
void ultrasonic(){
  digitalWrite(trigger,LOW);  //Esto estabiliza el sensor. 
  delayMicroseconds(5);      // Da un pulso LOW durante un muy corto periodo de tiempo para garantizar un pulso HIGH limpio
  
  digitalWrite(trigger,HIGH);
  tiempo = pulseIn(echo,HIGH, 10000);
  tiempo = tiempo/2;
  distancia = tiempo*velocidad;
  if(distancia == 0) {
    distancia = 100;
  }

  
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
  
  if (distancia < Collision_High) {
    //Serial.println("DANGER,DANGER");
    digitalWrite(led_amarillo,LOW);
    digitalWrite(led_rojo,HIGH);
  }
  
  else if(distancia < Collision_Medium) {
    Serial.println("WARNING");
    digitalWrite(led_amarillo,HIGH);
    digitalWrite(led_rojo,LOW);
  }
  
  else {
    digitalWrite(led_amarillo,LOW);
    digitalWrite(led_rojo,LOW);
  }
}
