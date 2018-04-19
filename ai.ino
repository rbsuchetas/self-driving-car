#define echoPin 4 // Echo Pin
#define trigPin 5 //trig
#define Pin 9
#define Pin 10
#define Pin 6
#define Pin 7

int maximumRange = 70; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

int forward = 9; // forward pin
int right = 6; // front pin
int reverse = 10; // reverse pin
int left = 7; // back pin


void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(forward, OUTPUT);
 pinMode(right, OUTPUT);
 pinMode(reverse, OUTPUT);
 pinMode(left, OUTPUT);
}

void go_forward()
{
digitalWrite(forward,HIGH); // turn forward motor on
digitalWrite(right,LOW); // turn front motor on
digitalWrite(reverse,LOW); // turn reverse motor off
digitalWrite(left,LOW);
// turn back motor off
Serial.println("forward");

}
void go_rvrs()
{
digitalWrite(forward,LOW); // turn forward motor off
digitalWrite(right,LOW); // turn front motor off
digitalWrite(reverse,HIGH); // turn reverse motor on
digitalWrite(left,LOW); // turn back motor on
Serial.println("reverse");
}

void stop_car()
{
digitalWrite(reverse,LOW); // turn reverse motor off
digitalWrite(forward,LOW); // turn forward motor off
digitalWrite(right,LOW);
digitalWrite(left,LOW);
Serial.println("stop");
}
void go_right()
{
digitalWrite(forward,HIGH); // turn forward motor on
digitalWrite(right,HIGH); // turn back motor on
digitalWrite(reverse,LOW); // turn reverse motor off
digitalWrite(left,LOW); // turn front motor off
Serial.println("right");
}
void go_left()
{
digitalWrite(forward,HIGH); // turn forward motor on
digitalWrite(right,LOW); //   turn back motor on
digitalWrite(reverse,LOW); // turn reverse motor off
digitalWrite(left,HIGH); // turn front motor off
Serial.println("left");
}
void go_revright()
{
digitalWrite(forward,LOW); // turn forward motor on
digitalWrite(right,HIGH); // turn back motor on
digitalWrite(reverse,HIGH); // turn reverse motor off
digitalWrite(left,LOW); // turn front motor off
Serial.println("left");
}
void go_revleft()
{
digitalWrite(forward,LOW); // turn forward motor on
digitalWrite(right,LOW); // turn back motor on
digitalWrite(reverse,HIGH); // turn reverse motor off
digitalWrite(left,HIGH); // turn front motor off
Serial.println("left");
}
// the loop() method runs over and over again,
// as long as the Arduino has power





void loop() {
/*
The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it.
*/
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);

 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);

 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;



if (distance > maximumRange || distance < minimumRange){
 /* Send a positive number to computer and Turn MOTORS ON
 to indicate "out of range" */
 Serial.println("1");
 go_forward();


}else {
  //stop_car();
  //delay(50);

  go_rvrs();
  go_right();


}

 //}
 //Delay 50ms before next reading.
 delay(50);
}
