#include"robomodule_due_CAN.h"
CRobomodule_due_CAN can;

//**遥控控制引脚定义**
int control1  =  2;  
int control2  =  3; 
int control3  =  4; 
int control4  =  5; 

int before = 0;
int rear   = 0;
int left   = 0;
int right  = 0;

 //**黄色红外引脚定义**
   int red1 = 7; //前左
   int red2 = 8; //前右
   int red3 = 9; //左前
   int red4 = 10; //左后
   int red5 = 11; //右前
   int red6 = 12; //右后
   int red7 = 13; //后左
   int red8 = 14; //后右

   int value1 = 0;
   int value2 = 0;
   int value3 = 0;
   int value4 = 0;
   int value5 = 0;
   int value6 = 0;
   int value7 = 0;
   int value8 = 0;

                    

//**红外距离传感器引脚定义**
float front1 =A1 ;   //前左
float front2 =A2 ;   //前中
float front3 =A3 ;   //前右
float left1 =A4  ;   //左前
float left2 =A5  ;   //左中
float left3 =A6  ;   //左后
float right1 =A7 ;   //右前
float right2 =A8 ;   //右中
float right3 =A9 ;   //右后
float black1 =A10;   //后左
float black2 =A11;   //后右

float XF1 =0;
float XF2 =0;
float XF3 =0;
float XL1 =0;
float XL2 =0;
float XL3 =0;
float XR1 =0;
float XR2 =0;
float XR3 =0;
float XB1 =0;
float XB2 =0;


void setup() 
{
  can.initdriver(CAN_BPS_1000K, 0, 0, 1);//模式选择
  Serial.begin(9600);

  
//******遥控控制********
  pinMode(control1,INPUT);
  pinMode(control2,INPUT);
  pinMode(control3,INPUT);
  pinMode(control4,INPUT);

 //*******黄色红外*********
    pinMode(red1,INPUT);
    pinMode(red2,INPUT);
    pinMode(red3,INPUT);
    pinMode(red4,INPUT);
    pinMode(red5,INPUT);
    pinMode(red6,INPUT);
    pinMode(red7,INPUT);
    pinMode(red8,INPUT);

                            
                          

//******红外距离传感器*****
  pinMode(front1,INPUT);
  pinMode(front2,INPUT);
  pinMode(front3,INPUT);
  pinMode(left1,INPUT);
  pinMode(left2,INPUT);
  pinMode(left3,INPUT);
  pinMode(right1,INPUT);
  pinMode(right2,INPUT);
  pinMode(right3,INPUT);
  pinMode(black1,INPUT);
  pinMode(black2,INPUT);

}

     float convert(float search) 
  {
        if (search < 70)  search = 70;
        return 12777.3/search-1.1;        
  }
void loop() 
{

                                    //*********黄色红外*********
                                      value1 = digitalRead(red1);
                                      value2 = digitalRead(red2);
                                      value3 = digitalRead(red3);
                                      value4 = digitalRead(red4);
                                      value5 = digitalRead(red5);
                                      value6 = digitalRead(red6);
                                      value7 = digitalRead(red7);
                                      value8 = digitalRead(red8);
                                      
   //********遥控控制名称********
      before = digitalRead(control1);
      rear   = digitalRead(control2);
      left   = digitalRead(control3);
      right  = digitalRead(control4);

//**********红外控制名称************
  XF1 = convert(analogRead (front1));    
  XF2 = convert(analogRead (front2));    
  XF3 = convert(analogRead (front3));    
  XL1 = convert(analogRead (left1));    
  XL2 = convert(analogRead (left2));    
  XL3 = convert(analogRead (left3));    
  XR1 = convert(analogRead (right1));
  XR2 = convert(analogRead (right2));
  XR3 = convert(analogRead (right3));   
  XB1 = convert(analogRead (black1));
  XB2 = convert(analogRead (black2));

//**********串口输出**********
//    Serial.print(before);
//    Serial.print("\t");


//***************************遥控控制系统*******************************//
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
