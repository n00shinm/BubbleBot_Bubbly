/*
 * Project 1: Feedback & Control
 * Project name: Bubble Bot, aka Bubbly
 * By Prayag Ichangimath & Nooshin Mohtashami
 * DIGF-6041-001 - Experiences & Interfaces
 * OCAD University
 * Created on Feb 17, 2022
 * 
*/



#define echoPin3 2 //front ultrasonic sensor
#define trigPin3 3
#define echoPin1 4 //right ultrasonic sensor
#define trigPin1 5
#define echoPin2 6 //left ultrasonic sensor
#define trigPin2 7
#define echoPin4 8 //back ultrasonic sensor
#define trigPin4 9

#define threshold 10 // threshold in cm (common for all)

#define motor_P 13 //combined motor terminals to send signals to H-bridge
#define motor_N 12

// variables to store calc distance from ultrasonic sensors
long duration1;
int distance1;
long duration2;
int distance2;
long duration3;
int distance3;
long duration4;
int distance4;

int state = 0; //to limit left, right and back sensor reading while turning 


void turnLeft() //turn bubbly left
{
  digitalWrite(motor_P, HIGH);
  digitalWrite(motor_N, LOW);
  Serial.println("in the loop");
}

void turnRight() //turn bubbly right
{
  digitalWrite(motor_P, LOW);
  digitalWrite(motor_N, HIGH);
  Serial.println("in the loop");
}
void stopMotors() //stop all motors
{
  digitalWrite(motor_P, LOW);
  digitalWrite(motor_N, LOW);
  Serial.println("in the loop");
}
void blowBubbles() // blow bubble for 5 seconds
{
  digitalWrite(11, HIGH);
  delay(5000);
}
void stopBubbles() //stop blowing bubbles
{
  digitalWrite(11, LOW);
}

void setup() {
  //initializations
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);

  pinMode(motor_P, OUTPUT);
  pinMode(motor_N, OUTPUT);

  pinMode(11, OUTPUT);

  Serial.begin(9600);
}


void loop() {
  stopBubbles();
  stopMotors();

  //get right sensor reading
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2;

  //get left sensor reading
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2;

  //get front sensor reading
  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin4, LOW);
  duration4 = pulseIn(echoPin4, HIGH);
  distance4 = duration4 * 0.034 / 2;

  if (distance2 < threshold) //start turning towards left
  {
    Serial.println("TURN LEFT");
    state = 1;
    while (state == 1)
    {
      Serial.println("turning left");

      turnLeft();

      digitalWrite(trigPin3, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin3, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin3, LOW);
      duration3 = pulseIn(echoPin3, HIGH);
      distance3 = duration3 * 0.034 / 2;
      if (distance3 < threshold) // stop turning left when front sensor detects the object
      {
        state = 0;
        stopMotors();
        Serial.println("blowing");
        blowBubbles();
        stopBubbles();
      }
    }
  }

  if (distance1 < threshold) //start turning towards right
  {
    Serial.println("TURN RIGHT");
    state = 1;
    while (state == 1)
    {
      Serial.println("turning right");

      turnRight();

      digitalWrite(trigPin3, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin3, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin3, LOW);
      duration3 = pulseIn(echoPin3, HIGH);
      distance3 = duration3 * 0.034 / 2;
      if (distance3 < threshold) // stop turning right when front sensor detects the object
      {
        state = 0;
        stopMotors();
        Serial.println("blowing");
        blowBubbles();
        stopBubbles();
      }
    }
  }
  if (distance4 < threshold)  //start turning towards left
  {
    Serial.println("TURN LEFT");
    state = 1;
    while (state == 1)
    {
      Serial.println("turning left");

      turnLeft();

      digitalWrite(trigPin3, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin3, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin3, LOW);
      duration3 = pulseIn(echoPin3, HIGH);
      distance3 = duration3 * 0.034 / 2;
      if (distance3 < threshold) // stop turning left when front sensor detects the object
      {
        state = 0;
        stopMotors();
        Serial.println("blowing");
        blowBubbles();
        stopBubbles();
      }
    }
  }
}
