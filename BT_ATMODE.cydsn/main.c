/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

/*
 * UART_BT communication test
*/

#include "project.h"
#include <stdio.h>

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_BT_Start();
    
    //UART_BT_PutString("AT");
    
    /* Uncomment *only one* of the following lines */
    // UART_BT_PutString("AT+UART=9600,0,0\r\n");   // 9600 baud rate,   1 stop bit (0), no parity (0)
    UART_BT_PutString("AT+UART=57600,0,0\r\n");     // 57600 baud rate,  1 stop bit (0), no parity (0)
    // UART_BT_PutString("AT+UART=115200,0,0\r\n"); // 115200 baud rate, 1 stop bit (0), no parity (0)
    
    /* 
     * 1. Make sure your HC device is in AT Mode 
     * 2. Program the Device with the HC-05/HC-06 connected
     * Hardware connections: HC-05/06 TX --> PSoC RX (12.6)
     *                          HC-05/06 RX --> PSoC TX (12.7)
     * The AT command is sent immediately after programming
     * You can switch to the project BT_UART for testing 
    */
    
    
    for(;;)
    {
        
    }
}

/* [] END OF FILE */
