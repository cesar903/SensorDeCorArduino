#define S0 8 // Atribui ao pino 8 o nome de SO, referente ao pino SO do sensor de cor
#define S1 9 // Atribui ao pino 9 o nome de S1, referente ao pino S1 do sensor de cor
#define S2 12 // Atribui ao pino 12 o nome de S2, referente ao pino S2 do sensor de cor
#define S3 11 // Atribui ao pino 11 o nome de S3, referente ao pino S3 do sensor de cor
#define OutSensor 10 // Atribui ao pino 10 o nome de OutSensor, referente ao pino OUT do sensor de cor

#define R 3 
#define G 5  
#define B 6       
 
int red = 0; // declara uma variavel int de nome red_frequency
int green = 0; // declara uma variavel int de nome green_frequency
int blue = 0;// declara uma variavel int de nome blue_frequency

void setup(){
  pinMode(S0, OUTPUT); // define o pino denominado SO como saída 
  pinMode(S1, OUTPUT); // define o pino denominado S1 como saída 
  pinMode(S2, OUTPUT); // define o pino denominado S2 como saída 
  pinMode(S3, OUTPUT); // define o pino denominado S3 como saída 
  pinMode(OutSensor, INPUT); // define o pino denominado OutSensor como saída 
  Serial.begin(9600); // Inicia a comunicação serial
  digitalWrite(S0, HIGH); // configura a escala de frequência do sensor para 20%
  digitalWrite(S1, LOW); // configura a escala de frequência do sensor para 20%

  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}
  
void loop(){
 
// leitura da cor vermelha
digitalWrite(S2,LOW); // configuração para os Fotodiodos red serem lidos
digitalWrite(S3,LOW); // configuração para os Fotodiodos red serem lidos
red = pulseIn (OutSensor, LOW); // armazena na variável red a frequência lida em OutSensor
Serial.print ("R= "); // escreve a letra R no monitor serial
Serial.print (red); // apresenta os valores armazenados na variável red no monitor serial
Serial.print ("   "); // espaço de texto no monitor serial

 
// leitura da cor verde
digitalWrite(S2,HIGH); // configuração para os Fotodiodos green serem lidos
digitalWrite(S3,HIGH); // configuração para os Fotodiodos green serem lidos
green = pulseIn (OutSensor, LOW); // armazena na variável green a frequência lida em OutSensor
Serial.print ("G= "); // escreve a letra G no monitor serial
Serial.print (green); // apresenta os valores armazenados na variável green no monitor serial
Serial.print ("   "); // espaço de texto no monitor serial

 
// leitura da cor azul
digitalWrite(S2,LOW); // configuração para os Fotodiodos blue serem lidos
digitalWrite(S3,HIGH); // configuração para os Fotodiodos blue serem lidos
blue = pulseIn (OutSensor, LOW); // armazena na variável blue a frequência lida em OutSensor
Serial.print ("B= "); // escreve a letra B no monitor serial
Serial.print (blue); // apresenta os valores armazenados na variável blue no monitor serial
Serial.print ("   "); // espaço de texto no monitor serial
   
  // condiçoes para detecção das cores 
  if (500 < red && red < 1000 &&  1200 < green && green < 1750 && 900 < blue && blue < 1700){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Vermelho"); 
    analogWrite(R, 255); //Ligando as portas PWM com valor aleatório de duty cicle
    analogWrite(G, 0);
   analogWrite(B, 0);
    }
  else if (300 < red && red < 700 &&  300< green && green < 1000 && 500< blue && blue < 1000  ){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Amarelo");
     analogWrite(R, 255); //Ligando as portas PWM com valor aleatório de duty cicle
    analogWrite(G, 255);
   analogWrite(B, 0);
    }
  else if ( 1050 < red && red < 1600 &&  800< green && green < 1300 && 600< blue && blue < 1500){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Verde");
     analogWrite(R, 0); //Ligando as portas PWM com valor aleatório de duty cicle
     analogWrite(G, 255);
     analogWrite(B, 0);
    }
   else  { // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Outra cor");
      analogWrite(R, random(255)); //Ligando as portas PWM com valor aleatório de duty cicle
      analogWrite(G, random(255));
      analogWrite(B, random(255));
    }
  
 
    Serial.println(); // quebra um linha no texto do serial monitor
    delay(300); // atraso de 300 milisegundos
 
}
