/*
Julkifli Awang Besar
TB6612FNG
Motordriver test
 */ 



//Motor A
int PWMA = 5; //Speed control
int AIN1 = 9; //Direction
int AIN2 = 4; //Direction

//Motor B
int PWMB = 6; //Speed control
int BIN1 = 8; //Direction
int BIN2 = 7; //Direction





void setup(){
//pinMode(STBY, OUTPUT);

pinMode(PWMA, OUTPUT);
pinMode(AIN1, OUTPUT);
pinMode(AIN2, OUTPUT);

pinMode(PWMB, OUTPUT);
pinMode(BIN1, OUTPUT);
pinMode(BIN2, OUTPUT);

delay(2000);

}

void loop(){

digitalWrite(BIN1, HIGH);
digitalWrite(BIN2, LOW);
analogWrite(PWMB, 100);

digitalWrite(AIN1, LOW);
digitalWrite(AIN2, HIGH);
analogWrite(PWMA, 100);


}


