#define echoPin	3 
#define trigPin	4 										 \

long duration;
int distance;

void setup()
{
	Serial.begin(9600);
	pinMode(trigPin,OUTPUT);
	pinMode(echoPin, INPUT);
	
	Serial.println("Distance measurement using Arduino Uno.");
	delay(500);
}

void loop()
{
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);

	digitalWrite(trigPin, HIGH); 
	delayMicroseconds(10); 

	digitalWrite(trigPin, LOW);

	// If pulse reached the receiver echoPin become high Then pulseIn() returns the time taken by the pulse to reach the receiver

	duration = pulseIn(echoPin, HIGH);
	distance = duration * 0.0344 / 2; // Expression to calculate distance using time

	Serial.print("Distance: ");
	Serial.print(distance);
	Serial.println(" cm");
	delay(100);
}