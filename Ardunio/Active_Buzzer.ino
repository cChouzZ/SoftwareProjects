// Shows how the potientomitor works as well to read values from it 
//int myNumb;
//int buzzPin = 8;
//String msg = "Please Input Your Number";
int dt = 100;

int potVal;
int buzzPin = 8; 
int potPin = A3; 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(buzzPin, OUTPUT);

pinMode(potPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
//Serial.println(msg);
//while (Serial.available()==0) { 
  
//}

potVal = analogRead(potPin);
Serial.println(potVal); 
//if (potVal > 1000){ 
//  digitalWrite(buzzPin, HIGH);
 // delay(dt);
 // digitalWrite(buzzPin, LOW); 
//}

while (potVal > 1000){ 
  digitalWrite(buzzPin, HIGH);
  potVal = analogRead(potPin);
  Serial.println(potVal); //Not freeze when going to the top value
}
digitalWrite(buzzPin, LOW);

//myNumb = Serial.parseInt();
//if (myNumb > 10) { 
 // digitalWrite(buzzPin, HIGH); 
 // delay(dt); 
 // digitalWrite(buzzPin, LOW);
//}
}
