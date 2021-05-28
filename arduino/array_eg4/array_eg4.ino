
const int ledPin = 7;
const int totalStates = 10;

int ledState[totalStates];

int ledDuration[totalStates] = {200,400,5010,100,200,50,50,500,500};

void setup() {
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);

  while(!Serial)
  {
    ;
  }
  for(int i = 0 ; i < totalStates ; i++)
  {
  
  Serial.print("Please type 1 or 0 for pattern step ");
  Serial.print(i);
  Serial.print(" out of ");
  Serial.print(totalStates - 1);
  Serial.print(" (default is 1):");
  

  while(Serial.available()==0)
  {
  }
  
char userInput = Serial.read();
if(userInput == '1')
ledState[i]=1;
else if (userInput=='0')
ledState[i]=0;
else
ledState[i]=1;
Serial.println(ledState[i]);
  }
  
Serial.println("Thank you,now lets blink this led using this pattern");
for(int i = 0; i < totalStates ; i++)
{
  Serial.print("step ");
  Serial.print(i);
  Serial.print(" state is: ");
  Serial.print(ledState[i]);
  Serial.print(" with duration ");
  Serial.println(ledDuration[i]);

}
}

 void loop() {
 for (int i = 0; i< totalStates; i++)
 {
  digitalWrite(ledPin,ledState[i]);
  delay(ledDuration[i]);
 }
 }
  // put your main code here, to run repeatedly:
