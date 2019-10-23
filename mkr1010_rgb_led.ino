/**
 * author: mickael cherouise
 * date:  23/10/2019
 * Rainbow RGB Led
 */
 
#define rgbledRed 2
#define rgbledGreen 3
#define rgbledBlue 4
#define buttonPin 0

void setup() 
{
  pinMode(rgbledRed, OUTPUT);
  pinMode(rgbledGreen, OUTPUT);
  pinMode(rgbledBlue, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() 
{
  int buttonState = LOW;
  int i = 0;
  int j;
  bool step1 = false;
  bool step2 = true;
  bool step3 = true;
  bool step4 = true;
  bool step5 = true;
  bool step6 = true;
  while(true)
  {
    buttonState = digitalRead(buttonPin);

    if(buttonState == LOW)
    {
      while((i<256) && (step1 == false)) // 1st step
      {
        analogWrite(rgbledRed, 255);
        analogWrite(rgbledGreen, i);
        analogWrite(rgbledBlue, 0);
        delay(10);
        i++;
        if(i>255)
        {
          step1 = true;
          step2 = false;
          i=0;       
        }
        break; // t
      }   
      while((i<256) && (step2 == false)) // 2nd step
      {
        analogWrite(rgbledRed, 255-i);
        analogWrite(rgbledGreen, 255);
        analogWrite(rgbledBlue, 0);
        delay(10);
        i++;
        if(i>255)
        {
          step2 = true;
          step3 = false;
          i=0;       
        }
        break;
      }
      while((i<256) && (step3 == false)) // 3rd step
      {
        analogWrite(rgbledRed, 0);
        analogWrite(rgbledGreen, 255);
        analogWrite(rgbledBlue, i);
        delay(10);
        i++;
        if(i>255)
        {
          step3 = true;
          step4 = false;
          i=0;          
        }
        break;
      }
      while((i<256) && (step4 == false)) // 4th step
      {
        analogWrite(rgbledRed, 0);
        analogWrite(rgbledGreen, 255-i);
        analogWrite(rgbledBlue, 255);
        delay(10);
        i++;
        if(i>255)
        {
          step4 = true;
          step5 = false;
          i=0;          
        }
        break;
      }
      while((i<256) && (step5 == false)) // 5th step
      {
        analogWrite(rgbledRed, i);
        analogWrite(rgbledGreen, 0);
        analogWrite(rgbledBlue, 255);
        delay(10);
        i++;
        if(i>255)
        {
          step5 = true;
          step6 = false;
          i=0;          
        }
        break;
      }
      while((i<256) && (step6 == false)) // 6th step
      {
        analogWrite(rgbledRed, 255);
        analogWrite(rgbledGreen, 0);
        analogWrite(rgbledBlue, 255-i);
        delay(10);
        i++;
        if(i>255)
        {
          step6 = true;
          step1 = false;
          i=0;          
        }
        break;
      }      
    }
    else // buttonState == HIGH
    {
      analogWrite(rgbledRed, random(0,255));
      analogWrite(rgbledGreen, random(0,255)); 
      analogWrite(rgbledBlue, random(0,255));
      delay(300);
    }  
  }// end while(true)
}// end void loop
