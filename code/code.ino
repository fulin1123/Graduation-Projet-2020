#include"robomodule_due_CAN.h"
CRobomodule_due_CAN can;

//  遥控控制定义
int control1  =  2;  
int control2  =  3; 
int control3  =  4; 
int control4  =  5; 

int before = 0;
int rear   = 0;
int left   = 0;
int right  = 0;


void setup() 
{
  can.initdriver(CAN_BPS_1000K, 0, 0, 1);//模式选择
  Serial.begin(9600);

  pinMode(control1,INPUT);
  pinMode(control2,INPUT);
  pinMode(control3,INPUT);
  pinMode(control4,INPUT);
  
  //remote control

}
void loop() 
{
  
      before = digitalRead(control1);
      rear   = digitalRead(control2);
      left   = digitalRead(control3);
      right  = digitalRead(control4);

}
