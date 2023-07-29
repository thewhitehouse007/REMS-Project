int RAIL_12_CURR_PIN = 0;
int RAIL_05_CURR_PIN = 1;
int RAIL_33_CURR_PIN = 2;
int RAIL_12_VOLT_PIN = 3;
int RAIL_05_VOLT_PIN = 4;
int RAIL_33_VOLT_PIN = 5;
int GAS_DET_APIN = 6;
int OK_PIN = 46;

void setup() {
  Serial.begin(9600);
  pinMode(RAIL_12_CURR_PIN,INPUT);
  pinMode(RAIL_05_CURR_PIN,INPUT);
  pinMode(RAIL_33_CURR_PIN,INPUT);
  pinMode(RAIL_12_VOLT_PIN,INPUT);
  pinMode(RAIL_05_VOLT_PIN,INPUT);
  pinMode(RAIL_33_VOLT_PIN,INPUT);
  pinMode(GAS_DET_APIN,INPUT);
  pinMode(OK_PIN,OUTPUT); 
}

void loop() {
  digitalWrite(OK_PIN, HIGH);
  // read the input on analog pins connected to the PSU Rails:
  int Rail12VoltValue = analogRead(RAIL_12_VOLT_PIN);
  int Rail05VoltValue = analogRead(RAIL_05_VOLT_PIN);
  int Rail33VoltValue = analogRead(RAIL_33_VOLT_PIN);
  int Rail12CurrValue = analogRead(RAIL_12_CURR_PIN);
  int Rail05CurrValue = analogRead(RAIL_05_CURR_PIN);
  int Rail33CurrValue = analogRead(RAIL_33_CURR_PIN);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float Rail12voltage = Rail12VoltValue * (12.0 / 1440.0);
  float Rail05voltage = Rail05VoltValue * (5.0 / 526.0);
  float Rail33voltage = Rail33VoltValue * (3.3 / 330.0);

  float Rail05current = Rail05CurrValue;

  Serial.println(Rail12voltage);
  Serial.println(Rail05voltage);
  Serial.println(Rail05current);
  Serial.println(Rail33voltage);
  delay(1000);
}
