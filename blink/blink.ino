// This blink is for the assignment that involves 3 leds and 1 pot pin

#define led1 5
#define led2 6
#define led3 9
#define pot1 A0

float pot1Data = 0;

//unsigned long curMillis = 0;
unsigned long preMillis = 0;
int interval = 500;
int led3State = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(pot1, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  pot1Data = analogRead(pot1);
  unsigned long curMillis = millis();

  Serial.println(pot1Data);

  if (curMillis - preMillis  >= interval) {
    preMillis = curMillis;

    if (led3State == LOW) {
      led3State = HIGH;
    } else {
      led3State = LOW;
    }
  }

  if (pot1Data < 256) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, led3State);
  } else if (pot1Data >= 256 && pot1Data < 512) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, led3State);
  } else if (pot1Data >= 512 && pot1Data < 768) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, led3State);
  } else if (pot1Data >= 768) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, led3State);
  }

}

