// Program to display exhaust gas temps on a 4-row display using four MAX31855 IC's and the Mega2560
// It's recommended to upload the sketch with a programmer so as to avoid using the bootloader and get a faster boot
// Software and hardware by Kim Gulle. Though this is open source and would benefit from more people getting involved.
// Feel free to use this uncommercially and modify it as you see fit. CAN-Bus comms for use with Megasquirt etc would be cool.


#include "Adafruit_MAX31855.h"
#include <LiquidCrystal.h>

// Givare 1
int thermoCLK = 44;
int thermoCS = 46;
int thermoDO = 47;
Adafruit_MAX31855 thermocouple(thermoCLK, thermoCS, thermoDO);

// Givare 2
int thermo2CLK = 48;
int thermo2CS = 50;
int thermo2DO = 52;
Adafruit_MAX31855 thermocouple2(thermo2CLK, thermo2CS, thermo2DO);

// Givare 3
int thermo3CLK = 28;
int thermo3CS = 30;
int thermo3DO = 31;
Adafruit_MAX31855 thermocouple3(thermo3CLK, thermo3CS, thermo3DO);

// Givare 4
int thermo4CLK = 29;
int thermo4CS = 27;
int thermo4DO = 25;
Adafruit_MAX31855 thermocouple4(thermo4CLK, thermo4CS, thermo4DO);


LiquidCrystal lcd(32, 34, 36, 38, 40, 42);

void setup() {
  Serial.begin(115200);
  lcd.begin(20, 4);
  lcd.setCursor(0, 0);
  lcd.print("  GULLE MOTORSPORT");

  lcd.setCursor(0, 1);
  lcd.print("   X4 EGT DISPLAY");

  lcd.setCursor(0, 15);
  lcd.print("             sw v0.8");
  delay(5000);
}

void loop() {
  // Read and write from first thermocouple
  double c = thermocouple.readCelsius();
  lcd.setCursor(0, 0); // Place the marker on row 1
  if (isnan(c)) // Checking so that the value is a real number
  {
    lcd.print("  CYL 1 = -- -- --   ");
  }
  else // If OK, write value on row 1
  {
    lcd.print("  CYL 1 = ");
    lcd.print(c);
    lcd.print("c      ");
    delay(20);
  }

 // Read and write from second thermocouple
  double c2 = thermocouple2.readCelsius();
  lcd.setCursor(0, 1); // Place the marker on row 2
  if (isnan(c2))
  {
    lcd.print("  CYL 2 = -- -- --   ");
  }
  else
  {
    lcd.print("  CYL 2 = ");
    lcd.print(c2);
    lcd.print("c      ");
    delay(20);
  }

 // Read and write from third thermocouple
  double c3 = thermocouple3.readCelsius();
  lcd.setCursor (0, 2); // Place the marker on row 3
  if (isnan(c3))
  {
    lcd.print("  CYL 3 = -- -- --   ");
  }
  else
  {
    lcd.print("  CYL 3 = ");
    lcd.print(c3);
    lcd.print("c      ");
    delay(20);
  }

  // Read and write from fourth thermocouple
  double c4 = thermocouple4.readCelsius();
  lcd.setCursor (0, 3); // Place the marker on row 4
  if (isnan(c4))
  {
    lcd.print("  CYL 4 = -- -- --   ");
  }
  else
  {
    lcd.print("  CYL 4 = ");
    lcd.print(c4);
    lcd.print("c      ");
    delay(20);
  }
}

