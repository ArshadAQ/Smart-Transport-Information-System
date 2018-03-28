/*
The circuit:
* RX is digital pin 19 (connect to TX of GSM Modem)
* TX is digital pin 18 (connect to RX of GSM Modem)
*/
//#include <SoftwareSerial.h>

#define gsmSerial Serial1   //this initialises pin 18 and 19 as TX,RX respectively
//SoftwareSerial gsmSerial(15, 16); // RX, TX

void setup()
{
    // Open serial communications and wait for port to open:
    Serial.begin(9600); 
    Serial.println("Calling through GSM Modem");
        
    // set the data rate for the SoftwareSerial port
    gsmSerial.begin(9600);
    delay(2000);
    gsmSerial.println("AT");
    delay(5000);    //this is compulsory! If it doesn't work, then try to increase
    gsmSerial.println("ATD9003171624;"); // ATD9003171624; -- watch out here for semicolon at the end!!
    delay(10000);

    gsmSerial.println("ATH");
    Serial.println("Called ATD9003171624");
}

void loop() // run over and over
{
    // print response over serial port
    if (gsmSerial.available())
        Serial.write(gsmSerial.read());
}
