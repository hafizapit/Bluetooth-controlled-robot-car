/*
 * Code Modified By: Mohamad Hafiz Bin Ahmad
 * Email: hafiz_apik99@yahoo.com
 * Youtube: https://www.youtube.com/channel/UC15t8HwKsRL2lTeP8uZlUjQ
*/
#include <SoftwareSerial.h>
#include <CytronMotorDriver.h> // https://github.com/CytronTechnologies/CytronMotorDriver 

// tetapan motor driver.
CytronMD motor1(PWM_PWM, 3, 4);   // PWM 1A = Pin 3, PWM 1B = Pin 4. Kalau motor pusing terbalik, tukarkan PWM 1A = Pin 4, PWM 1B = Pin 3
CytronMD motor2(PWM_PWM, 5, 6); // PWM 2A = Pin 5, PWM 2B = Pin 6. Kalau motor pusing terbalik, tukarkan PWM 2A = Pin 6,PWM 2B = Pin 5

char t;

void setup() 
{
  
Serial.begin(9600);
 
}
 
void loop() 
{
    if(Serial.available())
    {
      t = Serial.read();
      Serial.println(t);
    }
      
         if(t == 'F') //gerak kehadapan    
         {                 
          Serial.println("Forward");
          motor1.setSpeed(255);   // Motor 1 runs forward at 50% speed.
          motor2.setSpeed(255);  // Motor 2 runs forward at 100% speed.
        }
         
        else if(t == 'G') //gerak ke belakang  
        {             
          Serial.println("backward");
          motor1.setSpeed(-255);   // Motor 1 runs backward at 100% speed.
          motor2.setSpeed(-255);  // Motor 2 runs backward at 50% speed.
          
        }
         
        else if(t == 'L') //pusing ke kiri 
        {                 
          Serial.println("left");
          motor1.setSpeed(0);   // Motor 1 stops.
          motor2.setSpeed(128);  // Motor 2 runs forward at 50% speed.
        }
         
        else if(t == 'R') //pusing ke kanan
        {                 
          Serial.println("right");
          motor1.setSpeed(128);   // Motor 1 runs forward at 50% speed.
          motor2.setSpeed(0);  // Motor 2 stops
        }

          else if(t== 'S')//berhenti  
          {
          Serial.println("stop");
          motor1.setSpeed(0);   
          motor2.setSpeed(0);   
          }
        delay(50);
     
}
