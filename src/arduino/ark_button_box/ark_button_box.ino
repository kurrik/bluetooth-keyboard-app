#include <bluefruit.h>

BLEDis bledis;
BLEHidAdafruit blehid;

int buttonApin = 11;
int buttonBpin = 7;
int ledApin = 15;

unsigned long lastPressed;
bool buttonsEnabled;
uint8_t keycode[6] = { HID_KEY_NONE };

void setup() {
  // Button setup
  pinMode(buttonApin, INPUT_PULLUP);  
  pinMode(buttonBpin, INPUT_PULLUP);
  pinMode(ledApin, OUTPUT);
  buttonsEnabled = true;
    
  // Bluetooth setup
  Serial.begin(115200);
  while (!Serial) delay(10);   // for nrf52840 with native usb
  Serial.println("ARK Button Box starting.");
  Bluefruit.begin();
  Bluefruit.setTxPower(4);    // Check bluefruit.h for supported values
  Bluefruit.setName("ARK Button Box");
  bledis.setManufacturer("Arne Roomann-Kurrik");
  bledis.setModel("ARK Button Box v1");
  bledis.begin();
  blehid.begin();
  startAdvertising();

  digitalWrite(ledApin, HIGH);
  delay(1000);
  digitalWrite(ledApin, LOW);
}

void startAdvertising(void) {  
  // Advertising packet
  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();
  Bluefruit.Advertising.addAppearance(BLE_APPEARANCE_HID_KEYBOARD);
  Bluefruit.Advertising.addService(blehid);
  Bluefruit.Advertising.addName();
  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.setInterval(32, 244);    // in unit of 0.625 ms
  Bluefruit.Advertising.setFastTimeout(30);      // number of seconds in fast mode
  Bluefruit.Advertising.start(0);                // 0 = Don't stop advertising after n seconds
}

void loop() {
  // Buttons
  
  if (!buttonsEnabled) {
    if ((millis() - lastPressed) > 1000) {
      ledOff(LED_RED);
      digitalWrite(ledApin, LOW);
      buttonsEnabled = true;
    } else {
      ledOn(LED_RED);
      digitalWrite(ledApin, HIGH);
    }
  }
  if (buttonsEnabled) {
    bool pressed = false;
    if (digitalRead(buttonApin) == LOW) {
      uint8_t modifier = KEYBOARD_MODIFIER_LEFTCTRL | KEYBOARD_MODIFIER_LEFTSHIFT;
      keycode[0] = HID_KEY_F1;
      blehid.keyboardReport(modifier, keycode);
      pressed = true;

    } else if (digitalRead(buttonBpin) == LOW) {
      uint8_t modifier = KEYBOARD_MODIFIER_LEFTCTRL | KEYBOARD_MODIFIER_LEFTSHIFT;
      keycode[0] = HID_KEY_F2;
      blehid.keyboardReport(modifier, keycode);
      pressed = true;
    }
    if (pressed) {
      delay(10);
      blehid.keyRelease();
      lastPressed = millis();
      memset(keycode, HID_KEY_NONE, 6);
      buttonsEnabled = false;
    }  
  }
}
