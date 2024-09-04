/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v15.0
processor: MKL25Z128xxx4
package_id: MKL25Z128VLK4
mcu_data: ksdk2_0
processor_version: 13.0.1
board: FRDM-KL25Z
external_user_signals: {}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '28', peripheral: UART0, signal: TX, pin_signal: TSI0_CH3/PTA2/UART0_TX/TPM2_CH1}
  - {pin_num: '27', peripheral: UART0, signal: RX, pin_signal: TSI0_CH2/PTA1/UART0_RX/TPM2_CH0}
  - {pin_num: '2', peripheral: SPI1, signal: SIN, pin_signal: PTE1/SPI1_MOSI/UART1_RX/SPI1_MISO/I2C1_SCL}
  - {pin_num: '3', peripheral: SPI1, signal: SCK, pin_signal: PTE2/SPI1_SCK}
  - {pin_num: '4', peripheral: SPI1, signal: SOUT, pin_signal: PTE3/SPI1_MISO/SPI1_MOSI}
  - {pin_num: '5', peripheral: SPI1, signal: PCS0_SS, pin_signal: PTE4/SPI1_PCS0}
  - {pin_num: '13', peripheral: ADC0, signal: 'SE, 0', pin_signal: ADC0_DP0/ADC0_SE0/PTE20/TPM1_CH0/UART0_TX}
  - {pin_num: '14', peripheral: TPM1, signal: 'CH, 1', pin_signal: ADC0_DM0/ADC0_SE4a/PTE21/TPM1_CH1/UART0_RX}
  - {pin_num: '15', peripheral: UART2, signal: TX, pin_signal: ADC0_DP3/ADC0_SE3/PTE22/TPM2_CH0/UART2_TX}
  - {pin_num: '16', peripheral: UART2, signal: RX, pin_signal: ADC0_DM3/ADC0_SE7a/PTE23/TPM2_CH1/UART2_RX}
  - {pin_num: '24', peripheral: I2C0, signal: SCL, pin_signal: PTE24/TPM0_CH0/I2C0_SCL}
  - {pin_num: '25', peripheral: I2C0, signal: SDA, pin_signal: PTE25/TPM0_CH1/I2C0_SDA}
  - {pin_num: '34', peripheral: GPIOA, signal: 'GPIO, 14', pin_signal: PTA14/SPI0_PCS0/UART0_TX}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void)
{
    /* Port A Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortA);
    /* Port E Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortE);

    /* PORTA1 (pin 27) is configured as UART0_RX */
    PORT_SetPinMux(BOARD_INITPINS_DEBUG_UART_RX_PORT, BOARD_INITPINS_DEBUG_UART_RX_PIN, kPORT_MuxAlt2);

    /* PORTA14 (pin 34) is configured as PTA14 */
    PORT_SetPinMux(BOARD_INITPINS_ACCEL_INT1_PORT, BOARD_INITPINS_ACCEL_INT1_PIN, kPORT_MuxAsGpio);

    /* PORTA2 (pin 28) is configured as UART0_TX */
    PORT_SetPinMux(BOARD_INITPINS_DEBUG_UART_TX_PORT, BOARD_INITPINS_DEBUG_UART_TX_PIN, kPORT_MuxAlt2);

    /* PORTE1 (pin 2) is configured as SPI1_MISO */
    PORT_SetPinMux(PORTE, 1U, kPORT_MuxAlt5);

    /* PORTE2 (pin 3) is configured as SPI1_SCK */
    PORT_SetPinMux(PORTE, 2U, kPORT_MuxAlt2);

    /* PORTE20 (pin 13) is configured as ADC0_SE0 */
    PORT_SetPinMux(PORTE, 20U, kPORT_PinDisabledOrAnalog);

    /* PORTE21 (pin 14) is configured as TPM1_CH1 */
    PORT_SetPinMux(PORTE, 21U, kPORT_MuxAlt3);

    /* PORTE22 (pin 15) is configured as UART2_TX */
    PORT_SetPinMux(PORTE, 22U, kPORT_MuxAlt4);

    /* PORTE23 (pin 16) is configured as UART2_RX */
    PORT_SetPinMux(PORTE, 23U, kPORT_MuxAlt4);

    /* PORTE24 (pin 24) is configured as I2C0_SCL */
    PORT_SetPinMux(BOARD_INITPINS_ACCEL_SCL_PORT, BOARD_INITPINS_ACCEL_SCL_PIN, kPORT_MuxAlt5);

    /* PORTE25 (pin 25) is configured as I2C0_SDA */
    PORT_SetPinMux(BOARD_INITPINS_ACCEL_SDA_PORT, BOARD_INITPINS_ACCEL_SDA_PIN, kPORT_MuxAlt5);

    /* PORTE3 (pin 4) is configured as SPI1_MOSI */
    PORT_SetPinMux(PORTE, 3U, kPORT_MuxAlt5);

    /* PORTE4 (pin 5) is configured as SPI1_PCS0 */
    PORT_SetPinMux(PORTE, 4U, kPORT_MuxAlt2);

    SIM->SOPT5 = ((SIM->SOPT5 &
                   /* Mask bits to zero which are setting */
                   (~(SIM_SOPT5_UART0TXSRC_MASK | SIM_SOPT5_UART0RXSRC_MASK)))

                  /* UART0 transmit data source select: UART0_TX pin. */
                  | SIM_SOPT5_UART0TXSRC(SOPT5_UART0TXSRC_UART_TX)

                  /* UART0 receive data source select: UART0_RX pin. */
                  | SIM_SOPT5_UART0RXSRC(SOPT5_UART0RXSRC_UART_RX));
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
