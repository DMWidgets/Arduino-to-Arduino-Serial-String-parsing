#include <SoftwareSerial.h>
const int RXpin = 10;
const int TXpin = 9;
SoftwareSerial myPort(RXpin, TXpin);

void setup() {
myPort.begin(9600);
Serial.begin(9600);

}

void loop() {

  String content = "";
  String message = "";
  char character;
  char charmes;

//gets string from serial monitor and readies it to send to other arduino
  while(Serial.available()) {
      charmes = Serial.read();
      message.concat(charmes);
      delay(10);
  }

//gets return message from other arduino and readies it to send to serial monitor
  while(myPort.available()) {
      character = myPort.read();
      content.concat(character);
      delay(10);
      //content.trim();
  }

//takes readied message and sends to other arduino when there's something to send then clears payload
if (message != "") {
    myPort.print(message);
    message = "";
  }

//takes readied message and sends to other serial monitor when there's something to send then clears payload
  if (content != "") {
    Serial.println(content);
    content = "";
  }
}

