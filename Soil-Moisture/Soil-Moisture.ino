// Sensor pins
#define sensorPower D4
#define sensorPin A0

float val;
float sm;

void setup() {
  // Set power pins
	pinMode(sensorPower, OUTPUT);
	
	// Initially keep the sensor OFF
	digitalWrite(sensorPower, LOW);

  // Begin Serial Monitor
	Serial.begin(115200);
}

void loop() {
  //Device Initialization
  digitalWrite(sensorPower, HIGH);	// Turn the sensor ON
	delay(10);							          // Allow power to settle
  val = (analogRead(sensorPin)-10);
	digitalWrite(sensorPower, LOW);		// Turn the sensor OFF

	//Print Analog Output
	Serial.print("Analog output: ");
	Serial.print(val);
	
  // Calculate Soil Moisture
  sm = (1-(val-8)/629)*100;	// Read the analog value form sensor
  Serial.print("\t Soil Moisture: ");
	Serial.println(sm);

  //Time between data collection
	delay(1000);
}