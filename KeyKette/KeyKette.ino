#include <USBHost_t36.h>
#include <SD.h>

USBHost usbmanager;
KeyboardController keyboardcontrol(usbmanager);
USBHub hub1(usbmanager); // Hub USB

USBHIDParser hid1(usbmanager); // Parser pour le périphérique HID 1
USBHIDParser hid2(usbmanager); // Parser pour le périphérique HID 2
USBHIDParser hid3(usbmanager); // Parser pour le périphérique HID 3

string keytab = [];

void setup() {
    Serial.begin(9600);
    while (!Serial) {
        ;
    }
    usbmanager.begin();   // Vérifier la présence de la carte SD
    if (!SD.begin(BUILTIN_SDCARD)) {
        Serial.println("No SD Card");
        blinkLED(3, 200);
        while (true); // Boucle infinie si la carte SD est absente
    }
    File myFile = SD.open("/test.txt", FILE_WRITE);
    Keyboard.begin();
    keyboardcontrol.attachRawPress(keyPress);
    keyboardcontrol.attachRawRelease(keyRelease);
    blinkLED(2, 2000);
    Serial.println("Setup complete, entering loop.");
}

void loop() {
    usbmanager.Task();
}

void keyPress(uint8_t key){
    // Called when a key is pressed
    Serial.printf("Touche = %c\n", key);
    // Keyboard.print(key);
    Keyboard.press(key);
    // Next FEATURE
    // keytab.append(char(key));
    // if (char(key) == 'i' ){
    //     keytab
    // }
    // Keyboard.press(KEY_RETURN);
}

void keyRelease(uint8_t key){
    // Called when a key is released
    Keyboard.release(key);
}

void blinkLED(int count, int delayMs){
    // Blink the LED on the Teensy board by specified count and delay
    pinMode(LED_BUILTIN, OUTPUT);
    for (int i = 0; i < count; i++){
        digitalWrite(LED_BUILTIN, HIGH);
        delay(delayMs);
        digitalWrite(LED_BUILTIN, LOW);
        delay(delayMs);
    }
}