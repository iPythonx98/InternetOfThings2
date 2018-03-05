/*******************************************************************************
* File Name: SWITCHES.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware to read the value of a Status 
*  Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "SWITCHES.h"

#if !defined(SWITCHES_sts_sts_reg__REMOVED) /* Check for removal by optimization */


/*******************************************************************************
* Function Name: SWITCHES_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The current value in the Status Register.
*
*******************************************************************************/
uint8 SWITCHES_Read(void) 
{ 
    return SWITCHES_Status;
}


/*******************************************************************************
* Function Name: SWITCHES_InterruptEnable
********************************************************************************
*
* Summary:
*  Enables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SWITCHES_InterruptEnable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    SWITCHES_Status_Aux_Ctrl |= SWITCHES_STATUS_INTR_ENBL;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: SWITCHES_InterruptDisable
********************************************************************************
*
* Summary:
*  Disables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SWITCHES_InterruptDisable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    SWITCHES_Status_Aux_Ctrl &= (uint8)(~SWITCHES_STATUS_INTR_ENBL);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: SWITCHES_WriteMask
********************************************************************************
*
* Summary:
*  Writes the current mask value assigned to the Status Register.
*
* Parameters:
*  mask:  Value to write into the mask register.
*
* Return:
*  None.
*
*******************************************************************************/
void SWITCHES_WriteMask(uint8 mask) 
{
    #if(SWITCHES_INPUTS < 8u)
    	mask &= ((uint8)(1u << SWITCHES_INPUTS) - 1u);
	#endif /* End SWITCHES_INPUTS < 8u */
    SWITCHES_Status_Mask = mask;
}


/*******************************************************************************
* Function Name: SWITCHES_ReadMask
********************************************************************************
*
* Summary:
*  Reads the current interrupt mask assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The value of the interrupt mask of the Status Register.
*
*******************************************************************************/
uint8 SWITCHES_ReadMask(void) 
{
    return SWITCHES_Status_Mask;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
