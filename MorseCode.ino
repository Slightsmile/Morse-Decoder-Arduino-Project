#include <LiquidCrystal_I2C.h>
#include <IRremote.hpp>

// LCD setup (ensure the address is correct)
LiquidCrystal_I2C lcd(0x27, 16, 2); 

const int rcvPIN = 3;  // IR receiver pin
unsigned long lastSignalTime = 0;  // Tracks the time of the last valid signal
const unsigned long debounceDelay = 250;  // Debounce delay in milliseconds
const unsigned long dotDuration = 4000;  // Duration of a dot in milliseconds
const unsigned long dashDuration = 6000; // Duration of a dash in milliseconds
const unsigned long letterSpaceDuration = 8000; // Space between letters in milliseconds
String morseMessage = "";  // To store the decoded Morse message
int pos = 0;

// Morse code representation for each letter (A-Z)
const String morseLetters[26] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", 
  "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", 
  "..-", "...-", ".--", "-..-", "-.--", "--.."
};
const char morseChars[26] = {
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 
  'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};

void setup() {
  Serial.begin(9600);  // Start serial communication for debugging
  lcd.init();           // Initialize the LCD
  lcd.backlight();      // Turn on backlight for visibility
  lcd.clear();          // Clear the screen
  lcd.setCursor(0, 0);  // Set the cursor to the top-left corner
  lcd.print("IR Ready!");  // Display a message on LCD to confirm it’s working
  delay(500);
  lcd.clear();
  
  IrReceiver.begin(rcvPIN, ENABLE_LED_FEEDBACK); // Start the IR receiver
}

void loop() {
  if (IrReceiver.decode()) {  // Decode the received IR signal
    unsigned long currentTime = millis();

    // Apply debounce
    if (currentTime - lastSignalTime > debounceDelay) {
      // Check for a valid signal
      if (IrReceiver.decodedIRData.decodedRawData != 0) {
        if (currentTime - lastSignalTime < dotDuration) {
          // Short signal detected (dot)
          morseMessage += '.';
        } else if (currentTime - lastSignalTime < dashDuration && currentTime - lastSignalTime > dotDuration) {
          // Long signal detected (dash)
          morseMessage += '-';
        }
        lastSignalTime = currentTime;
      }
    }

    IrReceiver.resume();  // Prepare to receive the next signal
  } else {
    // No signal detected, check for timeout to decode
    if (morseMessage.length() > 0 && (millis() - lastSignalTime > letterSpaceDuration)) {
      lcd.setCursor(pos++, 0); 
      lcd.print(decodeMorse(morseMessage));
      Serial.print(" Decoded Morse: ");
      Serial.println(morseMessage);  // Print the current Morse code message
      morseMessage = "";  // Clear the message after decoding
    }
  }
}

char decodeMorse(String morseCode) {
 // Decode the Morse code into characters
  for (int i = 0; i < 26; i++) {
    if (morseCode == morseLetters[i]) {
      Serial.print(morseChars[i]);  // Print the decoded letter to Serial Monitor
      return morseChars[i];     // Display the decoded character on the LCD
    }
  }
  return '?'; // Return '?' for invalid Morse code
}



