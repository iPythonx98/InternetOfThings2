/* ===================================================================================
 *
 * Basisproject voor de SPI-print met dot-matrixdisplays 788BS, 
 *     in combinatie met een MAX7221
 *
 * De font dient een 8x8 pixel font te zijn die minstens alle ASCII-karakters bevat
 *
 * Piet Coussens 31/1/18
 * Startproject voor Labo IoT2 UART-proef
 *
 * ===================================================================================
*/
#define scanspeed   500   /* tijd tussen 2 karakters in ms */
#define SPIwacht    50    /* us verwerkingstijd drivers */

#include "project.h"
#include "max7221.h"

#include "console_font_8x8.h"
#define FONT console_font_8x8
#define FONT_MIN 0
#define FONT_MAX 255

void WriteMax7221(uint8 adres, uint8 data)
{
    while ((SPIM_ReadTxStatus()& SPIM_STS_TX_FIFO_NOT_FULL) == 0);  // wacht tot er plaats is in de Tx buffer
    SPIM_WriteTxData(((uint16)adres<<8)|data);
    CyDelayUs(50);
}    

void ClearDotDisplay()
// Deze routine wist het dotmatrixdisplay
{
    uint8 rij;
    for (rij=0;rij<8;rij++)
    {
        WriteMax7221(DIGIT_0+rij,0);
        CyDelayUs(100);
    }
}

void PrintChar(uint8 karakter)
// deze routine drukt een karakter af op het dotmatrixdisplay
{
    uint8 rij;
    WriteMax7221(SHUT_DOWN,0);              // driver UIT
    for(rij=0;rij<8; rij++)
        WriteMax7221(DIGIT_0+rij,FONT[karakter][rij]);
    WriteMax7221(SHUT_DOWN,1);              // driver aan
}

void InitDisplay()
{
    // initialiseer displaydriver + displaytest (alle dots aan)
    WriteMax7221(SHUT_DOWN,1);              // driver aan
    WriteMax7221(DISPLAY_TEST,1);           // displaytest aan
    WriteMax7221(INTENSITY,15);             // max intensiteit
    WriteMax7221(SCAN_LIMIT,7);             // alle digits
    WriteMax7221(DECODE_MODE,0);            // geen 7-segment decoder nodig
    CyDelay(2000);
    LEDS_Write(0);
    WriteMax7221(DISPLAY_TEST,0);           // displaytest uit
    ClearDotDisplay();
    PrintChar(254);
}

int main(void)
{
//    uint8 letter, vletter, 
    uint8 schakelaars;

    CyGlobalIntEnable;                      // Enable global interrupts
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    SPIM_Start();
//     UART_Start();
    InitDisplay();
    LEDS_Write(0);

    for(;;)
    /* Place your normal code here (e.g. MyProgram()) */
    {
        schakelaars = SWITCHES_Read();
        LEDS_Write(schakelaars);
    }
}

