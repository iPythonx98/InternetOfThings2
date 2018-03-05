/* ===================================================================================
 *
 * SPI-startproject voor de SPI-print met dot-matrixdisplays 788BS, 
 *     in combinatie met een MAX7221
 *
 * Dit programma bevat 2 fonts 
 * De font dient een 8x8 pixel font te zijn die minstens alle ASCII-karakters bevat
 *
 * Piet Coussens 17/2/18
 * Laboproject voor de SPI-proef
 * In dit project wordt een karakter dat binnenkomt via de UART afgebeeld op het display
 * instellingen UART: 9600Bd,8,1,N
 *
 * ===================================================================================
*/

#include "project.h"
#include "max7221.h"
#include "console_font_8x8.h"

void writeMax7221(uint8 adres, uint8 data)
{
    while ((SPIM_ReadTxStatus()& SPIM_STS_TX_FIFO_NOT_FULL) == 0);  // wacht tot er plaats is in de Tx buffer
    SPIM_WriteTxData(((uint16)adres<<8)|data);
    CyDelayUs(15);
}    

void clearDotDisplay()
// Deze routine wist het dotmatrixdisplay
{
    uint8 rij;
    for (rij=0;rij<8;rij++)
        writeMax7221(DIGIT_0+rij,0);
}

void printChar(uint8 karakter)
// deze routine drukt een karakter af op het dotmatrixdisplay
{
    uint8 rij;
    writeMax7221(SHUT_DOWN,0);              // driver UIT
    for(rij=0;rij<8; rij++)
        writeMax7221(DIGIT_0+rij,console_font_8x8[karakter][rij]);
    writeMax7221(SHUT_DOWN,1);              // driver aan
}

int main(void)
{
    uint8 letter, schakelaars;

    CyGlobalIntEnable;                      // Enable global interrupts
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    SPIM_Start();
    UART_Start();
    UART_PutString("SPI basisproject\n\r");
    // initialiseer alle displaydrivers + displaytest (alle dots aan)
    LEDS_Write(1);
    writeMax7221(SHUT_DOWN,1);              // driver aan
    writeMax7221(DISPLAY_TEST,1);           // displaytest aan
    writeMax7221(INTENSITY,15);             // max intensiteit
    writeMax7221(SCAN_LIMIT,7);             // alle digits
    writeMax7221(DECODE_MODE,0);            // geen 7-segment decoder nodig
    CyDelay(2000);
    LEDS_Write(0);
    writeMax7221(DISPLAY_TEST,0);           // displaytest uit
    clearDotDisplay();
    printChar((char)254);

    for(;;)
    {
        letter = UART_GetChar();
        schakelaars = SWITCHES_Read();
        LEDS_Write(schakelaars);
        if (letter != 0) 
        {
            
            UART_PutChar(letter); 
            printChar(letter);
        }
    }
}

/* [] END OF FILE */

