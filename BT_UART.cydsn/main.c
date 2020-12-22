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
    
    UART_BT_PutString("UART BT: communication started.\r\n");
    
    uint8_t count = 0;
    char buffer[50];
    
    for(;;)
    {
        /* Place your application code here. */
        sprintf(buffer, "count = %d\r\n", count);
        UART_BT_PutString(buffer);
        count++;
        CyDelay(1000);
    }
}

/* [] END OF FILE */
