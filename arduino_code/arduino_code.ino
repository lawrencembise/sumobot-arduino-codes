#include <Ultrasonic.h>
#include <Servo.h> 

Servo myservo1;  // create servo variable to control servo 1  LEFT
Servo myservo2;  // create servo variable to control servo 2  RIGHT

Ultrasonic ultrasonic(3,2);


#define IR_sensor_front A0 
#define IR_sensor_back A1 
int distance ;

void setup() 
{
Serial.begin(9600);
 myservo1.attach(4);  // servo 1 on DIGITAL pin 3 LEFT
 myservo2.attach(5);  // servo 2 on DIGITAL pin 4 RIGHT
 
delay (5000); 
}
void loop()
{
  
 int IR_front = analogRead(IR_sensor_front);
 int IR_back = analogRead(IR_sensor_back);
 distance = ultrasonic.read();
 ROTATE(); // start rotete if (distance < 20){
    while (distance < 20 ) {
    FORWARD(); 
    distance = ultrasonic.read();
    IR_front = analogRead(IR_sensor_front);
    IR_back = analogRead(IR_sensor_back);
    if ( IR_front > 650 || IR_back > 650 ) { break;}
    delay(10); }
  
  
 if (IR_front > 650 )  //white line
   {
   Stop();
   delay (50);
   BACKWARD();
   delay (500);
   } 
   
 if (IR_back > 650 )  //
   {
   Stop();
   delay (50);
   FORWARD();
   delay (500);
   }
   
//    ----------- debugging ----------------
  Serial.print(ultrasonic.read());
  Serial.println("cm");
  Serial.println("IR front :");
  Serial.println(IR_front); 
  Serial.println("IR back :");
  Serial.println(IR_back);  


} //--------------------------------------------
void FORWARD (){
  //When we want to let Motor To move forward,
  // just void this part on the loop section .
    myservo1.write(180);     // FULL SPEED AHEAD!  
    myservo2.write(0);       // FULL SPEED AHEAD!      
}//--------------------------------------------
void BACKWARD (){
  //When we want to let Motor To move forward,
  // just void this part on the loop section .
      myservo1.write(78);    
      myservo2.write(98);         
}//--------------------------------------------
void ROTATE ()
{
  //When we want to let Motor To Rotate ,
  // just void this part on the loop section .
    myservo1.write(97);  
    myservo2.write(85); 
}//--------------------------------------------
void Stop(){
  //When we want to  Motor To stop ,
  // just void this part on the loop section .
   myservo1.write(90);     
    myservo2.write(90); 
}
