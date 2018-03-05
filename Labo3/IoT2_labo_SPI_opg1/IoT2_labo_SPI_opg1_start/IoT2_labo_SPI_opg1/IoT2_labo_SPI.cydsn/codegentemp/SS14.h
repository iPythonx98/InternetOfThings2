/*******************************************************************************
* File Name: SS14.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_SS14_H) /* Pins SS14_H */
#define CY_PINS_SS14_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SS14_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SS14__PORT == 15 && ((SS14__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SS14_Write(uint8 value);
void    SS14_SetDriveMode(uint8 mode);
uint8   SS14_ReadDataReg(void);
uint8   SS14_Read(void);
void    SS14_SetInterruptMode(uint16 position, uint16 mode);
uint8   SS14_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SS14_SetDriveMode() function.
     *  @{
     */
        #define SS14_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SS14_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SS14_DM_RES_UP          PIN_DM_RES_UP
        #define SS14_DM_RES_DWN         PIN_DM_RES_DWN
        #define SS14_DM_OD_LO           PIN_DM_OD_LO
        #define SS14_DM_OD_HI           PIN_DM_OD_HI
        #define SS14_DM_STRONG          PIN_DM_STRONG
        #define SS14_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SS14_MASK               SS14__MASK
#define SS14_SHIFT              SS14__SHIFT
#define SS14_WIDTH              1u

/* Interrupt constants */
#if defined(SS14__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SS14_SetInterruptMode() function.
     *  @{
     */
        #define SS14_INTR_NONE      (uint16)(0x0000u)
        #define SS14_INTR_RISING    (uint16)(0x0001u)
        #define SS14_INTR_FALLING   (uint16)(0x0002u)
        #define SS14_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SS14_INTR_MASK      (0x01u) 
#endif /* (SS14__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SS14_PS                     (* (reg8 *) SS14__PS)
/* Data Register */
#define SS14_DR                     (* (reg8 *) SS14__DR)
/* Port Number */
#define SS14_PRT_NUM                (* (reg8 *) SS14__PRT) 
/* Connect to Analog Globals */                                                  
#define SS14_AG                     (* (reg8 *) SS14__AG)                       
/* Analog MUX bux enable */
#define SS14_AMUX                   (* (reg8 *) SS14__AMUX) 
/* Bidirectional Enable */                                                        
#define SS14_BIE                    (* (reg8 *) SS14__BIE)
/* Bit-mask for Aliased Register Access */
#define SS14_BIT_MASK               (* (reg8 *) SS14__BIT_MASK)
/* Bypass Enable */
#define SS14_BYP                    (* (reg8 *) SS14__BYP)
/* Port wide control signals */                                                   
#define SS14_CTL                    (* (reg8 *) SS14__CTL)
/* Drive Modes */
#define SS14_DM0                    (* (reg8 *) SS14__DM0) 
#define SS14_DM1                    (* (reg8 *) SS14__DM1)
#define SS14_DM2                    (* (reg8 *) SS14__DM2) 
/* Input Buffer Disable Override */
#define SS14_INP_DIS                (* (reg8 *) SS14__INP_DIS)
/* LCD Common or Segment Drive */
#define SS14_LCD_COM_SEG            (* (reg8 *) SS14__LCD_COM_SEG)
/* Enable Segment LCD */
#define SS14_LCD_EN                 (* (reg8 *) SS14__LCD_EN)
/* Slew Rate Control */
#define SS14_SLW                    (* (reg8 *) SS14__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SS14_PRTDSI__CAPS_SEL       (* (reg8 *) SS14__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SS14_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SS14__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SS14_PRTDSI__OE_SEL0        (* (reg8 *) SS14__PRTDSI__OE_SEL0) 
#define SS14_PRTDSI__OE_SEL1        (* (reg8 *) SS14__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SS14_PRTDSI__OUT_SEL0       (* (reg8 *) SS14__PRTDSI__OUT_SEL0) 
#define SS14_PRTDSI__OUT_SEL1       (* (reg8 *) SS14__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SS14_PRTDSI__SYNC_OUT       (* (reg8 *) SS14__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SS14__SIO_CFG)
    #define SS14_SIO_HYST_EN        (* (reg8 *) SS14__SIO_HYST_EN)
    #define SS14_SIO_REG_HIFREQ     (* (reg8 *) SS14__SIO_REG_HIFREQ)
    #define SS14_SIO_CFG            (* (reg8 *) SS14__SIO_CFG)
    #define SS14_SIO_DIFF           (* (reg8 *) SS14__SIO_DIFF)
#endif /* (SS14__SIO_CFG) */

/* Interrupt Registers */
#if defined(SS14__INTSTAT)
    #define SS14_INTSTAT            (* (reg8 *) SS14__INTSTAT)
    #define SS14_SNAP               (* (reg8 *) SS14__SNAP)
    
	#define SS14_0_INTTYPE_REG 		(* (reg8 *) SS14__0__INTTYPE)
#endif /* (SS14__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SS14_H */


/* [] END OF FILE */
