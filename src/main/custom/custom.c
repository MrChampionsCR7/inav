#include "io/serial.h"
#include "common/time.h"
#include "drivers/serial.h"
#include "common/printf.h"
#include <stdint.h>
#include "Euler/EulerController.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXIMUM_STRING_SIZE 50

/*ROO*/
void rt_OneStep(void);
/*ROO*/
static serialPort_t * serialPort = NULL;


void customSerialTest (timeUs_t currentTimeUs){
    UNUSED(currentTimeUs);
   char inBuf[MAXIMUM_STRING_SIZE];
    char outBuf[MAXIMUM_STRING_SIZE];
    uint8_t i = 0;
    double serialValue = (double)0.0;
    bool startReading = false;

    while (serialRxBytesWaiting(serialPort)) {
        char c = serialRead(serialPort);
        if (i >= MAXIMUM_STRING_SIZE) break;
        if (startReading){
            inBuf[i] = c;
            i++;
        
}
      if(c == '<')startReading= true;
      if (c == '>')break;
    }
      if(strlen(inBuf)>9){
       serialValue = atof(inBuf);
       EulerController_U.Error= (double)serialValue;
       rt_OneStep();
       serialValue = EulerController_Y.Manipulated;
       /* serialValue += (double)0.01;*/
        tfp_sprintf(outBuf,"%10f", serialValue);
        serialPrint(serialPort, outBuf);
      }  
}       

void customSerialTest_Init (void){
    serialPort = openCustomSerialPort(NULL, NULL, baudRates[BAUD_921600], MODE_RX | MODE_TX, SERIAL_NOT_INVERTED | SERIAL_STOPBITS_1);
    //serialPort = openCSerialPort(portConfig->identifier, FUNCTION_NONE, NULL, NULL, baudRates[BAUD_115200], MODE_TX, SERIAL_NOT_INVERTED | SERIAL_STOPBITS_1 | SERIAL_PARITY_NO );
    //serialPort = uartOpen(USART2, NULL, NULL, baudRates[BAUD_115200], MODE_TX, SERIAL_NOT_INVERTED | SERIAL_STOPBITS_1 | SERIAL_PARITY_NO);
}

/*ROO*/
void rt_OneStep(void)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(EulerController_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  EulerController_step();

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}
/*ROO*/