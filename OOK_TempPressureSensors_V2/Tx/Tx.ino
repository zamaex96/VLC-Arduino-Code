

#include <Arduino_LPS22HB.h> //Include library to read Pressure
#include <Arduino_HTS221.h> //Include library to read Temperature and Humidity

#define DELAY 4
//#define DELAY 1
#define LED 4 //Output pin where LED is connected
#define ID 180 //ID of Receiver
#define BITLENGTH 8 //1 Byte
#define FIRSTBIT pow(2,(BITLENGTH-1))//MSB Value
#define TRUE 1

int i, j;
int count=0;
//long Timer = millis();
//float voltage;
void writeByte(char);
//int counter=0;


float Pressure;
float Temperature, Humidity;

//int c = 0;

void setup() {
 //Setting the LED as Output
 pinMode(LED,OUTPUT);
 //Serial.begin(19200);
 //while (!Serial);
 // Serial.println("Started");
BARO.begin();
  //  if (!BARO.begin()) //Initialize Pressure sensor
 // { Serial.println("Failed to initialize Pressure Sensor!"); while (1);}
HTS.begin();  
 // if (!HTS.begin()) //Initialize Temperature and Humidity sensor
  //{ Serial.println("Failed to initialize Temperature and Humidity Sensor!"); while (1);}
  

//delay(20);
}



void loop()
{
//if ((millis()-Timer)<20000000000000000000)
//{
//Read Pressure value
//Pressure = BARO.readPressure();
//Read Temperature value
Temperature = HTS.readTemperature();
//Read Humidity value
//Humidity = HTS.readHumidity();
writeByte(ID); //Sending ID of Receiver
writeByte(Temperature);//sending the temperature to the receiver
//writeByte(Pressure);//sending the  Pressure to the receiver
//writeByte(Humidity);//sending the  Humidity  to the receiver
/*float temperature = (float)Temperature*5/1024;
temperature=(temperature -0.5)*100;
Serial.print(++count); // Sending the value of temperature
Serial.print (" : The tempereature is ");
Serial.print(temperature); // Sending the value of temperature
Serial.println(" 'C");
if (count >256)
{
count=0;
}
  Serial.print("Humidity = ");Serial.println(Humidity);
  Serial.print("Pressure = ");Serial.println(Pressure);
   Serial.print("Temperature = ");Serial.println(Temperature-12);

*/
//} 
}


//Sending 1byte number
void writeByte(char decimal)
{
//converting the decimal value to binary and sending 8 bit information from MSB to LSB
 int i,binary;
 for(i=0;i<BITLENGTH;i++)
 {
  //int a= decimal % 2;
 binary = (int)decimal/FIRSTBIT; //Getting the first binary bit value
 decimal= (decimal & ((int)FIRSTBIT -1));//Setting the first bit to zero
 decimal=decimal<<1; //Shift all bits by one to left
 if(binary==TRUE)
 //if (a==1)
 {
 digitalWrite(LED,HIGH);
 delayMicroseconds(5);
 digitalWrite(LED,LOW);
  //analogWrite(A0,255);  
 //Serial.print("1");
 }
 else
 {
 digitalWrite(LED,LOW);
 delayMicroseconds(5);
 digitalWrite(LED,HIGH);
 // analogWrite(A0,0);  
 //Serial.print("0");
 }
 //delay(DELAY);
 delayMicroseconds(5);
 }
//Serial.println();
//digitalWrite(LED,LOW);
}
