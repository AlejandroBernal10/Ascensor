

#define echo 11 
#define trig 12
const int motorDer=4;
const int motorIzq=3;

long distancia,duracion;//variables para calculo de la distancia detectada por el sensor

void setup()
{
  pinMode(1, INPUT);//boton ascensor 1
  pinMode(2, INPUT);//boton asensor 2
  pinMode(5, OUTPUT);//led verde
  pinMode(6, OUTPUT);//led rojo
  pinMode(motorIzq,OUTPUT);
  pinMode(motorDer,OUTPUT);
  Serial.begin(9600); //Monitor serial
  pinMode(echo, INPUT); // Echo como entrada de señal
  pinMode(trig, OUTPUT); //Trig como salida de señal
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10); //Envie una señal cada 10 microsegundos
  digitalWrite(trig,LOW);
  
  duracion = pulseIn(echo, HIGH);
  distancia =(duracion/2)/29;  // calculo de la distancia
  
  
  if (digitalRead(2) == 1 && digitalRead(1) == 1 ) {
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    
  }else{
    if (digitalRead(2) == 0 ) {
      digitalWrite(5, LOW);//led
      digitalWrite(6, LOW);//led
    }
    if (digitalRead(2) == 1 && distancia>=10 &&  distancia<=50) {
      digitalWrite(5, LOW);//Apaga led rojo
      digitalWrite(6, HIGH);//Enciende led verde
      Serial.print(distancia);
      Serial.println("cm");
      digitalWrite(4, HIGH);
      delay(250); // esperar durante 250 millisegundos
      digitalWrite(4, LOW);
     
      }
    }
    if (digitalRead(1) == 0) {
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      
    } else {
      if (digitalRead(1) == 1&& distancia>=51 && distancia <=89) {
        digitalWrite(3, HIGH);//Enciende led rojo
        digitalWrite(5, HIGH);//Movimiento del motor
        delay(250);
        digitalWrite(3, LOW);
        digitalWrite(5, HIGH);
        Serial.print(distancia);
        Serial.println("cm");
          }
        }}
    
  

