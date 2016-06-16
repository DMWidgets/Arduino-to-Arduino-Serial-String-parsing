#include <SoftwareSerial.h>
const int RXpin = 9; //remember there are pin limits depending on board as to which pins can be used for Rx (pin interrupt)
const int TXpin = 8;
SoftwareSerial myPort(RXpin, TXpin);

void setup() {
myPort.begin(9600);
}

void loop() {
  String content = "";
  char character;

//gets string from master and readies it to echo back to master
  while(myPort.available()) {
      character = myPort.read();
      content.concat(character);
      delay(10);
      //content.trim();
  }

//takes readied message and sends to master when there's something to send then clears payload
  if (content != "") {
    myPort.print(content);
    delay(250);
    content = "";
  }
}
