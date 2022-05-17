int Y_pin = 0;
int X_pin = 1;
int SW_pin = 3;

int X;
int Y;

void setup() {
  Serial.begin(9600);
  
  pinMode(SW_pin, INPUT_PULLUP);
}

void loop() {

  //Test for joysticks
  //Prints values in serial monitor
  
  X = map(analogRead(X_pin), 0, 1023, -100, 100);
  Y = map(analogRead(Y_pin), 0, 1023, -100, 100);
  
  Serial.print("X-axis: ");
  Serial.print(X);
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(Y);
  Serial.print("\n");
  Serial.print("Switch: ");
  Serial.println(digitalRead(SW_pin));
  Serial.print("\n");
  
  delay(100);
}
