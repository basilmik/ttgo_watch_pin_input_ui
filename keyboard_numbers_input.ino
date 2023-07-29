#define LILYGO_WATCH_2020_V3
#define LILYGO_WATCH_HAS_MOTOR
#include <LilyGoWatch.h>
#include "pinInput.h"

TTGOClass* ttgo = nullptr;
TFT_eSPI* tft = nullptr;


pinInput * mkeys = new pinInput;

void setup() {
  Serial.begin(115200);
  ttgo = TTGOClass::getWatch();
  ttgo->begin();
  ttgo->openBL();

  tft = ttgo->tft;
  tft->fillScreen(TFT_BLACK);
  tft->setTextColor(TFT_WHITE);
  tft->setTextSize(4);

  mkeys->draw(tft);
}


void loop() {
  Serial.println(mkeys->get_input(ttgo));
}
//EOF
