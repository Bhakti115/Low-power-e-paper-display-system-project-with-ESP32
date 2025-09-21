#include <GxEPD2_BW.h>
#include <Adafruit_GFX.h>
#include <SPI.h>

// E-Paper 1.54" b/w (200x200, GDEH0154D67)
// Paged buffer (HEIGHT / 4) works on UNO
GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT / 4> display(GxEPD2_154_D67(10, 9, 8, 7));

void setup()
{
  display.init(115200);
  display.setRotation(1);

  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.setTextColor(GxEPD_BLACK);
    display.setCursor(20, 40);
    display.setTextSize(4);
    display.print("Bhakti\n");
    display.print(" Vibha\n");
    display.print(" Shruti\n");
    display.print(" Namrata");
  } while (display.nextPage());

  display.hibernate(); // low power
}
void loop() {}
