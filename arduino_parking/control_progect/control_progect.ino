#include <Servo.h>
#include <DFRobot_RGBLCD1602.h>
#include  <Wire.h>
DFRobot_RGBLCD1602 lcd(0x27,  16, 2);


Servo myservo_t;
Servo myservo_p1;
Servo myservo_p2;
int car_park =2; 



void setup() 
{
 pinMode(1, INPUT);
 pinMode(2, INPUT);
 pinMode(8, INPUT);
 pinMode(9, INPUT);
 pinMode(11, INPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(6, OUTPUT);
 pinMode(10, OUTPUT);
 pinMode(12, OUTPUT);
 myservo_t.attach(6);
 myservo_p1.attach(10);
 myservo_p2.attach(12);




 digitalWrite(3, 0);
 digitalWrite(4, 0);
 digitalWrite(5, 1);

 myservo_t.write(180);
 myservo_p1.write(0); 
 myservo_p2.write(0); 
 
  lcd.init();
  lcd.setCursor(4, 0);
  lcd.print("Welcome!");
  lcd.setCursor(1, 1);
  lcd.print( String(car_park)+" "+"empty places");

 delay(10);


}



void loop() 
{
  
 

//1

  if(digitalRead(1) == 0  )
  {
    digitalWrite(3, 1);
    digitalWrite(4, 0);
    digitalWrite(5, 0);

     myservo_t.write(0);                      
  }
   
   else if(digitalRead(2) == 0   )
  { 
    digitalWrite(3, 0);
    digitalWrite(4, 0);
    digitalWrite(5, 1); 

    myservo_t.write(180);                      


  }

//2

  


  
  if(digitalRead(8)==0 && car_park>0 )
  {
   myservo_p1.write(180);                      

  } 
  else if(digitalRead(9)==0 && car_park>=1 )
  {
   myservo_p1.write(0);
   car_park =car_park-1;
   if(car_park==1)
   {
     empty();
   }
   else if(car_park==0)
   {
     busy();
   }
   delay(1000);                  

  }
  

  if(digitalRead(11)==0)
  {

   myservo_p2.write(180);
   car_park=car_park+1;
   empty();
   delay(1000);
   myservo_p2.write(0);
 
  } 

}



void empty()
{
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Welcome!");

  lcd.setCursor(1, 1);
  lcd.print(String(car_park)+" "+"empty places");

  

}
void busy()
{
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("Sorry!");
  
  lcd.setCursor(1, 1);
  lcd.print( "Parking is busy");
}





