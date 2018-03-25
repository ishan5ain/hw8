// This fade code is for the assignment that involves 3 leds and 1 pot pin

#define led1 5
#define led2 6
#define led3 9
#define pot1 A0

float pot1Data = 0;

int led3State = LOW;
int led3Brightness = 0;

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
  led3Brightness = map(pot1Data, 250, 0, 0, 255);

  Serial.print(pot1Data);
  Serial.print(" | ");
  Serial.println(led3Brightness);


  if (pot1Data < 256) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    analogWrite(led3, led3Brightness);
  } else if (pot1Data >= 256 && pot1Data < 512) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    analogWrite(led3, 0);
  } else if (pot1Data >= 512 && pot1Data < 768) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    analogWrite(led3, 0);
  } else if (pot1Data >= 768) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    analogWrite(led3, 0);
  }

}

