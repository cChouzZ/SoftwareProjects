// For hardware RGB LED 
// Far right is red 
// Far left is blue 
// Next to blue is green 

int redPin = 8;
int bluePin = 10;
int greenPin = 9;
String  myColor; 
String msg = "What Color Do You Want?"; 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); // Turns on the Serial Monitor 
pinMode(redPin, OUTPUT);
pinMode(bluePin, OUTPUT);  
pinMode(greenPin, OUTPUT);    
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  
while (Serial.available()==0) { 
  
}

myColor = Serial.readString();

if (myColor == "red") { 
  digitalWrite(redPin,HIGH);
  digitalWrite(bluePin,LOW);
  digitalWrite(greenPin,LOW); 
} 

if (myColor == "blue") { 
  digitalWrite(redPin,LOW);
  digitalWrite(bluePin,HIGH);
  digitalWrite(greenPin,LOW);
} 

if (myColor == "green") { 
  digitalWrite(redPin,LOW);
  digitalWrite(bluePin,LOW);
  digitalWrite(greenPin, HIGH);

} 

if (myColor == "cyan") { 
  digitalWrite(redPin,LOW);
  digitalWrite(bluePin,255);
  digitalWrite(greenPin, 255);

} 

if (myColor == "yellow") { 
  digitalWrite(redPin,255);
  digitalWrite(bluePin,LOW);
  digitalWrite(greenPin, 255);

} 

if (myColor == "violet") { 
  digitalWrite(redPin,255);
  digitalWrite(bluePin,255);
  digitalWrite(greenPin, LOW);

} 

 if (myColor == "off") { 
  digitalWrite(redPin,LOW);
 digitalWrite(bluePin,LOW);
  digitalWrite(greenPin,LOW);
}

}
