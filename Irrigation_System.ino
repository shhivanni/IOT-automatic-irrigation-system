#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 2        
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(5, 6, 7, 8, 9, 10); 

unsigned long previousMillis = 0;
unsigned long currentMillis2 = 0;

const unsigned long interval = 2000; 

int Moisture_sensor = A2;
int Rain_Sensor = A1;

int Pump = A0;

void setup() {
  Serial.begin(9600);
  dht.begin();

  lcd.begin(16, 2);
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();

  pinMode(Moisture_sensor,INPUT);
  pinMode(Rain_Sensor,INPUT);

  pinMode(Pump,OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  

  if( millis() - currentMillis2 > 2000 ){
    currentMillis2=millis();
    if(digitalRead(Rain_Sensor)==LOW){
      Serial.println("RAIN");
      digitalWrite(Pump,LOW);

      lcd.setCursor(14, 0); lcd.print("RY");
    }

    else {
      Serial.println(analogRead(Moisture_sensor));
      if(analogRead(Moisture_sensor)>500){ digitalWrite(Pump,HIGH); Serial.println("PUMP_ON");  lcd.setCursor(14, 1); lcd.print("MN"); }
      else                               { digitalWrite(Pump,LOW);  Serial.println("PUMP_OFF"); lcd.setCursor(14, 1); lcd.print("MY"); } 

      lcd.setCursor(14, 0); lcd.print("RN");
    }
  }

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; 

    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    if (isnan(temperature) || isnan(humidity)) {
      lcd.clear();
      lcd.print("Sensor Error");
      return;
    }

    lcd.clear();
    lcd.setCursor(0, 0); lcd.print("TEMP: ");  lcd.print(temperature); lcd.print(" C ");
    lcd.setCursor(0, 1); lcd.print("HUMI: ");  lcd.print(humidity);    lcd.print(" % ");
  }
}
