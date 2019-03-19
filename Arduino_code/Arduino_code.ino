
//ASSIGN PIN TO THE MOTORDRIVER AND THE IR SENSORS
int a=0;
int b=0;
int ir1=8;   //IR SENSOR 1
int ir2=9;   //IR SENSOR 2
int m1=5; //MOTOR ENABLE 1
int d11=2; //MOTOR INT 1
int d12=3; //MOTOR INT 2
int m2=6;  //MOTOR ENABLE 2
int d22=7; //MOTOR INT 4
int d21=4; //MOTOR INT 3

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
pinMode(ir1,INPUT);
pinMode(ir2,INPUT);
Serial.begin(9600);
 
 
}

void loop() {
  // put your main code here, to run repeatedly:
  
a =digitalRead(ir1);  //READING THE INPUT OF IR SENSOR 1
b= digitalRead(ir2);  //READING THE INUT OF IR SENSOR 2
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
