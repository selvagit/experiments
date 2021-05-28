
const int ledPin = 7;
const int totalStates = 10;

int ledState[totalStates] = {1, 0, 1, 0, 1, 0, 0, 1, 0};
int ledDuration[totalStates] = {200,400,500,100,200,50,50,500,500};

void setup() {
  pinMode(ledPin, OUTPUT);
}
 void loop() {
 for (int i = 0; i< totalStates; i++)
 {
  digitalWrite(ledPin,ledState[i]);
  delay(ledDuration[i]);
 }
 }
  // put your main code here, to run repeatedly:
