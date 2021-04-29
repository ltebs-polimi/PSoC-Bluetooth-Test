/**
  *  \file           main.c
  *  \brief          Source file for Bluetooth Module configuration program.
  *
  *  \author         Mattia Pesenti, Davide Marzorati
  */
 
/*******************************************************************************
 * Copyright (c) 2020 Mattia Pesenti
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
*******************************************************************************/

/*
 * BT_ATMODE | HC-05/HC-06 configuration
 *
 * 1. Make sure your HC device is in AT Mode (HC-06 is always in AT mode).
 * 2. Select the appropriate baudrate rate for the UART_BT component: this may require some tests.
 * 3. Program the Device with the HC-05/HC-06 connected.
 * 4. Visualize HC device response from COM Port.
 * Hardware connections: HC-05/06 TX --> PSoC RX (0.6)
 *                       HC-05/06 RX --> PSoC TX (0.7)
 *
 * The AT command is sent immediately after programming
 * You can switch to the project BT_UART for testing 
 * You *do not* need bluetooth connection for this step
*/

#include "project.h"
#include <stdio.h>

#define HC05 0
#define HC06 1
#define MAX_COMMAND_LENGTH 40

// Select your HC-05/06 device by uncommenting the corresponding line only
// #define BT_MODULE HC05
#define BT_MODULE HC06

#if (BT_MODULE == HC06)
    const char* help_message = "";
#else
    const char* help_messag = "";
#endif

int main(void)
{
    uint8_t command[MAX_COMMAND_LENGTH];    /* Command to be sent to the BT module */
    uint8_t command_lenght = 0;             /* Lenght of the current command */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_BT_Start();
    UART_Debug_Start();
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_Debug_PutString("\f");
    
    #ifndef BT_MODULE
        UART_Debug_PutString("!!! No HC device was specified!\r\n");
        return 0;
    #endif
    
    UART_Debug_PutString("HC-05/06 Bluetooth Module Configuration\r\n");
    UART_Debug_PutString("Enter your command followed by \\r\\n\r\n");
    UART_Debug_PutString("Example: AT+BAUD4\\r\\n\r\n");
    
    for(;;)
    {
        if (UART_Debug_GetRxBufferSize() > 0)
        {
            uint8_t received_char = UART_Debug_GetChar();
            command[command_lenght] = received_char;
            command_lenght += 1;
            if (command_lenght > 3)
            {
                if (command[command_lenght-1] == '\n' && command[command_lenght-2] == '\r')
                {
                    UART_Debug_PutString("Sending command: ");
                    UART_Debug_PutArray(command, command_lenght);
                    UART_BT_PutArray(command, command_lenght-2);
                    
                    for (uint8_t i = 0; i < MAX_COMMAND_LENGTH; i++)
                    {
                        command[i] = 0;
                    }
                    command_lenght = 0;
                }
            }
        }
        if (UART_BT_GetRxBufferSize() > 0)
        {
            uint8_t received_char = UART_BT_GetChar();
            UART_Debug_PutChar(received_char);
        }
    }
}

/* [] END OF FILE */
