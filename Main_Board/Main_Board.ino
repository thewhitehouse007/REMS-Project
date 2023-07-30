int RAIL_12_CURR_PIN = 0;
int RAIL_50_CURR_PIN = 1;
int RAIL_33_CURR_PIN = 2;
int RAIL_12_VOLT_PIN = 3;
int RAIL_50_VOLT_PIN = 4;
int RAIL_33_VOLT_PIN = 5;
int GAS_DET_APIN = 6;
int OK_PIN = 46;

void setup() {
  Serial.begin(9600);
  pinMode(RAIL_12_CURR_PIN,INPUT);
  pinMode(RAIL_50_CURR_PIN,INPUT);
  pinMode(RAIL_33_CURR_PIN,INPUT);
  pinMode(RAIL_12_VOLT_PIN,INPUT);
  pinMode(RAIL_50_VOLT_PIN,INPUT);
  pinMode(RAIL_33_VOLT_PIN,INPUT);
  pinMode(GAS_DET_APIN,INPUT);
  pinMode(OK_PIN,OUTPUT); 
}

void loop() {
  digitalWrite(OK_PIN, HIGH);
  // read the input on analog pins connected to the PSU Rails:
  int Rail12VoltValue = analogRead(RAIL_12_VOLT_PIN);
  int Rail50VoltValue = analogRead(RAIL_50_VOLT_PIN);
  int Rail33VoltValue = analogRead(RAIL_33_VOLT_PIN);
  int Rail12CurrValue = analogRead(RAIL_12_CURR_PIN);
  int Rail50CurrValue = analogRead(RAIL_50_CURR_PIN);
  int Rail33CurrValue = analogRead(RAIL_33_CURR_PIN);
  // Convert the analog reading (which goes from 0 - 1023) to a sensor range (0 - 25V):
  // Added a Pull Down resistor to detect no signal (Drops 40% of signal):
  float Rail12voltage = Rail12VoltValue / (1023 / 25) / 0.6;
  float Rail50voltage = Rail50VoltValue / (1023 / 25) / 0.6;
  float Rail33voltage = Rail33VoltValue / (1023 / 25) / 0.6;

  float Rail50current = Rail50CurrValue;

  Serial.println(Rail12voltage);
  Serial.println(Rail50voltage);
  //Serial.println(Rail50current);
  Serial.println(Rail33voltage);
  delay(1000);
}
