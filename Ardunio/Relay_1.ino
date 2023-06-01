int IN1 = 13;
int IN2 = 12;
int IN3 = 8;
int IN4 = 7;
int delta = 3500;

void setup() {
  // put your setup code here, to run once:
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(IN1, HIGH);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, HIGH); 
delay(delta); 

digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, HIGH); 
delay(delta); 

digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, HIGH); 
delay(delta); 

digitalWrite(IN1, HIGH);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, LOW);
digitalWrite(IN4, HIGH); 
delay(delta); 

digitalWrite(IN1, HIGH);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW); 
delay(delta); 

digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW); 
delay(delta); 
}
