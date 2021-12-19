#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into digital pin 2 on the Arduino
#define ONE_WIRE_BUS 2

const int fetPin = 3;

const int LED = 13;

float desiredTempC = 37; // which temperature to maintain

const int pinUp = 255;
const int pinDown = 0;

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);  

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

void setup() {
  sensors.begin();  // Start up the library
  Serial.begin(9600);

  pinMode(fetPin, OUTPUT);

  pinMode(LED, OUTPUT);

}

void loop() {
  sensors.requestTemperatures(); 

  Serial.println(String(sensors.getTempCByIndex(0)));

  if(sensors.getTempCByIndex(0) > desiredTempC){
    analogWrite(fetPin, pinDown);
    digitalWrite(LED, LOW);
  }
 else{
    analogWrite(fetPin, pinUp);
    digitalWrite(LED, HIGH);
  }
  
 
  
  delay(3000);

}
