/*******************************************************************************
* File Name: muxtest_PM.c
* Version 2.0
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "muxtest.h"
#include "muxtest_SAR.h"
#if(muxtest_CLOCK_SOURCE == muxtest_CLOCK_INTERNAL)
    #include "muxtest_IntClock.h"
#endif   /* muxtest_CLOCK_SOURCE == muxtest_CLOCK_INTERNAL */


/*******************************************************************************
* Function Name: muxtest_Sleep
********************************************************************************
*
* Summary:
*  Stops the ADC operation and saves the configuration registers and component
*  enable state. Should be called just prior to entering sleep
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void muxtest_Sleep(void)
{
    muxtest_SAR_Stop();
    muxtest_SAR_Sleep();
    muxtest_Disable();

    #if(muxtest_CLOCK_SOURCE == muxtest_CLOCK_INTERNAL)
        muxtest_IntClock_Stop();
    #endif   /* muxtest_CLOCK_SOURCE == muxtest_CLOCK_INTERNAL */
}


/*******************************************************************************
* Function Name: muxtest_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component enable state and configuration registers. This should
*  be called just after awaking from sleep mode
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void muxtest_Wakeup(void)
{
    muxtest_SAR_Wakeup();
    muxtest_SAR_Enable();

    #if(muxtest_CLOCK_SOURCE == muxtest_CLOCK_INTERNAL)
        muxtest_IntClock_Start();
    #endif   /* muxtest_CLOCK_SOURCE == muxtest_CLOCK_INTERNAL */

    /* The block is ready to use 10 us after the SAR enable signal is set high. */
    CyDelayUs(10u);
    
    muxtest_Enable();

    #if(muxtest_SAMPLE_MODE == muxtest_SAMPLE_MODE_FREE_RUNNING)
        muxtest_SAR_StartConvert();
    #endif /* (muxtest_SAMPLE_MODE == muxtest_SAMPLE_MODE_FREE_RUNNING) */

    (void) CY_GET_REG8(muxtest_STATUS_PTR);
}


/*******************************************************************************
* Function Name: muxtest_SaveConfig
********************************************************************************
*
* Summary:
*  Save the current configuration of ADC non-retention registers
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void muxtest_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: muxtest_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the configuration of ADC non-retention registers
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void muxtest_RestoreConfig(void)
{

}


/* [] END OF FILE */
