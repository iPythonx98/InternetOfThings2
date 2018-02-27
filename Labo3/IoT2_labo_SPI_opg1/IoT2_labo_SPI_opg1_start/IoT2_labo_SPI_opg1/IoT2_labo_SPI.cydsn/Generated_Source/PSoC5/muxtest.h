/*******************************************************************************
* File Name: muxtest.h
* Version 2.0
*
* Description:
*  Contains the function prototypes, constants and register definition of the
*  ADC SAR Sequencer Component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_muxtest_H)
    #define CY_muxtest_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h"
#include "muxtest_TempBuf_dma.h"
#include "muxtest_FinalBuf_dma.h"
#include "muxtest_SAR.h"

#define muxtest_NUMBER_OF_CHANNELS    (4u)
#define muxtest_SAMPLE_MODE           (0u)
#define muxtest_CLOCK_SOURCE          (0u)

extern int16  muxtest_finalArray[muxtest_NUMBER_OF_CHANNELS];
extern uint32 muxtest_initVar;

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component ADC_SAR_SEQ_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */


/***************************************
*        Function Prototypes
***************************************/
void muxtest_Init(void);
void muxtest_Enable(void);
void muxtest_Disable(void);
void muxtest_Start(void);
void muxtest_Stop(void);

uint32 muxtest_IsEndConversion(uint8 retMode);
int16 muxtest_GetResult16(uint16 chan);
int16 muxtest_GetAdcResult(void);
void muxtest_SetOffset(int32 offset);
void muxtest_SetResolution(uint8 resolution);
void muxtest_SetScaledGain(int32 adcGain);
int32 muxtest_CountsTo_mVolts(int16 adcCounts);
int32 muxtest_CountsTo_uVolts(int16 adcCounts);
float32 muxtest_CountsTo_Volts(int16 adcCounts);
void muxtest_Sleep(void);
void muxtest_Wakeup(void);
void muxtest_SaveConfig(void);
void muxtest_RestoreConfig(void);

CY_ISR_PROTO( muxtest_ISR );

/* Obsolete API for backward compatibility.
*  Should not be used in new designs.
*/
void muxtest_SetGain(int32 adcGain);


/**************************************
*    Initial Parameter Constants
**************************************/
#define muxtest_IRQ_REMOVE             (0u)                /* Removes internal interrupt */


/***************************************
*             Registers
***************************************/
#define muxtest_CYCLE_COUNTER_AUX_CONTROL_REG \
                                               (*(reg8 *) muxtest_bSAR_SEQ_ChannelCounter__CONTROL_AUX_CTL_REG)
#define muxtest_CYCLE_COUNTER_AUX_CONTROL_PTR \
                                               ( (reg8 *) muxtest_bSAR_SEQ_ChannelCounter__CONTROL_AUX_CTL_REG)
#define muxtest_CONTROL_REG    (*(reg8 *) \
                                             muxtest_bSAR_SEQ_CtrlReg__CONTROL_REG)
#define muxtest_CONTROL_PTR    ( (reg8 *) \
                                             muxtest_bSAR_SEQ_CtrlReg__CONTROL_REG)
#define muxtest_COUNT_REG      (*(reg8 *) \
                                             muxtest_bSAR_SEQ_ChannelCounter__COUNT_REG)
#define muxtest_COUNT_PTR      ( (reg8 *) \
                                             muxtest_bSAR_SEQ_ChannelCounter__COUNT_REG)
#define muxtest_STATUS_REG     (*(reg8 *) muxtest_bSAR_SEQ_EOCSts__STATUS_REG)
#define muxtest_STATUS_PTR     ( (reg8 *) muxtest_bSAR_SEQ_EOCSts__STATUS_REG)

#define muxtest_SAR_DATA_ADDR_0 (muxtest_SAR_ADC_SAR__WRK0)
#define muxtest_SAR_DATA_ADDR_1 (muxtest_SAR_ADC_SAR__WRK1)
#define muxtest_SAR_DATA_ADDR_0_REG (*(reg8 *) \
                                              muxtest_SAR_ADC_SAR__WRK0)
#define muxtest_SAR_DATA_ADDR_1_REG (*(reg8 *) \
                                              muxtest_SAR_ADC_SAR__WRK1)


/**************************************
*       Register Constants
**************************************/

#if(muxtest_IRQ_REMOVE == 0u)

    /* Priority of the ADC_SAR_IRQ interrupt. */
    #define muxtest_INTC_PRIOR_NUMBER          (uint8)(muxtest_IRQ__INTC_PRIOR_NUM)

    /* ADC_SAR_IRQ interrupt number */
    #define muxtest_INTC_NUMBER                (uint8)(muxtest_IRQ__INTC_NUMBER)

#endif   /* End muxtest_IRQ_REMOVE */


/***************************************
*       API Constants
***************************************/

/* Constants for IsEndConversion() "retMode" parameter */
#define muxtest_RETURN_STATUS              (0x01u)
#define muxtest_WAIT_FOR_RESULT            (0x00u)

/* Defines for the Resolution parameter */
#define muxtest_BITS_12    muxtest_SAR__BITS_12
#define muxtest_BITS_10    muxtest_SAR__BITS_10
#define muxtest_BITS_8     muxtest_SAR__BITS_8

#define muxtest_CYCLE_COUNTER_ENABLE    (0x20u)
#define muxtest_BASE_COMPONENT_ENABLE   (0x01u)
#define muxtest_LOAD_COUNTER_PERIOD     (0x02u)
#define muxtest_SOFTWARE_SOC_PULSE      (0x04u)

/* Generic DMA Configuration parameters */
#define muxtest_TEMP_BYTES_PER_BURST     (uint8)(2u)
#define muxtest_TEMP_TRANSFER_COUNT      ((uint16)muxtest_NUMBER_OF_CHANNELS << 1u)
#define muxtest_FINAL_BYTES_PER_BURST    ((uint16)muxtest_NUMBER_OF_CHANNELS << 1u)
#define muxtest_REQUEST_PER_BURST        (uint8)(1u)

#define muxtest_GET_RESULT_INDEX_OFFSET    ((uint8)muxtest_NUMBER_OF_CHANNELS - 1u)

/* Define for Sample Mode  */
#define muxtest_SAMPLE_MODE_FREE_RUNNING    (0x00u)
#define muxtest_SAMPLE_MODE_SW_TRIGGERED    (0x01u)
#define muxtest_SAMPLE_MODE_HW_TRIGGERED    (0x02u)

/* Define for Clock Source  */
#define muxtest_CLOCK_INTERNAL              (0x00u)
#define muxtest_CLOCK_EXTERNAL              (0x01u)


/***************************************
*        Optional Function Prototypes
***************************************/
#if(muxtest_SAMPLE_MODE != muxtest_SAMPLE_MODE_HW_TRIGGERED)
    void muxtest_StartConvert(void);
    void muxtest_StopConvert(void);
#endif /* muxtest_SAMPLE_MODE != muxtest_SAMPLE_MODE_HW_TRIGGERED */

#endif  /* !defined(CY_muxtest_H) */

/* [] END OF FILE */
