#include <IRremote.h>
IRrecv irrecv(6);
decode_results results;

int state = 0;
int enA = 10;
int enB = 9;
unsigned long lastButtonTime = millis();

#define trig_Pin 8
#define echo_Pin 11
//long mesafe = 0;
//long sure = 0;
//long engel = 0;

int timeoutDelay = 200;


void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  analogWrite(enA, 200);
  analogWrite(enB, 200);
  pinMode(2, OUTPUT); // Çıkış pinlerini belirliyoruz.
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
 // pinMode(trig_Pin, OUTPUT);
 // pinMode(echo_Pin, INPUT);
}
void loop()
{

/* Ultrasonic göz
  digitalWrite(trig_Pin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig_Pin, LOW);
  sure = pulseIn(echo_Pin, HIGH);
  mesafe = (sure / 29.1) / 2;

  if (mesafe > 1000) {
    //mesafe = 1000;

  }
  else if (mesafe < 15) {
    engel = 1;

  } else {
    engel = 0;
  }
  Serial.print("Engel: ");
  Serial.print(engel);
  Serial.println("  ");
  Serial.print("Ölçulen Mesafe = ");
  Serial.print(mesafe);
  Serial.println(" cm ");
  delay(100);
*/
  if ( (millis() - lastButtonTime > timeoutDelay))
  {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  }

  if (irrecv.decode(&results) )
  {
    Serial.println(results.value);
    if (results.value == 16718055 ) {
      digitalWrite(2, LOW);
      digitalWrite(5, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      lastButtonTime = millis();

      //İLERİ


    }
    else if (results.value == 16730805) {


      digitalWrite(2, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      lastButtonTime = millis();
      //GERİ
    }

    else if (results.value == 16716015) {

      digitalWrite(2, LOW);
      digitalWrite(4, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      lastButtonTime = millis();
      //SOL


    }

    else if (results.value == 16734885) {
      digitalWrite(2, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(5, LOW);
      lastButtonTime = millis();
      //SAG
    }

    else if (results.value == 16726215) {
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);

      //DUR
    }

    else if (results.value == 16756815) {
      analogWrite(enA, 255);
      analogWrite(enB, 255);
      //HIZ ARTTIR
    }

    else if (results.value == 16738455) {
      analogWrite(enA, 128);
      analogWrite(enB, 128);

      //HIZ AZALT
    }

    //




    else if (results.value == 4294967295) {
      lastButtonTime = millis();
      //DUR
    }



    irrecv.resume();
  }
}
