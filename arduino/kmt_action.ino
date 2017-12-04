// thoralf - proof of concept für arduino vs. pd
int led_pin = 13;
int button_pin1 = 8;
int button_pin2 = 9;
char incoming_char;

// put your setup code here, to run once:
void setup() {
  pinMode(led_pin, OUTPUT);     // LED as output
  pinMode(button_pin1, INPUT);    // button as input
  digitalWrite(button_pin1, HIGH); // turns on pull-up resistor after input
  pinMode(button_pin2, INPUT);    // button as input
  digitalWrite(button_pin2, HIGH); // turns on pull-up resistor after input
  Serial.begin(9600);
}

void loop()
{
  // buttons
  while(digitalRead(button_pin2) == LOW)   // when pin goes LOW
    {
      Serial.write("1");
    }
  while(digitalRead(button_pin1) == LOW)   // when pin goes LOW
    {
      Serial.write("0");
    }
    
  // input vom rechner
  if (Serial.available() > 0) {
    // 3=an, 4=aus
    incoming_char = Serial.read();
    if (incoming_char == '3') {
      digitalWrite(led_pin, LOW);
    }
    if (incoming_char == '4') {
      digitalWrite(led_pin, HIGH);
    }
  }
}

