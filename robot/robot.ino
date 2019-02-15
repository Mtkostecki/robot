#define L_PWM 5
#define L_DIR 4
#define R_PWM 6
#define R_DIR 9
#define PWM_MAX 165




void setup() {
  //Konfiguracja pinow od mostka H
  pinMode(L_DIR, OUTPUT);
  pinMode(R_DIR, OUTPUT);
  pinMode(L_PWM, OUTPUT);
  pinMode(R_PWM, OUTPUT);
  Serial.begin(9600);
}
 
void loop() {
   if (Serial.available()) {
    char ch = Serial.read();
    if(ch == 'u') {
      leftMotor(40); 
      rightMotor(40);
    }
    else if (ch == 's'){
      leftMotor(0); 
      rightMotor(0);
    }
     else if (ch == 'b'){
      leftMotor(-40); 
      rightMotor(-40);
    }
    else if (ch == 'l'){
      leftMotor(20); 
      rightMotor(40);
    }
    else if (ch == 'r'){
      leftMotor(40); 
      rightMotor(20);
    }
    
  }
 
  
 
}
 
void leftMotor(int V) {
  if (V > 0) { //Jesli predkosc jest wieksza od 0 (dodatnia)
    V = map(V, 0, 100, 0, PWM_MAX);
    digitalWrite(L_DIR, 1); //Kierunek: do przodu
    analogWrite(L_PWM, V); //Ustawienie predkosci 
  } else {
    V = abs(V); //Funkcja abs() zwroci wartosc V  bez znaku
    V = map(V, 0, 100, 0, PWM_MAX);
    digitalWrite(L_DIR, 0); //Kierunek: do tyłu
    analogWrite(L_PWM, V); //Ustawienie predkosci    
  }
}
 
void rightMotor(int V) {
  if (V > 0) { //Jesli predkosc jest wieksza od 0 (dodatnia)
    V = map(V, 0, 100, 0, PWM_MAX);
    digitalWrite(R_DIR, 0); //Kierunek: do przodu
    analogWrite(R_PWM, V); //Ustawienie predkosci 
  } else {
    V = abs(V); //Funkcja abs() zwroci wartosc V  bez znaku
    V = map(V, 0, 100, 0, PWM_MAX);
    digitalWrite(R_DIR, 1); //Kierunek: do tyłu
    analogWrite(R_PWM, V); //Ustawienie predkosci    
  }
}
 
void stopMotors() {
  analogWrite(L_PWM, 0); //Wylaczenie silnika lewego
  analogWrite(R_PWM, 0); //Wylaczenie silnika prawego
}
