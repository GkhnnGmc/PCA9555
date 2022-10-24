#include "Wire.h"
#include "PCA9555.h"

#define expanderID 0x20 //A0:0 A1:0 A2:0 

//Output Definations
int digitalOuts=0,testOutput=0,testInput=0;
int digitalOut1=0,digitalOut2=0,digitalOut3=0,digitalOut4=0;
int digitalOut5=0,digitalOut6=0,digitalOut7=0,digitalOut8=0;

//Input Definations
int digitalInputs=0;
int digitalIn1=0,digitalIn2=0,digitalIn3=0,digitalIn4=0;
int digitalIn5=0,digitalIn6=0,digitalIn7=0,digitalIn8=0;


void setup() 
{
   Serial.begin(9600);
   Wire.begin();
   beginExpander(expanderID, inputMode, outputMode); //Set PCA9555 address, PORT0 mode, PORT1 mode
}

void loop() 
{
   //Write data example
   if(testOutput==0)
   {
       digitalOut1=1;
       digitalOut2=0;
       digitalOut3=1;
       digitalOut4=0;      
       digitalOut5=1;
       digitalOut6=0;
       digitalOut7=1;
       digitalOut8=0;
 
       testOutput=1;
   }
  
   bitWrite(digitalOuts,0,digitalOut1);
   bitWrite(digitalOuts,1,digitalOut2);
   bitWrite(digitalOuts,2,digitalOut3);
   bitWrite(digitalOuts,3,digitalOut4);
   bitWrite(digitalOuts,4,digitalOut5);
   bitWrite(digitalOuts,5,digitalOut6);
   bitWrite(digitalOuts,6,digitalOut7);
   bitWrite(digitalOuts,7,digitalOut8);
   expanderWrite(expanderID, registerMode4, digitalOuts); //PCA9555 Address, Port1 output, write data
  
   delay(2000);
    
   if(testOutput==1)
   {
       digitalOut1=0;
       digitalOut2=1;
       digitalOut3=0;
       digitalOut4=1;      
       digitalOut5=0;
       digitalOut6=1;
       digitalOut7=0;
       digitalOut8=1;
  
       testOutput=0;
   }
  
   bitWrite(digitalOuts,0,digitalOut1);
   bitWrite(digitalOuts,1,digitalOut2);
   bitWrite(digitalOuts,2,digitalOut3);
   bitWrite(digitalOuts,3,digitalOut4);
   bitWrite(digitalOuts,4,digitalOut5);
   bitWrite(digitalOuts,5,digitalOut6);
   bitWrite(digitalOuts,6,digitalOut7);
   bitWrite(digitalOuts,7,digitalOut8);
   expanderWrite(expanderID, registerMode4, digitalOuts); //PCA9555 Address, Port1 output, write data
  
   delay(2000);

   //Read data example

   digitalInputs = expanderRead(expanderID, registerMode1, 1); //PCA9555 Address, Port0 input, Request 1 byte data
   Serial.print("Read data:");
   Serial.println(digitalInputs);

   digitalIn1 = bitRead(digitalInputs,0);
   digitalIn2 = bitRead(digitalInputs,1);
   digitalIn3 = bitRead(digitalInputs,2);
   digitalIn4 = bitRead(digitalInputs,3);
   digitalIn5 = bitRead(digitalInputs,4);
   digitalIn6 = bitRead(digitalInputs,5);
   digitalIn7 = bitRead(digitalInputs,6);
   digitalIn8 = bitRead(digitalInputs,7);
   

   Serial.print("Digital Inputs:");
   Serial.print(digitalIn1);
   Serial.print(digitalIn2);
   Serial.print(digitalIn3);
   Serial.print(digitalIn4);
   Serial.print(" ");
   Serial.print(digitalIn5);
   Serial.print(digitalIn6);
   Serial.print(digitalIn7);
   Serial.println(digitalIn8);

   delay(2000);
}
