
 // Definovanie pinov pre tlačidlá a LED diódy
#define CERVENY_PIN 23    // Pin pre červenú LED
#define ZLTY_PIN 21       // Pin pre žltú LED
#define ZELENY_PIN 18     // Pin pre zelenú LED

#define CERVENE_TLACIDLO_PIN 22    // Pin pre červené tlačidlo
#define ZLTE_TLACIDLO_PIN 19      // Pin pre žlté tlačidlo
#define ZELENE_TLACIDLO_PIN 15    // Pin pre zelené tlačidlo

int cervena_stav = 0;    // Premenná pre stav červenej LED
int zlta_stav = 0;       // Premenná pre stav žltej LED
int zelena_stav = 0;     // Premenná pre stav zelenej LED

void setup() {
  // Inicializácia sériového portu
  Serial.begin(9600);

  // Nastavenie pinov pre LED diódy ako výstupy
  pinMode(CERVENY_PIN, OUTPUT);
  pinMode(ZLTY_PIN, OUTPUT);
  pinMode(ZELENY_PIN, OUTPUT);

  // Nastavenie pinov pre tlačidlá ako vstupy s interným pull-up odporom
  pinMode(CERVENE_TLACIDLO_PIN, INPUT_PULLUP);
  pinMode(ZLTE_TLACIDLO_PIN, INPUT_PULLUP);
  pinMode(ZELENE_TLACIDLO_PIN, INPUT_PULLUP);

  // Inicializácia LED do vypnutého stavu
  digitalWrite(CERVENY_PIN, LOW);
  digitalWrite(ZLTY_PIN, LOW);
  digitalWrite(ZELENY_PIN, LOW);
}

void loop() {
  // Sledovanie stavu červeného tlačidla
  int cervene_tlacidlo_stav = digitalRead(CERVENE_TLACIDLO_PIN);
  if (cervene_tlacidlo_stav == LOW) { // Tlačidlo stlačené (LOW znamená stlačenie, keďže je použitý pull-up)
    Serial.println("Cervene tlacidlo stlacene");
    if (cervena_stav == 0) {
      digitalWrite(CERVENY_PIN, HIGH); // Zapni cervenu LED
      cervena_stav = 1;  // Zmeň stav LED na zapnutý
    } else {
      digitalWrite(CERVENY_PIN, LOW);  // Vypni cervenu LED
      cervena_stav = 0;  // Zmeň stav LED na vypnutý
    }
    delay(500);  // Krátke zdržanie na zabránenie duplicitného spínania (debounce)
  }

  // Sledovanie stavu žltého tlačidla
  int zlte_tlacidlo_stav = digitalRead(ZLTE_TLACIDLO_PIN);
  if (zlte_tlacidlo_stav == LOW) { // Tlačidlo stlačené
    Serial.println("Zlte tlacidlo stlacene");
    if (zlta_stav == 0) {
      digitalWrite(ZLTY_PIN, HIGH); // Zapni zltu LED
      zlta_stav = 1;  // Zmeň stav LED na zapnutý
    } else {
      digitalWrite(ZLTY_PIN, LOW);  // Vypni zltu LED
      zlta_stav = 0;  // Zmeň stav LED na vypnutý
    }
    delay(500);  // Krátke zdržanie na zabránenie duplicitného spínania (debounce)
  }

  // Sledovanie stavu zeleného tlačidla
  int zelene_tlacidlo_stav = digitalRead(ZELENE_TLACIDLO_PIN);
  if (zelene_tlacidlo_stav == LOW) { // Tlačidlo stlačené
    Serial.println("Zelene tlacidlo stlacene");
    if (zelena_stav == 0) {
      digitalWrite(ZELENY_PIN, HIGH); // Zapni zelenu LED
      zelena_stav = 1;  // Zmeň stav LED na zapnutý
    } else {
      digitalWrite(ZELENY_PIN, LOW);  // Vypni zelenu LED
      zelena_stav = 0;  // Zmeň stav LED na vypnutý
    }
    delay(500);  // Krátke zdržanie na zabránenie duplicitného spínania (debounce)
  }
}
