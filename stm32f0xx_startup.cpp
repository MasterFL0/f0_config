#include "core\system_stm32f0xx.h"
#include "globalConfig.hpp"
/*add Drivers with IRQ*/

#include "drivers/exti/stm32f0_exti.hpp"
#include "drivers\sysclk\sysclk.hpp"
/*----------*/

//#define MAIN_STACK_BLOCK_NAME "CSTACK"
//#pragma section = MAIN_STACK_BLOCK_NAME
//static void mainStackFillWaterMark() {
//    auto * pMainStack = static_cast<uint32_t *>(__section_begin(MAIN_STACK_BLOCK_NAME));
//    auto mainStackSize = __section_size(MAIN_STACK_BLOCK_NAME) / 4;
//    while (pMainStack && mainStackSize--)
//        *pMainStack++ = MAIN_STACK_WATER_MARK;
//}

typedef union VectorEntry_t {
    void ( *pHandler )();
    void * pStack;
}VectorEntry_t;

// IAR entry point
extern "C" void __iar_program_start();
extern "C" void HardFault_Handler_ext();

static __noreturn void reset() {
  //  mainStackFillWaterMark();
    SystemInit();
    __iar_program_start();
    while (1);
}
// В эти обработчики мы никогда не должны попасть, но если попали эта ошибка гораздо
// важнее неработающей консоли, т.к. говорит о серьёзной неисправности
static void NMI_DefaultHandler() {
    //configASSERT(0);
}
static void Reserved_DefaultHandler() {
    //configASSERT(0);
}
static void IRQ_DefaultHandler() {
    //configASSERT(0);
}

extern unsigned char CSTACK$$Limit;
#pragma location = ".intvec"
extern "C" const __root VectorEntry_t __vector_table[] = {
    {.pStack = &CSTACK$$Limit },                            // stack        0
    {.pHandler = reset        },                            // reset        1
    NMI_DefaultHandler,                                     // NMI          2
    HardFault_Handler_ext,                                  // HardFault    3
    Reserved_DefaultHandler,                                // Reserved     4
    Reserved_DefaultHandler,                                // Reserved     5
    Reserved_DefaultHandler,                                // Reserved     6
    Reserved_DefaultHandler,                                // Reserved     7
    Reserved_DefaultHandler,                                // Reserved     8
    Reserved_DefaultHandler,                                // Reserved     9
    Reserved_DefaultHandler,                                // Reserved     10
    Reserved_DefaultHandler,                                // SVC          11
    Reserved_DefaultHandler,                                // Reserved     12
    Reserved_DefaultHandler,                                // Reserved     13
    Reserved_DefaultHandler,                                // PendSV       14
    SysClock::sysCLKIrqHandler,                                // SysTick      15
    IRQ_DefaultHandler,                                     // IRQ0         16 (WWDG)
    IRQ_DefaultHandler,                                     // IRQ1         17 (PVD)
    IRQ_DefaultHandler,                                     // IRQ2         18 (RTC)
    IRQ_DefaultHandler,                                     // IRQ3         19 (FLASH)
    IRQ_DefaultHandler,                                     // IRQ4         20 (RCC)
    IrqHelper::exti0_1IrqHandler,                           // IRQ5         21 (EXTI0_1_IRQHandler)
    IrqHelper::exti2_3IrqHandler,                           // IRQ6         22 (EXTI2_3_IRQHandler)
    IrqHelper::exti4_15IrqHandler,                          // IRQ7         23 (EXTI4_15_IRQHandler)
    IRQ_DefaultHandler,                                     // IRQ8         24 (TS_IRQHandler)
    IRQ_DefaultHandler,                                     // IRQ9         25 (DMA1_Ch_1)
    IRQ_DefaultHandler,                                     // IRQ10        26 (DMA1_Ch_2_3)
    IRQ_DefaultHandler,                                     // IRQ11        27 (DMA1_Ch_4_5)
    IRQ_DefaultHandler,                                     // IRQ12        28 (ADC1_COMP_IRQHandler)
    IRQ_DefaultHandler,                                     // IRQ13        29 (TIM1 Break, Update, Trigger and Commutation)
    IRQ_DefaultHandler,                                     // IRQ14        30 (TIM1 Capture Compare)
    IRQ_DefaultHandler,                                     // IRQ15        31 (TIM2)
    IRQ_DefaultHandler,                                     // IRQ16        32 (TIM3)
    IRQ_DefaultHandler,                                     // IRQ17        33 (TIM6_DAC_IRQHandler)
    IRQ_DefaultHandler,                                     // IRQ18        34 (Reserved)
    IRQ_DefaultHandler,                                     // IRQ19        35 (TIM14)
    IRQ_DefaultHandler,                                     // IRQ20        36 (TIM15)
    IRQ_DefaultHandler,                                     // IRQ21        37 (TIM16)
    IRQ_DefaultHandler,                                     // IRQ22        38 (TIM17)
    IRQ_DefaultHandler,                                     // IRQ23        39 (I2C1)
    IRQ_DefaultHandler,                                     // IRQ24        40 (I2C2)
    IRQ_DefaultHandler,                                     // IRQ25        41 (SPI1)
    IRQ_DefaultHandler,                                     // IRQ26        42 (SPI2)
    IRQ_DefaultHandler,                                     // IRQ27        43 (USART1_IRQHandler)
    IRQ_DefaultHandler,                                     // IRQ28        44 (USART2_IRQHandler)
    IRQ_DefaultHandler,                                     // IRQ29        45 (Reserved)
    IRQ_DefaultHandler,                                     // IRQ30        46 (CEC_IRQHandler)
    IRQ_DefaultHandler,                                     // IRQ31        47 (Reserved)
};
