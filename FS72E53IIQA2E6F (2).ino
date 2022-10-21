/*
Music Reactive Color Changing Lights
Source code
Made by- Saiyam Agrawal
*/
int threshold = 20;

void setup()
{
  pinMode(9, OUTPUT); // set all the pins as output
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() 
{  // enter the loop
 if(analogRead(A0) > threshold) // check if audio signal goes above threshold
 {
   int a = random(1, 6); // store a random number
   
   if(a == 1) // glow red
   {
     digitalWrite(9, HIGH);
     digitalWrite(10, LOW);
     digitalWrite(11, LOW);
   }
   if(a == 2) // glow green
   {
     digitalWrite(9, 0);
     digitalWrite(10, 1);
     digitalWrite(11, 0);
   }
   if(a == 3) // glow orange
   {
     analogWrite(9, random(100, 255));
     analogWrite(10, random(100, 255));
     digitalWrite(11, 0);
   }
   if(a == 4) // glow cyan
   {
     digitalWrite(9, 0);
     analogWrite(10, random(100, 255));
     analogWrite(11, random(100, 255));
   }
   if(a == 5) // glow purple
   {
     analogWrite(9, random(100, 255));
     digitalWrite(10, 0);
     analogWrite(11, random(100, 255));
   }
   if(a == 6) glow blue
   {
     digitalWrite(9, 0);
     digitalWrite(10, 0);
     digitalWrite(11, 1);
   }
   delay(20); // wait for 20ms
 }
 else
 digitalWrite(9, LOW); // if audio signal is less than 20, set all the pins low
 digitalWrite(10, LOW);
 digitalWrite(11, LOW);
 // again reach the top and start
}
