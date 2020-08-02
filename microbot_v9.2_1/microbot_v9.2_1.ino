/*
MiCROBOT V1

Julkifli Awang Besar
2nd C0d3
PID for R0b0tr4c3r

Suite with MiCROBOT PCB.
***RBTX2019****

*/
#include <QTRSensors.h>
#define BUTTON  12

#define NUM_SENSORS 5 
#define TIMEOUT 2500 
#define EMITTER_PIN QTR_NO_EMITTER_PIN 

#define PWMA 5 
#define AIN2 4
#define AIN1 9 

#define PWMB 6  
#define BIN2 8 
#define BIN1 7

//#define motorPower 9


#define A_BaseSpeed 80
#define B_BaseSpeed 80

int PRESS;
int motorSpeed;
int error;
int position;


QTRSensorsRC qtra((unsigned char[]) { A3, A4 ,A5 , A6,A7} , NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS]; 

void setup() { 
  Serial.begin(9600);

  pinMode(AIN2, OUTPUT); 
  pinMode(AIN1, OUTPUT); 
  pinMode(PWMA, OUTPUT);
   
  pinMode(BIN2, OUTPUT); 
  pinMode(BIN1, OUTPUT); 
  pinMode(PWMB, OUTPUT);

  pinMode(BUTTON,INPUT);

  
  int i; 
  for (int i = 0; i < 200; i++) 
    { 
    qtra.calibrate(); 
    digitalWrite(13, HIGH); delay(20); 
    
    } 
  
    //digitalWrite(motorPower, LOW);
    digitalWrite(13, LOW); 
    delay(2000); 
    
  } 
    
    
    int lastError = 0; 
    float Kp = 0.06; 
    float Kd = 4; 
    float Ki = 0.000; 
    int MotorA_Speed = 0; 
    int MotorB_Speed = 0; 
    int integral = 0;

    void loop() { 
           


      position = qtra.readLine(sensorValues); 
       
      
      //for white Line
      //unsigned int position = qtrrc.readLine(sensorValues, QTR_EMITTERS_ON, 1);
      
      error = position - 2000; 
 
      
      motorSpeed = Kp * error + Kd * (error - lastError)+ Ki * integral; 
      lastError = error;

      MotorA_Speed = A_BaseSpeed - motorSpeed ; 
      MotorB_Speed = B_BaseSpeed + motorSpeed ; 
      MotorA_Speed = constrain(MotorA_Speed, 0, 255); 
      MotorB_Speed = constrain(MotorB_Speed, 0, 255);


      digitalWrite(AIN2, HIGH); 
      digitalWrite(AIN1, LOW); 
      analogWrite(PWMA, MotorA_Speed);
       
      digitalWrite(BIN2, HIGH); 
      digitalWrite(BIN1, LOW); 
      analogWrite(PWMB, MotorB_Speed);
    

      
      
  } 
      
      
 //************************ BASE CODE***********\\﻿

//best kp=0.06,kd=4.00 180
//best kp=0.2,kd=4.00 180
//best kp=0.2,kd=5.00 180
//best kp=0.2,kd=4.00 220


