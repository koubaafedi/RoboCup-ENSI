// Black Line Follower 
const int TopSensor=13;    //Right sensor
const int LeftSensor=12;    //left Sensor
const int RightSensor=11; //Right Sensor
const int MiddleRightSensor=2; //Middle Right Sensor
const int MiddleLeftSensor=3; //Middle Left Sensor

//Moteur Droite
const int MoteurDroiteForword = 7;
const int MoteurDroiteBackword = 6;
const int MoteurDroiteSpeed = 9;
//Moteur Gauche
const int MoteurGaucheForword = 5;
const int MoteurGaucheBackword = 4;
const int MoteurGaucheSpeed = 10;


void setup() {
  // put your setup code here, to run once:
  TCCR0B = TCCR0B & B11111000 | B00000010;
  //Sensors
  pinMode(TopSensor, INPUT);
  pinMode(LeftSensor, INPUT);
  pinMode(RightSensor, INPUT);
  pinMode(MiddleRightSensor, INPUT);
  pinMode(MiddleLeftSensor, INPUT);  
  //Motors
  pinMode(MoteurDroiteForword, OUTPUT);
  pinMode(MoteurDroiteBackword, OUTPUT);
  pinMode(MoteurDroiteSpeed, OUTPUT);
  pinMode(MoteurGaucheForword, OUTPUT);
  pinMode(MoteurGaucheBackword, OUTPUT);
  pinMode(MoteurGaucheSpeed, OUTPUT);
}


void loop() 
{
   if(digitalRead(TopSensor)==HIGH && digitalRead(MiddleRightSensor)==HIGH && digitalRead(MiddleLeftSensor)==HIGH )
  {
    GoForward();
  }
  else if(digitalRead(LeftSensor)==HIGH && digitalRead(RightSensor)==LOW){
    TurnLeft();
  }
  else if(digitalRead(MiddleRightSensor)==LOW && digitalRead(MiddleLeftSensor)==HIGH ) 
  {
    SlightlyTurnLeft();
  }
  else if(digitalRead(MiddleRightSensor)==HIGH && digitalRead(MiddleLeftSensor)==LOW ) 
  {
    SlightlyTurnRight();
  }
  else if(digitalRead(LeftSensor)==LOW && digitalRead(RightSensor)==HIGH){
    TurnRight();
  }
  else if(digitalRead(MiddleRightSensor)==LOW && digitalRead(MiddleLeftSensor)==LOW ) 
  {
    TurnLeft();
  }
  else
  {
    GoForward();
  }
}

//FONCTIONS MOTEURS
void GoForward()
{
 
  //Controlling speed (0 = off and 255 = max speed):
  analogWrite(MoteurDroiteSpeed, 110); //ENA pin
  analogWrite(MoteurGaucheSpeed, 110); //ENB pin

  //Controlling spin direction of motors:
  digitalWrite(MoteurDroiteForword, HIGH);
  digitalWrite(MoteurDroiteBackword, LOW);

  digitalWrite(MoteurGaucheForword, HIGH);
  digitalWrite(MoteurGaucheBackword, LOW);
 
}


void SlightlyTurnLeft()
{ 
  //Controlling speed (0 = off and 255 = max speed):
  analogWrite(MoteurDroiteSpeed, 110); //ENA pin
  analogWrite(MoteurGaucheSpeed, 90); //ENB pin

  //Controlling spin direction of motors:
  digitalWrite(MoteurDroiteForword, HIGH);
  digitalWrite(MoteurDroiteBackword, LOW);

  digitalWrite(MoteurGaucheForword, LOW);
  digitalWrite(MoteurGaucheBackword, HIGH);
}
void TurnLeft(){
  //Controlling speed (0 = off and 255 = max speed):
  analogWrite(MoteurDroiteSpeed, 110); //ENA pin
  analogWrite(MoteurGaucheSpeed, 110); //ENB pin

  //Controlling spin direction of motors:
  digitalWrite(MoteurDroiteForword, HIGH);
  digitalWrite(MoteurDroiteBackword, LOW);

  digitalWrite(MoteurGaucheForword, LOW);
  digitalWrite(MoteurGaucheBackword, HIGH);
}
void SlightlyTurnRight()
{
 //Controlling speed (0 = off and 255 = max speed):
  analogWrite(MoteurDroiteSpeed, 90); //ENA pin
  analogWrite(MoteurGaucheSpeed, 110); //ENB pin

  //Controlling spin direction of motors:
  digitalWrite(MoteurDroiteForword, LOW);
  digitalWrite(MoteurDroiteBackword, HIGH);

  digitalWrite(MoteurGaucheForword, HIGH);
  digitalWrite(MoteurGaucheBackword, LOW);
}
void TurnRight()
{
 //Controlling speed (0 = off and 255 = max speed):
  analogWrite(MoteurDroiteSpeed, 110); //ENA pin
  analogWrite(MoteurGaucheSpeed, 110); //ENB pin

  //Controlling spin direction of motors:
  digitalWrite(MoteurDroiteForword, LOW);
  digitalWrite(MoteurDroiteBackword, HIGH);

  digitalWrite(MoteurGaucheForword, HIGH);
  digitalWrite(MoteurGaucheBackword, LOW);
}
void GoBackward()
{
  //Controlling speed (0 = off and 255 = max speed):
  analogWrite(MoteurDroiteSpeed, 90); //ENA pin
  analogWrite(MoteurGaucheSpeed, 90); //ENB pin

  //Controlling spin direction of motors:
  digitalWrite(MoteurDroiteForword, LOW);
  digitalWrite(MoteurDroiteBackword, HIGH);

  digitalWrite(MoteurGaucheForword, LOW);
  digitalWrite(MoteurGaucheBackword, HIGH);
}

void STOP()
{ 
  //Controlling speed (0 = off and 255 = max speed):
  analogWrite(MoteurDroiteSpeed, 0); //ENA pin
  analogWrite(MoteurGaucheSpeed, 0); //ENB pin

  //Controlling spin direction of motors:
  digitalWrite(MoteurDroiteForword, LOW);
  digitalWrite(MoteurDroiteBackword, LOW);

  digitalWrite(MoteurGaucheForword, LOW);
  digitalWrite(MoteurGaucheBackword, LOW);
}
