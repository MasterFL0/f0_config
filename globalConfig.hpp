/**
 \brief The file contains projects' settings
 */
#ifndef GLOBALCONFIG_HPP
#define GLOBALCONFIG_HPP

#ifdef __ICCARM__

/// Частота внешнего кварца. Для указания часоты ядра перейт
/// и в файл FreeRTOSConfig.h
/// и настроить макрос configCPU_CLOCK_HZ
#define MAIN_OSC_FREQ           12000000

// Водяной знак для заполнения главного стэка
#define MAIN_STACK_WATER_MARK   0xcafecabe

/** Установить в 1, если прошивка релизная, иначе в 0. В релизной прошивке отключается дебажный вывод
 * в консоль, а также запароливается вход в командную строку */
#define RELEASE_SOFTWARE        0

// Версия (ревизия) платы
#define PCB_REVISION            1

// Вывод отладочной информации
#define DEBUG_COMMUTATOR        1

// Бесконечно тестирование ОЗУ при инициализации DAQ
#define EXT_RAM_CONTINUOUS_TEST 0

// Включить собаку (иногда мешает отладке, в релизе включится автоматически)
#define USE_WDT                 0
#define COMMUNICATION_BT_IFACE  1
#define SYSTEM_CLOCK            48000000UL

#define DBG_CONSOLE_UART_NUM    N1
#define LINK_UART_NUM           N2

/* Автоматическое гашение некоторых отладочных макросов для релиза */
/* Не править!!!!!!*/
#if( RELEASE_SOFTWARE == 1 )
#undef  USE_WDT
#define USE_WDT                 1
#endif


/* Interrupts Priority (0(highest)...0x03(lowest)) */
#define I2C1_IRQ_PRIORITY              0x03
#define I2C2_IRQ_PRIORITY              0x03
#define SSP1_IRQ_PRIORITY              0x03
#define SSP2_IRQ_PRIORITY              0x03
#define TIM1_IRQ_PRIORITY              0x00 // общий для двух прерываний
#define FRAME_PROCESSING_IRQ_PRIORITY  0x01 // используется любой свободный вектор NVIC для обработки измерительного фрейма
#define TIM2_IRQ_PRIORITY              0x03
#define TIM3_IRQ_PRIORITY              0x03
#define TIM14_IRQ_PRIORITY             0x03
#define TIM15_IRQ_PRIORITY             0x03
#define TIM16_IRQ_PRIORITY             0x03
#define TIM17_IRQ_PRIORITY             0x03
#define DMA_IRQ_PRIORITY               0x02 // общий для всех ПДП и каналов
#define ADC_IRQ_PRIORITY               0x03
#define UART_IRQ_PRIORITY              0x00
#define EXTI0_1_IRQ_PRIORITY           0x03
#define EXTI2_3_IRQ_PRIORITY           0x03
#define EXTI4_15_IRQ_PRIORITY          0x03
#endif  // __ICCARM__

#endif  // GLOBALCONFIG_HPP
