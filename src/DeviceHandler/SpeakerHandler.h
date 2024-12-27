#ifndef SPEAKERHANDLER_H
#define SPEAKERHANDLER_H

#include <M5AtomS3.h>
#include <M5Unified.h>

class SpeakerHandler {
public:
    void playTone(int frequency, int duration);
};

#endif