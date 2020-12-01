//TB6612FNG function
//for MiCROBOT
/*
Julkifli Awang Besar
TB6612FNG test for Microbot 9.2
Motordriver test with function and buton/led
 */


#define pwm_L  5   //PWM LEFT MOTOR
#define left1  4   //LEFT1 MOTOR
#define left2  9   //LEFT2 MOTOR

#define pwm_R  6  //PWM RIGHT MOTOR
#define right1  8   //RIGHT1 MOTOR
#define right2  7   //RIGHT2 MOTOR

const int buzzerPin = 10;
const int pin_switch = 12;
const int pin_LED1 =  A1;      // LED 1 pin
const int pin_LED2 =  A0;       // LED 2 pin

boolean oldSwitchState = LOW;
boolean newSwitchState = LOW;
boolean LEDstatus = LOW;

void setup() {

pinMode(pin_switch, INPUT);

pinMode(pin_LED1, OUTPUT);
pinMode(pin_LED2, OUTPUT);
pinMode(buzzerPin,OUTPUT);

digitalWrite(pin_LED1,LOW);
digitalWrite(pin_LED2,LOW);

TCCR2B = TCCR2B & B11111000 | B00000011;
//set timer 2 divisor to    32 for PWM frequency of   980.39 Hz


pinMode(left1,OUTPUT);
pinMode(left2,OUTPUT);
pinMode(right1,OUTPUT);
pinMode(right2,OUTPUT);

Serial.begin(9600);


}




void loop()
{
    newSwitchState = digitalRead(pin_switch);


    if ( newSwitchState != oldSwitchState )
    {
       // has the button switch been closed?
       if ( newSwitchState == HIGH )
       {
           if ( LEDstatus == LOW ) {
            motor(100,100);
            digitalWrite(pin_LED1, HIGH);
            digitalWrite(pin_LED2, HIGH);
            LEDstatus = HIGH; }
          else{
            motor(0,0);
            digitalWrite(pin_LED1, LOW);
            digitalWrite(pin_LED2, LOW);
            LEDstatus = LOW;  }
       }
       oldSwitchState = newSwitchState;
    }
}


void motor(int left, int right){   //0 until 255    0 until -255
  ////////////////motor LEFT  ////////////////////////
  if(left >= 0){
    digitalWrite(left1,HIGH);
    digitalWrite(left2,LOW);
  }else{
    digitalWrite(left1,LOW);
    digitalWrite(left2,HIGH);
    left=left*(-1);
  }
  analogWrite(pwm_L,left);

  ////////////////motor RIGHT  ////////////////////////
  if(right >= 0){
    digitalWrite(right1,HIGH);
    digitalWrite(right2,LOW);
  }else{
    digitalWrite(right1,LOW);
    digitalWrite(right2,HIGH);
    right=right*(-1);
  }
  analogWrite(pwm_R,right);

}
