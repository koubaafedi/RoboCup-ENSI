int led = 13;
int capteur = 3;
int detection;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(capteur, INPUT);
}

void loop() {

  // Lecture de la valeur de l'interface OUT du capteur
  detection = digitalRead(capteur);

  // Si on détecte une personne, on allume la LED
  if (detection == 0) {
    digitalWrite(led, HIGH);
  }

  // Si on ne détecte personne, on éteint la LED
  if (detection == 1) {
    digitalWrite(led, LOW);
  }

}
