/*問題点　最後のP（ストップコンディション）の前に[CR](\r)を
入れなくてはならないため、最後の文章は別にする必要あり？
もしくは
　talk_str("ko'udowa,<NUMK VAL=10>/me'-'toru+de_su");
この方法で10の部分を変化さることで1文で済ませる

*/


#include <Arduino.h>
#include <Wire.h>

int altitude = 10, velocity = 5; 

void talk_str(char str[]){
  Wire.beginTransmission(0x2E); // スタートとスレーブアドレスを送る役割　（swの役割）
  
  Wire.write(str,strlen(str)*sizeof(char)); 

  Wire.endTransmission();  // stop transmitting
}


void talk_num(int num){

  char str[64];
  sprintf(str,"<NUMK VAL=%d>",num);
  talk_str(str);  // メンバ関数の呼び出しのように　クラス名.関数名　でＯＫ？？
  
}

void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
    delay(500);
}


void loop()
{
  /*Wire.beginTransmission(0x2E); // スタートとスレーブアドレスを送る役割　（swの役割）
  
  Wire.write("<NUMK VAL=1000>"); 
  Wire.write('\r'); 

  Wire.endTransmission();   */
  //talk_str("ko'udowa,<NUMK VAL=10>/me'-'toru+de_su");
  talk_str("koudowa");
  talk_num(altitude);

  Wire.beginTransmission(0x2E); // スタートとスレーブアドレスを送る役割　（swの役割）
  
  Wire.write("de_su"); 
  Wire.write('\r'); 
  Wire.endTransmission();  
 
   delay(500);
  
  
}

