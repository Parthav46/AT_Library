#ifndef AT_LIBRARY_LIBRARY_H
#define AT_LIBRARY_LIBRARY_H

#include <Arduino.h>

class AT_Library{
    public:
        AT_Library();
        void setPort(Stream &port);
        bool ping();
    private:
        Stream *serial;
};

#endif