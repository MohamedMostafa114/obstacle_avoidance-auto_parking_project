#include<Servo.h>

Servo servo;

//ultrasonic
#define trigPin 4
#define echoPin 5

//servo
// #define servoPin 13


#define ENA 4
#define IN1 12
#define IN2 14
#define IN3 15
#define IN4 13
#define ENB 16


long duration, distanceCM, rightDistance, leftDistance;


void setup() {
  // put your setup code here, to run once:
  //start serial communication for debugging
  Serial.begin(9600);

  //initialize ultrasonic and servo pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN3, OUTPUT);
  // servo.attach(servoPin);

  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);

  //initialze servo angle to 0
  servo.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
  moveForward();
  detectObstacls();
  delay(1000);

}







long mesureDistance(){
  long cm;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);

  if(duration == 0){
    return 999;
  }
  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.println(" CM");
  return cm;
}

void detectObstacls(){
  //Read ultrasonic sensor data
  distanceCM = mesureDistance();
  //check if distance less than threshold
  if(distanceCM <= 10 && distanceCM != 0){
    //obstacle detected
    Serial.println("Obstacle detected in front of me");
    delay(500);
    //servo look right
    servo.write(0);
    delay(1000);
    rightDistance = mesureDistance();
    Serial.print("right Distance: ");
    Serial.println(rightDistance);
    //servo look left
    servo.write(180);
    delay(1000);

    leftDistance = mesureDistance();
    Serial.print("left Distance: ");
    Serial.println(leftDistance);

    //return to center
    servo.write(90);
    delay(500);

    //start decision
    if(rightDistance < leftDistance && leftDistance >=10){
      //go to the left
      Serial.println("Rotate left....");
      rotateLeft();
    }else if (leftDistance < rightDistance && rightDistance >=10){
      //go to the right
      Serial.println("Rotate Right....");
      rotateRight();
    }else{
      //go backword
      Serial.println("Return....");
    }
  }
}

void activateMotor(){
  //Logic
  /*
  if(switch == 1){
    detectObstacle();
    moveForward();
  }else{
    stopMotor();
  }
  */
}


//Motor movement
void moveForward(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void rotateRight(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void rotateLeft(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotor(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void goBack(){
  rotateRight();
  delay(1000);
}



long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
