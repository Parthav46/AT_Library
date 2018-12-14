#include "AT_Library.h"
#include <Arduino.h>

AT_Library::AT_Library() {
    end = "\r\r\n";
}

AT_Library::AT_Library(String &end) {
    AT_Library::end = end;
}

void AT_Library::setPort(Stream &port) {
    serial = &port;
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

bool AT_Library::ping() {
    if(serial == nullptr) return false;
    String message = "AT";
    message.concat(end);
    send(message);
    return isSuccess();
}

bool AT_Library::isSuccess() {
    auto input = response.lastIndexOf('\n', response.length());
    if(input == -1) input = 0;
    error = response.substring(input, response.length());
    return error.equals("OK\r\n");
}

String AT_Library::getError() {
    return error;
}

String AT_Library::sendCommand(String &command) {
    send(command);
    return response;
}

String AT_Library::getResponse(){
    return response;
}



