#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD I2C (alamat 0x27 untuk Wokwi)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Durasi tampilan untuk setiap sensor (dalam detik)
unsigned long displayDurations[] = {2000, 5000, 7000, 10000};
unsigned int sensorIndex = 0; // Indeks sensor yang sedang ditampilkan
unsigned long previousMillis = 0; // Waktu sebelumnya

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(2, 0);
  lcd.print("COPYRIGHT BY");
  lcd.setCursor(2, 1);
  lcd.print("YK REEF STORE");
  delay(3000); // Tampilkan copyright selama 3 detik
  lcd.clear();
}

void loop() {
 tampilan();
}

void tampilan(){
  unsigned long currentMillis = millis();

  // Cek apakah durasi tampilan untuk sensor saat ini telah habis
  if (currentMillis - previousMillis >= displayDurations[sensorIndex]) {
    previousMillis = currentMillis; // Reset waktu sebelumnya
    sensorIndex = (sensorIndex + 1) % 4; // Pindah ke sensor berikutnya (looping)
    lcd.clear(); // Bersihkan layar
  }

  // Menampilkan data sensor sesuai indeks
  switch (sensorIndex) {
    case 0:
      lcd.setCursor(0, 0);
      lcd.print("Sensor 1:");
      lcd.setCursor(0, 1);
      lcd.print("Nilai: ");
      lcd.print(random(100, 500)); // Data fiktif
      break;
    case 1:
      lcd.setCursor(0, 0);
      lcd.print("Sensor 2:");
      lcd.setCursor(0, 1);
      lcd.print("Nilai: ");
      lcd.print(random(20, 100)); // Data fiktif
      break;
    case 2:
      lcd.setCursor(0, 0);
      lcd.print("Sensor 3:");
      lcd.setCursor(0, 1);
      lcd.print("Nilai: ");
      lcd.print(random(0, 50)); // Data fiktif
      break;
    case 3:
      lcd.setCursor(0, 0);
      lcd.print("Sensor 4:");
      lcd.setCursor(0, 1);
      lcd.print("Nilai: ");
      lcd.print(random(500, 1000)); // Data fiktif
      break;
  }
}
