#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Servo.h>

// Thiết lập thông số cho WiFi
const char* ssid = "ABCXYZ";
const char* password = "11008565";

// Khởi tạo đối tượng máy chủ web
ESP8266WebServer server(80);


#define HongNgoaiIn 4
#define HongNgoaiOut 0
#define SERVO_IN 16
#define SERVO_OUT 5

#define SS_PIN 10
#define RST_PIN 9

Servo servoIn;
Servo servoOut;

int Slot = 4;

  // Xử lý vận hành Servo ở đây, dựa trên tham số được truyền (eg)
void handleServoIn() {
  Slot = Slot - 1;
  Serial.println("servo in");
  servoIn.write(180);
  delay(5000);
  servoIn.write(0);
  delay(1000);
  server.send(200, "text/plain", "Servo da duoc dieu khien");
}

  // Xử lý vận hành Servo ở đây, dựa trên tham số được truyền (eg)
void handleServoOut() {
  Slot = Slot + 1;
  Serial.println("servo out");
  servoOut.write(180);
  delay(5000);
  servoOut.write(0);
  delay(1000);
  server.send(200, "text/plain", "Servo da duoc dieu khien");
}


void handleHongngoaiIn() {
  // Đọc nhiệt độ từ cảm biến DHT
  int valueIn = digitalRead(HongNgoaiIn);
  Serial.println(valueIn);
  if (isnan(valueIn)) {
    server.send(500, "text/plain", "Loi doc cam bien");
  } else {
    server.send(200, "text/plain", String(valueIn));
  }
}

void handleSlot() {
  // Đọc nhiệt độ từ cảm biến DHT
  Serial.println(Slot);
  if (isnan(Slot)) {
    server.send(500, "text/plain", "Loi doc cam bien");
  } else {
    server.send(200, "text/plain", String(Slot));
  }
}

void handleHongngoaiOut() {
  // Đọc nhiệt độ từ cảm biến DHT
  int valueOut = digitalRead(HongNgoaiOut);
  Serial.println(valueOut);
  if (isnan(valueOut)) {
    server.send(500, "text/plain", "Loi doc cam bien");
  } else {
    server.send(200, "text/plain", String(valueOut));
  }
}


void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, password);
  Serial.println("Kết nối đến WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Đã kết nối thành công!");

  server.on("/servoIn", handleServoIn);
  server.on("/servoOut", handleServoOut);
  server.on("/hongNgoaiIn", handleHongngoaiIn);
  server.on("/hongNgoaiOut", handleHongngoaiOut);
  server.on("/Slot", handleSlot);

  server.enableCORS(true);
  server.begin();
  Serial.println("Server started");
  Serial.print("IP Address of network: "); 
  Serial.println(WiFi.localIP());
  Serial.print("Copy and paste the following URL: https://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

  servoIn.attach(SERVO_IN);
  servoIn.write(0);
  servoOut.attach(SERVO_OUT);
  servoOut.write(0);

}

void loop() {
  //Slot = 0;
  //Serial.print(Slot);
  server.handleClient(); 
}
