#include <SD.h>

int chipSelect = 4;
File file;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(chipSelect, OUTPUT);
  if(!SD.begin(chipSelect)){
    Serial.println("Could not initialize SD card.");
  }

  if(SD.exists("file.txt")){
    Serial.println("File exists.");
    if(SD.remove("file.txt")==true){
      Serial.println("Successfully removed file.");
    }else{
      Serial.println("Could not removed file.");
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  file = SD.open("file.txt",FILE_WRITE);
  if(file){
    int number = random(10);
    file.println(number);
    file.close();
    Serial.print("Wrote number : ");
    Serial.println(number);
  }else{
    Serial.println("Could not open file (writing).");
  }

  file = SD.open("file.txt",FILE_READ);
  if(file){
    Serial.println("---Reading start ---");
    char character;
    while((character = file.read()) != -1){
      Serial.print(character);
    }
    file.close();
    Serial.println("---Reading end ---");
  }else{
    Serial.println("Could not open file (reading).");
  }
  delay(5000);
  

}
