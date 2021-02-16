#include <LiquidCrystal.h>
LiquidCrystal lcd(45,255, 47, 46, 48, 49, 50,51); // Sets pins for RS, E2, E1, d4-7
const int selectPins[3] = {35, 36, 37};
const int selectPins1[3] = {38, 39, 40};
const int selectPins2[3] = {41, 42, 43};
int switchPin = 8;
int Display = 0;
float VValue;
float VValue1;
float VValue2;
float VValue3;
float VValue4;
float VValue5;
float VValue6;
float VValue7;
float VValue8;
float VValue9;
float VValue10;
float VValue11;
float VValue12;
float VValue13;
float VValue14;
float VValue15;
float VValue16;
float VValue17;
float VValue18;
float VValue19;
int FRO = 2;          
int REA = 3;          
int AUX = 4;          
int AQS = 5;          
int CDS = 6;
int PTC = 7;
int PWM = 0;
int PWM1 = 0;
int PWM2 = 0;
int PWM3 = 0;
int PWM4 = 0;
int PWM5 = 0;
int ontime1 = 0;
int ontime2 = 0;
int ontime3 = 0;
int ontime4 = 0;
int ontime5 = 0;
int ontime6 = 0;
int offtime1 = 0;
int offtime2 = 0;
int offtime3 = 0;
int offtime4 = 0;
int offtime5 = 0;
int offtime6 = 0;
int duty1 = 0;
int duty2 = 0;
int duty3 = 0;
int duty4 = 0;
int duty5 = 0;
int duty6 = 0;
float period1;          
float period2;
float period3;
float period4;
float period5;
float period6;
int currState = 0;
int prevState = 0;
float voltage = 0;

void setup() {
  // put your setup code here, to run once:
lcd.begin(40,4);
lcd.clear();
  for (int i=0; i<3; i++)
  {
    pinMode(selectPins[i], OUTPUT);
    digitalWrite(selectPins[i], HIGH);
  }
    for (int i=0; i<3; i++)
  {
    pinMode(selectPins1[i], OUTPUT);
    digitalWrite(selectPins1[i], HIGH);
  }
    for (int i=0; i<3; i++)
  {
    pinMode(selectPins2[i], OUTPUT);
    digitalWrite(selectPins2[i], HIGH);
  }
   pinMode(switchPin, INPUT);
   digitalWrite(switchPin, LOW);
}

void selectMuxPin(byte pin)
{
  for (int i=0; i<3; i++)
  {
    if (pin & (1<<i))
      digitalWrite(selectPins[i], HIGH);
    else
      digitalWrite(selectPins[i], LOW);
  }
}
void selectMuxPin1(byte pin)
{
  for (int i=0; i<3; i++)
  {
    if (pin & (1<<i))
      digitalWrite(selectPins1[i], HIGH);
    else
      digitalWrite(selectPins1[i], LOW);
  }
}
void selectMuxPin2(byte pin)
{
  for (int i=0; i<3; i++)
  {
    if (pin & (1<<i))
      digitalWrite(selectPins2[i], HIGH);
    else
      digitalWrite(selectPins2[i], LOW);
  }
}
void Screen1(){
    selectMuxPin(0); // Select one at a time
    int inputValue = analogRead(A0);
    float VValue = inputValue * (5.0/1023.0);// and read Z
  delay(20);
   selectMuxPin(1); // Select one at a time
    int inputValue1 = analogRead(A0);
    float VValue1 = inputValue1 * (5.0/1023.0);// and read Z
  delay(20);
   selectMuxPin(2); // Select one at a time
    int inputValue2 = analogRead(A0);
    float VValue2 = inputValue2 * (5.0/1023.0);// and read Z
  delay(20); 
  selectMuxPin(3); // Select one at a time
    int inputValue3 = analogRead(A0);
    float VValue3 = inputValue3 * (5.0/1023.0);// and read Z
  delay(20); 
  selectMuxPin(4); // Select one at a time
    int inputValue4 = analogRead(A0);
    float VValue4 = inputValue4 * (5.0/1023.0);// and read Z
  delay(20); 
  selectMuxPin(5); // Select one at a time
    int inputValue5 = analogRead(A0);
    float VValue5 = inputValue5 * (5.0/1023.0);// and read Z
  delay(20); 
  selectMuxPin(6); // Select one at a time
    int inputValue6 = analogRead(A0);
    float VValue6 = inputValue6 * (5.0/1023.0);// and read Z
  delay(20); 
  selectMuxPin(7); // Select one at a time
    int inputValue7 = analogRead(A0);
    float VValue7 = inputValue7 * (5.0/1023.0);// and read Z
  delay(20);
  lcd.setCursor(0,0);
  lcd.print("Foot Duct-Fr L:");
  lcd.print(VValue);
  lcd.print("V");
  lcd.setCursor(22,0);
  lcd.print("Fr R:");
  lcd.print(VValue1);
  lcd.print("V");
  lcd.setCursor(11,1);
  lcd.print("Re L:");
  lcd.print(VValue2);
  lcd.print("V");
  lcd.setCursor(22,1);
  lcd.print("Re R:");
  lcd.print(VValue3);
  lcd.print("V");
  lcd.setCursor(0,2);
  lcd.print("Face Duct-Fr L:");
  lcd.print(VValue4);
  lcd.print("V");
  lcd.setCursor(22,2);
  lcd.print("Fr R:");
  lcd.print(VValue5);
  lcd.print("V");
  lcd.setCursor(11,3);
  lcd.print("Re L:");
  lcd.print(VValue6);
  lcd.print("V");
  lcd.setCursor(22,3);
  lcd.print("Re R:");
  lcd.print(VValue7);
  lcd.print("V");
  delay(1000);
}

void Screen2(){
      selectMuxPin1(0); // Select one at a time
    int inputValue8 = analogRead(A1);
    float VValue8 = inputValue8 * (5.0/1023.0);// and read Z
  delay(20);
   selectMuxPin1(1); // Select one at a time
    int inputValue9 = analogRead(A1);
    float VValue9 = inputValue9 * (5.0/1023.0);// and read Z
  delay(20);
   selectMuxPin1(2); // Select one at a time
    int inputValue10 = analogRead(A1);
    float VValue10 = inputValue10 * (5.0/1023.0);// and read Z
  delay(20); 
  selectMuxPin1(3); // Select one at a time
    int inputValue11 = analogRead(A1);
    float VValue11 = inputValue11 * (5.0/1023.0);// and read Z
  delay(20); 
  selectMuxPin1(4); // Select one at a time
    int inputValue12 = analogRead(A1);
    float VValue12 = inputValue12 * (5.0/1023.0);// and read Z
  delay(50); 
  selectMuxPin1(5); // Select one at a time
    int inputValue13 = analogRead(A1);
    float VValue13 = inputValue13 * (5.0/1023.0);// and read Z
  delay(20); 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Solar- Fr L:");
  lcd.print(VValue8);
  lcd.print("V");
  lcd.setCursor(19,0);
  lcd.print("Fr R:");
  lcd.print(VValue9);
  lcd.print("V");
  lcd.setCursor(8,1);
  lcd.print("Re L:");
  lcd.print(VValue10);
  lcd.print("V");
  lcd.setCursor(19,1);
  lcd.print("Re R:");
  lcd.print(VValue11);
  lcd.print("V");
  lcd.setCursor(0,2);
  lcd.print("Air Intake Servo Position:");
  lcd.print(VValue12);
  lcd.print("V");
  lcd.setCursor(0,3);
  lcd.print("Upper In Car T/AC Dis T:");
  lcd.print(VValue13);
  lcd.print("V");  
}

void Screen3(){
      selectMuxPin2(0); // Select one at a time
    int inputValue14 = analogRead(A2);
    float VValue14 = inputValue14 * (5.0/1023.0);// and read Z
  delay(20);
   selectMuxPin2(1); // Select one at a time
    int inputValue15 = analogRead(A2);
    float VValue15 = inputValue15 * (5.0/1023.0);// and read Z
  delay(20);
   selectMuxPin2(2); // Select one at a time
    int inputValue16 = analogRead(A2);
    float VValue16 = inputValue16 * (5.0/1023.0);// and read Z
  delay(20); 
  selectMuxPin2(3); // Select one at a time
    int inputValue17 = analogRead(A2);
    float VValue17 = inputValue17 * (5.0/1023.0);// and read Z
  delay(20); 
  selectMuxPin2(4); // Select one at a time
    int inputValue18 = analogRead(A2);
    float VValue18 = inputValue18 * (5.0/1023.0);// and read Z
  delay(20); 
  selectMuxPin2(6); // Select one at a time
    int inputValue19 = analogRead(A2);
    float VValue19 = inputValue19 * (5.0/1023.0);// and read Z
  delay(20);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("AC Discharge p:");
  lcd.print(VValue14);
  lcd.print("V");
  lcd.setCursor(21,0);
  lcd.print("AC Suction p:");
  lcd.print(VValue15);
  lcd.print("V");
  lcd.setCursor(0,1);
  lcd.print("Front In Car T:");
  lcd.print(VValue16);
  lcd.print("V");
  lcd.setCursor(21,1);
  lcd.print("Front Evap T:");
  lcd.print(VValue17);
  lcd.print("V");
  lcd.setCursor(0,2);
  lcd.print("Rear Evap T/Powertrain Refrig T:");
  lcd.print(VValue18);
  lcd.print("V");
  lcd.setCursor(0,3);
  lcd.print("Evap Superheat T/AC Suction T:");
  lcd.print(VValue19);
  lcd.print("V");  

}

void PWMScreen(){
  PWM = analogRead(A8);        //reads value from pot (0-1023)
  PWM=PWM*(255.0/1023.0);      //converts value from (0-1023) to (0-255) for analogWrite function
  analogWrite(FRO, PWM);
  delay(20);//sends signal out through output pin 
  PWM1 = analogRead(A9);        
  PWM1=PWM1*(255.0/1023.0);      
  analogWrite(REA, PWM1);
  delay(20);       
  PWM2 = analogRead(A10);        
  PWM2=PWM2*(255.0/1023.0);      
  analogWrite(AUX, PWM2); 
  delay(20);       
  PWM3 = analogRead(A11);        
  PWM3=PWM3*(255.0/1023.0);      
  analogWrite(AQS, PWM3); 
  delay(20);      
  PWM4 = analogRead(A12);        
  PWM4=PWM4*(255.0/1023.0);      
  analogWrite(CDS, PWM4); 
  delay(20);      
  PWM5 = analogRead(A13);        
  PWM5=PWM5*(255.0/1023.0);      
  analogWrite(PTC, PWM5);
  delay(20);
  ontime1 = pulseIn(FRO, HIGH);
  ontime2 = pulseIn(REA, HIGH);
  ontime3 = pulseIn(AUX, HIGH);
  ontime4 = pulseIn(AQS, HIGH);
  ontime5 = pulseIn(CDS, HIGH);
  ontime6 = pulseIn(PTC, HIGH);
  offtime1 = pulseIn(FRO, LOW);
  offtime2 = pulseIn(REA, LOW);
  offtime3 = pulseIn(AUX, LOW);
  offtime4 = pulseIn(AQS, LOW);
  offtime5 = pulseIn(CDS, LOW);
  offtime6 = pulseIn(PTC, LOW);
  period1 = ontime1 + offtime1;
  period2 = ontime2 + offtime2;
  period3 = ontime3 + offtime3;
  period4 = ontime4 + offtime4;
  period5 = ontime5 + offtime5;
  period6 = ontime6 + offtime6;
  duty1 = (ontime1/period1)*100;
  duty2 = (ontime2/period2)*100;
  duty3 = (ontime3/period3)*100;
  duty4 = (ontime4/period4)*100;
  duty5 = (ontime5/period5)*100;
  duty6 = (ontime6/period6)*100;
  lcd.clear();
  lcd.setCursor(0,0);  
  lcd.print("Blowers- Front:");
  lcd.print(duty1);
  lcd.print("%");
  lcd.setCursor(20,0);
  lcd.print("Rear:");
  lcd.print(duty2);
  lcd.print("%");
  lcd.setCursor(29,0);
  lcd.print("Aux:");
  lcd.print(duty3);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("AQS Sensor:");
  lcd.print(duty4);
  lcd.print("%");
  lcd.setCursor(0,2);
  lcd.print("A/C Solenoid:");
  lcd.print(duty5);
  lcd.print("%");
  lcd.setCursor(0,3);
  lcd.print("PTC/Cabin Heat Water Pump:");
  lcd.print(duty6);
  lcd.print("%");
  delay(200);
}

  
  




void loop()
{
currState = digitalRead(switchPin);
 if (currState != prevState){  
   delay(100);                        // delay to debounce switch

   Display ++;
   if(Display > 4){
     lcd.clear();
     Display = 1;
   }
   }
   if(Display==1){
    Screen1();
   }
   if(Display==2){
    Screen2();
   }
   if(Display==3){
    Screen3();
   }
   if(Display==4){
    PWMScreen();
   }
   }

