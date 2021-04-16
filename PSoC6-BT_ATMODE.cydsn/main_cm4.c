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

#include "project.h"
#include "stdio.h"

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_Start();
    setvbuf( stdin, NULL, _IONBF, 0 );
    printf("\f");
    printf("PSoC 6 - HC05/06 Configuration\r\n");
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
