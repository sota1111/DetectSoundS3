#ifndef SDCARDHANDLER_H
#define SDCARDHANDLER_H

#include <M5AtomS3.h>
#include <SD.h>
#include <M5Unified.h>
#include <time.h>

#define SD_CS_PIN 4
#define TFCARD_CS_PIN SD_CS_PIN

class SDCardHandler {
public:
    void initSDCard(const char* dirname);
    void writeSDCard(const char* filename, const char* data);
};

#endif