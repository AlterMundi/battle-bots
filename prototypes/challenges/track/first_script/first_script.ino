// ROBOT AUTOMÁTICO - VERSIÓN SIMPLE
// Puente H L298N con 2 motores

// Conexiones del puente H
const int ENA = 11;    // Motor derecho - control de velocidad
const int IN1 = 10;    // Motor derecho - dirección
const int IN2 = 9;     // Motor derecho - dirección
const int IN3 = 7;     // Motor izquierdo - dirección  
const int IN4 = 6;     // Motor izquierdo - dirección
const int ENB = 8;     // Motor izquierdo - control de velocidad

const int velocidadDerecha = 255;  // Motor derecho (más rápido para corregir desviación)
const int velocidadIzquierda = 150;  // Motor izquierdo

// Tiempos para cada movimiento (ajustados según pruebas)
const int tiempoBloque = 1100;           // Reducido para que 7 bloques sean exactos
const int tiempoGiroIzquierda = 900;    // Giro izquierda perfecto
const int tiempoGiroDerecha = 1300;      // Giro derecha compensado por diferencia de velocidad

//----------------------------------------------------------------
// CONFIGURACIÓN INICIAL
//----------------------------------------------------------------
void setup() {
  Serial.begin(9600);
  
  // Configurar pines como salida
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  detener();
  Serial.println("Robot automático iniciado");
  Serial.println("Iniciando en 3 segundos...");
  delay(3000);
}

//----------------------------------------------------------------
// FUNCIONES BÁSICAS
//----------------------------------------------------------------

void avanzarUnBloque() {
  // Motor derecho adelante (velocidad ajustada)
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, velocidadDerecha);
  
  // Motor izquierdo adelante (velocidad ajustada)
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velocidadIzquierda);
  
  delay(tiempoBloque);
  detener();
  delay(100);  
}

void rotarDerecha() {
  // Motor derecho atrás
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, velocidadDerecha);
  
  // Motor izquierdo adelante
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velocidadIzquierda);
  
  delay(tiempoGiroDerecha);  
  detener();
  delay(200);  
}

void rotarIzquierda() {
  // Motor derecho adelante
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, velocidadDerecha);
  
  // Motor izquierdo atrás
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, velocidadIzquierda);
  
  delay(tiempoGiroIzquierda);  
  detener();
  delay(200);  
}

void detener() {
  // Apagar ambos motores
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

//----------------------------------------------------------------
// BUCLE PRINCIPAL
//----------------------------------------------------------------

void loop() {
  Serial.println("=== INICIANDO PATRÓN ===");
  
  avanzarUnBloque();
  avanzarUnBloque();
  avanzarUnBloque();
  avanzarUnBloque();
  avanzarUnBloque();
  avanzarUnBloque();
  avanzarUnBloque();
  
  rotarIzquierda();
  avanzarUnBloque();
  avanzarUnBloque();
  avanzarUnBloque();
  
  rotarDerecha();
  avanzarUnBloque();
  avanzarUnBloque();
  
  rotarDerecha();
  avanzarUnBloque();
  avanzarUnBloque();

  rotarIzquierda();
  avanzarUnBloque();
  avanzarUnBloque();
  avanzarUnBloque();

  rotarIzquierda();
  avanzarUnBloque();
  avanzarUnBloque();

  rotarDerecha();
  avanzarUnBloque();
  
  //----------------------------------------------------------------
  // Esto es solo para ver en la consola si el codigo ya terminó. 
  // A fines practicos es solo un delay antes del reinicio del ciclo.
  //----------------------------------------------------------------

  for (int i = 20; i > 0; i--) {
    Serial.print("Reiniciando en ");
    Serial.print(i);
    Serial.println(" segundos ");
    delay(1000);
  }
  
}