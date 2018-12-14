#ifndef AT_LIBRARY_LIBRARY_H
#define AT_LIBRARY_LIBRARY_H

#include <Arduino.h>

class AT_Library{
    public:
        AT_Library();
        AT_Library(String endString);
        void setPort(Stream &port); //initialize AT_Library with HardwareSerial or SoftwareSerial stream
        bool ping(); //ping the device for connectivity
        String sendCommand(String command);
        String getResponse();
    private:
        void send(String command);
        String response;
        String end;
        Stream *serial;
};

#endif