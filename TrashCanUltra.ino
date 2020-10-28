const int ultraPin = 6;
const int trigPin = 3; 
const int echoPin = 4;
float duration;
float distance;
void setup() {
 pinMode(trigPin, OUTPUT); 
 pinMode(echoPin, INPUT); 
 pinMode(ultraPin, OUTPUT); 
 Serial.begin(9600); 
 pinMode(5, OUTPUT);
}

void loop() {
 digitalWrite(9, LOW);
 digitalWrite(ultraPin, HIGH); 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH); 
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW); 
 duration = pulseIn(echoPin, HIGH); 
 distance = (duration*.0343)/2;
 if(distance<60)
 {
   digitalWrite(5, HIGH);
   delay(500);
   Serial.print("up: ");


 }
 else{
  digitalWrite(9, LOW);
  delay(500);
   Serial.print("down: ");

 }
 Serial.print("Distance: ");
 Serial.println(distance);
 delay(100);
}
