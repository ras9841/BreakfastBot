int coffeePin =2;
int waterPin = 4;
int tailPin = 5;
char input;
int start;

void setup() {
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(tailPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  if(Serial.available()){
    input= Serial.read();
  switch(input){
    case '0':
    if(digitalRead(coffeePin)){
      Serial.write('1');
    }
    else{
      Serial.write('0');
    }
    break;
    
    case '1':
    if(digitalRead(waterPin)){
      Serial.write('1');
    }
    else{
      Serial.write('0');
    }
    break;
    
    case '2':
    makeCoffee();
    break;
    
    case '3':
    digitalWrite(tailPin, HIGH);
    break;
    
    case '4':
    digitalWrite(tailPin, LOW);
    break;
  
  }
}
}

void makeCoffee(){
  if(digitalRead(coffeePin)&&digitalRead(waterPin)){
  digitalWrite(tailPin, HIGH);
  Serial.write('1');
  while(digitalRead(waterPin)==HIGH){
  //Serial.write('1');
  delay(10);
  }
  digitalWrite(tailPin,LOW);
  //start = millis();
  
  //while(millis()-start<480000){
  //delay(1);
  //if(Serial.available()){
 // input = Serial.read();
  //if(input == '1' || input == '0'){
 // Serial.write('1');
  }
  
   
 // }
  //}
 // }
  else{
 Serial.write('0');
  } 
//  digitalWrite(tailPin, LOW);
  
}
