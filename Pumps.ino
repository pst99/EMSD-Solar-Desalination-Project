
/************************************************
// Name：4 channel_relay
// Description: control the 4 channel relay module to ON or OFF
// Website: www.handsontec.com
// Email: techsupport@handsontec.com
*****************************************************/
//the relays connect to
int RelayControl1 = 4; // Digital Arduino Pin used to control the motor
int RelayControl2 = 5;
int RelayControl3 = 6;
int RelayControl4 = 7;
void setup()
{
   Serial.begin(9600);
   pinMode(RelayControl1, OUTPUT);
   pinMode(RelayControl2, OUTPUT);
   pinMode(RelayControl3, OUTPUT);
   pinMode(RelayControl4, OUTPUT);
   turnOffMotors();
}

void turnOffMotors(){
   digitalWrite(RelayControl1,HIGH);
   digitalWrite(RelayControl2,HIGH);
   digitalWrite(RelayControl3,HIGH);
   digitalWrite(RelayControl4,HIGH);
}

void loop()
{
   turnOffMotors();
   Serial.println("Which motor would you like to turn on?");  
   while (Serial.available() == 0){   
   } //Wait for user input
   
   int motorChoice = Serial.parseInt();
   
   switch(motorChoice){
    
   case 1:
      Serial.println("Motor 1 turning on...");
      digitalWrite(RelayControl1,LOW);
      break;

   case 2:
      Serial.println("Motor 2 turning on...");
      digitalWrite(RelayControl2,LOW);
      break;

   case 3:
      Serial.println("Motor 3 turning on...");
      digitalWrite(RelayControl3,LOW);
      break;

   case 4:
      Serial.println("Motor 4 turning on...");
      digitalWrite(RelayControl4,LOW);
      break;

   default:
      Serial.println("Please choose valid selection");
      break;
   }
   
   Serial.println(" ");  
   delay(10000);
}
