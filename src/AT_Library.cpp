#include "AT_Library.h"
#include <Arduino.h>

AT_Library::AT_Library() {}

void AT_Library::setPort(Stream &port) {
    serial = &port;
}

bool AT_Library::ping() {
    String message = "AT";
    serial->println(message);
    delay(100);
    String reply = "";
    while(serial->available()){
        reply.concat((char)serial->read());
    }
    unsigned int input = (unsigned int) reply.indexOf('\n');
    reply = reply.substring(input + 1);
    input = (unsigned int) reply.indexOf((char)13);
    reply = reply.substring(0, input);
    return reply.equals("OK");
}