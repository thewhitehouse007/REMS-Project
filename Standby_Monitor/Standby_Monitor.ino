# include <RGBLed.h>

int PSU_VOLTAGE_PIN = 0;
int RED_PIN = 2;
int GREEN_PIN = 4;
int BLUE_PIN = 3;
int OK_PIN = 12;
float low_voltage = 0.2;
float good_voltage = 4.6;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(OK_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Initialize the RGB LED using the RBDLed Library
  RGBLed led(RED_PIN, GREEN_PIN, BLUE_PIN, RGBLed::COMMON_CATHODE);
  // read the input on analog pin connected to the PSU 5V Output:
  int VoltsensorValue = analogRead(PSU_VOLTAGE_PIN);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = VoltsensorValue * (5.0 / 1023.0);
  // If no Voltage is detected on 5V PSU Rail set the LED to standby...
  // If acceptable voltage is detected then test for OK Status from Arduino MEGA (GREEN)
  if (voltage <= low_voltage) {
    // Standby State
    led.setColor(RGBLed::BLUE);
  }    
  else if (voltage >= good_voltage) {
    // Power On
    if (digitalRead(OK_PIN)) {
      // Arduino Mega Online
      led.setColor(RGBLed::GREEN);
    }
    else {
      // Arduino Mega not online!
      led.crossFade(RGBLed::MAGENTA, RGBLed::BLUE, 50, 1000);
    }
  }
  else {
    // Error State
    led.setColor(RGBLed::RED);
  }
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
}
