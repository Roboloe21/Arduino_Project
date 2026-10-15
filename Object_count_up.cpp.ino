/*
  Ultrasonic Sensor HC-SR04 and Arduino Tutorial
  by Dejan Nedelkovski,
  www.HowToMechatronics.com
*/

// defines pins numbers
const int trigPin = 11;
const int echoPin = 12;

// defines variables
long duration;
int distance;
int count = 1;

void setup() {
  // UltraSonoc Pins
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600); // Starts the serial communication   
}

 int get_distance() {
  int toReturn = 0;
 
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  toReturn = duration * 0.034 / 2;
  
  return toReturn;
  }

void loop() 
  { 
  // --------------------------------------------------------
  // ADD Your Code Here - Detect a specific distance... like distance > 5 cm
  if(get_distance() < 7)
  {
  count++;
  }
  while (get_distance() > 5)
  {
  Serial.println("Waiting To Detect An Object");
  delay(1000); 

  }

  Serial.println("Object is detected and present");
  Serial.println(String(count) + " objects detected");
  
  while (get_distance() < 7)
  {
  count++;
  delay(1000);
  }
  Serial.println("Detected Object Is Gone");
  // --------------------------------------------------------
  }
