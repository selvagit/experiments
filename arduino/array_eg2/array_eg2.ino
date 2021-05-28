char my_char[6] = {'a','b', 'c', 'd', 'e' };

void setup() {
Serial.begin(9600);

while(!Serial)
{
  ;
}

Serial.println("your array char: ");
for(int i =0; i < 5; i++)
{
  Serial.print("Index ");
  Serial.print(i);
  Serial.print(" contains char '");
  Serial.print(my_char[i]);
  Serial.print("', ASCII decimal ");
  Serial.println(my_char[i],DEC);
  
}
Serial.println();
Serial.println("Let's do some calculations: ");

for(int i = 0; i<4 ; i++)
{
  Serial.print(my_char[i]);
  Serial.print(" + ");
  Serial.print(my_char[i+1]);
  Serial.print(" = ");
  Serial.println(my_char[i] + my_char[i+1]);
}
Serial.println();
Serial.println("Let's do some calculations and see the results: ");

for(int i = 0; i<4 ; i++)
{
  Serial.print(my_char[i]);
  Serial.print(" + ");
  Serial.print(my_char[i+1]);
  Serial.print(" = ");
 char sum = (my_char[i] + my_char[i+1]);
 my_char[i] = sum;
 Serial.print(my_char[i],DEC);
 Serial.print("  -> Index ");
 Serial.print(i);
 Serial.print(" now contains value ");
 Serial.println(my_char[i], DEC);
 
}
}
 


void loop() {
  // put your main code here, to run repeatedly:

}
