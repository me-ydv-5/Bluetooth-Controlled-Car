
#define echoPinN 4// Echo Pin N
#define trigPinN 5// Trigger Pin N
#define echoPinE 2// Echo Pin E
#define trigPinE 3 // Trigger E
#define echoPinW 6 // Echo Pin W
#define trigPinW 7// Trigger W
#define LEDPin 13 // Onboard LED

int a1=10;
int a2=11;
int b1=8;
int b2=9;
int N=30;
int E=40;
int W=50;
int state=0;

int maximumRange = 300; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance
void check();
int checkN();
int checkW();
int checkE();
  void Movwest();
  void Moveast();
  void Movnorth();
  void Movsouth();
void Stop();
int maxofthree(int x,int y,int z);

void setup() {

 
 Serial.begin (9600);
 pinMode(trigPinN, OUTPUT);
 pinMode(echoPinN, INPUT);
  pinMode(trigPinE, OUTPUT);
 pinMode(echoPinE, INPUT);
  pinMode(trigPinW, OUTPUT);
 pinMode(echoPinW, INPUT);
 pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
pinMode(a1, OUTPUT);
digitalWrite(a1, LOW);
pinMode(a2, OUTPUT);
digitalWrite(a2, LOW);
pinMode(b1, OUTPUT);
digitalWrite(b1, LOW);
pinMode(b2, OUTPUT);
digitalWrite(b2, LOW);
}

void loop() {
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 
 if (Serial.available()) {
    //wait a bit for the entire message to arrive
    delay(100);
while (Serial.available() > 0) {
      // display each character to the LCD
    p:
    state = Serial.read();
    Serial.println(state);
    if(state=='w')
     {
     
digitalWrite(a1,HIGH);
 digitalWrite(a2, LOW);
 digitalWrite(b1,HIGH);
 digitalWrite(b2,LOW);
     
     }
     if(state=='s')
     {
   digitalWrite(a2,HIGH);
 digitalWrite(a1, LOW);
 digitalWrite(b2,HIGH);
 digitalWrite(b1,LOW);

   
     }
     if(state=='d')
     {
      
     digitalWrite(a2,LOW);
 digitalWrite(a1,HIGH);
 digitalWrite(b2,HIGH);
 digitalWrite(b1,LOW);
        }
     if(state=='a')
     {
    
     digitalWrite(a1,LOW);
 digitalWrite(a2,HIGH);
 digitalWrite(b1,HIGH);
 digitalWrite(b2,LOW);
        
        }
     
     if(state=='q')
     {
     
   Stop();
        
     }
    if(state=='g') {
                      while(state!='w'&&state!='a'&&state!='s'&&state!='d'&&state!='q'){
    
    delay(100);
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 


 N:
 check();
 Serial.println(N);
digitalWrite(a1,HIGH);
 digitalWrite(a2, LOW);
 digitalWrite(b1,HIGH);
 digitalWrite(b2,LOW);
 delay(checkN());

if(N<20){
digitalWrite(a1,LOW);
 digitalWrite(a2, LOW);
 digitalWrite(b1,LOW);
 digitalWrite(b2,LOW);
 check();

 if((E>=W))
 {
   digitalWrite(a1,LOW);
 digitalWrite(a2,HIGH);
 digitalWrite(b1,HIGH);
 digitalWrite(b2,LOW);
 delay(1000);
     digitalWrite(a2,LOW);
 digitalWrite(a1,HIGH);
 digitalWrite(b1,HIGH);
 digitalWrite(b2,LOW);
  delay(2000); 
  state = Serial.read();
  goto N;
 }
 else if(E<W)
 {
     digitalWrite(LEDPin, LOW);
 digitalWrite(a1,LOW);
 digitalWrite(a2,HIGH);
 digitalWrite(b1,HIGH);
 digitalWrite(b2,LOW);
 delay(1000);
     digitalWrite(a1,LOW);
 digitalWrite(a2,HIGH);
 digitalWrite(b1,HIGH);
 digitalWrite(b2,LOW);
  delay(2000);
  state = Serial.read();
  goto N;
  }
  
                       }
                                       
                      }}


                    }
  


 }}



void check(){

               // tell servo to go to position in variable 'pos'

 digitalWrite(trigPinN, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPinN, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPinN, LOW);
 duration = pulseIn(echoPinN, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 N= duration/58.2;
 
 
 digitalWrite(trigPinE, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPinE, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPinE, LOW);
 duration = pulseIn(echoPinE, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 E = duration/58.2;
 
 
 digitalWrite(trigPinW, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPinW, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPinW, LOW);
 duration = pulseIn(echoPinW, HIGH);

 
 //Calculate the distance (in cm) based on the speed of sound.
 W = duration/58.2;

 
 }
int maxofthree(int x,int y,int z)
{
int max;
if(x>y)
max=x;
else
max=y;
if(max>z)
;
else
max=z;
return max;
}

int checkN(){
    
    digitalWrite(trigPinN, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPinN, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPinN, LOW);
 duration = pulseIn(echoPinN, HIGH);
 Serial.println(duration/58.2);
 //Calculate the distance (in cm) based on the speed of sound.
 return  duration/58.2;
  }
 int checkW(){
      
    digitalWrite(trigPinW, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPinW, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPinW, LOW);
 duration = pulseIn(echoPinW, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
  
 
 return  duration/58.2;
  }
  int checkE(){
      
    digitalWrite(trigPinE, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPinE, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPinE, LOW);
 duration = pulseIn(echoPinE, HIGH);

  
 //Calculate the distance (in cm) based on the speed of sound.
return  duration/58.2;
  }
  void Movnorth(){
  digitalWrite(a1,HIGH);
 digitalWrite(a2, LOW);
 digitalWrite(b1,HIGH);
 digitalWrite(b2,LOW);}
  void Movwest(){
   digitalWrite(LEDPin, LOW);
 digitalWrite(a1,LOW);
 digitalWrite(a2,HIGH);
 digitalWrite(b1,HIGH);
 digitalWrite(b2,LOW);
 delay(1000);
     digitalWrite(a1,LOW);
 digitalWrite(a2,HIGH);
 digitalWrite(b1,HIGH);
 digitalWrite(b2,LOW);
  delay(1000);}
  void Moveast(){  digitalWrite(LEDPin, LOW);
 digitalWrite(a1,LOW);
 digitalWrite(a2,HIGH);
 digitalWrite(b1,HIGH);
 digitalWrite(b2,LOW);
 delay(1000);
     digitalWrite(a2,LOW);
 digitalWrite(a1,HIGH);
 digitalWrite(b2,HIGH);
 digitalWrite(b1,LOW);
  delay(1000); }
 void Stop(){
  digitalWrite(a1,LOW);
 digitalWrite(a2, LOW);
 digitalWrite(b1,LOW);
 digitalWrite(b2,LOW);}
void Movsouth(){
  digitalWrite(a2,HIGH);
 digitalWrite(a1, LOW);
 digitalWrite(b2,HIGH);
 digitalWrite(b1,LOW);}


