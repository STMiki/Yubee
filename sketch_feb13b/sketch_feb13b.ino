#include <Servo.h>
Servo servo_bras;
Servo servo_clapet;

const int inter = 7;
int etat_inter = 0;
int degree_bras;

void setup() {
  // put your setup code here, to run once:
   pinMode(inter, INPUT);
   digitalWrite(inter, HIGH);
   servo_bras.attach(3);
   servo_bras.write(0);
   servo_clapet.attach(2);
   servo_clapet.write(0);
   Serial.begin(9600);

}

void bras_clapet_soft(int temp)
{
   servo_clapet.write(180);
   servo_bras.write(degree_bras);
   degree_bras++;
   delay(temp);  
}

void bras_clapet_2step(int degree, int temp)
  {
    servo_clapet.write(180);
    servo_bras.write(degree);
    degree++;
    if (degree >= 45)
      {
        temp = 10;    
      }
    else 
      {
        temp = 100;
      }
    delay(temp);    
  }

void loop() {

  Serial.println(etat_inter);
  etat_inter = digitalRead(inter);

  if (etat_inter == HIGH)
  {
   servo_clapet.write(180);
   servo_bras.write(degree_bras);
   degree_bras++;
       
  }
  else
  {
   servo_bras.write(0); 
   servo_clapet.write(0); 
   degree_bras = 0;
  }

}
