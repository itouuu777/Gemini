#include "SerialBT.h"

void setup() {
  Serial.begin(115200);
  SerialBT.begin();
/*pinMode(32, OUTPUT);
  digitalWrite(32, LOW);*/
  Serial.println("Waiting for Bluetooth data...");
}

void loop() {
  if (SerialBT.available()) {
    String receivedData = SerialBT.readStringUntil('\n'); // 改行までのデータを読み取る

    // 受信したデータを表示
    SerialBT.print("Received data: ");
    SerialBT.println(receivedData); // ここで改行区切りで受信データを出力
    int num = atoi(receivedData.c_str());

    //atoiによる文字数値判定
    if (num == 0){
      if(0x30 != receivedData[0]){
        SerialBT.println("string");
        num = receivedData[0];//文字
      }
      
    }

    SerialBT.println(num);
  /*  // LEDの制御
    if (receivedData == "s") {
      SerialBT.println("ECHO BACK >> LED ON");
      digitalWrite(32, HIGH);
    } else if (receivedData == "g") {
      SerialBT.println("ECHO BACK >> LED OFF");
      digitalWrite(32, LOW);
    }*/
  }
}
