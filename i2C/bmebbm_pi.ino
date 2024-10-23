
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25) // 海面気圧（hPa）

Adafruit_BME280 bme;

void setup() {
  Serial.begin(9600);

  // I2C1の初期化 (SDA1 = GPIO6, SCL1 = GPIO7)
  Wire1.setSDA(14);  // SDA1をGPIO6に設定
  Wire1.setSCL(15);  // SCL1をGPIO7に設定
  Wire1.begin();    // I2C1を開始

  if (!bme.begin(0x77, &Wire1)) {  // I2C1バスを使用するようにWire1を渡す
    Serial.println("BME280センサーが見つかりません。配線を確認してください！");
    while (1);
  }
}

void loop() {
  /*Serial.print("温度 = ");
  Serial.print(bme.readTemperature());
  Serial.println(" °C");

  Serial.print("湿度 = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");*/

  Serial.print("気圧 = ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  /*Serial.print("高度 = ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" メートル");*/

  delay(2000); // 2秒待機
}
