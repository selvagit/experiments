
int my_integers[6] =  {1,
                       2,
                       3,
                       4,
                       5};


void setup() {
 Serial.begin(9600);
while(!Serial)
{
  ;
}
Serial.println("your array numbers: ");

for(int index = 0; index < 5; index++)
{
  Serial.print("Index ");
  Serial.print(index);
  Serial.print(" contains value ");
  Serial.println(my_integers[index]);
}
Serial.println();
Serial.println("Let's do some calculations:");

for(int i = 0; i < 4 ; i++)
{
  Serial.print(my_integers[i]);
  Serial.print(" + ");
  Serial.print(my_integers[i+1]);
  Serial.print(" = ");
  Serial.println(my_integers[i] + my_integers[i+1]);

}
Serial.println();
Serial.println("Let's do some calculations and store the results:");

for(int i = 0; i < 4 ; i++)
{
  Serial.print(my_integers[i]);
  Serial.print(" + ");
  Serial.print(my_integers[i+1]);
  Serial.print(" = ");
  int sum = my_integers[i] + my_integers[i+1];
  my_integers[i] = sum;
  Serial.print(my_integers[i]);
  Serial.print(" --> Index ");
  Serial.print(i);
  Serial.print( " now contains value ");
  Serial.println(my_integers[i]);
}  

}

void loop() {
  // put your main code here, to run repeatedly:

}
