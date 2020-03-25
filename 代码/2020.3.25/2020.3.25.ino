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

//**********串口输出**********
//    Serial.print(before);
//    Serial.print("\t");


//*****************************遥控控制*******************************//
    if(( before == 1 ) && (rear ==1 ) && (left == 1 ) && (right == 1 ))
    {
        can.speedwheel(0, 0, 1);    //转向电机
        can.speedwheel(0, 0, 2);//前左轮
        can.speedwheel(0, 0, 3);//前右轮
        Serial.println("原地站立");
    }
    
    if(( before == 0 ) && (rear ==1 ) && (left == 1 ) && (right == 1 ))
    {
        can.speedwheel(0, 0, 1);    //转向电机
        can.speedwheel(1000, 0, 2);//前左轮
        can.speedwheel(1000, 0, 3);//前右轮
        Serial.println("向前走");
    }

     if(( before == 1 ) && (rear ==0 ) && (left == 1 ) && (right == 1 ))
    {
        can.speedwheel(0, 0, 1);    //转向电机
        can.speedwheel(-1000, 0, 2);//前左轮
        can.speedwheel(-1000, 0, 3);//前右轮
        Serial.println("向后走");
    }

     if(( before == 1 ) && (rear ==1 ) && (left == 0 ) && (right == 1 ))
    {
        can.speedwheel(0, 0, 1);    //转向电机
        can.speedwheel(0, 0, 2);//前左轮
        can.speedwheel(0, 0, 3);//前右轮
        Serial.println("单按左控制键原地不动");
    }
    
     if(( before == 1 ) && (rear ==1 ) && (left == 1 ) && (right == 0 ))
    {
        can.speedwheel(0, 0, 1);    //转向电机
        can.speedwheel(0, 0, 2);//前左轮
        can.speedwheel(0, 0, 3);//前右轮
        Serial.println("单按右控制键原地不动");
    }

    if(( before == 0 ) && (rear ==1 ) && (left == 0 ) && (right == 1 ))
    {
        can.speedwheel(500, 0, 1);    //转向电机
//方向盘打死的问题？
        can.speedwheel(1000, 0, 2);//前左轮
        can.speedwheel(1000, 0, 3);//前右轮
        Serial.println("向左前方移动");
    }

    
    if(( before == 0 ) && (rear ==1 ) && (left == 1 ) && (right == 0 ))
    {
        can.speedwheel(-500, 0, 1);    //转向电机
//方向盘打死的问题？
        can.speedwheel(1000, 0, 2);//前左轮
        can.speedwheel(1000, 0, 3);//前右轮
        Serial.println("向左前方移动");
    }

    if(( before == 1 ) && (rear ==0 ) && (left == 0 ) && (right == 1 ))
    {
        can.speedwheel(500, 0, 1);    //转向电机
//方向盘打死的问题？
        can.speedwheel(-1000, 0, 2);//前左轮
        can.speedwheel(-1000, 0, 3);//前右轮
        Serial.println("向左后方移动");
    }

    if(( before == 1 ) && (rear ==0 ) && (left == 1 ) && (right == 0 ))
    {
        can.speedwheel(-500, 0, 1);    //转向电机
//方向盘打死的问题？
        can.speedwheel(-1000, 0, 2);//前左轮
        can.speedwheel(-1000, 0, 3);//前右轮
        Serial.println("向右后方移动");
    }

    if(( before == 0 ) && (rear ==0 ) && (left == 1 ) && (right == 1 ))
    {
        can.speedwheel(0, 0, 1);//转向电机
        can.speedwheel(0, 0, 2);//前左轮
        can.speedwheel(0, 0, 3);//前右轮
        Serial.println("操作有误");
    }

     if(( before == 1 ) && (rear ==1 ) && (left == 0 ) && (right == 0 ))
    {
        can.speedwheel(0, 0, 1);//转向电机
        can.speedwheel(0, 0, 2);//前左轮
        can.speedwheel(0, 0, 3);//前右轮
        Serial.println("操作有误");
    }

    if(( before == 0 ) && (rear ==1 ) && (left == 0 ) && (right == 0 ))
    {
        can.speedwheel(0, 0, 1);//转向电机
        can.speedwheel(0, 0, 2);//前左轮
        can.speedwheel(0, 0, 3);//前右轮
        Serial.println("操作有误");
    }

    if(( before == 0 ) && (rear ==0 ) && (left == 1 ) && (right == 0 ))
    {
        can.speedwheel(0, 0, 1);//转向电机
        can.speedwheel(0, 0, 2);//前左轮
        can.speedwheel(0, 0, 3);//前右轮
        Serial.println("操作有误");
    }

    if(( before == 1 ) && (rear ==0 ) && (left == 0 ) && (right == 0 ))
    {
        can.speedwheel(0, 0, 1);//转向电机
        can.speedwheel(0, 0, 2);//前左轮
        can.speedwheel(0, 0, 3);//前右轮
        Serial.println("操作有误");
    }

    if(( before == 0 ) && (rear ==0 ) && (left == 0 ) && (right == 1 ))
    {
        can.speedwheel(0, 0, 1);//转向电机
        can.speedwheel(0, 0, 2);//前左轮
        can.speedwheel(0, 0, 3);//前右轮
        Serial.println("操作有误");
    }

    if(( before == 0 ) && (rear ==0 ) && (left == 0 ) && (right == 0 ))
    {
        can.speedwheel(0, 0, 1);//转向电机
        can.speedwheel(0, 0, 2);//前左轮
        can.speedwheel(0, 0, 3);//前右轮
        Serial.println("操作有误");
    }

    


    
}
