#include <TinyGPS++.h>
#include <SoftwareSerial.h>

/* GPS Initialisation */

static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
#define ss Serial1 

#define gsmSerial Serial2

float lat_curr,lng_curr, speed_curr;

long previousMillis = 0;

long interval = 10000;

long send_interval = 11000;

long send_sms_interval = 30000;

long previousSmsMillis = 0;

/*People counter Initialisation*/
int in = 7;
int p_in = LOW;

int out = 2;
int p_out = LOW;

int person_counter = 0;

unsigned long distanceKmToTambaram;


void setup()
{
    Serial.begin(9600);
    ss.begin(GPSBaud);

    gsmSerial.begin(9600);
    delay(2000);
    
    /*people counter*/
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(in, INPUT);
    pinMode(out, INPUT);

}

void loop()
{
    if(digitalRead(in)==0 &&digitalRead(out)==1)
    {
        delay(4);
        while( (digitalRead(in)==0 && digitalRead(out)==0) || (digitalRead(in)==0 && digitalRead(out)==1) || (digitalRead(in)==1 && digitalRead(out)==0))
        {
            delay(2);
            if(digitalRead(in)==1 && digitalRead(out)==0)
            {
                person_counter--;
                Serial.print("No.of people in the bus are:");
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
            delay(2);
            if((digitalRead(in)==0) && (digitalRead(out)==1))
            {
                person_counter++;
                Serial.print("No.of people in the bus are:");
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

    unsigned long currentMillis = millis();

    if(currentMillis - previousMillis > interval)
    {
        previousMillis = currentMillis;

        Serial.println("GPS data");
        static const double LONDON_LAT = 51.508131, LONDON_LON = -0.128002;

        static const double TAMBARAM_LAT = 12.9254344, TAMBARAM_LON = 80.11667669999997;
        
        if(gps.location.isValid())
        {
            lat_curr = gps.location.lat();
            lng_curr = gps.location.lng();
             unsigned long distanceKmToLondon =
                (unsigned long)TinyGPSPlus::distanceBetween(
                  lat_curr,
                  lng_curr,
                  LONDON_LAT, 
                  LONDON_LON) / 1000;

              distanceKmToTambaram =
                (unsigned long)TinyGPSPlus::distanceBetween(
                  lat_curr,
                  lng_curr,
                  TAMBARAM_LAT, 
                  TAMBARAM_LON) / 1000;
                  
            Serial.print(lat_curr,6);Serial.print(",");Serial.print(lng_curr,6);
            Serial.print("\t");
            if(gps.speed.isValid())
            {
                speed_curr = gps.speed.kmph();
                Serial.print(speed_curr,2);
            }
            Serial.print("\t");
            Serial.print(distanceKmToLondon);
            Serial.print("\t");
            Serial.print(distanceKmToTambaram);
            printDateTime(gps.date, gps.time);
        }
        
        Serial.println();
        
        smartDelay(1000);
        
        if (millis() > 5000 && gps.charsProcessed() < 10)
            Serial.println(F("No GPS data received: check wiring"));
        
    }

    unsigned long currentSmsMillis = millis();
    if(currentSmsMillis - previousSmsMillis > send_sms_interval)
    {
        previousSmsMillis = currentSmsMillis;
        Serial.println("Trying to send sms");

        gsmSerial.println("AT");
        delay(5000);    //this is compulsory! If it doesn't work, then try to increase
        
        gsmSerial.println("AT+CMGF=1"); //sending SMS in text mode
        delay(1000);
        
        gsmSerial.println("AT+CMGS=\"+919003171624\"");
        delay(1000);
        
        gsmSerial.print("No.of People in bus1 are: "); delay(1000); gsmSerial.println(person_counter);
        gsmSerial.print("Current location of the bus: ");delay(1000);gsmSerial.print(lat_curr);delay(1000);gsmSerial.print(",");delay(1000);gsmSerial.println(lng_curr);delay(1000);
        gsmSerial.print("Speed of the bus: ");delay(1000);gsmSerial.print(speed_curr);delay(1000);gsmSerial.println("kmph");delay(1000);
        gsmSerial.print("Distance to Tambaram: ");delay(1000);gsmSerial.print(distanceKmToTambaram);delay(1000);gsmSerial.println("km");delay(1000);
        gsmSerial.write(0x1a);

    }
    
}

// This custom version of delay() ensures that the gps object
// is being "fed".
static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (ss.available())
      gps.encode(ss.read());
  } while (millis() - start < ms);
}

static void printInt(unsigned long val, bool valid, int len)
{
  char sz[32] = "*****************";
  if (valid)
    sprintf(sz, "%ld", val);
  sz[len] = 0;
  for (int i=strlen(sz); i<len; ++i)
    sz[i] = ' ';
  if (len > 0) 
    sz[len-1] = ' ';
  Serial.print(sz);
  smartDelay(0);
}

static void printDateTime(TinyGPSDate &d, TinyGPSTime &t)
{
  if (!d.isValid())
  {
    Serial.print(F("********** "));
  }
  else
  {
    char sz[32];
    sprintf(sz, "%02d/%02d/%02d ", d.month(), d.day(), d.year());
    Serial.print(sz);
  }
  
  if (!t.isValid())
  {
    Serial.print(F("******** "));
  }
  else
  {
    char sz[32];
    sprintf(sz, "%02d:%02d:%02d ", t.hour(), t.minute(), t.second());
    Serial.print(sz);
  }

  printInt(d.age(), d.isValid(), 5);
  smartDelay(0);
}

