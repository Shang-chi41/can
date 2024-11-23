#include<Q2HX711.h>
const byte hx711_data_pin = 2;
const byte hx711_clock_pin = 3;
float zero = 0;
float kl;
Q2HX711 hx711(hx711_data_pin, hx711_clock_pin);
void setup(){
  Serial.begin(9600);
  Serial.println("Hieu chinh zero");
  Serial.println("Vui long khong di chuyen can");
  for(int i = 0; i < 100; i++){
    zero += (hx711.read()/100);
  }
  zero = zero / 100;
  Serial.println("Hieu chinh thanh cong");
  Serial.println("Tien hanh can");
  Serial.print(zero);
  delay(500);
}
void loop(){
  kl = ((hx711.read()/100)-zero)/10.342;
  Serial.print(kl);
  Serial.println("g");

}
//0 g 88026
//250g 90471