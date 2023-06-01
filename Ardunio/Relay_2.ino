
int IN1 = 8;
int IN1State1 = 0;
int buttonPin1 = 12; 
int buttonNew1;
int buttonOld1 = 1; 
int delta = 50;

int IN2 = 10;
int IN2State2 = 0; 
int buttonPin2 = 11; 
int buttonNew2;
int buttonOld2 = 1;

int IN3 = 9;
int IN3State3 = 0; 
int buttonPin3 = 13; 
int buttonNew3;
int buttonOld3 = 1; 

int IN4 = 6;
int IN4State4 = 0; 
int buttonPin4 = 7; 
int buttonNew4;
int buttonOld4 = 1; 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
pinMode(buttonPin1, INPUT); 
pinMode(IN1, OUTPUT); 

pinMode(buttonPin1, INPUT); 
pinMode(IN2, OUTPUT);

pinMode(buttonPin2, INPUT); 
pinMode(IN3, OUTPUT); 

pinMode(buttonPin3, INPUT); 
pinMode(IN4, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
buttonNew1 = digitalRead(buttonPin1);
if(buttonOld1 == 0 && buttonNew1 == 1) { 
  if(IN1State1 == 0) { 
    digitalWrite(IN1, HIGH); 
    IN1State1 = 1;
  }
  else { 
    digitalWrite(IN1, LOW); 
    IN1State1 = 0; 
  }
} 
buttonOld1 = buttonNew1; 
delay(delta); 

buttonNew2 = digitalRead(buttonPin2);
if(buttonOld2 == 0 && buttonNew2 == 1) { 
  if(IN2State2 == 0) { 
    digitalWrite(IN2, HIGH); 
    IN2State2 = 1;
  }
  else { 
    digitalWrite(IN2, LOW); 
    IN2State2 = 0; 
  }
} 
buttonOld2 = buttonNew2; 
delay(delta); 

buttonNew3 = digitalRead(buttonPin3);
if(buttonOld3 == 0 && buttonNew3 == 1) { 
  if(IN3State3 == 0) { 
    digitalWrite(IN3, HIGH); 
    IN3State3 = 1;
  }
  else { 
    digitalWrite(IN3, LOW); 
    IN3State3 = 0; 
  }
} 
buttonOld3 = buttonNew3; 
delay(delta); 

buttonNew4 = digitalRead(buttonPin4);
if(buttonOld4 == 0 && buttonNew4 == 1) { 
  if(IN4State4 == 0) { 
    digitalWrite(IN4, HIGH); 
    IN4State4 = 1;
  }
  else { 
    digitalWrite(IN4, LOW); 
    IN4State4 = 0; 
  }
} 
buttonOld4 = buttonNew4; 
delay(delta); 
}
