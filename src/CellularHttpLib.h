#ifndef CELLULARHTTPLIB_H
#define CELLULARHTTPLIB_H

#include <Arduino.h>
#include <GPRS.h>
#include <CellularHttp.h>

class CellularHttpLib {
public:
    CellularHttpLib();
    void begin();
    bool connectToServer();
    String httpGet(const String& resource);
    String httpPost(const String& resource);
};

#endif // CELLULARHTTPLIB_H