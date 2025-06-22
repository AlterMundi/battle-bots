// CODIGO FUNCIONAL CON UN SOLO PUENTE H (primer modelo)

// Conexiones del ÚNICO PUENTE H
const int ENA = 11;   // Canal A (rueda izquierda)
const int IN1 = 10;  // Control canal A
const int IN2 = 9;
const int ENB = 8;   // Canal B (rueda derecha)
const int IN3 = 7;  // Control canal B
const int IN4 = 6;

//----------------------------------------------------------------
// ASIGNACIÓN DE PINES
//----------------------------------------------------------------
void configurarPines() {
  // Canal A (rueda izquierda)
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
  // Canal B (rueda derecha)
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

//----------------------------------------------------------------
// FUNCIÓN: AVANZAR
//----------------------------------------------------------------
void avanzar() {
  // Rueda izquierda (canal A: adelante)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 200);
  
  // Rueda derecha (canal B: adelante)
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 200);
}

//----------------------------------------------------------------
// FUNCIÓN: RETROCEDER
//----------------------------------------------------------------
void retroceder() {
  // Rueda izquierda (canal A: atrás)
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 200);
  
  // Rueda derecha (canal B: atrás)
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 200);
}

//----------------------------------------------------------------
// FUNCIÓN: GIRAR DERECHA (sobre su eje)
//----------------------------------------------------------------
void girarDerecha() {
  // Rueda izquierda (canal A: adelante)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 200);
  
  // Rueda derecha (canal B: atrás)
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 200);
}

//----------------------------------------------------------------
// FUNCIÓN: GIRAR IZQUIERDA (sobre su eje)
//----------------------------------------------------------------
void girarIzquierda() {
  // Rueda izquierda (canal A: atrás)
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 200);
  
  // Rueda derecha (canal B: adelante)
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 200);
}

//----------------------------------------------------------------
// FUNCIÓN: DETENER
//----------------------------------------------------------------
void detener() {
  // Apagar ambos canales
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  
  // Resetear pines de dirección
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

//----------------------------------------------------------------
// SETUP
//----------------------------------------------------------------
void setup() {
  Serial.begin(9600);
  configurarPines();
  detener();
  Serial.println("Sistema listo. Comandos: A, R, D, I, S");
}

//----------------------------------------------------------------
// LOOP PRINCIPAL
//----------------------------------------------------------------
void loop() {
  if (Serial.available() > 0) {
    char comando = Serial.read();
    
    switch(comando) {
      case 'A': 
        avanzar();
        Serial.println("Avanzando");
        break;
      case 'R': 
        retroceder();
        Serial.println("Retrocediendo");
        break;
      case 'D': 
        girarDerecha();
        Serial.println("Girando derecha");
        break;
      case 'I': 
        girarIzquierda();
        Serial.println("Girando izquierda");
        break;
      case 'S': 
        detener();
        Serial.println("Detenido");
        break;
    }
  }
}