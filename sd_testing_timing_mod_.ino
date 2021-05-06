#include <SPI.h>
#include <SD.h>
#include "HX711.h"
#include "RTClib.h"

#define calibration_factor -211100.0 //This value is obtained using the SparkFun_HX711_Calibration sketch

#define LOADCELL_DOUT_PIN  3
#define LOADCELL_SCK_PIN  2

HX711 scale;
RTC_PCF8563 rtc;

int CS = 10;
File myFile;
String fileName = ""; //need a way to automatically generate a file name -- use RTC once I get battery -- OR USE FOR LOOP AND LOOP THROUGH "TESTING_#"
int buttonPin = 8; //wire according to arduino website (pretty sure button press opens 5v)
String buttonState = "";
int runTime = 0;

void setup() {
  Serial.begin(9600);
  delay(100);
  if (Serial.available()) {
  Serial.println("Serial initialized");
  } else {
    Serial.println("Serial not initialized");
  }
  pinMode(LED_BUILTIN, OUTPUT);

  if(SD.begin(CS)) {
    Serial.println("SD initialized");
  } else {
    Serial.println("SD not initialized");
  }
  
  myFile = SD.open(, FILE_WRITE);

  }
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0
  
  
  /*for (int x = 0; x < 8; x++) { //blink the red led 4 times once the SD file is opened
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(50);
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(50);
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);*/

  }
  Serial.println("File successfully opened");
  Serial.println("8 second delay");
  delay(8000);
 
}

void loop() {
  runTime = millis();
  Serial.println("void loop entered");
  currTime = millis
  while (runTime < 30000) //while the button is not pressed
  {
    runTime = millis();
    myFile.print(scale.get_units(), 3); //print the scale output to the SD file
    myFile.print("   ");
    myFile.println(millis());
    (scale.get_units(), 3); //print the scale output to the Serial monitor
  }

  myFile.close(); //close the file once the button is pressed
    Serial.println("File closed");
    
  for (int x = 0; x < 4; x++) { //blink the green LED 4 times
    digitalWrite(LED_BUILTIN, HIGH);
    delay(50);
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);
  }
  delay(100000);
}