int pinoSensor = A0; // Pino do sensor de umidade
int pinoRele = 2;    // Pino do relé

void setup() {
  pinMode(pinoSensor, INPUT);  
  pinMode(pinoRele, OUTPUT);   
  Serial.begin(9600);          
}

void loop() {
  int leitura = analogRead(pinoSensor);           // Lê o sensor de umidade
  float porcentoUmidade = map(leitura, 0, 1023, 100, 0); // Converte para porcentagem
  
  Serial.print("Umidade: ");
  Serial.print(porcentoUmidade);
  Serial.println("%");

  // Se a umidade for menor que 70%, liga o relé
  if (porcentoUmidade < 70) {
    digitalWrite(pinoRele, HIGH);  
    Serial.println("Relé ativado!");
  } else {
    digitalWrite(pinoRele, LOW);   
  }

  // Envia a umidade pela porta serial
  Serial.print("UMIDADE:");
  Serial.println(porcentoUmidade);

  delay(1000);  
