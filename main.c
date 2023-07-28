#include <Servo.h>
#include <LiquidCrystal.h>

Servo myservo;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int pos = 0;
const int trigPin = 9;
const int echoPin = 10;
const int moteur = 11;
const int buzzer = 12;
const int ledPin1 = 14;
const int ledPin2 = 15;
float distanceCm, DistanceSec,duration;

void setup() {
myservo.attach(moteur);
lcd.begin(16,2);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
DistanceSec=20;

}

void loop() {
for (pos = 0; pos <= 180; pos += 1) {

myservo.write(pos);
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
if (distanceCm <= DistanceSec)
{

if(distanceCm <= DistanceSec/2)
{

tone(buzzer, 10);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, HIGH);
delay(700);
noTone(buzzer);
lcd.setCursor(0,0);
lcd.print("Distance: ");
lcd.print(distanceCm);
lcd.print(" cm ");
delay(10);
lcd.setCursor(0,1);
lcd.print("Angle : ");
lcd.print(pos);
lcd.print(" deg ");
delay(2000);
}
else
{
digitalWrite(buzzer, HIGH);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin1, HIGH);
delay(100);
digitalWrite(buzzer, LOW);
lcd.setCursor(0,0);
lcd.print("Distance: ");
lcd.print(distanceCm);
lcd.print(" cm ");
delay(10);
lcd.setCursor(0,1);
lcd.print("Angle : ");
lcd.print(pos);
lcd.print(" deg ");
delay(2000);
}
}
else{
digitalWrite(buzzer, LOW);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
}

lcd.setCursor(0,0);
lcd.print("Distance: ");
lcd.print(distanceCm);
lcd.print(" cm ");
delay(10);
lcd.setCursor(0,1);
lcd.print("Angle : ");
lcd.print(pos);
lcd.print(" deg ");
delay(80);

}
for (pos = 180; pos >= 0; pos -= 1) { //
myservo.write(pos); //
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
if (distanceCm <= DistanceSec){
if(distanceCm <= DistanceSec/2)
{
tone(buzzer, 10);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, HIGH);
delay(700);
noTone(buzzer);
lcd.setCursor(0,0);
lcd.print("Distance: ");
lcd.print(distanceCm);
lcd.print(" cm ");
delay(10);
lcd.setCursor(0,1);
lcd.print("Angle : ");
lcd.print(pos);
lcd.print(" deg ");
delay(2000);
}
else
{
digitalWrite(buzzer, HIGH);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin1, HIGH);
delay(100);
digitalWrite(buzzer, LOW);
lcd.setCursor(0,0);
lcd.print("Distance: ");
lcd.print(distanceCm);
lcd.print(" cm ");
delay(10);
lcd.setCursor(0,1);
lcd.print("Angle : ");
lcd.print(pos);
lcd.print(" deg ");
delay(2000);
}
}
else{
digitalWrite(buzzer, LOW);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
}

lcd.setCursor(0,0);
lcd.print("Distance: ");
lcd.print(distanceCm);
lcd.print(" cm ");
delay(10);
lcd.setCursor(0,1);
lcd.print("Angle : ");
lcd.print(pos);
lcd.print(" deg ");
delay(80);
}
}
