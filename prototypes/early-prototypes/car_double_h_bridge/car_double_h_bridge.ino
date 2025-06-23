// CODIGO FUNCIONAL CON UN SOLO PUENTE H (primer modelo)

// Conexiones PUENTE DELANTERO (rueda derecha)
const int pd_ENA = 2;    // ENA canal A
const int pd_IN1 = 23;   // Control canal A
const int pd_IN2 = 24;
const int pd_ENB = 3;    // ENB canal B
const int pd_IN3 = 25;   // Control canal B
const int pd_IN4 = 26;

// Conexiones PUENTE TRASERO (rueda izquierda)
const int pt_ENA = 11;   // ENA canal A
const int pt_IN1 = 10;   // Control canal A
const int pt_IN2 = 9;
const int pt_ENB = 5;    // ENB canal B (usando pin 5 como especificaste)
const int pt_IN3 = 8;    // Control canal B
const int pt_IN4 = 7;

//----------------------------------------------------------------
// ASIGNACIÓN DE PINES
//----------------------------------------------------------------
void configurarPines() {
  // Puente delantero (rueda derecha)
  pinMode(pd_ENA, OUTPUT); pinMode(pd_ENB, OUTPUT);
  pinMode(pd_IN1, OUTPUT); pinMode(pd_IN2, OUTPUT);
  pinMode(pd_IN3, OUTPUT); pinMode(pd_IN4, OUTPUT);
  
  // Puente trasero (rueda izquierda)
  pinMode(pt_ENA, OUTPUT); pinMode(pt_ENB, OUTPUT);
  pinMode(pt_IN1, OUTPUT); pinMode(pt_IN2, OUTPUT);
  pinMode(pt_IN3, OUTPUT); pinMode(pt_IN4, OUTPUT);
}

//----------------------------------------------------------------
// FUNCIÓN: AVANZAR
//----------------------------------------------------------------
void avanzar() {
  // Rueda derecha - ambos canales adelante
  digitalWrite(pd_IN1, HIGH); digitalWrite(pd_IN2, LOW);
  digitalWrite(pd_IN3, HIGH); digitalWrite(pd_IN4, LOW);
  analogWrite(pd_ENA, 200); analogWrite(pd_ENB, 200);
  
  // Rueda izquierda - ambos canales adelante
  digitalWrite(pt_IN1, HIGH); digitalWrite(pt_IN2, LOW);
  digitalWrite(pt_IN3, HIGH); digitalWrite(pt_IN4, LOW);
  analogWrite(pt_ENA, 200); analogWrite(pt_ENB, 200);
}

//----------------------------------------------------------------
// FUNCIÓN: RETROCEDER
//----------------------------------------------------------------
void retroceder() {
  // Rueda derecha - ambos canales atrás
  digitalWrite(pd_IN1, LOW); digitalWrite(pd_IN2, HIGH);
  digitalWrite(pd_IN3, LOW); digitalWrite(pd_IN4, HIGH);
  analogWrite(pd_ENA, 200); analogWrite(pd_ENB, 200);
  
  // Rueda izquierda - ambos canales atrás
  digitalWrite(pt_IN1, LOW); digitalWrite(pt_IN2, HIGH);
  digitalWrite(pt_IN3, LOW); digitalWrite(pt_IN4, HIGH);
  analogWrite(pt_ENA, 200); analogWrite(pt_ENB, 200);
}

//----------------------------------------------------------------
// FUNCIÓN: GIRAR DERECHA (sobre su eje)
//----------------------------------------------------------------
void girarDerecha() {
  // Rueda derecha - ambos canales atrás
  digitalWrite(pd_IN1, LOW); digitalWrite(pd_IN2, HIGH);
  digitalWrite(pd_IN3, LOW); digitalWrite(pd_IN4, HIGH);
  analogWrite(pd_ENA, 200); analogWrite(pd_ENB, 200);
  
  // Rueda izquierda - ambos canales adelante
  digitalWrite(pt_IN1, HIGH); digitalWrite(pt_IN2, LOW);
  digitalWrite(pt_IN3, HIGH); digitalWrite(pt_IN4, LOW);
  analogWrite(pt_ENA, 200); analogWrite(pt_ENB, 200);
}

//----------------------------------------------------------------
// FUNCIÓN: GIRAR IZQUIERDA (sobre su eje)
//----------------------------------------------------------------
void girarIzquierda() {
  // Rueda derecha - ambos canales adelante
  digitalWrite(pd_IN1, HIGH); digitalWrite(pd_IN2, LOW);
  digitalWrite(pd_IN3, HIGH); digitalWrite(pd_IN4, LOW);
  analogWrite(pd_ENA, 200); analogWrite(pd_ENB, 200);
  
  // Rueda izquierda - ambos canales atrás
  digitalWrite(pt_IN1, LOW); digitalWrite(pt_IN2, HIGH);
  digitalWrite(pt_IN3, LOW); digitalWrite(pt_IN4, HIGH);
  analogWrite(pt_ENA, 200); analogWrite(pt_ENB, 200);
}

//----------------------------------------------------------------
// FUNCIÓN: DETENER
//----------------------------------------------------------------
void detener() {
  // Apagar puente delantero
  analogWrite(pd_ENA, 0); analogWrite(pd_ENB, 0);
  digitalWrite(pd_IN1, LOW); digitalWrite(pd_IN2, LOW);
  digitalWrite(pd_IN3, LOW); digitalWrite(pd_IN4, LOW);
  
  // Apagar puente trasero
  analogWrite(pt_ENA, 0); analogWrite(pt_ENB, 0);
  digitalWrite(pt_IN1, LOW); digitalWrite(pt_IN2, LOW);
  digitalWrite(pt_IN3, LOW); digitalWrite(pt_IN4, LOW);
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