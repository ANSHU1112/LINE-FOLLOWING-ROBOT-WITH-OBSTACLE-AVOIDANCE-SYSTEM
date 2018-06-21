int trigPin = 5;
int echoPin = 4;
int LMotor1 = 11;
int LMotor2 = 12;
int RMotor1 = 9;
int RMotor2 = 10;

long durationL, distanceL;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LMotor1, OUTPUT);
  pinMode(LMotor2, OUTPUT);
  pinMode(RMotor1, OUTPUT);
  pinMode(RMotor2, OUTPUT);  
}

void loop() {
  digitalWrite(trigPin, LOW); //Left Ultrasonic
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  durationL = pulseIn(echoPin, HIGH);
  distanceL = (durationL/2) / 29.1;
  Serial.print("Left Distance:");
  Serial.print(distanceL);
  delay(2000);

if(distanceL > 12){
  forward();
  }
  if(distanceL <= 12){
    halt();
    delay(250);
    left();
  }
}

 void backward() { 
  digitalWrite(LMotor1, HIGH);
  digitalWrite(LMotor2, LOW);
  digitalWrite(RMotor1, HIGH);
  digitalWrite(RMotor2, LOW);
}

void forward() { 
  digitalWrite(LMotor1, LOW);
  digitalWrite(LMotor2, HIGH);
  digitalWrite(RMotor1, LOW);
  digitalWrite(RMotor2, HIGH);
}

void right(){ 
  digitalWrite(LMotor1, LOW);
  digitalWrite(LMotor2, HIGH);
  digitalWrite(RMotor1, HIGH);
  digitalWrite(RMotor2, LOW);
}

void left(){ // Turns Right
  digitalWrite(LMotor1, HIGH);
  digitalWrite(LMotor2, LOW);
  digitalWrite(RMotor1, LOW);
  digitalWrite(RMotor2, HIGH);
}

void halt(){ // Bot Stops
  digitalWrite(LMotor1, LOW);
  digitalWrite(LMotor2, LOW);
  digitalWrite(RMotor1, LOW);
  digitalWrite(RMotor2, LOW);
}
