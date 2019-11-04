#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4LCD lcd;
Zumo32U4ButtonA buttonA;
Zumo32U4ButtonB buttonB;
Zumo32U4ButtonC buttonC;
Zumo32U4Motors motors;
Zumo32U4LineSensors lineSensors;
Zumo32U4ProximitySensors proxSensors;


unsigned int lineSensorValues[5];
int16_t valornegro = 500;
int16_t velocidadgiro = 150;
char x=0;
int16_t velocidad=400;
int16_t tiempogiro=300;
int16_t tiempoatras = 300;


void setup()
{
  proxSensors.initFrontSensor();
 lineSensors.initFiveSensors();
 
  lcd.clear();
  lcd.gotoXY(0, 1);
  lcd.print("rv.JUMPR!");
  lcd.gotoXY(0, 0);
  lcd.print(F("  sumo"));
  
 // lcd.clear();
  /*motors.setSpeeds(200,200);
  delay(500);
  motors.setSpeeds(0,0);*/
}

  void giroderecha()
{
  motors.setSpeeds(velocidadgiro, -velocidadgiro);
 
}

void giroizquierda()
{
  motors.setSpeeds(-velocidadgiro, velocidadgiro);
  
}

void ataque()
{
  motors.setSpeeds(400,400);
 
}
void adelante()
{
  motors.setSpeeds(200,200);
}


void loop()
{
  if (buttonA.isPressed())
  {
    lcd.clear();
    lcd.gotoXY(0, 1);
    lcd.print("Modo A");
    delay(5000);
    while(1)
      {
      lineSensors.read(lineSensorValues);
        proxSensors.read();
      uint8_t izquierdo = proxSensors.countsFrontWithLeftLeds();
      uint8_t derecho = proxSensors.countsFrontWithRightLeds();
    
    if (derecho>izquierdo&&izquierdo>2)
    {
      giroderecha();
    } else if (izquierdo>derecho&&derecho>2)
    {
      giroizquierda();
    } else if (derecho==izquierdo&&derecho<5&&lineSensorValues[0]>valornegro&&lineSensorValues[4]>valornegro)
    {
      adelante();
    }else if (derecho>=5&&izquierdo==derecho)
      {
         
        while(1){
          lineSensors.read(lineSensorValues);
        
    
      
          if (lineSensorValues[1]<valornegro)
            {
             
              motors.setSpeeds(-velocidad,100-velocidad);
              delay(tiempoatras);
          /*    motors.setSpeeds(velocidadgiro+100, -(velocidadgiro+100));
              delay(tiempogiro);*/
              x=0;
              break;
            
            } else if (lineSensorValues[3]<valornegro)
            {
               motors.setSpeeds(100-velocidad, -velocidad);
              delay(tiempoatras);
            /*  motors.setSpeeds(-(velocidadgiro+100), velocidadgiro+100);
              delay(tiempogiro);*/
              x=0;
              break;
          
            } else {
                    ataque();
            }
     
        }
      }else
      {
        giroderecha();
      }
      if (lineSensorValues[0]<valornegro)
        {
         
          motors.setSpeeds(-velocidad,100-velocidad);
          delay(tiempoatras);
          motors.setSpeeds(velocidadgiro+100, -(velocidadgiro+100));
          delay(tiempogiro);
          
        
        } else if (lineSensorValues[4]<valornegro)
        {
           motors.setSpeeds(100-velocidad, -velocidad);
          delay(tiempoatras);
          motors.setSpeeds(-(velocidadgiro+100), velocidadgiro+100);
          delay(tiempogiro);
              
          
            }
      
        lcd.gotoXY(0, 0);
        lcd.print(izquierdo);
        lcd.print(' ');
        lcd.print(derecho);
      }
  }
  if (buttonB.isPressed())
  {
    lcd.clear();
     lcd.gotoXY(0, 1);
    lcd.print("Modo B");
    delay(5000);
    motors.setSpeeds(400,-400);
    delay(162);
    while(1)
      {
      lineSensors.read(lineSensorValues);
        proxSensors.read();
      uint8_t izquierdo = proxSensors.countsFrontWithLeftLeds();
      uint8_t derecho = proxSensors.countsFrontWithRightLeds();
    
    if (derecho>izquierdo&&izquierdo>2)
    {
      giroderecha();
    } else if (izquierdo>derecho&&derecho>2)
    {
      giroizquierda();
    } else if (derecho==izquierdo&&derecho<5&&lineSensorValues[0]>valornegro&&lineSensorValues[4]>valornegro)
    {
      adelante();
    }else if (derecho>=5&&izquierdo==derecho)
      {
         
        while(1){
          lineSensors.read(lineSensorValues);
        
    
      
          if (lineSensorValues[1]<valornegro)
            {
             
              motors.setSpeeds(-velocidad,100-velocidad);
              delay(tiempoatras);
          /*    motors.setSpeeds(velocidadgiro+100, -(velocidadgiro+100));
              delay(tiempogiro);*/
              x=0;
              break;
            
            } else if (lineSensorValues[3]<valornegro)
            {
               motors.setSpeeds(100-velocidad, -velocidad);
              delay(tiempoatras);
            /*  motors.setSpeeds(-(velocidadgiro+100), velocidadgiro+100);
              delay(tiempogiro);*/
              x=0;
              break;
          
            } else {
                    ataque();
            }
     
        }
      }else
      {
        giroderecha();
      }
      if (lineSensorValues[0]<valornegro)
        {
         
          motors.setSpeeds(-velocidad,100-velocidad);
          delay(tiempoatras);
          motors.setSpeeds(velocidadgiro+100, -(velocidadgiro+100));
          delay(tiempogiro);
          
        
        } else if (lineSensorValues[4]<valornegro)
        {
           motors.setSpeeds(100-velocidad, -velocidad);
          delay(tiempoatras);
          motors.setSpeeds(-(velocidadgiro+100), velocidadgiro+100);
          delay(tiempogiro);
              
          
            }
      
        lcd.gotoXY(0, 0);
        lcd.print(izquierdo);
        lcd.print(' ');
        lcd.print(derecho);
      }
  }
  if (buttonC.isPressed())
  {
    lcd.clear();
  lcd.gotoXY(0, 1);
  lcd.print("Modo C");
    delay(5000);
    motors.setSpeeds(400,-400);
    delay(325);
    while(1)
      {
      lineSensors.read(lineSensorValues);
        proxSensors.read();
      uint8_t izquierdo = proxSensors.countsFrontWithLeftLeds();
      uint8_t derecho = proxSensors.countsFrontWithRightLeds();
    
    if (derecho>izquierdo&&izquierdo>2)
    {
      giroderecha();
    } else if (izquierdo>derecho&&derecho>2)
    {
      giroizquierda();
    } else if (derecho==izquierdo&&derecho<5&&lineSensorValues[0]>valornegro&&lineSensorValues[4]>valornegro)
    {
      adelante();
    }else if (derecho>=5&&izquierdo==derecho)
      {
         
        while(1){
          lineSensors.read(lineSensorValues);
        
    
      
          if (lineSensorValues[1]<valornegro)
            {
             
              motors.setSpeeds(-velocidad,100-velocidad);
              delay(tiempoatras);
          /*    motors.setSpeeds(velocidadgiro+100, -(velocidadgiro+100));
              delay(tiempogiro);*/
              x=0;
              break;
            
            } else if (lineSensorValues[3]<valornegro)
            {
               motors.setSpeeds(100-velocidad, -velocidad);
              delay(tiempoatras);
            /*  motors.setSpeeds(-(velocidadgiro+100), velocidadgiro+100);
              delay(tiempogiro);*/
              x=0;
              break;
          
            } else {
                    ataque();
            }
     
        }
      }else
      {
        giroderecha();
      }
      if (lineSensorValues[0]<valornegro)
        {
         
          motors.setSpeeds(-velocidad,100-velocidad);
          delay(tiempoatras);
          motors.setSpeeds(velocidadgiro+100, -(velocidadgiro+100));
          delay(tiempogiro);
          
        
        } else if (lineSensorValues[4]<valornegro)
        {
           motors.setSpeeds(100-velocidad, -velocidad);
          delay(tiempoatras);
          motors.setSpeeds(-(velocidadgiro+100), velocidadgiro+100);
          delay(tiempogiro);
              
          
            }
      
        lcd.gotoXY(0, 0);
        lcd.print(izquierdo);
        lcd.print(' ');
        lcd.print(derecho);
      }
  }
}
