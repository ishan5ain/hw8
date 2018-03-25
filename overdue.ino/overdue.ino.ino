// This fade code is for the assignment that involves 3 leds and 1 pot pin

#define led1 5
#define led2 6
#define led3 9
#define pot1 A0

float pot1Data = 0;

int led3State = LOW;
unsigned long preMillis = 0;
int interval = 200;
int interval2 = 1000;
int counter = 0;

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

  unsigned long curMillis = millis();

  Serial.println(counter);

  if (curMillis - preMillis >= interval && counter <= 6) {
    preMillis = curMillis;
    if (led3State == LOW) {
      led3State = HIGH;
      counter++;
    } else {
      led3State = LOW;
      counter++;
    }
  }

  digitalWrite(led3, led3State);

  if (counter == 6) {
    counter = 0;
    delay(interval2);
  }

  


}

