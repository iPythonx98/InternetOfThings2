/*******************************************************************************
* File Name: SS11.h  
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

#if !defined(CY_PINS_SS11_H) /* Pins SS11_H */
#define CY_PINS_SS11_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SS11_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SS11__PORT == 15 && ((SS11__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SS11_Write(uint8 value);
void    SS11_SetDriveMode(uint8 mode);
uint8   SS11_ReadDataReg(void);
uint8   SS11_Read(void);
void    SS11_SetInterruptMode(uint16 position, uint16 mode);
uint8   SS11_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SS11_SetDriveMode() function.
     *  @{
     */
        #define SS11_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SS11_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SS11_DM_RES_UP          PIN_DM_RES_UP
        #define SS11_DM_RES_DWN         PIN_DM_RES_DWN
        #define SS11_DM_OD_LO           PIN_DM_OD_LO
        #define SS11_DM_OD_HI           PIN_DM_OD_HI
        #define SS11_DM_STRONG          PIN_DM_STRONG
        #define SS11_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SS11_MASK               SS11__MASK
#define SS11_SHIFT              SS11__SHIFT
#define SS11_WIDTH              1u

/* Interrupt constants */
#if defined(SS11__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SS11_SetInterruptMode() function.
     *  @{
     */
        #define SS11_INTR_NONE      (uint16)(0x0000u)
        #define SS11_INTR_RISING    (uint16)(0x0001u)
        #define SS11_INTR_FALLING   (uint16)(0x0002u)
        #define SS11_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SS11_INTR_MASK      (0x01u) 
#endif /* (SS11__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SS11_PS                     (* (reg8 *) SS11__PS)
/* Data Register */
#define SS11_DR                     (* (reg8 *) SS11__DR)
/* Port Number */
#define SS11_PRT_NUM                (* (reg8 *) SS11__PRT) 
/* Connect to Analog Globals */                                                  
#define SS11_AG                     (* (reg8 *) SS11__AG)                       
/* Analog MUX bux enable */
#define SS11_AMUX                   (* (reg8 *) SS11__AMUX) 
/* Bidirectional Enable */                                                        
#define SS11_BIE                    (* (reg8 *) SS11__BIE)
/* Bit-mask for Aliased Register Access */
#define SS11_BIT_MASK               (* (reg8 *) SS11__BIT_MASK)
/* Bypass Enable */
#define SS11_BYP                    (* (reg8 *) SS11__BYP)
/* Port wide control signals */                                                   
#define SS11_CTL                    (* (reg8 *) SS11__CTL)
/* Drive Modes */
#define SS11_DM0                    (* (reg8 *) SS11__DM0) 
#define SS11_DM1                    (* (reg8 *) SS11__DM1)
#define SS11_DM2                    (* (reg8 *) SS11__DM2) 
/* Input Buffer Disable Override */
#define SS11_INP_DIS                (* (reg8 *) SS11__INP_DIS)
/* LCD Common or Segment Drive */
#define SS11_LCD_COM_SEG            (* (reg8 *) SS11__LCD_COM_SEG)
/* Enable Segment LCD */
#define SS11_LCD_EN                 (* (reg8 *) SS11__LCD_EN)
/* Slew Rate Control */
#define SS11_SLW                    (* (reg8 *) SS11__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SS11_PRTDSI__CAPS_SEL       (* (reg8 *) SS11__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SS11_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SS11__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SS11_PRTDSI__OE_SEL0        (* (reg8 *) SS11__PRTDSI__OE_SEL0) 
#define SS11_PRTDSI__OE_SEL1        (* (reg8 *) SS11__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SS11_PRTDSI__OUT_SEL0       (* (reg8 *) SS11__PRTDSI__OUT_SEL0) 
#define SS11_PRTDSI__OUT_SEL1       (* (reg8 *) SS11__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SS11_PRTDSI__SYNC_OUT       (* (reg8 *) SS11__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SS11__SIO_CFG)
    #define SS11_SIO_HYST_EN        (* (reg8 *) SS11__SIO_HYST_EN)
    #define SS11_SIO_REG_HIFREQ     (* (reg8 *) SS11__SIO_REG_HIFREQ)
    #define SS11_SIO_CFG            (* (reg8 *) SS11__SIO_CFG)
    #define SS11_SIO_DIFF           (* (reg8 *) SS11__SIO_DIFF)
#endif /* (SS11__SIO_CFG) */

/* Interrupt Registers */
#if defined(SS11__INTSTAT)
    #define SS11_INTSTAT            (* (reg8 *) SS11__INTSTAT)
    #define SS11_SNAP               (* (reg8 *) SS11__SNAP)
    
	#define SS11_0_INTTYPE_REG 		(* (reg8 *) SS11__0__INTTYPE)
#endif /* (SS11__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SS11_H */


/* [] END OF FILE */
