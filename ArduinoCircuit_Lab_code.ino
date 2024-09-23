/* Circuit Lab Arduino Code - Alex Otten USF 10/18/20
 *  -- Code uses Arduino ADC in conjunction with a voltage divider
 *  to determine the current flowing through a resistor + LED circuit.
 *  Used to validate predictions made using Kirchhoff’s Voltage Law and
 *  Ohm's Law. R1 and R2 can be made of any series or parallel combination
 *  of resistors. R1 + R2 >= 200 to avoid burning out the LED. 
 */
// The pin used for reading analog signals
int analogPin=A0;

// Variable to store the bit-code
int analogValue;

// Baud rate for communications
int baudRate=9600;

// Reference voltage used by the ADC
float vRef=5.0;

// Number of unique codes the ADC can produce
float numStep=pow(2,10)-1;

// Conversion rate between the ADC code and volts
float vStep=vRef/numStep;

// Variable to store the resulting voltage value
float volts;

// Variable to store the current value (assumes
// 100 Ohm resistor
float current;

void setup() {
  // Starts communication between the Arduino and
  // your PC
  Serial.begin(baudRate);
}

void loop() {
  // Gets the analog code from the ADC
  analogValue=analogRead(analogPin);

  // Translates the ADC code to volts
  volts=analogValue*vStep;

  // Ohms law to find current
  current=volts/100;

  // Serial communication with the PC
  // println prints whatever is in "" followed
  // by a new line (think pressing enter), while
  // print prints whatever is in "" without
  // starting a new line
  Serial.println("----------");
  Serial.print("Voltage: ");

  // Using "" causes the exact typed words/numbers
  // to be printed, whereas putting a variable
  // without "" causes whatever number is in that
  // variable to be printed
  Serial.print(volts);
  Serial.println(" V");
  
  Serial.print("Current: ");
  Serial.print(current*1000);
  Serial.println(" mA");
  Serial.println("----------");

  // Causes the Arduino to pause for 500ms
  // Good to do to avoid sending too many messages
  // too quickly to the PC
  delay(500);
}
