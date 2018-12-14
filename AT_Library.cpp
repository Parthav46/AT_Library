#include "AT_Library.h"
#include <Arduino.h>

AT_Library::AT_Library() {
    end = "\r\r\n";
}

AT_Library::AT_Library(String endString) {
    end = endString;
}

void AT_Library::setPort(Stream &port) {
    serial = &port;
}

bool AT_Library::ping() {
    String message = "AT";
    message.concat(end);
    send(message);
    auto input = (unsigned int) response.indexOf((char)13);
    String resp = response.substring(0, input);
    return resp.equals("OK");
}

String AT_Library::getResponse(){
    return response;
}

void AT_Library::send(String command) {
    serial->print(command);
    delay(50);
    response = "";
    while(serial->available()){
        response.concat((char)serial->read());
    }
    response.replace(command, "");
}

