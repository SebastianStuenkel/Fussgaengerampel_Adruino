/* 
 *  Arduino Projekt: Ampel mit Fußgängerampel, Taster und Knopf.
 *  Geschrieben von Sebastian Stünkel, FT23C. 
*/
const int buttonPin = 13;

int buttonState = 0;

void setup() {  //LEDs als Outputt festgelegt + Buttonpin als Eingang festgelegt
  pinMode(10, OUTPUT); //Auto grün
  pinMode(11, OUTPUT); //Auto gelb
  pinMode(12, OUTPUT); //Auto rot
  pinMode(9, OUTPUT);  //Fußgänger rot
  pinMode(8, OUTPUT);  //Fußgänger grün
  pinMode(7, OUTPUT);  //Signal kommt LED
  pinMode(buttonPin, INPUT);
}

void loop() {

  buttonState = digitalRead(buttonPin);

  if (!buttonState) {
    for (int i = 0; i < 8; i++) {  // "for" Schleife für die "Signal LED"
      digitalWrite(7, HIGH);
      delay(1000);
      digitalWrite(7, LOW);
      delay(1000);
    }
    digitalWrite(10, HIGH);//grün HIGH
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
    delay(1000);
    digitalWrite(11, HIGH);  //gelb HIGH
    digitalWrite(10, LOW);
    digitalWrite(12, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
    delay(3000);
    digitalWrite(12, HIGH);    //rot HIGH
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    delay(3000);
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
    for (int i = 0; i < 6; i++) {  //Ton an und abschalten
    tone(6, 100);  
    delay(1000);
    noTone(6);
    delay(1000);
    }
    delay(5000);
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
    delay(5000);
    digitalWrite(12, HIGH);    //rot und gelb HIGH
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    delay(3000);
  }
  else {
    digitalWrite(10, HIGH);    //nur grün HIGH
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
  }
}
