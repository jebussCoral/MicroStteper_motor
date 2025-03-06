Stepper Motor Control
This program is designed to control a stepper motor using a 4-pin driver. It uses the basic stepper motor sequence to move the motor forward or backward in small steps. Below is an explanation of the key features and functions:

#### Pin Definitions
```
#define in_A_1 2
#define in_A_2 4
#define in_B_1 3
#define in_B_2 5
```
These define the pins on the microcontroller where the two coils (A and B) of the stepper motor are connected.


```
int currentStep = 0;
```
currentStep keeps track of the current position of the motor in terms of steps.

#### setup()
```
void setup() {
    pinMode(in_A_1, OUTPUT);
    pinMode(in_A_2, OUTPUT);
    pinMode(in_B_1, OUTPUT);
    pinMode(in_B_2, OUTPUT);
}
```
This function initializes the motor control pins as outputs.

#### Step Functions: step1(), step2(), step3(), step4().
Each of these functions represents a specific step of the motor’s rotation. By activating the appropriate pins, the motor is moved one step at a time.
```
void step1(){
    //A+,B+
    digitalWrite(in_A_1, 1);
    digitalWrite(in_A_2, 0);
    digitalWrite(in_B_1, 1);
    digitalWrite(in_B_2, 0);
    delay(time_delay);
}

void step2(){
    //A+,B-
    digitalWrite(in_A_1, 1);
    digitalWrite(in_A_2, 0);
    digitalWrite(in_B_1, 0);
    digitalWrite(in_B_2, 1);
    delay(time_delay);
}

void step3(){
    //A-,B-
    digitalWrite(in_A_1, 0);
    digitalWrite(in_A_2, 1);
    digitalWrite(in_B_1, 0);
    digitalWrite(in_B_2, 1);
    delay(time_delay);
}

void step4(){
    //A-,B+
    digitalWrite(in_A_1, 0);
    digitalWrite(in_A_2, 1);
    digitalWrite(in_B_1, 1);
    digitalWrite(in_B_2, 0);
    delay(time_delay);
}
```
tickClock() and counter_tickClock()
These functions are used to rotate the motor forward (tickClock()) or backward (counter_tickClock()) by one step. The currentStep variable is incremented or decremented, and the corresponding step function is called based on its value.
```
void tickClock(){
  currentStep++;
  if( currentStep >= 4 ){
    currentStep = 0;
  }
  int cycle = currentStep % 4;
  if( cycle == 0 ){
    step1();
  } else if( cycle == 1 ){
    step2();
  } else if( cycle == 2 ){
    step3();
  } else if( cycle == 3 ){
    step4();
  }
}

void counter_tickClock(){
  currentStep--;
  if( currentStep < 0 ){
    currentStep = 3;
  }
  int cycle = currentStep % 4;
  if( cycle == 0 ){
    step1();
  } else if( cycle == 1 ){
    step2();
  } else if( cycle == 2 ){
    step3();
  } else if( cycle == 3 ){
    step4();
  }
}
```
clockwise() and counter_clockwise()
These functions rotate the motor a specified number of steps in a clockwise (clockwise()) or counterclockwise (counter_clockwise()) direction, calling the appropriate step functions in sequence.
```
void clockwise(long st){
  long i = 0;
  while( i < st ){
    //step1
    step1();
    //step2
    step2();
    //step3
    step3();
    //step4
    step4();
    i++;
  }
}

void counter_clockwise(long st){
  long i = 0;
  while( i < st ){
    //step1
    step1();
    //step4
    step4();
    //step3
    step3();
    //step2
    step2();
    i++;
  }
}
```

loop()
In the loop() function, the motor is continuously rotated backward by calling counter_tickClock(), moving the motor one step at a time in reverse.

```
void loop()
{
    //clockwise(18);//counter_clockwise(18);
    //tickClock();
    counter_tickClock();
}
```



