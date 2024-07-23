#include <Arduino.h>
#include <ESP32Servo.h>

int led = 2;           // LED บนบอร์ด
int buttonPin1 = 4;    // พินของปุ่ม 1
int buttonPin2 = 5;    // พินของปุ่ม 2
int servoPin = 14;     // พินที่ต่อ Servo
Servo myservo;

int servoPosition = 0; // ตำแหน่งปัจจุบันของ Servo

void setup() {
    Serial.begin(9600);
    pinMode(led, OUTPUT);
    pinMode(buttonPin1, INPUT);
    pinMode(buttonPin2, INPUT);
    myservo.attach(servoPin);
}

void loop() {
    // ตรวจสอบสถานะปุ่ม 1
    if (digitalRead(buttonPin1) == HIGH) {
        if (servoPosition != 90) {  // ตรวจสอบว่า Servo ยังไม่ได้หมุนไปที่ 90 องศา
            Serial.println("Button 1 pressed, turning LED on and rotating servo to 90 degrees");
            digitalWrite(led, HIGH);
            myservo.write(90);     // หมุน Servo ไปที่ 90 องศา
            servoPosition = 90;    // อัปเดตตำแหน่งของ Servo
            delay(10000);          // รอ 10 วินาที
            // ไม่ต้องเขียนโค้ดที่จะหมุน Servo กลับมาที่ 0 องศา
        }
    }

    // ตรวจสอบสถานะปุ่ม 2
    if (digitalRead(buttonPin2) == HIGH) {
        Serial.println("Button 2 pressed, turning LED off and rotating servo to 0 degrees");
        digitalWrite(led, LOW);
        myservo.write(0);      // หมุน Servo ไปที่ 0 องศา
        servoPosition = 0;     // อัปเดตตำแหน่งของ Servo
        delay(1000);           // รอสักครู่
    }
}

