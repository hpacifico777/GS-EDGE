#include <Wire.h>                // Biblioteca para comunicação I2C
#include <LiquidCrystal_I2C.h>   // Biblioteca para LCD I2C

// Configuração do LCD I2C (endereço 0x27, LCD 16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Definições de pinos
#define LDRPIN A0          // Pino analógico para o LDR (potenciômetro)
#define PIRPIN 2           // Pino digital para o sensor PIR (botão)
#define LEDPIN 3           // Pino digital para o LED (iluminação)
#define BATTERY_PIN A1     // Pino para simular leitura de tensão da bateria

// Variáveis globais
float luminosidade = 0;  // Percentual de luminosidade
bool movimento = false;  // Estado do PIR (movimento detectado ou não)
float tensaoBateria = 0; // Nível de tensão da bateria

void setup() {
  // Configuração dos pinos
  pinMode(PIRPIN, INPUT);    // Entrada do botão simulando PIR
  pinMode(LEDPIN, OUTPUT);   // Saída para o LED
  pinMode(LDRPIN, INPUT);    // Entrada do potenciômetro simulando LDR
  pinMode(BATTERY_PIN, INPUT); // Entrada do potenciômetro simulando bateria

  // Inicializa o LCD
  lcd.begin(16, 2);  // Configura o LCD como 16x2
  lcd.backlight();  // Ativa a luz de fundo do LCD
  lcd.setCursor(0, 0);
  lcd.print("Iniciando...");
  delay(2000);
  lcd.clear();

  // Inicializa o monitor serial
  Serial.begin(9600);
}

void loop() {
  // Leitura do LDR
  int ldrValue = analogRead(LDRPIN);          // Lê o valor analógico
  luminosidade = map(ldrValue, 0, 1023, 0, 100); // Converte para porcentagem (0-100)

  // Leitura do PIR
  movimento = digitalRead(PIRPIN);  // Lê o botão (PIR)

  // Leitura da tensão da bateria
  int batteryValue = analogRead(BATTERY_PIN); 
  tensaoBateria = batteryValue * (5.0 / 1023) * 2; // Conversão para tensão em volts (divisor de tensão)

  // Controle da iluminação
  if (luminosidade < 20) {  // Condição de baixa luminosidade
    if (movimento) {
      digitalWrite(LEDPIN, HIGH);  // Brilho máximo
    } else {
      analogWrite(LEDPIN, 10);    // Brilho reduzido
    }
  } else {
    digitalWrite(LEDPIN, LOW);     // Desligado em alta luminosidade
  }

  // Atualização do LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Luz:");
  lcd.print(luminosidade);
  lcd.print(" %");

  lcd.setCursor(0, 1);
  lcd.print("Bateria:");
  lcd.print(tensaoBateria, 1); // Mostra 1 casa decimal
  lcd.print(" V");

  // Registro Serial para análise
  Serial.print("Luminosidade: ");
  Serial.print(luminosidade);
  Serial.print(" %, Movimento: ");
  Serial.print(movimento ? "Sim" : "Não");
  Serial.print(", Bateria: ");
  Serial.print(tensaoBateria);
  Serial.println(" V");

  // Pequena pausa para atualização do sistema
  delay(1000);
}
