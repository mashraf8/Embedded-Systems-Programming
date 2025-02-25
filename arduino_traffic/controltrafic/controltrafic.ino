byte segValue[10][7] = 
{
   {0,0,0,0,0,0,1}, 
   {1,0,0,1,1,1,1}, 
   {0,0,1,0,0,1,0}, 
   {0,0,0,0,1,1,0}, 
   {1,0,0,1,1,0,0}, 
   {0,1,0,0,1,0,0}, 
   {0,1,0,0,0,0,0}, 
   {0,0,0,1,1,1,1}, 
   {0,0,0,0,0,0,0}, 
   {0,0,0,0,1,0,0}   
};

byte segPin[8]={1,2,3,4,5,6,7,0};  
byte digitPin[2] = {8,9}; 



void setup() 
{
  for(int i=0;i<10;i++)
  {
    pinMode(segPin[i], OUTPUT);
  }
  pinMode(digitPin[0], OUTPUT);
  pinMode(digitPin[1], OUTPUT); 
  digitalWrite(digitPin[0], LOW); 
  digitalWrite(digitPin[1], LOW);
 
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);

 


  digitalWrite(A0, 1);  
  digitalWrite(A1, 0);
  digitalWrite(A2, 0);  
  digitalWrite(A3, 0);
  digitalWrite(A4, 0);  
  digitalWrite(A5, 1);
  

   

  

}


bool x1 = true;
bool x2 =false;


void loop()
{
  
 
  for (int i = 15; i>=0; i-=1)
  {
    display_N(i);

    //1 seg
     if(i==0 && (digitalRead(10) == 0 && digitalRead(11) == 0 && digitalRead(12) == 0 && digitalRead(13) == 0 ))
     {
      if(digitalRead(A0)==1)
      {
         digitalWrite(A0, 0);  
         digitalWrite(A1, 0);
         digitalWrite(A2, 1);  
         digitalWrite(A3, digitalRead(A3));
         digitalWrite(A4, digitalRead(A4));  
         digitalWrite(A5,digitalRead(A5));

      }
      else if(digitalRead(A2)==1 )
      {
         digitalWrite(A0, 1);  
         digitalWrite(A1, 0);
         digitalWrite(A2, 0);  
         digitalWrite(A3, digitalRead(A3));
         digitalWrite(A4, digitalRead(A4));  
         digitalWrite(A5,digitalRead(A5));


      }
      if(digitalRead(A3)==1)
      {
         digitalWrite(A3, 0);  
         digitalWrite(A4, 0);
         digitalWrite(A5, 1);  
         digitalWrite(A0, digitalRead(A0));
         digitalWrite(A1, digitalRead(A1));  
         digitalWrite(A2,digitalRead(A2));

      }
      else if(digitalRead(A5)==1)
      {
        digitalWrite(A3, 1);  
         digitalWrite(A4, 0);
         digitalWrite(A5, 0);  
         digitalWrite(A0, digitalRead(A0));
         digitalWrite(A1, digitalRead(A1));  
         digitalWrite(A2,digitalRead(A2));

      }

    
      if(digitalRead(A1)==1 && digitalRead(A4)==1 && x1 == true)
     {
         digitalWrite(A0, 0);  
         digitalWrite(A1, 0);
         digitalWrite(A2, 1);  
         digitalWrite(A3, 1);
         digitalWrite(A4, 0);  
         digitalWrite(A5,0);
     }
     else if(digitalRead(A1)==1 && digitalRead(A4)==1 && x1 == false)
     {
         digitalWrite(A0, 1);  
         digitalWrite(A1, 0);
         digitalWrite(A2, 0);  
         digitalWrite(A3, 0);
         digitalWrite(A4, 0);  
         digitalWrite(A5,1);
     }

    }

    //2seg
    else if(i==0 && (digitalRead(10) == 0 && digitalRead(11) == 0))
    {
         digitalWrite(A0, 0);  
         digitalWrite(A1, 0);
         digitalWrite(A2, 1);  
         digitalWrite(A3,1);
         digitalWrite(A4,0);  
         digitalWrite(A5,0);

       

    }


     else if(i==0 && (digitalRead(12) == 0 && digitalRead(13) == 0))
    {
         digitalWrite(A0, 1);  
         digitalWrite(A1, 0);
         digitalWrite(A2, 0);  
         digitalWrite(A3,0);
         digitalWrite(A4,0);  
         digitalWrite(A5,1);
    }
    
    //3seg
    else if (i==0)
    {
      if(digitalRead(A0)==1)
      {
         digitalWrite(A0, 0);  
         digitalWrite(A1, 1);
         digitalWrite(A2, 0);  
         digitalWrite(A3, digitalRead(A3));
         digitalWrite(A4, digitalRead(A4));  
         digitalWrite(A5,digitalRead(A5));

         x1 = true;
      }
      else if(digitalRead(A1)==1 && x1 == true)
      {
        digitalWrite(A0, 0);  
         digitalWrite(A1, 0);
         digitalWrite(A2, 1);  
         digitalWrite(A3, digitalRead(A3));
         digitalWrite(A4, digitalRead(A4));  
         digitalWrite(A5,digitalRead(A5));

      }
      else if(digitalRead(A1)==1 && x1 == false)
      {
        digitalWrite(A0, 1);  
         digitalWrite(A1, 0);
         digitalWrite(A2, 0);  
         digitalWrite(A3, digitalRead(A3));
         digitalWrite(A4, digitalRead(A4));  
         digitalWrite(A5,digitalRead(A5));

      }
      else if(digitalRead(A2)==1)
      {
         digitalWrite(A0, 0);  
         digitalWrite(A1, 1);
         digitalWrite(A2, 0);  
         digitalWrite(A3, digitalRead(A3));
         digitalWrite(A4, digitalRead(A4));  
         digitalWrite(A5,digitalRead(A5));

         x1=false;
      }



    if(digitalRead(A3)==1)
      {
         digitalWrite(A3, 0);  
         digitalWrite(A4, 1);
         digitalWrite(A5, 0);  
         digitalWrite(A0, digitalRead(A0));
         digitalWrite(A1, digitalRead(A1));  
         digitalWrite(A2,digitalRead(A2));

         x2 = true;
      }
      else if(digitalRead(A4)==1 && x2 == true)
      {
        digitalWrite(A3, 0);  
         digitalWrite(A4, 0);
         digitalWrite(A5, 1);  
         digitalWrite(A0, digitalRead(A0));
         digitalWrite(A1, digitalRead(A1));  
         digitalWrite(A2,digitalRead(A2));

      }
      else if(digitalRead(A4)==1 && x2 == false)
      {
        digitalWrite(A3, 1);  
         digitalWrite(A4, 0);
         digitalWrite(A5, 0);  
         digitalWrite(A0, digitalRead(A0));
         digitalWrite(A1, digitalRead(A1));  
         digitalWrite(A2,digitalRead(A2));

      }
      else if(digitalRead(A5)==1)
      {
         digitalWrite(A3, 0);  
         digitalWrite(A4, 1);
         digitalWrite(A5, 0);  
         digitalWrite(A0, digitalRead(A0));
         digitalWrite(A1, digitalRead(A1));  
         digitalWrite(A2,digitalRead(A2));

         x2=false;
      }
    }

   
    delay(1);
    
  }
}



void display_N(int num)
{
  int und = num % 10;
  int dec = (num % 100) / 10;
  for(int i=15; i>0; i-=1)
  {
    segOutput(1, und, 1);
    segOutput(0, dec, 1);
    delay(2); 
  }
  
  Serial.print(dec);
  Serial.println(und);
}
 
void segClear()
{ 
  for(int i=0;i<8;i++)
  {
    digitalWrite(segPin[i], HIGH);        
  }
}

void segOutput(int d, int Number, int dp)
{ 
  segClear();
  digitalWrite(digitPin[d], HIGH);
  for(int i=0;i<7;i++)
  {
     digitalWrite(segPin[i], segValue[Number][i]);                
  }
  digitalWrite(segPin[7], dp);
  delayMicroseconds(1000);
  digitalWrite(digitPin[d], LOW); 
}

