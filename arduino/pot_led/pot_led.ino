void setup() {
  // put your setup code here, to run once:
pinMode(6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//possible value 0....1023
int potValue = analogRead(A0);

int mappedValue=map(potValue,0,1023,0,255);
//possible value 0...255
analogWrite(6,potValue);
}
