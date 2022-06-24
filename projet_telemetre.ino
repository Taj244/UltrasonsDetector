#define VITESSE 340

const int pin_echo=3;
const int pin_trig=2;


void setup() {
  // put your setup code here, to run once:
  pinMode(pin_echo,INPUT);
  pinMode(pin_trig,OUTPUT);
  digitalWrite(pin_trig,LOW);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pin_trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_trig,LOW);

  unsigned long duree= pulseIn(pin_echo, HIGH);

  if(duree>30000){
    Serial.println("Mesure échouée");
  }
  else{
    duree=duree/2;
    
    float temps=duree/10000.0;
    float distance=temps*VITESSE;

    Serial.print("Duree = ");
    Serial.print(temps);
    Serial.println("s");
    
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println("cm");

    delay(1000);
    
  }
  
}
