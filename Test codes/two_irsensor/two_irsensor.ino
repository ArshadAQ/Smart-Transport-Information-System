//Vcc of irsensor should be connected to 5V of arduino (connecting to Vin doesn't work)
int detect_person_in_pin = 7;
int person_detected_in = LOW;

int detect_person_out_pin = 2;
int person_detected_out = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(detect_person_in_pin, INPUT);
  pinMode(detect_person_out_pin, INPUT);
  Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
  person_detected_in = digitalRead(detect_person_in_pin);
  if(person_detected_in == HIGH) //just if(person_detected) doesn't work!
  {
    Serial.println("in Detected!");  //single quotes not working
//    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
    Serial.println("in Not detected");
//    digitalWrite(LED_BUILTIN, LOW);
  }
    delay(2000);

    person_detected_out = digitalRead(detect_person_out_pin);
  if(person_detected_out == HIGH) //just if(person_detected) doesn't work!
  {
    Serial.println("out Detected!");  //single quotes not working
//    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
    Serial.println("out Not detected");
//    digitalWrite(LED_BUILTIN, LOW);
  }
    delay(2000);
}
