#include <avdweb_AnalogReadFast.h>

#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float input_volt = 0.0;
float temp=0.0;
bool GameOver = false;
int  counter = 15;
int barrelPosX = 0, Score = 0, number=0, solution=0;




byte barrel[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b11111,
  0b11111
};

byte EnemyLeft[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b11100,
  0b00100,
  0b00100,
  0b01010
};
byte EnemyRight[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b00111,
  0b00100,
  0b00100,
  0b01010
};

byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};

void setup() {
  ADCSRA = (ADCSRA & 0xf8) | 0x04;
  // initialize LCD and set up the number of columns and rows:
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.createChar(1,barrel);
  lcd.createChar(2,EnemyLeft);
  lcd.createChar(3, armsDown);
  lcd.createChar(4, armsUp);
  lcd.createChar(5,EnemyRight);
  delay(100);
  lcd.setCursor(15, 0);
  lcd.write(2);
  lcd.setCursor(15, 0);
  lcd.write(5);
}





void loop() {
  Serial.println(input_volt);
 if (GameOver == false){
   if(counter== 0){
   lcd.setCursor(15, 0);
   lcd.write(2);
   counter = 15;
   }
  while(counter!=0 && GameOver == false){    
       counter -=1;
        barrelPosX = counter;
      lcd.setCursor(15, 0);
      lcd.write(5);
      lcd.setCursor(counter-1, 1);
     lcd.write(1);
     lcd.setCursor(counter,1);
     lcd.write(" ");
      number = random(20,30);
     delay(number);
      solution = 0;    
     // for (int i = 0;i<49;i++){
      //input_volt = analogRead(A0);  //APO EDW DIABAZEI5-+`  15678
      //solution = input_volt + solution;
      //}
      //input_volt = solution/50 ; 
      //Serial.println(input_volt);
     input_volt = analogReadFast(A0);
     Serial.println(input_volt);
     if (input_volt >= 14.0)
     { 
       lcd.setCursor(0,1);
       lcd.print(" ");
       lcd.setCursor(0, 0);
       lcd.write(4);
      input_volt= 1.0;
      if(barrelPosX==0){
        Score+=1;  }
      delay(1500);
      input_volt = 3.0;
      
       
     }
    else if (input_volt<=1.0){
       lcd.setCursor(counter-1, 1);
            lcd.write(1);
            lcd.setCursor(counter,1);
            lcd.write(" ");
            delay(number);  
     if(barrelPosX==0){
      GameOver = true;
     }
     lcd.setCursor(0,0);
     lcd.print(" ");
     delay(250);
      lcd.setCursor(0, 1); // edw 8a mpei h funcAnim()
      lcd.write(3);     //
     }
  }
  if(counter==0){
  counter = 15;
  lcd.setCursor(15, 0);
   lcd.write(2);   
   delay(300); 
  }
}
else if(GameOver == true){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Game Over");
  lcd.setCursor(0,1);
  lcd.print(Score);
  delay(5000);
  lcd.clear();
  Score = 0;
  counter= 15;
  GameOver = false;
   lcd.setCursor(15, 0);
   lcd.write(2);
   delay(500);

 
}
 
}