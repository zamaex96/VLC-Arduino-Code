#define SETTING 5
#define DELAY 2
#define BITLENGTH 8
#define DIFFERENCE 10
#define S1 4
#define ID 180
#define sensorPin A0
#define ledPin  4
#define TRUE 1
int sensorValue = 0;
int middleValue;
int inputByte[4];
int CheckID;
void checkMiddle();
int readByte();
int j;
float temperature;
//long counter=millis();
int count=0;
int temp[256];
float ber=0;
int correct=0;
int chk=0;
 float low=0.0, avg=0.0,sum=0.0;
  float high=0.0;
void setup() {
Serial.begin(115200);
pinMode(ledPin, INPUT);  // sets the digital pin 13 as output
//checkMiddle();//Setting the value between Logic 0 and Logic 1
}


void loop() {
/*do
{
//if(digitalRead(S1)==HIGH)
{
checkMiddle();
//Serial.println("Sensor is calibrated ");
}
sensorValue = analogRead(sensorPin);
}while(sensorValue<=middleValue);*/
if((CheckID=readByte())==ID)
{
 for(int i=0;i<3;i++)
{inputByte[i]=readByte();} //Reading 1 Byte
//Calculating temperature
Serial.print(count);Serial.println(" : "); 
Serial.print("Temperature = ");Serial.print(inputByte[0]);Serial.println(" 'C");
Serial.print("Pressure = ");Serial.print(inputByte[1]);Serial.println(" Pa");
Serial.print("Humidity = ");Serial.print(inputByte[2]);Serial.println(" g/kg");
temp[++count]=inputByte[0];

}
if (count >256)
{
  for (int k = 0; k < 256; ++k) {
  //avg=(temp[0]+temp[1]+temp[2]+temp[3]+temp[4]+temp[5]+temp[6]+temp[7]+temp[8]+temp[9])/10;
  sum += temp[k];}
  avg = sum / 256;
  Serial.print("Average Temperature = ");Serial.println(avg);
  low=avg-10;
  high=avg+10;
 
  for(int j=0;j<256;j++)
    {Serial.print("Temperature in temp array = ");Serial.print(j);Serial.print(" = ");;Serial.print(temp[j]);Serial.println(" 'C");
     if ((chk=inRange(low,high,temp[j]))== 1)
        {correct++;}
    }
   Serial.print("Number of correct packets = ");Serial.println(correct);
   //ber=correct/256;
   Serial.print("PSR =  ");Serial.print(correct/256.0*100);Serial.println("%");
    Serial.print("PER =  ");Serial.print((256-correct)/256.0*100);Serial.println("%");
   count=0;correct=0; ber=0;avg=0;sum=0;low=0;high=0;
}
}


void checkMiddle()
{
int difference;
middleValue = analogRead(sensorPin); //Cehcking initial voltage on the sensor
Serial.println(middleValue);
do{
sensorValue=analogRead(sensorPin);//Checking second voltage on sensor
Serial.println(sensorValue);
difference= sensorValue - middleValue;//Comparing the values of the voltage
//delay(SETTING);
delayMicroseconds(2000);
}while(difference<DIFFERENCE && difference>-DIFFERENCE);
//Calculating the middle value between Logic 1 and Logic 0
middleValue = (sensorValue + middleValue)/2;
}


int readByte()
{
int i,input=0;
for(i=0;i<BITLENGTH;i++)
{//Repeat for each bit
sensorValue=analogRead(sensorPin);//Read the sensor Value
//int val = digitalRead(ledPin);
//Serial.println(sensorValue);
//if(sensorValue>=middleValue)
if(sensorValue>=500)
//if(val==HIGH)
{
input++;
}
//Binary shift to store another bit
input=input<<1;
//delay(DELAY);
delayMicroseconds(1000);
}
//Return the value if input
input=input>>1;
return input;
}


int inRange(float low, float high, float x)        
{        
 if (low <= x && x <= high)
 return 1;
 else
 return 0;         
}
