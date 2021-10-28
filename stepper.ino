//Barbu Angelo-Gabriel (angelo.barbu123@gmail.com)

#define BUTTON_PIN_1 7

#define STEPPER_PIN_1 9
#define STEPPER_PIN_2 10
#define STEPPER_PIN_3 11
#define STEPPER_PIN_4 12

bool oldDirection = true;
bool buttonState_1 = true;
int stepNumber = 0;

//function for one step
//signal sent to each stepper pin
void one_step (bool direction) {
  if (direction) {
    //going forward from S_PIN_1 to S_PIN_4
    switch (stepNumber) {
      case 0:
      digitalWrite(STEPPER_PIN_1, HIGH);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, LOW);
      break;
      case 1:
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, HIGH);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, LOW);
      break;
      case 2:
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, LOW); 
      digitalWrite(STEPPER_PIN_3, HIGH);
      digitalWrite(STEPPER_PIN_4, LOW);
      break;
      case 3:
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, HIGH);
      break;
    }
  } else {
    //going backwards from S_PIN_4 to S_PIN_1
    switch (stepNumber) {
      case 0:
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, HIGH);
      break;
      case 1:
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, HIGH);
      digitalWrite(STEPPER_PIN_4, LOW);
      break;
      case 2:
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, HIGH);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, LOW);
      break;
      case 3:
      digitalWrite(STEPPER_PIN_1, HIGH);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, LOW);
      break;
    }
  }
  stepNumber++;
  //4 signals sequence
  if (stepNumber > 3)
    stepNumber = 0;
}

void setup() {
  pinMode(BUTTON_PIN_1, INPUT_PULLUP);
  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);
}

void loop() {
  
  buttonState_1 = digitalRead(BUTTON_PIN_1);
  if (buttonState_1 == LOW) {
    if (oldDirection) { //if pushed
      for (int i = 0; i < 1400; i++) {
        one_step(false); //goes forward for 1400 steps
        delay(2);
      }
      oldDirection = false; //changes next direction to backwards
    } else { //if pushed again
      for (int i = 0; i < 1400; i++) {
        one_step(true); //goes backwards for 1400 steps
        delay(2);
      }
      oldDirection = true; //changes next direction to forward
    }
  }
}
