#include "PCA9555.h"
#include "Wire.h"

// Port 0 input mode, Port 1 output mode init function
void beginExpander(int deviceAddress, int port0Mode, int port1Mode)
{
    Wire.beginTransmission(deviceAddress);     //Write device address
    Wire.write(configPort0);                   //Port 0 configuration
    Wire.write(port0Mode);              	     //Port 0 choice input mode
    Wire.endTransmission();		           //End transmission

    Wire.beginTransmission(deviceAddress);     //Write device address
    Wire.write(configPort1);           	     //Port 1 configuration
    Wire.write(port1Mode);             	     //Port 1 choice output mode 
    Wire.endTransmission();		           //End transmission
}

//Data write function
void expanderWrite(int deviceAddress, int registerMode, int sendData)
{
    Wire.beginTransmission(deviceAddress);     //Start communication with defined device ID
    Wire.write(registerMode);			     //Choice port0/port1 register mod input-output	
    Wire.write(sendData);			     //Send write data	
    Wire.endTransmission();		           //End transmission
}

//Data read function
int expanderRead(int deviceAddress, int registerMode, int dataLength)
{
    int readData=0;

    Wire.beginTransmission(deviceAddress);     //Start communication with defined device ID
    Wire.write(registerMode);			     //Choice port0/port1 register mod input-output
    Wire.endTransmission();		           //End transmission

    Wire.requestFrom(deviceAddress,dataLength);  //Send device id and data size
    if(Wire.available())			     //When communicate active;	
    {
        readData = Wire.read();                //Get read data
    }

    return readData;
}