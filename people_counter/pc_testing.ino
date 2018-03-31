//Vcc of irsensor should be connected to 5V of arduino (connecting to Vin doesn't work)
int in = 7;
int p_in = LOW;

int out = 2;
int p_out = LOW;

int person_counter = 0;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  Serial.begin(9600);  
}

void loop() 
{
  if((digitalRead(in)==0)&&(digitalRead(out)==1))
  {
    while(((digitalRead(in)==0) && (digitalRead(out))==0))||((digitalRead(in)==0)&&(digitalRead(out)==1)))
    {
      if((digitalRead(in)==1) && (digitalRead(out)==0))
      {
        person_counter--;
        Serial.println(person_counter);
        return;
      }
      
    }
    if((digitalRead(in)==1) && (digitalRead(out)==0))
    {
        person_counter--;
        Serial.println(person_counter);
        return;
    }
  }

 if((digitalRead(in)==1)&&(digitalRead(out)==0))
  {
    while(((digitalRead(in)==0) && (digitalRead(out))==0))||((digitalRead(in)==1)&&(digitalRead(out)==0)))
    {
      if((digitalRead(in)==0) && (digitalRead(out)==1))
      {
        person_counter++;
        Serial.println(person_counter);
        return;
      }
      
    }
    if((digitalRead(in)==1) && (digitalRead(out)==0))
    {
        person_counter++;
        Serial.println(person_counter);
        return;
    }
  }
}
 









/*

  // put your main code here, to run repeatedly:
  p_in = digitalRead(in);
  p_out = digitalRead(out);
  
  if(p_in == HIGH) //just if(person_detected) doesn't work!
  {
    Serial.println("in Detected!");  //single quotes not working
    p_in = LOW;  //immediately change the status once a person's presence has been sensed and recorded
    while(1)
    {
         if(p_out = digitalRead(out))
        {
              if(!(p_in = digitalRead(in)))
              {
                
                Serial.println(--person_counter);
                break;
              }
        }
    }

  }
  
  if(p_out == HIGH) //just if(person_detected) doesn't work!
  {
    Serial.println("out Detected!");  //single quotes not working
    p_out = LOW;  //immediately change the status once a person's presence has been sensed and recorded
    while(1)
    {
         if(p_in = digitalRead(in))
        {
              if(!(p_out = digitalRead(out)))
              {
                
                Serial.println(++person_counter);
                break;
              }
        }
    }

  }
  
} */
