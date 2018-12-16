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

void AT_Library::send(String &command) {
    serial->print(command);
    delay(50);
    response = "";
    while(serial->available()){
        response.concat((char)serial->read());
    }
}

bool AT_Library::ping() {
    if(serial == nullptr) return false;
    String message = "AT";
    message.concat(end);
    send(message);
    return isSuccess();
}

String AT_Library::sendMessage(String &number, String &message) {
    String ascii = "AT+CMGF=1" + end;
    send(ascii);
    String command = "AT+CMGS=\"" + number + "\"" + end;
    send(command);
    delay(50);
    command = message + end;
    command.concat(messageEnd);
    command.concat('\r');
    send(command);
    delay(1000); //Todo: enter error correction methods
    return response;
}

bool AT_Library::isSuccess() {
    auto input = response.lastIndexOf('\n', response.length() - 2);
    error = response.substring((unsigned int) (input+1), response.length());
    return error.equals("OK\r\n");
}

String AT_Library::getError() {
    return error;
}

String AT_Library::sendCommand(String &command, bool check) {
    do{
        send(command);
    } while(check && !isSuccess());
    return response;
}

String AT_Library::getResponse(){
    return response;
}



