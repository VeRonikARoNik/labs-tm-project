#include <LiquidCrystal.h> //Dołączenie bilbioteki
#define trigPin 12
#define echoPin 11
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //Informacja o podłączeniu nowego wyświetlacza 
void loop() {
   Serial.begin (9600); 
  pinMode(trigPin, OUTPUT); //Pin, do którego podłączymy trig jako wyjście
  pinMode(echoPin, INPUT); //a echo, jako wejście
  lcd.begin(16, 2); //Deklaracja typu
  lcd.setCursor(0, 0); //Ustawienie kursora
  lcd.print(zmierzOdleglosc());
  lcd.print(" cm");
  delay(2000);
}
int zmierzOdleglosc() {
  long czas, dystans;
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  czas = pulseIn(echoPin, HIGH);
  dystans = czas / 58;
 
  return dystans;
}
