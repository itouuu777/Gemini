#include <Adafruit_TinyUSB.h>

Adafruit_USBD_BLE ble;
BLEConnection* connection;

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    delay(10); // シリアルポートが接続されるまで待つ
  }
  
  // BLE初期化
  if (!ble.begin()) {
    Serial.println("Failed to start BLE");
    while (1);
  }
  
  ble.setDeviceName("PicoW_BLE_Client");
  Serial.println("BLE client initialized, searching for server...");

  // サーバーと接続を試みる
  connection = ble.connect("PicoW_BLE_Server");
  if (connection) {
    Serial.println("Connected to BLE server");
  } else {
    Serial.println("Failed to connect to server");
    while (1);
  }
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();

    if (command == '1') {
      Serial.println("Sending command: LED ON");
      // サーバーにLED ONの値を送信
      connection->write(1); 
    } else if (command == '0') {
      Serial.println("Sending command: LED OFF");
      // サーバーにLED OFFの値を送信
      connection->write(0);
    }
  }

  // BLE接続の維持
  ble.loop();
}
