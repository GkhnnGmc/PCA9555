// TCA9555 Datasheet: https://www.ti.com/lit/ds/symlink/tca9555.pdf?ts=1666088911770
// PCA9555 Datasheet: https://www.nxp.com/docs/en/data-sheet/PCA9555.pdf

//CONTROL REGISTER BITS

#define configPort0 0x06
#define configPort1 0x07

// Bit 0 : Output mode Bit 1 : Input mode
#define outputMode 0x00  //All bits output mode : 0000 0000
#define inputMode  0xFF  //All bits input mode  : 1111 1111

//Port control register mode ;
#define registerMode1 0x00  //Port 0 input mode data
#define registerMode2 0x01  //Port 1 input mode data
#define registerMode3 0x02  //Port 0 output mode data
#define registerMode4 0x03  //Port 1 output mode data

//void beginExpander(int deviceAddress);

void beginExpander(int deviceAddress, int port0Mode, int port1Mode);
void expanderWrite(int deviceAddress, int registerMode, int sendData);
int expanderRead(int deviceAddress, int registerMode, int dataLength);