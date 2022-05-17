// Translate joystick positions to motor velocities

// Define the pins used for the input connections
const int Xin = A0;
const int Yin = A1;
const int SWin = 3;

// Motor output variables
signed char L = 0;
signed char R = 0;

// Initialize the output function
int joyToMotor(int X, int Y, signed char *L, signed char *R);


void setup() {
  // Set the switch as an input pin
  pinMode(SWin, INPUT_PULLUP);

  // For tests (DELETE ONCE DONE TESTING)
  Serial.begin(115200);
  
}

void loop() {
  // Read the values of the x and y joystick
  int x = analogRead(Xin);
  int y = analogRead(Yin);
  int sw = digitalRead(SWin);

  joyToMotor(x, y, &L, &R);

  //Print output
  Serial.print("X input: ");
  Serial.println(x);
  Serial.print("Y input: ");
  Serial.println(y);
  Serial.print("Switch: ");
  Serial.println(sw);
  Serial.print("r output: ");
  Serial.println(R);
  Serial.print("l output: ");
  Serial.println(L);
  Serial.println("");

  delay(100);
}


// Define the translation from XY coordinate space to LR
int joyToMotor(int X, int Y, signed char *L, signed char *R) {  
  // Map values to usable figures
  int x = map(X, 0, 1023, -100, 100);
  int y = map(Y, 0, 1023, -100, 100);

  // Correct for any initial offsets
  if(x > -5 && x < 5){
    x = 0;
  }
  if(y > -5 && y < 5){
    y = 0;
  }
  
  // Calculate Motor values
  x = -1 * x; //Invert x
  int v = (100 -abs(x))* (y/100) +y; //Calculate a v value: R-L
  int w = (100 -abs(y))* (x/100) +x; //Calculate a w value: R+L
  int r = (v +w)/2; //Calcualte r
  int l = (w -v)/2; //Calculate l
  r = map(r, -100, 100, -127, 127); //Map to bytes
  l = map(l, -100, 100, -127, 127);

  // Set to the output bytes
  *L = l;
  *R = r;
}
