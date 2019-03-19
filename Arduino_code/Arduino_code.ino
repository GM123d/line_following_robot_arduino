
//ASSIGN PIN TO THE MOTORDRIVER AND THE IR SENSORS
int a=0;   //IR SENSOR 1
int b=0;   //IR SENSOR 2
int m1=10; //MOTOR ENABLE 1
int d11=9; //MOTOR INT 1
int d12=8; //MOTOR INT 2
int m2=5;  //MOTOR ENABLE 2
int d22=6; //MOTOR INT 3
int d21=7; //MOTOR INT 4

//WHEN IR SENSOR 2 GET INPUT DIGITAL 1 'bm' FUNCTION WILL EXECUTE

void bm(){
digitalWrite(m1,HIGH);
digitalWrite(d11,HIGH);
digitalWrite(d12,LOW);

delay(500);

digitalWrite(m1,LOW);
digitalWrite(d11,HIGH);
digitalWrite(d12,LOW);
 }

//WHEN IR SENSOR 1 AND 2 GET INPUT DIGITAL 0 'bm' FUNCTION WILL EXECUTE
 
 void motor(){
digitalWrite(m1,HIGH);
digitalWrite(d11,HIGH);
digitalWrite(d12,LOW);
digitalWrite(m2,HIGH);
digitalWrite(d21,HIGH);
digitalWrite(d22,LOW);
}

//WHEN IR SENSOR 1 GET INPUT DIGITAL 1 'am' FUNCTION WILL EXECUTE
 
  void am(){
digitalWrite(m2,HIGH);
digitalWrite(d21,HIGH);
digitalWrite(d22,LOW);

delay(500);

digitalWrite(m2,LOW);
digitalWrite(d21,HIGH);
digitalWrite(d22,LOW);
 }

void setup() {
  // put your setup code here, to run once:
pinMode(m1,OUTPUT);
pinMode(d11,OUTPUT);
pinMode(d12,OUTPUT);
pinMode(m2,OUTPUT);
pinMode(d21,OUTPUT);
pinMode(d22,OUTPUT);
pinMode(2,INPUT);
pinMode(3,INPUT);
Serial.begin(9600);
 
 
}

void loop() {
  // put your main code here, to run repeatedly:
  
a =digitalRead(2);  //READING THE INPUT OF IR SENSOR 1
b= digitalRead(3);  //READING THE INUT OF IR SENSOR 2
 if (a==1){
  digitalWrite(m1,LOW);
  digitalWrite(m2,LOW);
am();
 }
 if (b==1){
  digitalWrite(m1,LOW);
  digitalWrite(m2,LOW);
bm();
 }
 if(a==0 && b==0){

  motor();
 }
  
}
