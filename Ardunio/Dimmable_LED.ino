int pin = 3; 
int potVal;
int potPin = A3;
float LEDVal;  

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
pinMode(potPin, INPUT); 
pinMode(pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
potVal = analogRead(pin); 
LEDVal = (255./1023.)*potVal;
Serial.println(LEDVal); 
analogWrite(pin, LEDVal); 
}
