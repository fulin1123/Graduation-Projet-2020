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
float XR1 =0;
float XR2 =0;
float XB1 =0;
float XB2 =0;


//****超声波传感器引脚定义*******
int sound1 = 20;
int sound2 = 21;
int sound3 = 22;
int sound4 = 24;
int sound5 = 25;
int sound6 = 26;
int sound7 = 27;
int sound8 = 28;

int voice1 = 0;
int voice2 = 0;
int voice3 = 0;
int voice4 = 0;
int voice5 = 0;
int voice6 = 0;
int voice7 = 0;
int voice8 = 0;



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
  pinMode(right1,INPUT);
  pinMode(right2,INPUT);
  pinMode(black1,INPUT);
  pinMode(black2,INPUT);

//*******超声波距离传感器*****

  pinMode(sound1,INPUT);
  pinMode(sound2,INPUT);
  pinMode(sound3,INPUT);
  pinMode(sound4,INPUT);
  pinMode(sound5,INPUT);
  pinMode(sound6,INPUT);
  pinMode(sound7,INPUT);
  pinMode(sound8,INPUT);
  
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
  XR1 = convert(analogRead (right1));
  XR2 = convert(analogRead (right2));  
  XB1 = convert(analogRead (black1));
  XB2 = convert(analogRead (black2));

//**********串口输出**********
//    Serial.print(before);
//    Serial.print("\t");


//********超声波控制名称*********

voice1 = convert(analogRead (sound1));
voice2 = convert(analogRead (sound2));
voice3 = convert(analogRead (sound3));
voice4 = convert(analogRead (sound4));
voice5 = convert(analogRead (sound5));
voice6 = convert(analogRead (sound6));
voice7 = convert(analogRead (sound7));
voice8 = convert(analogRead (sound8));
 


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

    

//**********************************************遥控控制and红外控制结合*********************************************



    
    if(( before == 0 ) && (rear ==1 ) && (left == 1 ) && (right == 1 ) && ( XF1 <= 35 || XF2 <=35 || XF3<=35 ) )
    {
        can.speedwheel(0, 0, 1);    //转向电机
        can.speedwheel(1000, 0, 2);//前左轮
        can.speedwheel(1000, 0, 3);//前右轮
        Serial.println("前方有物体 暂停行驶");
    }

     if(( before == 1 ) && (rear ==0 ) && (left == 1 ) && (right == 1 ) && ( XB1 <= 35 || XB2 <= 35 ) )
    {
        can.speedwheel(0, 0, 1);    //转向电机
        can.speedwheel(-1000, 0, 2);//前左轮
        can.speedwheel(-1000, 0, 3);//前右轮
        Serial.println("后方有物体 暂停倒车");
    }


    if(( before == 0 ) && (rear ==1 ) && (left == 0 ) && (right == 1 ) && ( ( XF1 >= 20 || XF2 >= 20 || XF3 >= 20 ) && ( XL1 >= 20 ) ) )
    {
        can.speedwheel(500, 0, 1);    //转向电机
//方向盘打死的问题？
        can.speedwheel(1000, 0, 2);//前左轮
        can.speedwheel(1000, 0, 3);//前右轮
        Serial.println("向左前方移动");
    }

    if(( before == 0 ) && (rear ==1 ) && (left == 0 ) && (right == 1 ) && ( XF1 <= 35 || XF2 <= 35 || XF3 <= 35 || XL1 <= 20 ) )
    {
        can.speedwheel(0, 0, 1);    //转向电机
//方向盘打死的问题？
        can.speedwheel(0, 0, 2);//前左轮
        can.speedwheel(0, 0, 3);//前右轮
        Serial.println("左方或前方有障碍物 无法继续前进");
    }

    
    if(( before == 0 ) && (rear ==1 ) && (left == 1 ) && (right == 0 ) && ( XF1 <= 35 || XF2 <= 35 || XF3 <= 35 || XR1 <= 20 ) )
    {
        can.speedwheel(0, 0, 1);    //转向电机
//方向盘打死的问题？
        can.speedwheel(0, 0, 2);//前左轮
        can.speedwheel(0, 0, 3);//前右轮
        Serial.println("右方或前方有障碍物 无法继续前进");
    }

    if(( before == 1 ) && (rear ==0 ) && (left == 0 ) && (right == 1 ) && ( ( XB1>=20 || XB2>=20 ) && ( XL2>=20 ) ) )
    {
        can.speedwheel(500, 0, 1);    //转向电机
//方向盘打死的问题？
        can.speedwheel(-1000, 0, 2);//前左轮
        can.speedwheel(-1000, 0, 3);//前右轮
        Serial.println("向左后方移动");
    }

    if(( before == 1 ) && ( rear ==0 ) && ( left == 0 ) && (right == 1 ) && ( XB1 <=35 || XB2 <=35 || XL2 <= 20 ) )
    {
        can.speedwheel(0, 0, 1);    //转向电机
//方向盘打死的问题？
        can.speedwheel(0, 0, 2);//前左轮
        can.speedwheel(0, 0, 3);//前右轮
        Serial.println("左方或后方有障碍物 无法倒车");
    }

    if(( before == 1 ) && ( rear ==0 ) && ( left == 1 ) && ( right == 0 ) && ( ( XB1>=20 || XB2>=20 ) && ( XR2>=20 ) ) )
    {
        can.speedwheel(-500, 0, 1);    //转向电机
//方向盘打死的问题？
        can.speedwheel(-1000, 0, 2);//前左轮
        can.speedwheel(-1000, 0, 3);//前右轮
        Serial.println("向右后方移动");
    }

    if(( before == 1 ) && ( rear ==0 ) && ( left == 1 ) && ( right == 0 ) && ( XB1 <=35 || XB2 <=35 || XR2 <= 20 ) )
    {
        can.speedwheel(0, 0, 1);    //转向电机
//方向盘打死的问题？
        can.speedwheel(0, 0, 2);//前左轮
        can.speedwheel(0, 0, 3);//前右轮
        Serial.println("右方或后方有障碍物 无法倒车");
    }

//*************************报警系统*********************



        if( value1 == 1 && value2 == 1 )    
    {
        can.speedwheel(5000, 0, 4);    
        Serial.println("报警");
    }
        if( value1 == 1 || value2 == 1 )    
    {
        can.speedwheel(5000, 0, 4);    
        Serial.println("报警");
    }


    
        if( value3 == 1 && value4 == 1 )    
    {
        can.speedwheel(5000, 0, 4);    
        Serial.println("报警");
    }
        if( value3 == 1 || value4 == 1 )    
    {
        can.speedwheel(5000, 0, 4);    
        Serial.println("报警");
    }



        if( value5 == 1 && value6 == 1 )    
    {
        can.speedwheel(5000, 0, 4);    
        Serial.println("报警");
    }
        if( value5 == 1 || value6 == 1 )    
    {
        can.speedwheel(5000, 0, 4);    
        Serial.println("报警");
    }



        if( value7 == 1 && value8 == 1 )    
    {
        can.speedwheel(5000, 0, 4);    
        Serial.println("报警");
    }
        if( value7 == 1 || value8 == 1 )    
    {
        can.speedwheel(5000, 0, 4);    
        Serial.println("报警");
    }


    if( value1 == 1 && value2 == 1 && value3 == 1 && value4 == 1 && value5 == 1 && value6 == 1 && value7 == 1 && value8 == 1)    
    {
        can.speedwheel(5000, 0, 4);    
        Serial.println("报警");
    }

    
    if( value1 == 1 || value2 == 1 || value3 == 1 || value4 == 1 || value5 == 1 || value6 == 1 || value7 == 1 || value8 == 1)    
    {
        can.speedwheel(5000, 0, 4);    
        Serial.println("报警");
    }

}
