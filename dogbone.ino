#include <IcsHardSerialClass.h>

const byte EN_PIN = 2;//サーボモーターENABLEピンの設定
const long BAUDRATE = 115200;//シリアル通信速度の設定
const int TIMEOUT = 1000;    //通信できてないか確認用にわざと遅めに設定

IcsHardSerialClass krs(&Serial, EN_PIN, BAUDRATE, TIMEOUT); //インスタンス＋ENピン(2番ピン)およびUARTの指定
int wait;
int servoflag;

void setup() {
  krs.begin();  //サーボモータの通信初期設定
}

void loop() {
  int A0val = analogRead(A0);//加速度センサー
  int A1val = analogRead(A1);//フォース1
  int A2val = analogRead(A2);//フォース2
  int A3val = analogRead(A3);//フォース3
  int A4val = analogRead(A4);//フォース4
  int A5val = analogRead(A5);//フォース5

  if (A0val > 340) {
    wait++;
    delay (1);
    if (wait == 1000) {
      servoflag = 1;
    }
  }

  if (A1val > 100) {
    wait++;
    delay (1);
    if (wait == 1000) {
      servoflag = 1;
    }
  }
  if (A2val > 100) {
    wait++;
    delay (1);
    if (wait == 1000) {
      servoflag = 1;
    }
  }
  if (A3val > 100) {
    wait++;
    delay (1);
    if (wait == 1000) {
      servoflag = 1;
    }
  }
  if (A4val > 100) {
    wait++;
    delay (1);
    if (wait == 1000) {
      servoflag = 1;
    }
  }
  if (A5val > 100) {
    wait++;
    delay (1);
    if (wait == 1000) {
      servoflag = 1;
    }
  }
  if (servoflag == 1) {
    krs.setPos(0, 9500);     //位置指令　ID:0サーボを9500へ 右
    delay(3000);
    servoflag = 0;
    wait = 0;
    krs.setPos(0, 7500);
    delay(3000);
    krs.setPos(0, 7400);
    delay(10000);
  } else {
    krs.setPos(0, 7500);
  }
}
