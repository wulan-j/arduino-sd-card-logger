//Mohammad Alshahrani
// I repeated it again, but it became faster, shorter, and easier to read and study
//edited by Julan

#include <SD.h> // load the Sd library
#include <SPI.h> // lad the SPI comminucation library

unsigned long previousMillis = 0;
long interval = 200;

int chipSelect = 4; //Set chipSelect = 4
File mySensorData; // Variable for working with our file object

void setup() {
  Serial.begin (9600);

 // pinMode(10, OUTPUT);// reseve pin 10, even wheile we dont use is.
  SD.begin(chipSelect); // initilaize the SD card with chipselect to pin 4
}
void loop() {

  mySensorData = SD.open("data.txt", FILE_WRITE); //open file on the SD card to write to , max 8 character + 3 for extension

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;


    if (mySensorData) { //onely do these tings if the data file opend sucessfully

      Serial.println(currentMillis);

      mySensorData.print(currentMillis); //print currentmilis to sd card
      mySensorData.print(","); // write comma to sd card
      mySensorData.println("time in miliseconds"); // write text time in miliseconds to sd card
      mySensorData.close(); //close the file
    }
  }

  else {
    Serial.println("error opening data.txt");
  }

}
