
void setup() {
  //Entradas de los servomotores de las ruedas
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);

  //Entradas del sensor de ultrasonido
  Serial.begin(9600);
 
  pinMode(12, OUTPUT);
  pinMode(13, INPUT);


}


void loop() 
{
  
  if (Serial.available()>0)
  {
    char data = Serial.read();
    if (data =="1")
    {
      Avanzar(70);
      delay(5000);
    }
  }

  /*Ultrasonic_Sensor_Module();

  Avanzar(70);//avanza por 2 segundos
  delay(2000);
  Atras(70);
  delay(2000);
  Izquierda(80);
  delay(2000);
  Derecha(80);
  delay(2000);
  Alto();
  delay(2000);**/

}

//Funciones de movimiento de las ruedas
void Avanzar(int speed) //Definimos la funcion de avance de la velocidad de entrada
{
  digitalWrite(2,HIGH); //El puerto D2 digital I/O controla la direccion del motor de la interfaz A
  analogWrite(5,speed); //El puerto D5 digital I/O emite señal PWM para controlar la velocidad del motor del puerto A
  digitalWrite(4,LOW);//El puerto D4 digital I/O controla la direccion del motor de la interfaz B
  analogWrite(6,speed);//El puerto D6 digital I/O emite señal PWM para controlar la velocidad del motor del puerto 6
}

void Izquierda(int speed) //Definimos la funcion de rotacion izquierda de la velocidad de entrada
{
  digitalWrite(2,LOW);
  analogWrite(5,speed);
  digitalWrite(4,LOW);
  analogWrite(6,speed);
}

void Atras(int speed) //Definimos la funcion de atras de la velocidad de entrada
{
  digitalWrite(2,LOW);
  analogWrite(5,speed);
  digitalWrite(4,HIGH);
  analogWrite(6,speed);
}

void Alto() //Definimos la funcion de Alto
{
  digitalWrite(2,LOW);
  analogWrite(5,0);
  digitalWrite(4,HIGH);
  analogWrite(6,0);
}

void Derecha(int speed) //Definimos la funcion de rotacion a la Derecha de la velocidad de entrada
{
  digitalWrite(2,HIGH);
  analogWrite(5,speed);
  digitalWrite(4,HIGH);
  analogWrite(6,speed);
}

//Funciones del sensor de ultrasonido
float checar_distancia() {
  digitalWrite(12, LOW);
  delayMicroseconds(2);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);
  float distance = pulseIn(13, HIGH) / 58.00;
  delay(10);
  return distance;
}

void Ultrasonic_Sensor_Module() {
  int Distance = 0;
  Distance = checar_distancia();
  Serial.print("Distance:");
  Serial.print(Distance);
  Serial.println("CM");
  delay(100);
}