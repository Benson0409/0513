byte seven_seg_digits[10][7] = { { 1,1,1,1,1,1,0 }, // = 0

{ 0,1,1,0,0,0,0 }, // = 1

{ 1,1,0,1,1,0,1 }, // = 2

{ 1,1,1,1,0,0,1 }, // = 3

{ 0,1,1,0,0,1,1 }, // = 4

{ 1,0,1,1,0,1,1 }, // = 5

{ 1,0,1,1,1,1,1 }, // = 6

{ 1,1,1,0,0,0,0 }, // = 7

{ 1,1,1,1,1,1,1 }, // = 8

{ 1,1,1,0,0,1,1 } // = 9

};

const int buttonPin = 12;

int buttonState = 0;

int num = 0;
byte present=0;
byte previous=0;
void setup() {

pinMode(2, OUTPUT);

pinMode(3, OUTPUT);

pinMode(4, OUTPUT);

pinMode(5, OUTPUT);

pinMode(6, OUTPUT);

pinMode(7, OUTPUT);

pinMode(8, OUTPUT);

pinMode(9, OUTPUT);

digitalWrite(9, 0); // 關閉小數點

digitalWrite(buttonPin,HIGH);

pinMode(buttonPin,INPUT);
pinMode(12,INPUT_PULLUP);


}

void sevenSegWrite(byte digit) {

byte pin = 2;

for (byte seg = 0; seg < 7; ++seg) {

digitalWrite(pin,
seven_seg_digits[digit][seg]==0?1:0);

++pin;

}

}

void loop() {
buttonState = digitalRead(buttonPin);
previous==present;
present=digitalRead(buttonPin);

if(num > 9){
num = 0; 
}
if(present==0&&previous==1){
  num++;
  previous=0;  
}
if(present==1){
 previous=1;
  }

sevenSegWrite(num);

delay(100);

}








