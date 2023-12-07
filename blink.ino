/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID           "TMPL6x0BKQHwq"
#define BLYNK_TEMPLATE_NAME         "automatic door open"
#define BLYNK_AUTH_TOKEN            "QB7aMXpKqnfdjSpwEWLOkOCXXeP_KTIS"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


#define pin1 D1
#define pin2 D2
#define pin3 D5
#define pin4 D6
#define pin5 A0



// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "iPhone_Racha";
char pass[] = "racha555";
int value;

BlynkTimer timer;


// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

  digitalWrite(D4, !value);
  if (value == 1)
  {
    motor_turnleft();
  }
  else
  {
    motor_stop();
  }
 
}

BLYNK_WRITE(V1)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
 
  if (value == 1)
  {
    Serial.println("press turn right");
    motor_turnright();
   
  }
  else
  {
    motor_stop();
  }
 
}

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  value = analogRead(pin5);
  Serial.println(value);
  if (value >= 700)
  {
    Blynk.virtualWrite(V2, "DETECTED");
  }
  else
  {
    Blynk.virtualWrite(V2, "NOT DETECTED");
  }
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  pinMode(D4, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, INPUT);


 
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  timer.setInterval(10L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
 
}
void motor_stop()
{
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
}
void motor_turnleft()
{
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, HIGH);
}
void motor_turnright()
{
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
}
