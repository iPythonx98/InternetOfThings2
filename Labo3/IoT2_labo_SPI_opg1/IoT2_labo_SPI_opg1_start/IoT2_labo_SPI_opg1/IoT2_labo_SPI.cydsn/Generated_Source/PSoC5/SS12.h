/*******************************************************************************
* File Name: SS12.h  
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

#if !defined(CY_PINS_SS12_H) /* Pins SS12_H */
#define CY_PINS_SS12_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SS12_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SS12__PORT == 15 && ((SS12__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SS12_Write(uint8 value);
void    SS12_SetDriveMode(uint8 mode);
uint8   SS12_ReadDataReg(void);
uint8   SS12_Read(void);
void    SS12_SetInterruptMode(uint16 position, uint16 mode);
uint8   SS12_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SS12_SetDriveMode() function.
     *  @{
     */
        #define SS12_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SS12_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SS12_DM_RES_UP          PIN_DM_RES_UP
        #define SS12_DM_RES_DWN         PIN_DM_RES_DWN
        #define SS12_DM_OD_LO           PIN_DM_OD_LO
        #define SS12_DM_OD_HI           PIN_DM_OD_HI
        #define SS12_DM_STRONG          PIN_DM_STRONG
        #define SS12_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SS12_MASK               SS12__MASK
#define SS12_SHIFT              SS12__SHIFT
#define SS12_WIDTH              1u

/* Interrupt constants */
#if defined(SS12__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SS12_SetInterruptMode() function.
     *  @{
     */
        #define SS12_INTR_NONE      (uint16)(0x0000u)
        #define SS12_INTR_RISING    (uint16)(0x0001u)
        #define SS12_INTR_FALLING   (uint16)(0x0002u)
        #define SS12_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SS12_INTR_MASK      (0x01u) 
#endif /* (SS12__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SS12_PS                     (* (reg8 *) SS12__PS)
/* Data Register */
#define SS12_DR                     (* (reg8 *) SS12__DR)
/* Port Number */
#define SS12_PRT_NUM                (* (reg8 *) SS12__PRT) 
/* Connect to Analog Globals */                                                  
#define SS12_AG                     (* (reg8 *) SS12__AG)                       
/* Analog MUX bux enable */
#define SS12_AMUX                   (* (reg8 *) SS12__AMUX) 
/* Bidirectional Enable */                                                        
#define SS12_BIE                    (* (reg8 *) SS12__BIE)
/* Bit-mask for Aliased Register Access */
#define SS12_BIT_MASK               (* (reg8 *) SS12__BIT_MASK)
/* Bypass Enable */
#define SS12_BYP                    (* (reg8 *) SS12__BYP)
/* Port wide control signals */                                                   
#define SS12_CTL                    (* (reg8 *) SS12__CTL)
/* Drive Modes */
#define SS12_DM0                    (* (reg8 *) SS12__DM0) 
#define SS12_DM1                    (* (reg8 *) SS12__DM1)
#define SS12_DM2                    (* (reg8 *) SS12__DM2) 
/* Input Buffer Disable Override */
#define SS12_INP_DIS                (* (reg8 *) SS12__INP_DIS)
/* LCD Common or Segment Drive */
#define SS12_LCD_COM_SEG            (* (reg8 *) SS12__LCD_COM_SEG)
/* Enable Segment LCD */
#define SS12_LCD_EN                 (* (reg8 *) SS12__LCD_EN)
/* Slew Rate Control */
#define SS12_SLW                    (* (reg8 *) SS12__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SS12_PRTDSI__CAPS_SEL       (* (reg8 *) SS12__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SS12_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SS12__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SS12_PRTDSI__OE_SEL0        (* (reg8 *) SS12__PRTDSI__OE_SEL0) 
#define SS12_PRTDSI__OE_SEL1        (* (reg8 *) SS12__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SS12_PRTDSI__OUT_SEL0       (* (reg8 *) SS12__PRTDSI__OUT_SEL0) 
#define SS12_PRTDSI__OUT_SEL1       (* (reg8 *) SS12__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SS12_PRTDSI__SYNC_OUT       (* (reg8 *) SS12__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SS12__SIO_CFG)
    #define SS12_SIO_HYST_EN        (* (reg8 *) SS12__SIO_HYST_EN)
    #define SS12_SIO_REG_HIFREQ     (* (reg8 *) SS12__SIO_REG_HIFREQ)
    #define SS12_SIO_CFG            (* (reg8 *) SS12__SIO_CFG)
    #define SS12_SIO_DIFF           (* (reg8 *) SS12__SIO_DIFF)
#endif /* (SS12__SIO_CFG) */

/* Interrupt Registers */
#if defined(SS12__INTSTAT)
    #define SS12_INTSTAT            (* (reg8 *) SS12__INTSTAT)
    #define SS12_SNAP               (* (reg8 *) SS12__SNAP)
    
	#define SS12_0_INTTYPE_REG 		(* (reg8 *) SS12__0__INTTYPE)
#endif /* (SS12__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SS12_H */


/* [] END OF FILE */
