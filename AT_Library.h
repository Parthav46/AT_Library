#ifndef AT_LIBRARY_H
#define AT_LIBRARY_H

#include <Arduino.h>
#define messageEnd (char)26

class AT_Library{
    public:
        AT_Library();
        explicit AT_Library(String &end);
        void setPort(Stream &port);     //initialize AT_Library with HardwareSerial or SoftwareSerial stream
        bool ping();                    //ping the device for connectivity
        String sendMessage(String &number, String &message);
        String sendCommand(String &command, bool check);
        String getResponse();
        String getError();
        bool isSuccess();
    private:
        void send(String &command);
        String error;
        String response = "";
        String end;
        Stream *serial = nullptr;
};

#endif