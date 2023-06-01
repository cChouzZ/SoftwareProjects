int pinA = 12;
int pinB = 11; 
int pinC = 10; 
int pinD = 9; 
int dt = 2000; 

void setup() {
  // put your setup code here, to run once:
pinMode(pinA, OUTPUT);
pinMode(pinB, OUTPUT);
pinMode(pinC, OUTPUT);
pinMode(pinD, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(pinA, LOW);
digitalWrite(pinB, LOW);
digitalWrite(pinC, LOW);
digitalWrite(pinD, LOW);
delay(dt); 

delay(dt);
digitalWrite(pinA, HIGH);
digitalWrite(pinB, LOW);
digitalWrite(pinC, LOW);
digitalWrite(pinD, LOW);
delay(dt);

digitalWrite(pinA, LOW);
digitalWrite(pinB, HIGH);
digitalWrite(pinC, LOW);
digitalWrite(pinD, LOW);
delay(dt);

digitalWrite(pinA, LOW);
digitalWrite(pinB, LOW);
digitalWrite(pinC, HIGH);
digitalWrite(pinD, LOW);
delay(dt);

digitalWrite(pinA, LOW);
digitalWrite(pinB, LOW);
digitalWrite(pinC, LOW);
digitalWrite(pinD, HIGH);
delay(dt);

digitalWrite(pinA, HIGH);
digitalWrite(pinB, HIGH);
digitalWrite(pinC, HIGH);
digitalWrite(pinD, HIGH);
delay(dt);


}
