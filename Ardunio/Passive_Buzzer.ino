int buzzPin = 8;
//int buzzTime = 1;
int potPin = A1; 
int potVal; 
//int buzzTime2 = 5000;
int toneVal; 

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  pinMode(buzzPin,OUTPUT); 
  pinMode(potPin, INPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
 // Serial.println(potVal);
  potVal = analogRead(potPin); 
  toneVal = (9940./1023.)*potVal+60;
digitalWrite(buzzPin,HIGH); 
delayMicroseconds(toneVal); 
digitalWrite(buzzPin,LOW); 
delayMicroseconds(toneVal);  
}
