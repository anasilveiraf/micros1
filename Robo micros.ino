
int enable_1 = 11; //amarelo 
int roda_esquerda1 = 10; // roxo in1
int roda_esquerda2 = 9; // azul in2
int enable_2 = 6; // roxo
int roda_direita1 = 5; // verde in3
int roda_direita2 = 4; // azul in4
int detector_direita = 7;
int detector_esquerda = 8;
volatile byte state = LOW;

int detecta_direita;
int detecta_esquerda;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(enable_1, OUTPUT);
  pinMode(roda_esquerda1, OUTPUT);
  pinMode(roda_esquerda2, OUTPUT);
  pinMode(enable_2, OUTPUT);
  pinMode(roda_direita1, OUTPUT);
  pinMode(roda_direita2, OUTPUT);

  pinMode(detector_direita, INPUT);
  pinMode(detector_esquerda, INPUT);
  
}

void blink() {
  state = !state;
}

void ir_para_frente ( ){

  digitalWrite(roda_esquerda1,HIGH);
  digitalWrite(roda_esquerda2,LOW);
  digitalWrite(roda_direita1,HIGH);
  digitalWrite(roda_direita2,LOW);

}

void ir_para_tras ( ){

  digitalWrite(roda_esquerda1,LOW);
  digitalWrite(roda_esquerda2,HIGH);
  digitalWrite(roda_direita1,LOW);
  digitalWrite(roda_direita2,HIGH);

}

void parar ( ){

  digitalWrite(roda_esquerda1,LOW);
  digitalWrite(roda_esquerda2,LOW);
  digitalWrite(roda_direita1,LOW);
  digitalWrite(roda_direita2,LOW);

}

void ir_para_direita ( ){
// delay 945ms para girar totalmente
 // while (detecta_esquerda == LOW){
    digitalWrite(roda_direita1,LOW);
    digitalWrite(roda_direita2,HIGH);
    digitalWrite(roda_esquerda1,HIGH);
    digitalWrite(roda_esquerda2,LOW);
    detecta_esquerda = digitalRead(detector_esquerda);
  //}
}

void ir_para_esquerda ( ){
// delay delay(1030); para girar totalmente
  //while(detecta_direita == LOW){
    digitalWrite(roda_esquerda1,LOW);
    digitalWrite(roda_esquerda2,HIGH);
    digitalWrite(roda_direita1,HIGH);
    digitalWrite(roda_direita2,LOW);
    detecta_direita = digitalRead(detector_direita);
 // }
}

void cruz ( ){
// delay delay(1030); para girar totalmente
  delay(10);
}

void detector_de_linha( ){
  int detecta_direita;
  int detecta_esquerda;

  detecta_direita = digitalRead(detector_direita);
  detecta_esquerda = digitalRead(detector_esquerda);

  if(detecta_direita == LOW) 
  {
    ir_para_esquerda ( );
    
  }

  if(detecta_esquerda == LOW) 
  {
    ir_para_direita ( );
  }
}

void loop() {

  analogWrite(enable_2, 255);
  analogWrite(enable_1, 255);
  
  detecta_direita = digitalRead(detector_direita);
  detecta_esquerda = digitalRead(detector_esquerda);
   
  ir_para_esquerda ( );
  delay(1000);
  ir_para_direita ( );
  delay(2000);

 /* while(detecta_direita == detecta_esquerda && detecta_direita == HIGH ) 
  {
    ir_para_frente ( );
    delay(100);
    detecta_direita = digitalRead(detector_direita);
  	detecta_esquerda = digitalRead(detector_esquerda);
  }
 
    if (detecta_direita == detecta_esquerda && detecta_direita == LOW)
      cruz();
      else
     if (detecta_direita == LOW){
       ir_para_esquerda ( );
     
      }
    else 
      if (detecta_esquerda == LOW){
        ir_para_direita ( );
    }
  delay(100);


/*if(detecta_direita == LOW) 
  {
    ir_para_esquerda ( );
    
  }
  if(detecta_esquerda == LOW) 
  {
    ir_para_direita ( );
  }*/

}

