/* ========================================
 *
 * @author Mattia Pesenti
 * @date 22-dec-2020
 *
 * ========================================
*/

/*
 * UART_BT communication test
 * This project can be used to test the Bluetooth-UART communication.
 * Make sure you are connected to the COM port of the HC-05/HC-06 module,
 * using the baudrate and the settings configured with the BT_ATMODE project.
 * Warning: if using Windows under a virtual environment (VirtualBox/Parallels/etc),
 *          connect directly to your host operating system if having trouble with
 *          bluetooth sharing (i.e., directly use CoolTerm on your host OS)
*/

#include "project.h"
#include <stdio.h>

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_BT_Start();
    
    UART_BT_PutString("UART BT: communication started.\r\nCounting at 1 Hz...\r\n");
    
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
