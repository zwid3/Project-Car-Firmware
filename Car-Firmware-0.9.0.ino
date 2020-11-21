
const int leftPos = 2; // Left wheel forward
const int leftNeg = 3; // Left wheel backward
const int rightPos = 4; // Right wheel forward
const int rightNeg = 5; // Left wheel forward
const int echoPin = 6; // Trigger Pin of Ultrasonic Sensor
const int pingPin = 7; // Echo Pin of Ultrasonic Sensor

const int carMode = 0; // Mode used to controll speed or function of the car ( 0 = Slow mode, 1 = Normal mode, 2 = Fast mode, 3 = Experimental mode, 4 = debug mode sensors, 5 = debug mode wheels)

void setup() {
   Serial.begin(9600); // Starting Serial Terminal for debugging purposes (check if sensor works)
   delay(5000); // waits for 5 seconds to allow for preperation of placement of car after power-on
}

void loop() {

  
  
   long duration, inches, cm; // initialize variables used for purposes of measuring distance and time in establishing proximity through the electronic sensor
   pinMode(pingPin, OUTPUT); 
   digitalWrite(pingPin, LOW); // Start the ping sensor to idle state
   delayMicroseconds(2); // 2 microseconds
   digitalWrite(pingPin, HIGH); // Generate ultrasonic wave for 10 microseconds
   delayMicroseconds(10); // 10 microseconds
   digitalWrite(pingPin, LOW); // Set ping to idle state
   pinMode(echoPin, INPUT); // Set echo pin to accept echo wave
   duration = pulseIn(echoPin, HIGH); // Read the waves travel time for duration
   inches = microsecondsToInches(duration); // Send duration to function to convert to inches and assign value to inches
   cm = microsecondsToCentimeters(duration); // Send duration to function to convert to centimeters and assign values to cm
   Serial.print(inches); // Print distance in inches
   Serial.print("in, "); // Print "in" and go to next line
   Serial.print(cm); // Print distance in centimeters
   Serial.print("cm, "); // Print "cm" and go to next line
   delay(100); // Delay of 100 microseconds between each phase to prevent overlapping of ultrasonic waves


 if((cm>450)) // If distance is less than 20cm turn right
 {
   digitalWrite(leftPos,LOW);                          
   digitalWrite(leftNeg,HIGH);                      
   digitalWrite(rightPos,LOW);                   
   digitalWrite(rightNeg,HIGH);                            
 }
 
 else if(cm<45)  // if distance is greater than 20cm keep moving forward
 {
   digitalWrite(leftPos,LOW);                             
   digitalWrite(leftNeg,HIGH);    
   digitalWrite(rightPos,HIGH);                            
   digitalWrite(rightNeg,LOW);                                      
 }

   
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2; // Equation to get inches from speed of sound of ultrasonic wave
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2; // Equation to get centimeters from speed of sound of ultrasonic wave
}
