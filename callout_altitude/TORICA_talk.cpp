#include "TORICA_talk.h"
#include <Arduino.h>
#include <Wire.h>


TORICA_talk speaker;//質問（このクラスオブジェクトの生成をしないとしたのCONVERT_numでtalk_strが使えないのではないか？）


void COVERT_num(int num){

  char str[];
  sprintf(str,"<NUM VAL=%d>",num);
  speaker.talk_str(str);// メンバ関数の呼び出しのように　クラス名.関数名　でＯＫ？？
  
}




/*talk_str関数の定義づけ
TORICA＿talkと呼ばれるクラスにtalk_str（メンバ関数）は所属していなければならない*/

void TORICA_talk::talk_str(char str[]){
  
  Wire1.beginTransmission(0x2E); // スタートとスレーブアドレスを送る役割　（swの役割）
  
  Wire1.write(str,strlen(str)*sizeof(char)); 
  Wire1.write('\n'); 

  Wire1.endTransmission();    // stop transmitting
}

 //sprintf(x);//文字列を作る←数値を文字列に変換することで文字列のまま読むことができる
  