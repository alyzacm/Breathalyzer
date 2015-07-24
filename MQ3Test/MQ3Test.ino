short sensorReading;
short sensor = A0;

void setup(){
	Serial.begin(9800);
	pinMode(sensor, INPUT);
}

void loop(){
	sensorReading = analogRead(sensor);
	Serial.println("sensorReading: ");
	Serial.println(sensorReading);
	Serial.println("\r\n");

	delay(500);
}
