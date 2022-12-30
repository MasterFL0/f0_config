/**
 \brief The file contains projects' settings
 */
#ifndef GLOBALCONFIG_HPP
#define GLOBALCONFIG_HPP

#ifdef __ICCARM__

/// ������� �������� ������. ��� �������� ������ ���� ������
/// � � ���� FreeRTOSConfig.h
/// � ��������� ������ configCPU_CLOCK_HZ
#define MAIN_OSC_FREQ           12000000

// ������� ���� ��� ���������� �������� �����
#define MAIN_STACK_WATER_MARK   0xcafecabe

/** ���������� � 1, ���� �������� ��������, ����� � 0. � �������� �������� ����������� �������� �����
 * � �������, � ����� �������������� ���� � ��������� ������ */
#define RELEASE_SOFTWARE        0

// ������ (�������) �����
#define PCB_REVISION            1

// ����� ���������� ����������
#define DEBUG_COMMUTATOR        1

// ���������� ������������ ��� ��� ������������� DAQ
#define EXT_RAM_CONTINUOUS_TEST 0

// �������� ������ (������ ������ �������, � ������ ��������� �������������)
#define USE_WDT                 0
#define COMMUNICATION_BT_IFACE  1
#define SYSTEM_CLOCK            48000000UL

#define DBG_CONSOLE_UART_NUM    N1
#define LINK_UART_NUM           N2

/* �������������� ������� ��������� ���������� �������� ��� ������ */
/* �� �������!!!!!!*/
#if( RELEASE_SOFTWARE == 1 )
#undef  USE_WDT
#define USE_WDT                 1
#endif


/* Interrupts Priority (0(highest)...0x03(lowest)) */
#define I2C1_IRQ_PRIORITY              0x03
#define I2C2_IRQ_PRIORITY              0x03
#define SSP1_IRQ_PRIORITY              0x03
#define SSP2_IRQ_PRIORITY              0x03
#define TIM1_IRQ_PRIORITY              0x00 // ����� ��� ���� ����������
#define FRAME_PROCESSING_IRQ_PRIORITY  0x01 // ������������ ����� ��������� ������ NVIC ��� ��������� �������������� ������
#define TIM2_IRQ_PRIORITY              0x03
#define TIM3_IRQ_PRIORITY              0x03
#define TIM14_IRQ_PRIORITY             0x03
#define TIM15_IRQ_PRIORITY             0x03
#define TIM16_IRQ_PRIORITY             0x03
#define TIM17_IRQ_PRIORITY             0x03
#define DMA_IRQ_PRIORITY               0x02 // ����� ��� ���� ��� � �������
#define ADC_IRQ_PRIORITY               0x03
#define UART_IRQ_PRIORITY              0x00
#define EXTI0_1_IRQ_PRIORITY           0x03
#define EXTI2_3_IRQ_PRIORITY           0x03
#define EXTI4_15_IRQ_PRIORITY          0x03
#endif  // __ICCARM__

#endif  // GLOBALCONFIG_HPP
