/*
  CLUB ELEC - LLN

  HO2 - RF Telegraph project
*/

// Pins utilisés
unsigned int tx_pin = 4;
unsigned int rx_pin = A0;

unsigned int threshold_pin = A1;
unsigned int mode_pin = 3; // HIGH - Auto encode , LOW - Manual
unsigned int led_pin = 5;
unsigned int button_pin = 6;


// threshold définit indirectement la tension de seuil de la sortie du module RF.
// La valaeur threshold est calculé comme suit : threshold = V_seuil/5*1024
// (5 = Vdd, la tension d'alimentation, 1024 = le nombre de valeurs possibles pour l'ADC)
unsigned int threshold = 270;

/*
- t_base : longueur de pulse "unitaire" [ms]
- t_short : longueur de pulse court [ms]
- t_long : longueur de pulse long [ms]
- t_end : longueur de pause de fin de caractère [ms]
- t_space : longueur de pause de fin de mot [ms]
- t_pause : longueur de pause inter-symbole [ms]
- del : définit indirectement la fréquence PWM
        del = 1/(4*f)
*/
unsigned int t_base = 500;
unsigned int t_short = t_base;
unsigned int t_long = 3*t_base;
unsigned int t_end = 3*t_base;
unsigned int t_space = 74*t_base;
unsigned int t_pause = t_base;
unsigned int del = 500;

// variable utilisé dans gen_pulse
unsigned long t_start;

// La fonction setup est lancé une fois, lors du reset de l'arduino
void setup() {
  // Parametrer le pin tx en sortie, et bouton et mode en entrée avec pull-up
  pinMode(tx_pin, OUTPUT);
  pinMode(mode_pin, INPUT_PULLUP);
  pinMode(button_pin, INPUT_PULLUP);

  // Parametrer les leds en sortie
  pinMode(led_pin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  // Créer une communication série vers le PC (pour debug, peut être enlevé)
  Serial.begin(9600);
}

// La fonction loop est exécuté indéfiniement.
void loop() {
  if (digitalRead(mode_pin)==HIGH){ // Auto TX
    //INSERER CODE POUR ENVOYER UN SOS AUTOMATIQUEMENT
  } else { // Manual TX
    //INSERER CODE POUR ENVOYER AVEC LE BOUTON
  }
}


/*
- fonction gen_pulse : Crée un pulse d'une durée demandé pour un envoyer un
- signal HIGH (1) ou LOW (0).
- duration : argument qui permet de choisir la durée du pulse en ms.
- level : deux valeurs possibles : 0 pour envoyer un pulse de niveau bas
-                                  1 pour un niveau haut.
*/
void gen_pulse(unsigned int duration,int level) {
  t_start = millis();
  while (millis()-t_start < duration) {
    digitalWrite(tx_pin, level);
    delayMicroseconds(3*del);

    digitalWrite(tx_pin, 1-level);
    delayMicroseconds(1*del);
  }
}
