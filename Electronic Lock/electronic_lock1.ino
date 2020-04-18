#include <Servo.h>



int buttonState = 0;


Servo servo_9;



void setup()
{


	servo_9.attach(9);
  

	pinMode(2, INPUT);
  

	pinMode(13, OUTPUT);


}



void loop()
{
  
  

	buttonState = digitalRead(2);
 
  

if (buttonState == HIGH) {
   
    

	digitalWrite(13, HIGH);
    

	servo_9.write(180);
  	

	delay(15); 
    
  

	} 

else {
    
    
	digitalWrite(13, LOW);
    
	servo_9.write(0);
    
	delay(15); 
 
   
  
	}
  
	
	delay(10); 

}