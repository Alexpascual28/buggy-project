int trigger = 3;
int echo = 4;
int led_rojo = 8;
int led_amarillo = 2;
int alarma = 11;  //Creo que solo se pueden utilizar los pines 3 y 11 con el altavoz

int Right_A = 6;  // Right motot-A
int Right_B = 7;  // Right motor-B
int Left_A = 9;   // Left motor-B
int Left_B = 10;  // Left motor-B
 
float tiempo;
float distancia;
float velocidad = 0.034;
float Collision_Medium = 25.0;
float Collision_High = 10.0;


void setup() {   // put your setup code here, to run once:
  
Serial.begin(9600);
pinMode(trigger,OUTPUT);
pinMode(echo,INPUT);
pinMode(led_rojo,OUTPUT);
pinMode(led_amarillo,OUTPUT);

}

void loop() {   // put your main code here, to run repeatedly:
  
digitalWrite(trigger,LOW);  //Esto estabiliza el sensor. 
delayMicroseconds(5);      // Da un pulso LOW durante un muy corto periodo de tiempo para garantizar un pulso HIGH limpio


digitalWrite(trigger,HIGH);
tiempo = pulseIn(echo,HIGH);
tiempo = tiempo/2;
distancia = tiempo*velocidad;

Serial.print("Distancia: ");
Serial.print(distancia);
Serial.println(" cm");




if (distancia < Collision_High) {
  Serial.println("DANGER,DANGER");
  tone(alarma,500);   //No se pueden generar frecuencias más bajas que 31 Hz
  digitalWrite(led_amarillo,LOW);
  digitalWrite(led_rojo,HIGH);
  delay(100);
}


else if(distancia < Collision_Medium) {
  Serial.println("WARNING");
  tone(alarma,2000,50);
  digitalWrite(led_amarillo,HIGH);
  digitalWrite(led_rojo,LOW);
  delay(100);
    
}

else {
  digitalWrite(led_amarillo,LOW);
  digitalWrite(led_rojo,LOW);
  noTone(alarma);
  delay(100);
}

                                                    
}
