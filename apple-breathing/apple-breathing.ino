// This fade code is for the assignment that involves 3 leds and 1 pot pin

#define led1 5
#define led2 6
#define led3 9
#define pot1 A0

float pot1Data = 0;

int led3State = LOW;
int led3Brightness = 0;
unsigned long preMillis = 0;
int interval = 10;
boolean rising = true;

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

  if (curMillis - preMillis >= interval) {
    preMillis = curMillis;
    if (rising) {
      led3Brightness += 1;
    } else {
      led3Brightness -= 1;
    }
  }

  if (led3Brightness == 255 && rising == true) {
    rising = false;
  }

  if (led3Brightness == 0 && rising == false) {
    rising = true;
  }

  analogWrite(led3, led3Brightness);
}

