#######################################################################
##                                                                   ##
##   Created by Jesus David Coral                                    ##
##   Version: 2.0_05_02_2025                                         ##
##                                                                   ##
##   Program to drive stepper motors, 2 coils from 3.3 to 5 V        ##
##   without driver                                                  ##
##                                                                   ##
##   https://github.com/jebussCoral/MicroStteper_motor               ##
##                                                                   ##
#######################################################################
#                                                                     #
# Modify pins according to motor coils- current conection to the Digitals pinds D2,D3, D4, D5
# Adjust the Time Delay to increase or decrease the engine speed

#define in_A_1 2
#define in_A_2 3
#define in_B_1 4
#define in_B_2 5

int currentStep = 0;

void setup()
{
    pinMode(in_A_1, OUTPUT);
    pinMode(in_A_2, OUTPUT);
    pinMode(in_B_1, OUTPUT);
    pinMode(in_B_2, OUTPUT);
}

unsigned int time_delay = 20;

void step1(){
    digitalWrite(in_A_1, 1);
    digitalWrite(in_A_2, 0);
    digitalWrite(in_B_1, 1);
    digitalWrite(in_B_2, 0);
    delay(time_delay);
}

void step2(){
    digitalWrite(in_A_1, 1);
    digitalWrite(in_A_2, 0);
    digitalWrite(in_B_1, 0);
    digitalWrite(in_B_2, 1);
    delay(time_delay);
}

void step3(){
    digitalWrite(in_A_1, 0);
    digitalWrite(in_A_2, 1);
    digitalWrite(in_B_1, 0);
    digitalWrite(in_B_2, 1);
    delay(time_delay);
}

void step4(){
    digitalWrite(in_A_1, 0);
    digitalWrite(in_A_2, 1);
    digitalWrite(in_B_1, 1);
    digitalWrite(in_B_2, 0);
    delay(time_delay);
}

void clockwise(long steps){
    for(long i = 0; i < steps; i++){
        step1();
        step2();
        step3();
        step4();
    }
}

void counter_clockwise(long steps){
    for(long i = 0; i < steps; i++){
        step1();
        step4();
        step3();
        step2();
    }
}

void loop()
{
    // Girar 6 vueltas en sentido horario ---- Turn 6 turns clockwise
    counter_clockwise(20);
    
    // Esperar 2 segundos ---- Wait 2 seconds
    delay(2000);

    // Girar otras 6 vueltas en sentido horario ---- Turn another 6 turns clockwise
    counter_clockwise(20);

    // Esperar 4 segundos ---- Wait 2 seconds
    delay(4000);

    // Retroceder 12 vueltas en sentido antihorario ---- Go back 12 turns counter-clockwise
    clockwise(40);

    // Detener el programa ---- Stop the program
    while(1);
}
