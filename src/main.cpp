// --- Main.cpp ---
#include "core/NoiseDetector.h"
#include "core/WaveformDrawer.h"
#include "DeviceHandler/WiFiHandler.h"
#include "config/secret.h"

WiFiHandler wifiHandler;
NoiseDetector noiseDetector;
WaveformDrawer waveformDrawer;

volatile int micValue = 0;
volatile int maxMicValue = 0;
hw_timer_t *timer = NULL;

void IRAM_ATTR onTimer() {
    micValue = analogRead(36);
    //waveformDrawer.updateBuffer(micValue);
    //maxMicValue = waveformDrawer.calcMaxADValue(micValue);
}

void setup() {
    M5.begin();
    wifiHandler.connectWiFi(WIFI_SSID, WIFI_PASSWORD);
    wifiHandler.synchronizeTime();
    noiseDetector.initNoiseDetector();
    timer = timerBegin(0, 80, true); 
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, 10000, true);
    timerAlarmEnable(timer);
}

void loop() {
    M5.Lcd.fillScreen(TFT_BLACK);
    M5.Lcd.setCursor(80, 80);
    M5.Lcd.printf("micValue: %d", micValue);
    waveformDrawer.drawMaxADValue(micValue);
    noiseDetector.detectNoise(maxMicValue);
    waveformDrawer.drawWaveform();
    delay(20);
}