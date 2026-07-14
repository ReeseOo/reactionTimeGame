const int signalLed = 12; // The "GO" light
const int p1Led = 8;
const int p2Led = 9;
const int p1Button = 2;
const int p2Button = 3;
volatile bool p1Pressed = false;
volatile bool p2Pressed = false;
volatile unsigned long p1PressTime = 0;
volatile unsigned long p2PressTime = 0;

void setup() {
  pinMode(signalLed, OUTPUT);
  pinMode(p1Led, OUTPUT);
  pinMode(p2Led, OUTPUT);
  pinMode(p1Button, INPUT_PULLUP);
  pinMode(p2Button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(p1Button), p1Interrupted, FALLING);
  attachInterrupt(digitalPinToInterrupt(p2Button), p2Interrupted, FALLING);
  Serial.begin(9600);
  randomSeed(analogRead(0));
  // Serial.println("=== HACK CLUB VERSUS MODE ===");
  Serial.println("Press any button to start...");
}

void p1Interrupted() {
  p1PressTime = millis();
  p1Pressed = true;
}

void p2Interrupted() {
  p2PressTime = millis();
  p2Pressed = true;
}

void loop() {
  // 1. Wait for any button press to start
  Serial.println("Waiting for a challenger...");
  while (digitalRead(p1Button) == HIGH && digitalRead(p2Button) == HIGH);
  
  // 2. Clear all lights for the start
  digitalWrite(signalLed, LOW);
  digitalWrite(p1Led, LOW);
  digitalWrite(p2Led, LOW);
  
  Serial.println("\nREADY...");
  delay(1000);
  Serial.println("SET...");
  
  // 3. Foul Detection Wait
  unsigned long waitDuration = random(2000, 5000);
  unsigned long startWait = millis();
  bool foul = false;
  p1Pressed = false;
  p2Pressed = false;

  while (millis() - startWait < waitDuration) {
    if (p1Pressed) {
      Serial.println("P1 FOUL! P2 WINS!");
      digitalWrite(p2Led, HIGH);
      foul = true;
      break; 
    }
    if (p2Pressed) {
      Serial.println("P2 FOUL! P1 WINS!");
      digitalWrite(p1Led, HIGH);
      foul = true;
      break;
    }
  }

  // 4. Race Check
  if (!foul) {
    digitalWrite(signalLed, HIGH); 
    unsigned long startTime = millis();
    
    while (true) {
      if (p1Pressed) {
        digitalWrite(signalLed, LOW); 
        digitalWrite(p1Led, HIGH);
        Serial.print("P1 SPEED: "); 
        Serial.print(p1PressTime - startTime);
        Serial.println("ms");
        break;
      }
      if (p2Pressed) {
        digitalWrite(signalLed, LOW); 
        digitalWrite(p2Led, HIGH);
        Serial.print("P2 SPEED: "); 
        Serial.print(p2PressTime - startTime);
        Serial.println("ms");
        break;
      }
    }
  }
  
  // 5. End of round
  Serial.println("Rematch? Press any button.");
  delay(3000); // Give them 3 seconds to see the result
}
