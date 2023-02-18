#define S0 8
#define S1 9
#define S2 6
#define S3 7
#define sensorOut 2

//Calibration
#define RED_LOW_PARA 40
#define RED_HIGH_PARA 200
#define GREEN_LOW_PARA 50
#define GREEN_HIGH_PARA 300
#define BLUE_LOW_PARA 50
#define BLUE_HIGH_PARA 300

int blue=0;
int red=0;
int green=0;
int frequency = 0;

void setup() {

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
   
  Serial.begin(9600);
}

void loop() {

digitalWrite(S2, LOW);
digitalWrite(S3, LOW);

frequency = pulseIn(sensorOut, LOW);
frequency= map(frequency, RED_HIGH_PARA, RED_LOW_PARA, 255, 0);
red = frequency;

Serial.print("R= ");
Serial.print(frequency);
Serial.print("  ");
delay(100);

digitalWrite(S2, HIGH);
digitalWrite(S3, HIGH);

frequency = pulseIn(sensorOut, LOW);
frequency= map(frequency, GREEN_HIGH_PARA, GREEN_LOW_PARA, 255, 0);
green = frequency;

Serial.print("G= ");
Serial.print(frequency);
Serial.print("  ");
delay(100);

digitalWrite(S2, LOW);
digitalWrite(S3, HIGH);

frequency = pulseIn(sensorOut, LOW);
frequency= map(frequency, BLUE_HIGH_PARA, BLUE_LOW_PARA, 255, 0);
blue = frequency;

Serial.print("B= ");
Serial.print(frequency);
Serial.print("  ");
delay(100);
Serial.print("-----------------");
if(red>blue && red>green){
  Serial.print("RED");
  digitalWrite(3, HIGH);
}
if(blue>red && blue>green){
  Serial.print("BLUE");
    digitalWrite(4, HIGH);
  }
if(green>blue && green>red){
  Serial.print("GREEN");
    digitalWrite(5, HIGH);
  }
Serial.print("-----------------");
Serial.println(" ");

delay(2000);
    digitalWrite(3, LOW);
        digitalWrite(4, LOW);
            digitalWrite(5, LOW);
}
