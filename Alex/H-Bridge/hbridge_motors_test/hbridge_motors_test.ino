int motor1A = 5;
int motor1B = 6;

int motor2A = 10;
int motor2B = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  motion("front");
  delay(1000);
  motion("stop");
  delay(1000);
  motion("back");
  delay(1000);
  motion("stop");
  delay(1000);
  motion("right");
  delay(1000);
  motion("stop");
  delay(1000);
  motion("left");
  delay(1000);
  motion("stop");
  delay(1000);
}

void motor1(String i) {
  if(i.equals("CW") == true){
    digitalWrite(motor1A, HIGH);
    digitalWrite(motor1B, LOW);
  } else if(i.equals("CCW") == true){
    digitalWrite(motor1A, LOW);
    digitalWrite(motor1B, HIGH);
  } else if(i.equals("OFF") == true){
    digitalWrite(motor1A, LOW);
    digitalWrite(motor1B, LOW);
  } else {
    digitalWrite(motor1A, LOW);
    digitalWrite(motor1B, LOW);
  }
}

void motor2(String i) {
  if(i.equals("CW") == true){
    digitalWrite(motor2A, HIGH);
    digitalWrite(motor2B, LOW);
  } else if(i.equals("CCW") == true){
    digitalWrite(motor2A, LOW);
    digitalWrite(motor2B, HIGH);
  } else if(i.equals("OFF") == true){
    digitalWrite(motor2A, LOW);
    digitalWrite(motor2B, LOW);
  } else {
    digitalWrite(motor2A, LOW);
    digitalWrite(motor2B, LOW);
  }
}

void motion(String m){
  if(m.equals("front") == true){
    motor1("CW");
    motor2("CCW");
  } else if(m.equals("back") == true){
    motor1("CCW");
    motor2("CW");
  } else if(m.equals("right") == true){
    motor1("CCW");
    motor2("CCW");
  } else if(m.equals("left") == true){
    motor1("CW");
    motor2("CW");
  } else {
    motor1("OFF");
    motor2("OFF");
  }
}
