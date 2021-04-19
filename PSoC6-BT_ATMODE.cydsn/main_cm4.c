/**
*   \brief Main source file for CM4 project.
*
*   Scan the input serial connection and sends
*   the commands to the Bluetooth moduel via
*   UART.
*/

#include "project.h"
#include "stdio.h"

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */

    char received = 0;  // Variable holding received chars
    
    // Initialize debug serial port    
    UART_Debug_Start();
    setvbuf( stdin, NULL, _IONBF, 0 );
    printf("\f");
    printf("PSoC 6 - HC05/06 Configuration\r\n\r\n");
    printf("Enter the commands you want to send!");
    
    // Initialize blueooth serial port
    UART_BT_Start();
    
    for(;;)
    {
        // Scan and sends the commands to the Bluetooth module
        scanf("%c", &received);
        Cy_SCB_UART_PutString(UART_BT_HW, &received);
    }
}

/* [] END OF FILE */
