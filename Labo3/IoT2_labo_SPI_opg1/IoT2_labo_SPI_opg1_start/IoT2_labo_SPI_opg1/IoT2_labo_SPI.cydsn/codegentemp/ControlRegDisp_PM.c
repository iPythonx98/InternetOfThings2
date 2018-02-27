/*******************************************************************************
* File Name: ControlRegDisp_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "ControlRegDisp.h"

/* Check for removal by optimization */
#if !defined(ControlRegDisp_Sync_ctrl_reg__REMOVED)

static ControlRegDisp_BACKUP_STRUCT  ControlRegDisp_backup = {0u};

    
/*******************************************************************************
* Function Name: ControlRegDisp_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ControlRegDisp_SaveConfig(void) 
{
    ControlRegDisp_backup.controlState = ControlRegDisp_Control;
}


/*******************************************************************************
* Function Name: ControlRegDisp_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void ControlRegDisp_RestoreConfig(void) 
{
     ControlRegDisp_Control = ControlRegDisp_backup.controlState;
}


/*******************************************************************************
* Function Name: ControlRegDisp_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ControlRegDisp_Sleep(void) 
{
    ControlRegDisp_SaveConfig();
}


/*******************************************************************************
* Function Name: ControlRegDisp_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ControlRegDisp_Wakeup(void)  
{
    ControlRegDisp_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
