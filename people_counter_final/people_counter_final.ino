//Vcc of irsensor should be connected to 5V of arduino (connecting to Vin doesn't work)
//digitalRead takes sometime, so delay is required between each digitalread, else it checks the old value
int in = 7;
int p_in = LOW;

int out = 2;
int p_out = LOW;


int person_counter = 0;
int count1 = 1;

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
    if(digitalRead(in)==0 &&digitalRead(out)==1)
    {
        delay(4);
        while( (digitalRead(in)==0 && digitalRead(out)==0) || (digitalRead(in)==0 && digitalRead(out)==1) || (digitalRead(in)==1 && digitalRead(out)==0))
        {
            delay(4);
            if(digitalRead(in)==1 && digitalRead(out)==0)
            {
                person_counter--;
                Serial.println(person_counter);
                while(digitalRead(in)==1 && digitalRead(out)==0);   //this is extremely important -> Otherwise in a short span of time the loop starts over while the sensor values remain tbe same.
                return;
            }
          
        }
        if(digitalRead(in)==1 && digitalRead(out)==0)
        {
            person_counter--;
            Serial.println(person_counter);
            while(digitalRead(in)==1 && digitalRead(out)==0);
            return;
        }
    }

    else if(digitalRead(in)==1 && digitalRead(out)==0)
    {
        delay(4);
        while( (digitalRead(in)==0 && digitalRead(out)==0) || (digitalRead(in)==1 && digitalRead(out)==0) || (digitalRead(in)==0 && digitalRead(out)==1))
        {
            delay(4);
            if((digitalRead(in)==0) && (digitalRead(out)==1))
            {
                person_counter++;
                Serial.println(person_counter);
                while(digitalRead(in)==0 && digitalRead(out)==1);
                return;
            }
            //here digitalRead(in) is becoming 1 and digitalRead(out) is becoming 1 and goin out of the loop
          
        }
        if(digitalRead(in)==1 && digitalRead(out)==0)
        {
            person_counter++;
            Serial.println(person_counter);
            while(digitalRead(in)==1 && digitalRead(out)==0);
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
