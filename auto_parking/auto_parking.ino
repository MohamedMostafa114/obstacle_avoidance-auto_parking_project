// === Motor Pins ===
#define ENA 13
#define IN1 12
#define IN2 14
#define ENB 27
#define IN3 26
#define IN4 25

// === Ultrasonic Pins ===
#define TRIG_FRONT 18
#define ECHO_FRONT 19
#define TRIG_RIGHT 33
#define ECHO_RIGHT 35
#define TRIG_BACK 23
#define ECHO_BACK 22

bool parkingStarted = false;
bool parked = false;

void setup() {
  // Motor setup
  pinMode(ENA, OUTPUT); 
  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT); 
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT);
  analogWrite(ENA, 180); 
  analogWrite(ENB, 150);

  // Ultrasonic setup
  pinMode(TRIG_FRONT, OUTPUT); 
  pinMode(ECHO_FRONT, INPUT);
  pinMode(TRIG_RIGHT, OUTPUT); 
  pinMode(ECHO_RIGHT, INPUT);
  pinMode(TRIG_BACK, OUTPUT); 
  pinMode(ECHO_BACK, INPUT);

  Serial.begin(115200);
  Serial.println("System Ready: Scanning for parking spot...");
}

void loop() {
  if (!parkingStarted && !parked) {
    int rightDistance = readDistance(TRIG_RIGHT, ECHO_RIGHT);

    if (rightDistance > 25) {
      Serial.println("Spot detected! Starting parking...");
      parkingStarted = true;
      stopMotors();
      delay(300);
      turnRight();
      delay(700);  // Adjust to align with spot
      stopMotors();
      delay(300);
    } else {
      moveForward();
    }
  }

  // Start entering the parking spot
  if (parkingStarted && !parked) {
    int front = readDistance(TRIG_FRONT, ECHO_FRONT);

    if (front > 10) {
      moveForward();  // Enter the spot straight
    } else {
      stopMotors();
      delay(300);
      turnLeft();
      delay(500);  // Adjust as needed to straighten car
      stopMotors();
      delay(500);

      // Now check if car is in good position
      int frontNow = readDistance(TRIG_FRONT, ECHO_FRONT);
      int backNow = readDistance(TRIG_BACK, ECHO_BACK);

      Serial.print("Front Distance: "); 
      Serial.println(frontNow);
      Serial.print("Back Distance: "); 
      Serial.println(backNow);

      if (frontNow >= 1 && frontNow <= 20 && backNow >= 1 && backNow <= 20) {
        Serial.println("Perfect parking position reached!");
        parked = true;
        stopMotors();
      } else {
        Serial.println("Not in correct range, adjusting...");
        // You can add more adjusting logic here if needed
      }
    }
  }

  delay(100);
}

// === Ultrasonic Distance Reader ===
int readDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH, 30000); // timeout = 30ms
  int distance = duration * 0.034 / 2;
  return distance;
}

// === Movement Functions ===
void moveForward() {
  digitalWrite(IN1, HIGH); 
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); 
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, HIGH);
}

void turnRight() {
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); 
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  digitalWrite(IN1, HIGH); 
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, LOW);
}
