# Trava De Cofre
>Repositório dedicado ao projeto de objetos inteligentes turma

>Alunos:

>Marcus Vinicius Silva de Sousa 

>Luciano Guimarães Costa 

## O que é o projeto

Buscando inspiração no âmbito facilitador e prático da ação da internet das coisas no nosso dia a dia, foi idealizado um projeto que reúne tecnologia, segurança e praticidade em um só contexto. O projeto consiste em uma trava de segurança inteligente via radiofrequência, podendo ser adaptada a cofres, portarias, cômodos internos residenciais e a qualquer outra função onde aplicar segurança e restringir acesso for necessário de acordo com a vontade do usuário. Utilizando-se do benefício de objetos inteligentes munidos de interconexão digital e eletrônica, foi desenvolvido uma trava inteligente que funcionará via aproximação, identificando o usuário e liberando seu acesso, garantindo assim segurança e praticidade.

## Pré Requisitos 

- IDE Arduino (de preferência)
- Libs utilizadas: 
  - ESP8266WIFI
  - PubSubClient
  - SPI
  - SoftwareSerial
  - MFRC522
 
 - Materiais utilizados:
  - Arduino Uno
  - Trava Elétrica Solenóide 12V 
  - Módulo relé 5V
  - Módulo RFID Mfrc522
  - LED Difuso 
  - Resistores 1KΩ 1/4 W
  - Fonte 12V (chaveada 12V é uma alternativa) 
  - Protoboard
  - Tag RFID 
  - Buzzer
  - NodeMCU ESP8266
  - Protocolo MQTT 
  - MQTT Broker (mqtt eclipse foi utilizado para o projeto)
  - MQTT Client (MQTTBox foi utilizado para o projeto)
 
## Objetivo do software

O objetivo do software é prover uma solução inteligente e conectada à internet para proteção de bens. Com este projeto é possível monitorar o acesso ao cofre através da utilização do protocolo MQTT, baseado no protocolo TCP/IP da web. Além disso, conta com duas tecnologias altamente eficazes como o sensor RFID para realizar a leitura e validação dos dados de acesso, juntamente com o NodeMCU ESP8266 com conectividade WI-FI para contemplar a internet das coisas!
