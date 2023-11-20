#include<SoftwareSerial.h> 
#include <SPI.h>
#include <MFRC522.h>

//Inicializa SoftwareSerial em RX e TX do Arduino
SoftwareSerial s(0,1);
  
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(10, 9);

void setup() {
  s.begin(9600);
  SPI.begin();      // Inicia  SPI bus
  mfrc522.PCD_Init();   // Inicia MFRC522
  pinMode(7, OUTPUT);
}

void loop() {
  // Procura por cartao RFID
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Seleciona o cartao RFID
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  
  //Mostra UID na serial
  String conteudo= "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  conteudo.toUpperCase();

  if (conteudo.substring(1) == "A2 D3 CB 1C") //UID Tag RFID 
  {
    s.write('1');
    delay(500);
    digitalWrite(7, LOW); // ativa rele, abre a trava solenoide
    delay(3000);           // espera 3 segundos
    digitalWrite(7, HIGH);  // desativa rele, fecha a trava solenoide
  }  else {
    s.write('2');
    delay(500);
  }
}
