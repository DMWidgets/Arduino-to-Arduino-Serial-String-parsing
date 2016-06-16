# Arduino to Arduino Serial String parsing
basic example of passing string from one arduino to another and back again.

String communication over serial for arduino is annoying and frankly, more obtuse than it should be but it is what it is. Examples and code vary and in general they either stop short or carry on so far past the basics that trying to figure out "how do I just send a message over serial that the arduino can use" with little initial experience is a painful process. Fortunately for me, that's in the past now!

The example is barebones enough that it should be self explanatory. Enter your string into the serial monitor > master parses it and sends it over to the other arduino (slave) > slave parses it (at this point it could do something if it wanted; you now have a workable variable/whatever) and echos it back to the master > master echos the received message to the serial monitor. Fairly useless operation but it's to show the functionality and how little code you need.
