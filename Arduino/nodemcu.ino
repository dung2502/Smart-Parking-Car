#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Servo.h>
#include <SPI.h>
#include <Wire.h>                 //Thư viện giao tiếp I2C
#include <LiquidCrystal_I2C.h>    //Thư viện LCD
LiquidCrystal_I2C lcd(0x3F,16,2);

// Thiết lập thông số cho WiFi
const char* ssid = "ABCXYZ";
const char* password = "11008565";

// Khởi tạo đối tượng máy chủ web
ESP8266WebServer server(80);



void handleLCDIn() {
  if (server.hasArg("carIdIn")) {
    String carIdIn = server.arg("carIdIn");
    lcd.clear();
    lcd.setCursor (0,0);
    lcd.print("    WELCOME!    ");
    lcd.setCursor (0,1);
    lcd.print("CARID: " + carIdIn);
    server.send(200, "text/plain", "lcd da dc dieu khien");
  } else {
    server.send(400, "text/plain", "Thieu tham so cho lcd");
  }
  delay(5000);
  //lcd.clear();
}

void handleLCDOut() {
  if (server.hasArg("carIdOut")) {
    String carIdOut = server.arg("carIdOut");
    String cost = server.arg("cost");
    lcd.clear();
    lcd.setCursor (0,0);
    lcd.print("CARID: " + carIdOut);
    lcd.setCursor (0,1);
    lcd.print("Cost " + cost);
    delay(5000);
    lcd.clear();
    lcd.setCursor (0,0);
    lcd.print("Cam on quy khach");
    lcd.setCursor (0,1);
    lcd.print("   ArigaThank <3");
    server.send(200, "text/plain", "lcd da dc dieu khien");
  } else {
    server.send(400, "text/plain", "Thieu tham so cho lcd");
  }
  delay(5000);
}

void handleLCDThank() {
  if (server.hasArg("carIdOut")) {
    String carIdOut = server.arg("carIdOut");
    String cost = server.arg("cost");
    lcd.clear();
    lcd.setCursor (0,0);
    lcd.print("CARID: " + carIdOut);
    lcd.setCursor (0,1);
    lcd.print("Cost " + cost);
    server.send(200, "text/plain", "lcd da dc dieu khien");
  } else {
    server.send(400, "text/plain", "Thieu tham so cho lcd");
  }
  delay(5000);
}
void handleSlot() {
  if (server.hasArg("slot")) {
    int slot = server.arg("slot").toInt();
    if(slot > 3)
    {
      lcd.clear(); 
      lcd.setCursor (0,0);
      lcd.print("    WELCOME!    ");
      lcd.setCursor (0,1);
      lcd.print("  Parking Ready  "); 
    }
    else if(slot < 1)
    {
      lcd.clear(); 
      lcd.setCursor (0,0);
      lcd.print("    SORRY :(    ");  
      lcd.setCursor (0,1);
      lcd.print("  Parking Full  "); 
    }
    else
    {
      lcd.clear();
      lcd.setCursor (0,0);
      lcd.print("    WELCOME!    ");
      lcd.setCursor (0,1);
      lcd.print("Slot Left: ");
      lcd.print(slot);
    }
    server.send(200, "text/plain", "slot da duoc hien thi");
  } else {
    server.send(400, "text/plain", "Thieu tham so cho /slot");
  }
}

void setup() {
  // Khởi động Serial để theo dõi thông tin debug
  Serial.begin(9600);
  Wire.begin(D2,D1);               //Thiết lập chân kết nối I2C (SDA,SCL);
  lcd.init();                      //Khởi tạo LCD
  lcd.clear();                     //Xóa màn hình
  lcd.backlight();
  lcd.setCursor (0,0);
  lcd.print("     ARDUINO    ");
  lcd.setCursor (0,1);
  lcd.print(" PARKING SYSTEM ");

  WiFi.begin(ssid, password);
  Serial.println("Kết nối đến WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
   Serial.println("Đã kết nối thành công!");

  server.on("/lcd/carIn", HTTP_GET, handleLCDIn);
  server.on("/lcd/carOut", HTTP_GET, handleLCDOut);
  server.on("/lcd/slot", HTTP_GET, handleSlot);
  // Khởi động máy chủ
  server.enableCORS(true);
  server.begin();
  Serial.println("Server started");
  Serial.print("IP Address of network: "); // will IP address on Serial Monitor
  Serial.println(WiFi.localIP());
  Serial.print("Copy and paste the following URL: https://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

}
void loop() {

  server.handleClient(); // Xử lý các yêu cầu từ client
}
