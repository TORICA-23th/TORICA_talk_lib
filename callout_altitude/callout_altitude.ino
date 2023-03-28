//高度を音声にして伝えるプログラム


#include <Wire.h>
#include "TORICA_talk.h"

TORICA_talk speaker; //クラスの変数定義(クラスのオブジェクト定義→メモリ上に)





void setup()
{
  Wire1.begin(); // join i2c bus (address optional for master)
}


void loop()
{

  speaker.talk_num(1232); //メンバ関数の呼び出しを行った
  delay(500);

}


//中身にsprintf(センサ読み取り関数（）)
/*　sprintf()を関数 CONVERT_numTostrで数字を文字列に変換する機構を作ることで複雑な関数の入れ子を防ぐ*/