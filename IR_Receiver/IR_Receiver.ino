#include "IRremote.h"
int receiver = 10; // Signal Pin of IR receiver to Arduino Digital Pin 10
int led = 13;
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

// take action corresponding to the remote control button pressed
void actionIR() {
  switch(results.value) {
    case 0xFFA25D: Serial.println("POWER");         break;  //POWER
    case 0xFFE21D: Serial.println("FUNC/STOP");     break;  //FUNC/STOP
    case 0xFF629D: Serial.println("VOL+");          break;  //VOL+
    case 0xFF22DD: Serial.println("FAST BACK");     break;  //FAST BACK
    case 0xFF02FD: Serial.println("PAUSE");         break;  //PAUSE
    case 0xFFC23D: Serial.println("FAST FORWARD");  break;  //FAST FORWARD
    case 0xFFE01F: Serial.println("DOWN");          break;  //DOWN
    case 0xFFA857: Serial.println("VOL-");          break;  //VOL-
    case 0xFF906F: Serial.println("UP");            break;  //UP
    case 0xFF9867: Serial.println("EQ");            break;  //EQ
    case 0xFFB04F: Serial.println("ST/REPT");       break;  //ST/REPT
    case 0xFF6897: digitalWrite(led, LOW); Serial.println("0");             break;  //0
    case 0xFF30CF: digitalWrite(led, HIGH);Serial.println("1");             break;  //1
    case 0xFF18E7: Serial.println("2");             break;  //2
    case 0xFF7A85: Serial.println("3");             break;  //3
    case 0xFF10EF: Serial.println("4");             break;  //4
    case 0xFF38C7: Serial.println("5");             break;  //5
    case 0xFF5AA5: Serial.println("6");             break;  //6
    case 0xFF42BD: Serial.println("7");             break;  //7
    case 0xFF4AB5: Serial.println("8");             break;  //8
    case 0xFF52AD: Serial.println("9");             break;  //9
    case 0xFFFFFFFF: Serial.println(" REPEAT");     break;  //REPEAT
    default: 
      Serial.println(" other button : ");
      Serial.println(results.value);
  }// End Case
  delay(500); // Do not get immediate repeat
}

void setup() {
  Serial.begin(19200);
  Serial.println("Welcome to EECE 1208");
  irrecv.enableIRIn(); // Start the receiver
  pinMode(led, OUTPUT); 
}
  void loop() {
  // have we received an IR signal?
  if (irrecv.decode(&results)) {
    actionIR(); 
    irrecv.resume(); // receive the next value

  }  
}
