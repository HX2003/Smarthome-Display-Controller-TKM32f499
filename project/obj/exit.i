#line 1 "bsp\\exit\\exit.c"
#line 1 "bsp\\exit\\exit.h"



#line 1 "..\\Hal_lib\\inc\\HAL_conf.h"


















  



 
#line 1 "..\\Hal_lib\\inc\\HAL_device.h"
 














 






#line 1 "..\\CMSIS_and_startup\\tk499.h"





















 












 








 
 





 





 












 



 



 






 
typedef enum IRQn
{
   
  NonMaskableInt_IRQn         = -14,     
  MemoryManagement_IRQn       = -12,     
  BusFault_IRQn               = -11,     
  UsageFault_IRQn             = -10,     
  SVCall_IRQn                 = -5,      
  DebugMonitor_IRQn           = -4,      
  PendSV_IRQn                 = -2,      
  SysTick_IRQn                = -1,      
  
   
  
  WWDG_IRQn                   = 0,       
  
  TAMPER_IRQn                 = 2,       
  RTC_IRQn                    = 3,       
  
  RCC_IRQn                    = 5,       
  EXTI0_IRQn                  = 6,       
  EXTI1_IRQn                  = 7,       
  EXTI2_IRQn                  = 8,       
  EXTI3_IRQn                  = 9,       
  EXTI4_IRQn                  = 10,      
  DMA1_Channel1_IRQn          = 11,      
  DMA1_Channel2_IRQn          = 12,      
  DMA1_Channel3_IRQn          = 13,      
  DMA1_Channel4_IRQn          = 14,      
  DMA1_Channel5_IRQn          = 15,      
  DMA1_Channel6_IRQn          = 16,      
  DMA1_Channel7_IRQn          = 17,      
  ADC1_IRQn                   = 18,      
  CAN1_IRQn         = 19,      
  
 
  
  EXTI9_5_IRQn                = 23,      
  TIM1_BRK_IRQn               = 24,      
  TIM1_UP_IRQn                = 25,      
  TIM1_TRG_COM_IRQn           = 26,      
  TIM1_CC_IRQn                = 27,      
	        
  
  TIM3_IRQn                   = 28,      
  TIM4_IRQn                   = 29,      
  TIM5_IRQn                   = 30,      
	TIM6_IRQn                   = 31,      
	TIM7_IRQn                   = 32,      
	
	I2C1_IRQn                = 33,      
  I2C2_IRQn                = 34,      
  
  SPI1_IRQn                   = 35,      
  SPI2_IRQn                   = 36,      
  UART1_IRQn                 = 37,      
  UART2_IRQn                 = 38,      
  UART3_IRQn                 = 39,      
  EXTI15_10_IRQn              = 40,      
  RTCAlarm_IRQn               = 41,      
  USBAwake_IRQn                    = 42,      
	TIM2_BRK_IRQn               = 43,     
	TIM2_UP_IRQn               = 44,     
	TIM2_TRG_COM_IRQn               = 45,     
	TIM2_CC_IRQn               = 46,     
	DMA1_Channel8_IRQn               = 47,     
	TK80_IRQn               = 48,     
	
	SDIO1_IRQn               = 49,     
	SDIO2_IRQn               = 50,     
	SPI3_IRQn               = 51,     
	UART4_IRQn               = 52,     
	UART5_IRQn               = 53,     
	TIM8_IRQn               = 55,     
	DMA2_Channel1_IRQn               = 56,     
	DMA2_Channel2_IRQn               = 57,     
	DMA2_Channel3_IRQn               = 58,     
	DMA2_Channel4_IRQn               = 59,     
	DMA2_Channel5_IRQn               = 60,     
	TIM9_IRQn               = 61,     
	TIM10_IRQn               = 62,     
	CAN2_IRQn               = 63,     
	USB_IRQn               = 67,     
	DMA2_Channel6_IRQn               = 68,     
	DMA2_Channel7_IRQn               = 69,     
	DMA2_Channel8_IRQn               = 70,     
	I2C3_IRQn               = 72,     
	I2C4_IRQn               = 73,     
	FPU_IRQn               = 81,     
	SPI4_IRQn               = 84,     
	TOUCHPAD_IRQn           = 86,
	QSPI_IRQn               = 87,     
	LTDC_IRQn            		= 88,     
	I2S1_IRQn               = 90,     
  
} IRQn_Type;






 

#line 1 "..\\CMSIS_and_startup\\CMSIS\\core_cm4.h"
 




 

























 











#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
 
 





 









     
#line 27 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
     











#line 46 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"





 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     




typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;


     
typedef   signed     long long intmax_t;
typedef unsigned     long long uintmax_t;




     

     





     





     





     

     





     





     





     

     





     





     





     

     






     






     






     

     


     


     


     

     
#line 216 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     



     






     
    
 



#line 241 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     







     










     











#line 305 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"






 
#line 45 "..\\CMSIS_and_startup\\CMSIS\\core_cm4.h"

















 




 



 

 













#line 120 "..\\CMSIS_and_startup\\CMSIS\\core_cm4.h"



 
#line 135 "..\\CMSIS_and_startup\\CMSIS\\core_cm4.h"

#line 209 "..\\CMSIS_and_startup\\CMSIS\\core_cm4.h"

#line 1 "..\\CMSIS_and_startup\\CMSIS\\core_cmInstr.h"
 




 

























 












 



 

 
#line 1 "..\\CMSIS_and_startup\\CMSIS\\cmsis_armcc.h"
 




 

























 










 



 

 
 





 
static __inline uint32_t __get_CONTROL(void)
{
  register uint32_t __regControl         __asm("control");
  return(__regControl);
}






 
static __inline void __set_CONTROL(uint32_t control)
{
  register uint32_t __regControl         __asm("control");
  __regControl = control;
}






 
static __inline uint32_t __get_IPSR(void)
{
  register uint32_t __regIPSR          __asm("ipsr");
  return(__regIPSR);
}






 
static __inline uint32_t __get_APSR(void)
{
  register uint32_t __regAPSR          __asm("apsr");
  return(__regAPSR);
}






 
static __inline uint32_t __get_xPSR(void)
{
  register uint32_t __regXPSR          __asm("xpsr");
  return(__regXPSR);
}






 
static __inline uint32_t __get_PSP(void)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  return(__regProcessStackPointer);
}






 
static __inline void __set_PSP(uint32_t topOfProcStack)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  __regProcessStackPointer = topOfProcStack;
}






 
static __inline uint32_t __get_MSP(void)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  return(__regMainStackPointer);
}






 
static __inline void __set_MSP(uint32_t topOfMainStack)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  __regMainStackPointer = topOfMainStack;
}






 
static __inline uint32_t __get_PRIMASK(void)
{
  register uint32_t __regPriMask         __asm("primask");
  return(__regPriMask);
}






 
static __inline void __set_PRIMASK(uint32_t priMask)
{
  register uint32_t __regPriMask         __asm("primask");
  __regPriMask = (priMask);
}








 







 







 
static __inline uint32_t  __get_BASEPRI(void)
{
  register uint32_t __regBasePri         __asm("basepri");
  return(__regBasePri);
}






 
static __inline void __set_BASEPRI(uint32_t basePri)
{
  register uint32_t __regBasePri         __asm("basepri");
  __regBasePri = (basePri & 0xFFU);
}







 
static __inline void __set_BASEPRI_MAX(uint32_t basePri)
{
  register uint32_t __regBasePriMax      __asm("basepri_max");
  __regBasePriMax = (basePri & 0xFFU);
}






 
static __inline uint32_t __get_FAULTMASK(void)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  return(__regFaultMask);
}






 
static __inline void __set_FAULTMASK(uint32_t faultMask)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  __regFaultMask = (faultMask & (uint32_t)1);
}










 
static __inline uint32_t __get_FPSCR(void)
{

  register uint32_t __regfpscr         __asm("fpscr");
  return(__regfpscr);



}






 
static __inline void __set_FPSCR(uint32_t fpscr)
{

  register uint32_t __regfpscr         __asm("fpscr");
  __regfpscr = (fpscr);

}





 


 



 




 






 







 






 








 










 










 











 








 

__attribute__((section(".rev16_text"))) static __inline __asm uint32_t __REV16(uint32_t value)
{
  rev16 r0, r0
  bx lr
}







 

__attribute__((section(".revsh_text"))) static __inline __asm int32_t __REVSH(int32_t value)
{
  revsh r0, r0
  bx lr
}









 









 








 
#line 455 "..\\CMSIS_and_startup\\CMSIS\\cmsis_armcc.h"







 










 












 












 














 














 














 










 









 









 









 

__attribute__((section(".rrx_text"))) static __inline __asm uint32_t __RRX(uint32_t value)
{
  rrx r0, r0
  bx lr
}








 








 








 








 








 








 




   


 



 



#line 720 "..\\CMSIS_and_startup\\CMSIS\\cmsis_armcc.h"











 


#line 54 "..\\CMSIS_and_startup\\CMSIS\\core_cmInstr.h"

 
#line 84 "..\\CMSIS_and_startup\\CMSIS\\core_cmInstr.h"

   

#line 211 "..\\CMSIS_and_startup\\CMSIS\\core_cm4.h"
#line 1 "..\\CMSIS_and_startup\\CMSIS\\core_cmFunc.h"
 




 

























 












 



 

 
#line 54 "..\\CMSIS_and_startup\\CMSIS\\core_cmFunc.h"

 
#line 84 "..\\CMSIS_and_startup\\CMSIS\\core_cmFunc.h"

 

#line 212 "..\\CMSIS_and_startup\\CMSIS\\core_cm4.h"
#line 1 "..\\CMSIS_and_startup\\CMSIS\\core_cmSimd.h"
 




 

























 
















 



 

 
#line 58 "..\\CMSIS_and_startup\\CMSIS\\core_cmSimd.h"

 
#line 88 "..\\CMSIS_and_startup\\CMSIS\\core_cmSimd.h"

 






#line 213 "..\\CMSIS_and_startup\\CMSIS\\core_cm4.h"
















 
#line 256 "..\\CMSIS_and_startup\\CMSIS\\core_cm4.h"

 






 
#line 272 "..\\CMSIS_and_startup\\CMSIS\\core_cm4.h"

 




 













 



 






 



 
typedef union
{
  struct
  {
    uint32_t _reserved0:16;               
    uint32_t GE:4;                        
    uint32_t _reserved1:7;                
    uint32_t Q:1;                         
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} APSR_Type;

 





















 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       
    uint32_t _reserved0:23;               
  } b;                                    
  uint32_t w;                             
} IPSR_Type;

 






 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       
    uint32_t _reserved0:7;                
    uint32_t GE:4;                        
    uint32_t _reserved1:4;                
    uint32_t T:1;                         
    uint32_t IT:2;                        
    uint32_t Q:1;                         
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} xPSR_Type;

 






























 
typedef union
{
  struct
  {
    uint32_t nPRIV:1;                     
    uint32_t SPSEL:1;                     
    uint32_t FPCA:1;                      
    uint32_t _reserved0:29;               
  } b;                                    
  uint32_t w;                             
} CONTROL_Type;

 









 







 



 
typedef struct
{
  volatile uint32_t ISER[8U];                
        uint32_t RESERVED0[24U];
  volatile uint32_t ICER[8U];                
        uint32_t RSERVED1[24U];
  volatile uint32_t ISPR[8U];                
        uint32_t RESERVED2[24U];
  volatile uint32_t ICPR[8U];                
        uint32_t RESERVED3[24U];
  volatile uint32_t IABR[8U];                
        uint32_t RESERVED4[56U];
  volatile uint8_t  IP[240U];                
        uint32_t RESERVED5[644U];
  volatile  uint32_t STIR;                    
}  NVIC_Type;

 



 







 



 
typedef struct
{
  volatile const  uint32_t CPUID;                   
  volatile uint32_t ICSR;                    
  volatile uint32_t VTOR;                    
  volatile uint32_t AIRCR;                   
  volatile uint32_t SCR;                     
  volatile uint32_t CCR;                     
  volatile uint8_t  SHP[12U];                
  volatile uint32_t SHCSR;                   
  volatile uint32_t CFSR;                    
  volatile uint32_t HFSR;                    
  volatile uint32_t DFSR;                    
  volatile uint32_t MMFAR;                   
  volatile uint32_t BFAR;                    
  volatile uint32_t AFSR;                    
  volatile const  uint32_t PFR[2U];                 
  volatile const  uint32_t DFR;                     
  volatile const  uint32_t ADR;                     
  volatile const  uint32_t MMFR[4U];                
  volatile const  uint32_t ISAR[5U];                
        uint32_t RESERVED0[5U];
  volatile uint32_t CPACR;                   
} SCB_Type;

 















 






























 



 





















 









 


















 










































 









 









 















 







 



 
typedef struct
{
        uint32_t RESERVED0[1U];
  volatile const  uint32_t ICTR;                    
  volatile uint32_t ACTLR;                   
} SCnSCB_Type;

 



 















 







 



 
typedef struct
{
  volatile uint32_t CTRL;                    
  volatile uint32_t LOAD;                    
  volatile uint32_t VAL;                     
  volatile const  uint32_t CALIB;                   
} SysTick_Type;

 












 



 



 









 







 



 
typedef struct
{
  volatile  union
  {
    volatile  uint8_t    u8;                  
    volatile  uint16_t   u16;                 
    volatile  uint32_t   u32;                 
  }  PORT [32U];                          
        uint32_t RESERVED0[864U];
  volatile uint32_t TER;                     
        uint32_t RESERVED1[15U];
  volatile uint32_t TPR;                     
        uint32_t RESERVED2[15U];
  volatile uint32_t TCR;                     
        uint32_t RESERVED3[29U];
  volatile  uint32_t IWR;                     
  volatile const  uint32_t IRR;                     
  volatile uint32_t IMCR;                    
        uint32_t RESERVED4[43U];
  volatile  uint32_t LAR;                     
  volatile const  uint32_t LSR;                     
        uint32_t RESERVED5[6U];
  volatile const  uint32_t PID4;                    
  volatile const  uint32_t PID5;                    
  volatile const  uint32_t PID6;                    
  volatile const  uint32_t PID7;                    
  volatile const  uint32_t PID0;                    
  volatile const  uint32_t PID1;                    
  volatile const  uint32_t PID2;                    
  volatile const  uint32_t PID3;                    
  volatile const  uint32_t CID0;                    
  volatile const  uint32_t CID1;                    
  volatile const  uint32_t CID2;                    
  volatile const  uint32_t CID3;                    
} ITM_Type;

 



 



























 



 



 



 









   







 



 
typedef struct
{
  volatile uint32_t CTRL;                    
  volatile uint32_t CYCCNT;                  
  volatile uint32_t CPICNT;                  
  volatile uint32_t EXCCNT;                  
  volatile uint32_t SLEEPCNT;                
  volatile uint32_t LSUCNT;                  
  volatile uint32_t FOLDCNT;                 
  volatile const  uint32_t PCSR;                    
  volatile uint32_t COMP0;                   
  volatile uint32_t MASK0;                   
  volatile uint32_t FUNCTION0;               
        uint32_t RESERVED0[1U];
  volatile uint32_t COMP1;                   
  volatile uint32_t MASK1;                   
  volatile uint32_t FUNCTION1;               
        uint32_t RESERVED1[1U];
  volatile uint32_t COMP2;                   
  volatile uint32_t MASK2;                   
  volatile uint32_t FUNCTION2;               
        uint32_t RESERVED2[1U];
  volatile uint32_t COMP3;                   
  volatile uint32_t MASK3;                   
  volatile uint32_t FUNCTION3;               
} DWT_Type;

 






















































 



 



 



 



 



 



 



























   







 



 
typedef struct
{
  volatile uint32_t SSPSR;                   
  volatile uint32_t CSPSR;                   
        uint32_t RESERVED0[2U];
  volatile uint32_t ACPR;                    
        uint32_t RESERVED1[55U];
  volatile uint32_t SPPR;                    
        uint32_t RESERVED2[131U];
  volatile const  uint32_t FFSR;                    
  volatile uint32_t FFCR;                    
  volatile const  uint32_t FSCR;                    
        uint32_t RESERVED3[759U];
  volatile const  uint32_t TRIGGER;                 
  volatile const  uint32_t FIFO0;                   
  volatile const  uint32_t ITATBCTR2;               
        uint32_t RESERVED4[1U];
  volatile const  uint32_t ITATBCTR0;               
  volatile const  uint32_t FIFO1;                   
  volatile uint32_t ITCTRL;                  
        uint32_t RESERVED5[39U];
  volatile uint32_t CLAIMSET;                
  volatile uint32_t CLAIMCLR;                
        uint32_t RESERVED7[8U];
  volatile const  uint32_t DEVID;                   
  volatile const  uint32_t DEVTYPE;                 
} TPI_Type;

 



 



 












 






 



 





















 



 





















 



 



 


















 






   








 



 
typedef struct
{
  volatile const  uint32_t TYPE;                    
  volatile uint32_t CTRL;                    
  volatile uint32_t RNR;                     
  volatile uint32_t RBAR;                    
  volatile uint32_t RASR;                    
  volatile uint32_t RBAR_A1;                 
  volatile uint32_t RASR_A1;                 
  volatile uint32_t RBAR_A2;                 
  volatile uint32_t RASR_A2;                 
  volatile uint32_t RBAR_A3;                 
  volatile uint32_t RASR_A3;                 
} MPU_Type;

 









 









 



 









 






























 









 



 
typedef struct
{
        uint32_t RESERVED0[1U];
  volatile uint32_t FPCCR;                   
  volatile uint32_t FPCAR;                   
  volatile uint32_t FPDSCR;                  
  volatile const  uint32_t MVFR0;                   
  volatile const  uint32_t MVFR1;                   
} FPU_Type;

 



























 



 












 
























 












 








 



 
typedef struct
{
  volatile uint32_t DHCSR;                   
  volatile  uint32_t DCRSR;                   
  volatile uint32_t DCRDR;                   
  volatile uint32_t DEMCR;                   
} CoreDebug_Type;

 




































 






 







































 







 






 







 


 







 

 
#line 1541 "..\\CMSIS_and_startup\\CMSIS\\core_cm4.h"

#line 1550 "..\\CMSIS_and_startup\\CMSIS\\core_cm4.h"











 










 


 



 





 









 
static __inline void NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  uint32_t reg_value;
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);              

  reg_value  =  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR;                                                    
  reg_value &= ~((uint32_t)((0xFFFFUL << 16U) | (7UL << 8U)));  
  reg_value  =  (reg_value                                   |
                ((uint32_t)0x5FAUL << 16U) |
                (PriorityGroupTmp << 8U)                      );               
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR =  reg_value;
}






 
static __inline uint32_t NVIC_GetPriorityGrouping(void)
{
  return ((uint32_t)((((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8U)) >> 8U));
}






 
static __inline void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}






 
static __inline void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICER[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}








 
static __inline uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
}






 
static __inline void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}






 
static __inline void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}








 
static __inline uint32_t NVIC_GetActive(IRQn_Type IRQn)
{
  return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IABR[(((uint32_t)(int32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
}








 
static __inline void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if ((int32_t)(IRQn) < 0)
  {
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[(((uint32_t)(int32_t)IRQn) & 0xFUL)-4UL] = (uint8_t)((priority << (8U - 4)) & (uint32_t)0xFFUL);
  }
  else
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[((uint32_t)(int32_t)IRQn)]               = (uint8_t)((priority << (8U - 4)) & (uint32_t)0xFFUL);
  }
}










 
static __inline uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{

  if ((int32_t)(IRQn) < 0)
  {
    return(((uint32_t)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[(((uint32_t)(int32_t)IRQn) & 0xFUL)-4UL] >> (8U - 4)));
  }
  else
  {
    return(((uint32_t)((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[((uint32_t)(int32_t)IRQn)]               >> (8U - 4)));
  }
}












 
static __inline uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);    
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(4)) ? (uint32_t)(4) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(4)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(4));

  return (
           ((PreemptPriority & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL)) << SubPriorityBits) |
           ((SubPriority     & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL)))
         );
}












 
static __inline void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* const pPreemptPriority, uint32_t* const pSubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);    
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(4)) ? (uint32_t)(4) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(4)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(4));

  *pPreemptPriority = (Priority >> SubPriorityBits) & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL);
  *pSubPriority     = (Priority                   ) & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL);
}





 
static __inline void NVIC_SystemReset(void)
{
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);                                                          
 
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR  = (uint32_t)((0x5FAUL << 16U)    |
                           (((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8U)) |
                            (1UL << 2U)    );          
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);                                                           

  for(;;)                                                            
  {
    __nop();
  }
}

 



 





 













 
static __inline uint32_t SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1UL) > (0xFFFFFFUL ))
  {
    return (1UL);                                                    
  }

  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD  = (uint32_t)(ticks - 1UL);                          
  NVIC_SetPriority (SysTick_IRQn, (1UL << 4) - 1UL);  
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL   = 0UL;                                              
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL  = (1UL << 2U) |
                   (1UL << 1U)   |
                   (1UL );                          
  return (0UL);                                                      
}



 



 





 

extern volatile int32_t ITM_RxBuffer;                     










 
static __inline uint32_t ITM_SendChar (uint32_t ch)
{
  if (((((ITM_Type *) (0xE0000000UL) )->TCR & (1UL )) != 0UL) &&       
      ((((ITM_Type *) (0xE0000000UL) )->TER & 1UL               ) != 0UL)   )      
  {
    while (((ITM_Type *) (0xE0000000UL) )->PORT[0U].u32 == 0UL)
    {
      __nop();
    }
    ((ITM_Type *) (0xE0000000UL) )->PORT[0U].u8 = (uint8_t)ch;
  }
  return (ch);
}







 
static __inline int32_t ITM_ReceiveChar (void)
{
  int32_t ch = -1;                            

  if (ITM_RxBuffer != 0x5AA55AA5U)
  {
    ch = ITM_RxBuffer;
    ITM_RxBuffer = 0x5AA55AA5U;        
  }

  return (ch);
}







 
static __inline int32_t ITM_CheckChar (void)
{

  if (ITM_RxBuffer == 0x5AA55AA5U)
  {
    return (0);                               
  }
  else
  {
    return (1);                               
  }
}

 










#line 191 "..\\CMSIS_and_startup\\tk499.h"

#line 193 "..\\CMSIS_and_startup\\tk499.h"



   

 
typedef int32_t  s32;
typedef int16_t s16;
typedef int8_t  s8;

typedef const int32_t sc32;   
typedef const int16_t sc16;   
typedef const int8_t sc8;    

typedef volatile int32_t  vs32;
typedef volatile int16_t  vs16;
typedef volatile int8_t   vs8;

typedef volatile const int32_t vsc32;   
typedef volatile const int16_t vsc16;   
typedef volatile const int8_t vsc8;    

typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

typedef const uint32_t uc32;   
typedef const uint16_t uc16;   
typedef const uint8_t uc8;    

typedef volatile uint32_t  vu32;
typedef volatile uint16_t vu16;
typedef volatile uint8_t  vu8;

typedef volatile const uint32_t vuc32;   
typedef volatile const uint16_t vuc16;   
typedef volatile const uint8_t vuc8;    

typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;

typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;


typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;



 



    
typedef struct
{
    volatile uint32_t     CCR;  
    volatile uint32_t     SR; 
    volatile uint32_t     IRQMASKR; 
    volatile uint32_t     IRQSTATR; 
    volatile uint32_t     RESERVED0; 
    volatile uint32_t     CSHR; 
    volatile uint32_t     CSMR; 
    volatile uint32_t     RESERVED1; 
    volatile uint32_t     ADDR0;
    volatile uint32_t     ADDR1;
    volatile uint32_t     ADDR2;
    volatile uint32_t     ADDR3;

} AI_Responder_TypeDef;


 

typedef struct
{
  volatile uint32_t ADDATA;
  volatile uint32_t ADCFG;
  volatile uint32_t ADCR;
  volatile uint32_t ADCHS;
  volatile uint32_t ADCMPR;
  volatile uint32_t ADSTA;
  volatile uint32_t ADDR0;
  volatile uint32_t ADDR1;
  volatile uint32_t ADDR2;
  volatile uint32_t ADDR3;
  volatile uint32_t ADDR4;
  volatile uint32_t ADDR5;
  volatile uint32_t ADDR6;
  volatile uint32_t ADDR7;
  volatile uint32_t ADDR8;
} ADC_TypeDef;



 

typedef struct
{
  uint32_t  RESERVED0;
  volatile uint16_t DR1;
  uint16_t  RESERVED1;
  volatile uint16_t DR2;
  uint16_t  RESERVED2;
  volatile uint16_t DR3;
  uint16_t  RESERVED3;
  volatile uint16_t DR4;
  uint16_t  RESERVED4;
  volatile uint16_t DR5;
  uint16_t  RESERVED5;
  volatile uint16_t DR6;
  uint16_t  RESERVED6;
  volatile uint16_t DR7;
  uint16_t  RESERVED7;
  volatile uint16_t DR8;
  uint16_t  RESERVED8;
  volatile uint16_t DR9;
  uint16_t  RESERVED9;
  volatile uint16_t DR10;
  uint16_t  RESERVED10; 
  volatile uint16_t RTCCR;
  uint16_t  RESERVED11;
  volatile uint16_t CR;
  uint16_t  RESERVED12;
  volatile uint16_t CSR;
} BKP_TypeDef;



 
typedef struct
{
  volatile uint32_t CR;			
  volatile uint32_t CMR;			
  volatile uint32_t SR;			
  volatile uint32_t IR;			
  volatile uint32_t ACR;			
  volatile uint32_t AMR;			
  volatile uint32_t BTR0;		
  volatile uint32_t BTR1;		
  volatile uint32_t  RESERVED0;	
  uint32_t RESERVED1; 		
  volatile uint32_t TXID0;		
  volatile uint32_t TXID1;		
  volatile uint32_t TXDR0;		
  volatile uint32_t TXDR1;		
  volatile uint32_t TXDR2;		
  volatile uint32_t TXDR3;		
  volatile uint32_t TXDR4;		
  volatile uint32_t TXDR5;		
  volatile uint32_t TXDR6;		
  volatile uint32_t TXDR7;		
  volatile uint32_t RXID0;		
  volatile uint32_t RXID1;		
  volatile uint32_t RXDR0;		
  volatile uint32_t RXDR1;		
  volatile uint32_t RXDR2;		
  volatile uint32_t RXDR3;
  volatile uint32_t RXDR4;
  volatile uint32_t RXDR5;		
  volatile uint32_t RXDR6;		
  volatile uint32_t RXDR7;		
  uint32_t RESERVED2;
  volatile uint32_t CDR;			
}CAN_TypeDef;



 
typedef struct
{
  volatile uint32_t MOD;
  volatile uint32_t CMR;
  volatile uint32_t SR;
  volatile uint32_t IR;
  volatile uint32_t IER;		
  uint32_t RESERVED0;
  volatile uint32_t BTR0;
  volatile uint32_t BTR1;
  uint32_t RESERVED1;	
  uint32_t RESERVED2;
  uint32_t RESERVED3;
  volatile uint32_t ALC;
  volatile uint32_t ECC;		
  volatile uint32_t EWLR;
  volatile uint32_t RXERR;
  volatile uint32_t TXERR;
  volatile uint32_t FF;		
  volatile uint32_t ID0;
  volatile uint32_t ID1;
  volatile uint32_t DATA0;
  volatile uint32_t DATA1;	
  volatile uint32_t DATA2;
  volatile uint32_t DATA3;
  volatile uint32_t DATA4;
  volatile uint32_t DATA5;	
  volatile uint32_t DATA6;
  volatile uint32_t DATA7;
  volatile uint32_t DATA8;
  volatile uint32_t DATA9;	
  volatile uint32_t RMC;
  volatile uint32_t RBSA;
  volatile uint32_t CDR;
}CAN_Peli_TypeDef;




 

typedef struct
{
  volatile uint32_t DR;
  volatile uint8_t  IDR;
  uint8_t   RESERVED0;
  uint16_t  RESERVED1;
  volatile uint32_t CR;
} CRC_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t SWTRIGR;
  volatile uint32_t DHR12R1;
  volatile uint32_t DHR12L1;
  volatile uint32_t DHR8R1;
  volatile uint32_t DHR12R2;
  volatile uint32_t DHR12L2;
  volatile uint32_t DHR8R2;
  volatile uint32_t DHR12RD;
  volatile uint32_t DHR12LD;
  volatile uint32_t DHR8RD;
  volatile uint32_t DOR1;
  volatile uint32_t DOR2;
} DAC_TypeDef;




 

typedef struct
{
  volatile uint32_t IDCODE;
  volatile uint32_t CR;	
}DBGMCU_TypeDef;



 

typedef struct
{
  volatile uint32_t CCR;
  volatile uint32_t CNDTR;
  volatile uint32_t CPAR;
  volatile uint32_t CMAR;
} DMA_Channel_TypeDef;

typedef struct
{
  volatile uint32_t ISR;
  volatile uint32_t IFCR;
} DMA_TypeDef;



 

typedef struct
{
  volatile uint32_t IMR;
  volatile uint32_t EMR;
  volatile uint32_t RTSR;
  volatile uint32_t FTSR;
  volatile uint32_t SWIER;
  volatile uint32_t PR;
} EXTI_TypeDef;



 

typedef struct
{
  volatile uint32_t ACR;
  volatile uint32_t KEYR;
  volatile uint32_t OPTKEYR;
  volatile uint32_t SR;
  volatile uint32_t CR;
  volatile uint32_t AR;
  volatile uint32_t RESERVED;
  volatile uint32_t OBR;
  volatile uint32_t WRPR;
} FLASH_TypeDef;



 

typedef struct
{
  volatile uint16_t RDP;
  volatile uint16_t USER;
  volatile uint16_t Data0;
  volatile uint16_t Data1;
  volatile uint16_t WRP0;
  volatile uint16_t WRP1;
  volatile uint16_t WRP2;
  volatile uint16_t WRP3;
} OB_TypeDef;





 












typedef struct
{
  volatile uint32_t CRL;
  volatile uint32_t CRH;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t BRR;
  volatile uint32_t LCKR;
       uint32_t RESERVED;
  volatile uint32_t AFRL;
  volatile uint32_t AFRH;
  volatile uint32_t CRH_EXT;
  volatile uint32_t BSRR_EXT;
  volatile uint32_t AFRH_EXT;
} GPIO_TypeDef;



 








  
typedef struct
{
  volatile uint32_t CSR;         
} OPAMP_TypeDef;

typedef struct
{
  volatile uint32_t CFGR;       
  volatile uint32_t EXTICR[4];   
} SYSCFG_TypeDef;



 

typedef struct
{
  volatile uint16_t IC_CON;
  uint16_t  RESERVED0;
  volatile uint16_t IC_TAR;
  uint16_t  RESERVED1;
  volatile uint16_t IC_SAR;
  uint16_t  RESERVED2;
  volatile uint16_t IC_HS_MADDR;
  uint16_t  RESERVED3;
  volatile uint16_t IC_DATA_CMD;
  uint16_t  RESERVED4;
  volatile uint16_t IC_SS_SCL_HCNT;
  uint16_t  RESERVED5;
  volatile uint16_t IC_SS_SCL_LCNT;
  uint16_t  RESERVED6;
  volatile uint16_t IC_FS_SCL_HCNT;
  uint16_t  RESERVED7;
  volatile uint16_t IC_FS_SCL_LCNT;
  uint16_t  RESERVED8;
  volatile uint16_t IC_HS_SCL_HCNT;
  uint16_t  RESERVED9;
  volatile uint16_t IC_HS_SCL_LCNT;
  uint16_t  RESERVED10;
  volatile uint16_t IC_INTR_STAT;
  uint16_t  RESERVED11;
  volatile uint16_t IC_INTR_MASK;
  uint16_t  RESERVED12;
  volatile uint16_t IC_RAW_INTR_STAT;
  uint16_t  RESERVED13;
  volatile uint16_t IC_RX_TL;
  uint16_t  RESERVED14;
  volatile uint16_t IC_TX_TL;
  uint16_t  RESERVED15;
  volatile uint16_t IC_CLR_INTR;
  uint16_t  RESERVED16;
  volatile uint16_t IC_CLR_RX_UNDER;
  uint16_t  RESERVED17;
  volatile uint16_t IC_CLR_RX_OVER;
  uint16_t  RESERVED18;
  volatile uint16_t IC_CLR_TX_OVER;
  uint16_t  RESERVED19;
  volatile uint16_t IC_CLR_RD_REQ;
  uint16_t  RESERVED20;
  volatile uint16_t IC_CLR_TX_ABRT;
  uint16_t  RESERVED21;
  volatile uint16_t IC_CLR_RX_DONE;
  uint16_t  RESERVED22;
  volatile uint16_t IC_CLR_ACTIVITY;
  uint16_t  RESERVED23;
  volatile uint16_t IC_CLR_STOP_DET;
  uint16_t  RESERVED24;
  volatile uint16_t IC_CLR_START_DET;
  uint16_t  RESERVED25;
  volatile uint16_t IC_CLR_GEN_CALL;
  uint16_t  RESERVED26;
  volatile uint16_t IC_ENABLE;               
  uint16_t  RESERVED27;
  
  volatile uint32_t IC_STATUS;               
  volatile uint32_t IC_TXFLR;                
  volatile uint32_t IC_RXFLR;                
  volatile uint32_t IC_SDA_HOLD;             
  volatile uint32_t IC_TX_ABRT_SOURCE;       
  volatile uint32_t IC_SLV_DATA_NACK_ONLY;   
  volatile uint32_t IC_DMA_CR;               
  volatile uint32_t IC_DMA_TDLR;             
  volatile uint32_t IC_DMA_RDLR;             
  volatile uint32_t IC_SDA_SETUP;            
  volatile uint32_t IC_ACK_GENERAL_CALL;     
  
  volatile uint32_t IC_FS_SPKLEN;
  volatile uint32_t IC_HS_SPKLEN;
  
  volatile uint16_t IC_CLR_RESTART_DET;
  uint16_t  RESERVED28;
  volatile uint32_t IC_COMP_PARAM_1;
  volatile uint32_t IC_COMP_VERSION;
  volatile uint32_t IC_COMP_TYPE;
  
} I2C_TypeDef;



 

typedef struct
{
  volatile uint32_t KR;
  volatile uint32_t PR;
  volatile uint32_t RLR;
  volatile uint32_t SR;
} IWDG_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CSR;
} PWR_TypeDef;



 















 

typedef struct
{
  volatile uint32_t CR;             
  volatile uint32_t PLLCFGR;        
  volatile uint32_t CFGR;           
  volatile uint32_t CIR;            
  volatile uint32_t AHB1RSTR;       
  volatile uint32_t AHB2RSTR;       
  volatile uint32_t APB1RSTR;       
  volatile uint32_t APB2RSTR;       
  volatile uint32_t AHB1ENR;        
  volatile uint32_t AHB2ENR;        
  volatile uint32_t APB1ENR;        
  volatile uint32_t APB2ENR;        
  volatile uint32_t BDCR;            
  volatile uint32_t CSR;            
  volatile uint32_t PLLLCDCFGR;    
  volatile uint32_t PLLDCKCFGR;         
} RCC_TypeDef;

 



 

typedef struct
{
  volatile uint16_t CRH;
  uint16_t  RESERVED0;
  volatile uint16_t CRL;
  uint16_t  RESERVED1;
  volatile uint16_t PRLH;
  uint16_t  RESERVED2;
  volatile uint16_t PRLL;
  uint16_t  RESERVED3;
  volatile uint16_t DIVH;
  uint16_t  RESERVED4;
  volatile uint16_t DIVL;
  uint16_t  RESERVED5;
  volatile uint16_t CNTH;
  uint16_t  RESERVED6;
  volatile uint16_t CNTL;
  uint16_t  RESERVED7;
  volatile uint16_t ALRH;
  uint16_t  RESERVED8;
  volatile uint16_t ALRL;
  uint16_t  RESERVED9;
} RTC_TypeDef;




 

typedef struct
{
  volatile uint32_t TXREG;    
  volatile uint32_t RXREG;
  volatile uint32_t CSTAT;    
  volatile uint32_t INTSTAT;
  volatile uint32_t INTEN;
  volatile uint32_t INTCLR;   
  volatile uint32_t GCTL;    
  volatile uint32_t CCTL;
  volatile uint32_t SPBRG;
  volatile uint32_t RXDNR;
  volatile uint32_t SCSR;    
  volatile uint32_t TXREGBH;   
	volatile uint32_t TXREGBL; 
} SPI_TypeDef;






 

typedef struct
{
  volatile uint32_t CR1;          
  volatile uint32_t CR2;          
  volatile uint32_t SMCR;         
  volatile uint32_t DIER;         
  volatile uint32_t SR;           
  volatile uint32_t EGR;          
  volatile uint32_t CCMR1;        
  volatile uint32_t CCMR2;        
  volatile uint32_t CCER;         
  volatile uint32_t CNT;          
  volatile uint32_t PSC;          
  volatile uint32_t ARR;          
  volatile uint32_t RCR;          
  volatile uint32_t CCR1;         
  volatile uint32_t CCR2;         
  volatile uint32_t CCR3;         
  volatile uint32_t CCR4;         
  volatile uint32_t BDTR;         
  volatile uint32_t DCR;          
  volatile uint32_t DMAR;         
  volatile uint32_t OR;           
} TIM_TypeDef;



 

typedef struct
{
  volatile uint32_t TDR;
  volatile uint32_t RDR;
  volatile uint32_t CSR;
  volatile uint32_t ISR;
  volatile uint32_t IER;
  volatile uint32_t ICR;
  volatile uint32_t GCR;
  volatile uint32_t CCR;
  volatile uint32_t BRR;
  volatile uint32_t FRABRG;
  
} UART_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CFR;
  volatile uint32_t SR;
} WWDG_TypeDef;




 
typedef struct
{
  volatile uint32_t  rTOP;        		 
  volatile uint32_t  rINT_STATE;        	 
  volatile uint32_t  rEP_INT_STATE;  		 
  volatile uint32_t  rEP0_INT_STATE; 		 
  volatile uint32_t  rINT_EN;        		 
  volatile uint32_t  rEP_INT_EN;        	 	
  volatile uint32_t  rEP0_INT_EN;      	 
  
  volatile uint32_t  RESERVED0; 	
  
  
  
  volatile uint32_t  rEP1_INT_STATE;       
  volatile uint32_t  rEP2_INT_STATE;       	
  volatile uint32_t  rEP3_INT_STATE;       
  volatile uint32_t  rEP4_INT_STATE;       
  
  volatile uint32_t  RESERVED1; 			 
  volatile uint32_t  RESERVED2; 			 
  volatile uint32_t  RESERVED3; 			 
  volatile uint32_t  RESERVED4; 			 
  
  volatile uint32_t  rEP1_INT_EN;        	 	
  volatile uint32_t  rEP2_INT_EN;        	 
  volatile uint32_t  rEP3_INT_EN;        	 
  volatile uint32_t  rEP4_INT_EN;        	 	
  
  volatile uint32_t  RESERVED5; 			 
  volatile uint32_t  RESERVED6; 			 
  volatile uint32_t  RESERVED7; 			 
  volatile uint32_t  RESERVED8; 			 
  
  volatile uint32_t  rADDR;        		 
  volatile uint32_t  rEP_EN;        		 
  
  volatile uint32_t  RESERVED9; 			 
  volatile uint32_t  RESERVED10; 			 
  volatile uint32_t  RESERVED11; 			 
  volatile uint32_t  RESERVED12; 			 
  
  volatile uint32_t  rTOG_CTRL1_4;         
  
  volatile uint32_t  RESERVED13; 			 
  
  volatile uint32_t  rSETUP[8];        		 
  
  
  
  
  
  
  
  
  volatile uint32_t  rPAKET_SIZE0;    	 	
  volatile uint32_t  rPAKET_SIZE1;    	 	
  
  volatile uint32_t  RESERVED14; 			 
  volatile uint32_t  RESERVED15; 			 
  
  volatile uint32_t  RESERVED16; 			 
  volatile uint32_t  RESERVED17; 			 
  volatile uint32_t  RESERVED18; 			 
  volatile uint32_t  RESERVED19; 			 
  
  volatile uint32_t  RESERVED20; 			 
  volatile uint32_t  RESERVED21; 			 
  volatile uint32_t  RESERVED22; 			 
  volatile uint32_t  RESERVED23; 			 
  
  volatile uint32_t  RESERVED24; 			 
  volatile uint32_t  RESERVED25; 			 
  volatile uint32_t  RESERVED26; 			 
  volatile uint32_t  RESERVED27; 			 
  
  volatile uint32_t  RESERVED28; 			 
  volatile uint32_t  RESERVED29; 			 
  volatile uint32_t  RESERVED30; 			 
  volatile uint32_t  RESERVED31; 			 
  
  volatile uint32_t  RESERVED32; 			 
  volatile uint32_t  RESERVED33; 			 
  volatile uint32_t  RESERVED34; 			 
  volatile uint32_t  RESERVED35; 			 
  
  volatile uint32_t  rEP0_AVIL;		 	 
  volatile uint32_t  rEP1_AVIL;			 
  volatile uint32_t  rEP2_AVIL;			 
  volatile uint32_t  rEP3_AVIL;			 
  volatile uint32_t  rEP4_AVIL;			 
  
  volatile uint32_t  RESERVED36; 			 
  volatile uint32_t  RESERVED37; 			 
  volatile uint32_t  RESERVED38; 			 
  volatile uint32_t  RESERVED39; 			 
  
  volatile uint32_t  RESERVED40; 			 
  volatile uint32_t  RESERVED41; 			 
  volatile uint32_t  RESERVED42; 			 
  volatile uint32_t  RESERVED43; 			 
  
  volatile uint32_t  RESERVED44; 			 
  volatile uint32_t  RESERVED45; 			 
  volatile uint32_t  RESERVED46; 			 
  
  volatile uint32_t  rEP0_CTRL;			 
  volatile uint32_t  rEP1_CTRL;			 
  volatile uint32_t  rEP2_CTRL;			 
  volatile uint32_t  rEP3_CTRL;			 
  volatile uint32_t  rEP4_CTRL;			 
  
  volatile uint32_t  RESERVED47; 			 
  volatile uint32_t  RESERVED48; 			 
  volatile uint32_t  RESERVED49; 			 
  
  
  
  
  volatile uint32_t  rEP0_FIFO;			 
  volatile uint32_t  rEP1_FIFO;			 
  volatile uint32_t  rEP2_FIFO;			 
  volatile uint32_t  rEP3_FIFO;			 
  volatile uint32_t  rEP4_FIFO;			 
  
  volatile uint32_t  RESERVED51; 			 
  volatile uint32_t  RESERVED52; 			 
  volatile uint32_t  RESERVED53; 			 
  
  volatile uint32_t  RESERVED54; 			 
  
  volatile uint32_t  rEP_DMA;				 
  volatile uint32_t  rEP_HALT;			 
  volatile uint32_t  RESERVED55; 			 
  
  volatile uint32_t  RESERVED56; 			 
  volatile uint32_t  RESERVED57; 			 
  volatile uint32_t  RESERVED58; 			 
  volatile uint32_t  RESERVED59; 			 
  
  volatile uint32_t  RESERVED60; 			 
  volatile uint32_t  RESERVED61; 			 
  volatile uint32_t  RESERVED62; 			 
  volatile uint32_t  RESERVED63; 			 
  
  volatile uint32_t  RESERVED64; 			 
  volatile uint32_t  RESERVED65; 			 
  volatile uint32_t  RESERVED66; 			 
  volatile uint32_t  RESERVED67; 			 
  volatile uint32_t  rPOWER;				 
} USB_TypeDef;

typedef struct
{
    u32 sHsyncStart;    
    u32 sHsyncEnd; 
    u32 aHorLen;   
    u32 blkHorEnd;

    u32 sVsyncStart; 
    u32 sVsyncEnd;   
    u32 aVerLen;   
    u32 blkVerEnd;    
} LCD_FORM_TypeDef;

typedef struct
{
  volatile uint32_t DP_ADDR0;  
  volatile uint32_t DP_ADDR1;  
  volatile uint32_t P_HOR;     
  volatile uint32_t HSYNC;     
  volatile uint32_t A_HOR;     
  volatile uint32_t A_HOR_LEN; 
  volatile uint32_t BLK_HOR;   
  volatile uint32_t P_VER;     
  volatile uint32_t VSYNC;     
  volatile uint32_t A_VER;     
  volatile uint32_t A_VER_LEN; 
  volatile uint32_t BLK_VER;   
  volatile uint32_t BLK_DATA;  
  volatile uint32_t POL_CTL;   
  volatile uint32_t OUT_EN;    
  volatile uint32_t INTR_STA;  
  volatile uint32_t INTR_EN;   
  volatile uint32_t INTR_CLR;  
  volatile uint32_t DP_SWT;    
  volatile uint32_t VI_FORMAT; 
} LCD_TypeDef;

typedef struct
{
  volatile uint32_t IER;   
  volatile uint32_t IRER;  
  volatile uint32_t ITER;  
  volatile uint32_t CER;   
  volatile uint32_t RXFFR; 
  volatile uint32_t TXFFR; 
  volatile uint32_t LRBR0; 
  volatile uint32_t RRBR0; 
  volatile uint32_t RER0;  
  volatile uint32_t TER0;  
  volatile uint32_t RCR0;  
  volatile uint32_t TCR0;  
  volatile uint32_t ISR0;  
  volatile uint32_t IMR0;  
  volatile uint32_t ROR0;  
  volatile uint32_t TOR0;  
  volatile uint32_t RFCR0; 
  volatile uint32_t TFCR0; 
  volatile uint32_t RFF0;  
  volatile uint32_t TFF0;  
} I2S_TypeDef;















typedef struct
{
  volatile uint32_t MMC_CTRL;   
  volatile uint32_t MMC_IO;   
  volatile uint32_t MMC_BYTECNTL;   
  volatile uint32_t MMC_TR_BLOCKCNT;   
  volatile uint32_t MMC_CRCCTL;   
  volatile uint32_t CMD_CRC;   
  volatile uint32_t DAT_CRCL;   
  volatile uint32_t DAT_CRCH;   
  volatile uint32_t MMC_PORT;   
  volatile uint32_t MMC_INT_MASK;   
  volatile uint32_t CLR_MMC_INT;   
  volatile uint32_t MMC_CARDSEL;   
  volatile uint32_t MMC_SIG;   
  volatile uint32_t MMC_IO_MBCTL;   
  volatile uint32_t MMC_BLOCKCNT;   
  volatile uint32_t MMC_TIMEOUTCNT;   
  volatile uint32_t CMD_BUF[16];     
  volatile uint32_t BUF_CTL;  
  volatile uint32_t RESERVED[31];  
  volatile uint32_t DATA_BUF0;  
  volatile uint32_t DATA_BUF1;  
  volatile uint32_t DATA_BUF2;  
  volatile uint32_t DATA_BUF3;  
  volatile uint32_t DATA_BUF4;    
} SDIO_TypeDef;

typedef struct 
{
    volatile uint32_t DP_ADDR0;
    volatile uint32_t DP_ADDR1;
    volatile uint32_t P_HOR;
    volatile uint32_t HSYNC;
    volatile uint32_t A_HOR;
    volatile uint32_t A_HOR_LEN;
    volatile uint32_t BLK_HOR;
    volatile uint32_t P_VER;
    volatile uint32_t VSYNC;
    volatile uint32_t A_VER;
    volatile uint32_t A_VER_LEN;
    volatile uint32_t BLK_VER;
    volatile uint32_t BLK_DATA;
    volatile uint32_t POL_CTL;
    volatile uint32_t OUT_EN;
    volatile uint32_t INTR_STA;
    volatile uint32_t INTR_EN;
    volatile uint32_t INTR_CLR;
    volatile uint32_t DP_SWT;
    volatile uint32_t VI_FORMAT;
}
LTDCTypeDef;

typedef struct
{
  volatile uint32_t CR;
    volatile uint32_t CFGR1;
    volatile uint32_t CFGR2;
    volatile uint32_t SR;
    volatile uint32_t CMDIR;
    volatile uint32_t DINR;
    volatile uint32_t CMDOR;
    volatile uint32_t RESERVE0;
    volatile uint32_t DOUTR;
    volatile uint32_t BRDR;
		volatile uint32_t RESERVE1;
		volatile uint32_t RESERVE2;
		volatile uint32_t CFGR3;
} TK80_TypeDef;


typedef struct
{
  uint32_t  TXREG;         
  uint32_t  RXREG;         
  uint32_t  CSTAT;         
  uint32_t  INTSTAT;         
  uint32_t  INTEN;         
  uint32_t  INTCLR;         
  uint32_t  GCTL;         
  uint32_t  CCTL;         
  uint32_t  SPBRG;         
  uint32_t  RXDNR;         
  uint32_t  SCSR;         
  uint32_t  MODE;         
} QSPI_TypeDef;




 
typedef struct
{
  volatile uint32_t CR;             
  volatile uint32_t IER;            
  volatile uint32_t ICR;            
  volatile uint32_t ISR;            
  volatile uint32_t IOHCR;          
  uint32_t      RESERVED1;      
  volatile uint32_t IOASCR;         
  uint32_t      RESERVED2;      
  volatile uint32_t IOSCR;          
  uint32_t      RESERVED3;      
  volatile uint32_t IOCCR;          
  uint32_t      RESERVED4;      
  volatile uint32_t IOGCSR;         
  volatile uint32_t IOGXCR[8];      
} TSC_TypeDef;

typedef struct
{
	volatile uint32_t ADDATA;      
  volatile uint32_t ADCFG;           
  volatile uint32_t ADCR;     
  volatile uint32_t ADCHS;   
  volatile uint32_t ADCMPR; 	
  volatile uint32_t ADSTA; 
  volatile uint32_t ADDR0; 	  
	volatile uint32_t ADDR1; 
	volatile uint32_t ADDR2; 		
	volatile uint32_t ADDR3; 
	volatile uint32_t ADDR4; 
	volatile uint32_t ADDR5; 
	volatile uint32_t ADDR6; 		
	volatile uint32_t ADDR7; 
	volatile uint32_t ADDR8; 
	volatile uint32_t ADDR9; 
	volatile uint32_t RESERVED0;
	volatile uint32_t RESERVED1;
  volatile uint32_t TPXDR;  
  volatile uint32_t TPYDR;  
  volatile uint32_t TPCR; 
	volatile uint32_t TPFR;
	volatile uint32_t TPCSR;

} TOUCHPAD_TypeDef;



 



 









 








 
#line 1238 "..\\CMSIS_and_startup\\tk499.h"

#line 1248 "..\\CMSIS_and_startup\\tk499.h"



 


 



			
 
#line 1279 "..\\CMSIS_and_startup\\tk499.h"
 
#line 1297 "..\\CMSIS_and_startup\\tk499.h"









 



  

#line 1331 "..\\CMSIS_and_startup\\tk499.h"

#line 1351 "..\\CMSIS_and_startup\\tk499.h"

#line 1382 "..\\CMSIS_and_startup\\tk499.h"



















 



 



 

 
 
 

 
 
 
 
 

 



 



 


 
 
 
 
 

 












 
#line 1463 "..\\CMSIS_and_startup\\tk499.h"




 





 
 
 
 
 

 


 


 


 


 


 


 


 


 


 



 





 



 






 
 
 
 
 

 
#line 1544 "..\\CMSIS_and_startup\\tk499.h"

#line 1552 "..\\CMSIS_and_startup\\tk499.h"





 




 








 










 
#line 1592 "..\\CMSIS_and_startup\\tk499.h"






 











 


















 
#line 1637 "..\\CMSIS_and_startup\\tk499.h"

 
#line 1656 "..\\CMSIS_and_startup\\tk499.h"

 
#line 1672 "..\\CMSIS_and_startup\\tk499.h"

 
#line 1687 "..\\CMSIS_and_startup\\tk499.h"

 





 
#line 1708 "..\\CMSIS_and_startup\\tk499.h"

 
#line 1724 "..\\CMSIS_and_startup\\tk499.h"

 








 








   
#line 1753 "..\\CMSIS_and_startup\\tk499.h"

 
 
 
 
 

 




































































 




































































 
#line 1915 "..\\CMSIS_and_startup\\tk499.h"

 
#line 1933 "..\\CMSIS_and_startup\\tk499.h"

 
#line 1951 "..\\CMSIS_and_startup\\tk499.h"

#line 1968 "..\\CMSIS_and_startup\\tk499.h"

 
#line 1986 "..\\CMSIS_and_startup\\tk499.h"

 
#line 2005 "..\\CMSIS_and_startup\\tk499.h"

 

 
 
 
 
 
 
#line 2028 "..\\CMSIS_and_startup\\tk499.h"

 







 
#line 2044 "..\\CMSIS_and_startup\\tk499.h"



  
#line 2054 "..\\CMSIS_and_startup\\tk499.h"



 
#line 2064 "..\\CMSIS_and_startup\\tk499.h"



 
#line 2074 "..\\CMSIS_and_startup\\tk499.h"

 







 
#line 2090 "..\\CMSIS_and_startup\\tk499.h"



 
#line 2100 "..\\CMSIS_and_startup\\tk499.h"



 
#line 2110 "..\\CMSIS_and_startup\\tk499.h"



 
#line 2120 "..\\CMSIS_and_startup\\tk499.h"

 







 








 
#line 2145 "..\\CMSIS_and_startup\\tk499.h"



 
#line 2155 "..\\CMSIS_and_startup\\tk499.h"



 






 







 








 








 








 






 
 
 
 
 

 





 


 


 




 
 
 
 
 

 
#line 2270 "..\\CMSIS_and_startup\\tk499.h"

 
#line 2305 "..\\CMSIS_and_startup\\tk499.h"

 
#line 2340 "..\\CMSIS_and_startup\\tk499.h"

 
#line 2375 "..\\CMSIS_and_startup\\tk499.h"

 
#line 2410 "..\\CMSIS_and_startup\\tk499.h"

 





 





 





 





 





 





 





 





 





 





 





 





 






 
#line 2501 "..\\CMSIS_and_startup\\tk499.h"

 



 









 
#line 2525 "..\\CMSIS_and_startup\\tk499.h"




 




 
#line 2541 "..\\CMSIS_and_startup\\tk499.h"

 





 
#line 2563 "..\\CMSIS_and_startup\\tk499.h"

 
 





 
#line 2578 "..\\CMSIS_and_startup\\tk499.h"
 
#line 2585 "..\\CMSIS_and_startup\\tk499.h"

 




 






 


 


 


 
 
 
 
 

 
#line 2635 "..\\CMSIS_and_startup\\tk499.h"

 
#line 2658 "..\\CMSIS_and_startup\\tk499.h"

 
#line 2681 "..\\CMSIS_and_startup\\tk499.h"
 
#line 2703 "..\\CMSIS_and_startup\\tk499.h"
 
#line 2725 "..\\CMSIS_and_startup\\tk499.h"
 
#line 2747 "..\\CMSIS_and_startup\\tk499.h"
 
 
 
 
 

 
#line 2782 "..\\CMSIS_and_startup\\tk499.h"

 
#line 2812 "..\\CMSIS_and_startup\\tk499.h"

 
#line 2822 "..\\CMSIS_and_startup\\tk499.h"















 
#line 2846 "..\\CMSIS_and_startup\\tk499.h"















 
#line 2870 "..\\CMSIS_and_startup\\tk499.h"















 
#line 2894 "..\\CMSIS_and_startup\\tk499.h"















 
#line 2918 "..\\CMSIS_and_startup\\tk499.h"















 
#line 2942 "..\\CMSIS_and_startup\\tk499.h"















 
#line 2966 "..\\CMSIS_and_startup\\tk499.h"















 


 


 


 


 


 


 


 


 


 



 


 


 



 


 


 


 



 


 


 


 


 
 
 
 
 

 
#line 3062 "..\\CMSIS_and_startup\\tk499.h"


 
#line 3076 "..\\CMSIS_and_startup\\tk499.h"

 
#line 3086 "..\\CMSIS_and_startup\\tk499.h"

#line 3098 "..\\CMSIS_and_startup\\tk499.h"


   
#line 3110 "..\\CMSIS_and_startup\\tk499.h"


                        



                           
#line 3126 "..\\CMSIS_and_startup\\tk499.h"

#line 3146 "..\\CMSIS_and_startup\\tk499.h"


 





 
 
 
 
 

 









































 



 


 


 


 


 


 


 



 



 



 


 





 
 
 
 
 

 
















 









#line 3286 "..\\CMSIS_and_startup\\tk499.h"

 

























 
#line 3329 "..\\CMSIS_and_startup\\tk499.h"

 
#line 3343 "..\\CMSIS_and_startup\\tk499.h"

 
#line 3353 "..\\CMSIS_and_startup\\tk499.h"

 




























 





















 




























 





















 
#line 3472 "..\\CMSIS_and_startup\\tk499.h"

 


 


 


 


 


 


 


 


 
#line 3507 "..\\CMSIS_and_startup\\tk499.h"





#line 3518 "..\\CMSIS_and_startup\\tk499.h"

 
#line 3526 "..\\CMSIS_and_startup\\tk499.h"

#line 3533 "..\\CMSIS_and_startup\\tk499.h"

 


 
 
 
 
 

 




 
#line 3555 "..\\CMSIS_and_startup\\tk499.h"

 


 


 


 


 


 


 


 


 
 
 
 
 

 


 





 


 



 
 
 
 
 

 
#line 3617 "..\\CMSIS_and_startup\\tk499.h"



 
#line 3629 "..\\CMSIS_and_startup\\tk499.h"







 




 
 
 
 
 

 










 






 






 
#line 3681 "..\\CMSIS_and_startup\\tk499.h"

 






 






 
#line 3705 "..\\CMSIS_and_startup\\tk499.h"














































 


 






 
#line 3770 "..\\CMSIS_and_startup\\tk499.h"

 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


#line 3827 "..\\CMSIS_and_startup\\tk499.h"

 


#line 3839 "..\\CMSIS_and_startup\\tk499.h"

 


#line 3851 "..\\CMSIS_and_startup\\tk499.h"

 


#line 3863 "..\\CMSIS_and_startup\\tk499.h"

 


#line 3875 "..\\CMSIS_and_startup\\tk499.h"

 



 






 





 
 
 
 
 
 


 


 





 
#line 3918 "..\\CMSIS_and_startup\\tk499.h"

 
#line 3927 "..\\CMSIS_and_startup\\tk499.h"

 
#line 3936 "..\\CMSIS_and_startup\\tk499.h"

   
#line 3948 "..\\CMSIS_and_startup\\tk499.h"

   
#line 3956 "..\\CMSIS_and_startup\\tk499.h"

  


  


  




 
 
 
 
 

 
#line 3982 "..\\CMSIS_and_startup\\tk499.h"





 



#line 4002 "..\\CMSIS_and_startup\\tk499.h"

 


 


 


#line 4021 "..\\CMSIS_and_startup\\tk499.h"

 


 


 


 


 


 


 
#line 4055 "..\\CMSIS_and_startup\\tk499.h"

 
#line 4071 "..\\CMSIS_and_startup\\tk499.h"

 
#line 4087 "..\\CMSIS_and_startup\\tk499.h"

 


 


 


 


 


 


 


 


 


 


 


 



 
#line 4133 "..\\CMSIS_and_startup\\tk499.h"

 




 




 



 



 


 


 
 
 
 
 

 


 


 





 
#line 4183 "..\\CMSIS_and_startup\\tk499.h"

 
#line 4192 "..\\CMSIS_and_startup\\tk499.h"

 
#line 4201 "..\\CMSIS_and_startup\\tk499.h"

 






 









 


 
 
 
 
 

 



 




#line 4243 "..\\CMSIS_and_startup\\tk499.h"


 
 
 
 
 

 









 


 


 





 
#line 4284 "..\\CMSIS_and_startup\\tk499.h"

 


 









 


 

 
 
 
 
 

 






 
#line 4325 "..\\CMSIS_and_startup\\tk499.h"

 
#line 4335 "..\\CMSIS_and_startup\\tk499.h"

 
#line 4344 "..\\CMSIS_and_startup\\tk499.h"





 













 


 
 






 
#line 4384 "..\\CMSIS_and_startup\\tk499.h"

 
#line 4395 "..\\CMSIS_and_startup\\tk499.h"

 
#line 4406 "..\\CMSIS_and_startup\\tk499.h"

 













 

 

 

 

 

 

 

 


 
#line 4448 "..\\CMSIS_and_startup\\tk499.h"

 













 

 

 

 

 

 

 

 


 
 






 
#line 4497 "..\\CMSIS_and_startup\\tk499.h"

 
#line 4505 "..\\CMSIS_and_startup\\tk499.h"

 


#line 4515 "..\\CMSIS_and_startup\\tk499.h"





 


 


 


 









 
#line 4549 "..\\CMSIS_and_startup\\tk499.h"

 
#line 4560 "..\\CMSIS_and_startup\\tk499.h"

 
#line 4571 "..\\CMSIS_and_startup\\tk499.h"

 
#line 4582 "..\\CMSIS_and_startup\\tk499.h"

 
#line 4593 "..\\CMSIS_and_startup\\tk499.h"

 
#line 4604 "..\\CMSIS_and_startup\\tk499.h"

 
#line 4615 "..\\CMSIS_and_startup\\tk499.h"

 
#line 4626 "..\\CMSIS_and_startup\\tk499.h"

 


 




 



  







 

















 
#line 4682 "..\\CMSIS_and_startup\\tk499.h"




 





 



 

 
#line 24 "..\\Hal_lib\\inc\\HAL_device.h"



 
#line 25 "..\\Hal_lib\\inc\\HAL_conf.h"
#line 1 "..\\Hal_lib\\inc\\HAL_adc.h"



















  

 



 
#line 28 "..\\Hal_lib\\inc\\HAL_adc.h"



 



 



 



 











 
typedef struct
{
  uint32_t ADC_Resolution;  
  uint32_t ADC_PRESCARE;
  uint32_t ADC_Mode;
  FunctionalState ADC_ContinuousConvMode;
  uint32_t ADC_TRGEN;
  uint32_t ADC_ExternalTrigConv;   
  uint32_t ADC_DataAlign;
}ADC_InitTypeDef;


 



 









  













 

#line 106 "..\\Hal_lib\\inc\\HAL_adc.h"





 











 






 



 

#line 144 "..\\Hal_lib\\inc\\HAL_adc.h"



 

#line 157 "..\\Hal_lib\\inc\\HAL_adc.h"



#line 176 "..\\Hal_lib\\inc\\HAL_adc.h"


 



 







 



 

#line 206 "..\\Hal_lib\\inc\\HAL_adc.h"









 



  








  

#line 238 "..\\Hal_lib\\inc\\HAL_adc.h"

#line 247 "..\\Hal_lib\\inc\\HAL_adc.h"





 

#line 271 "..\\Hal_lib\\inc\\HAL_adc.h"


 



 








 



 










 



 








 



 





 



 





 



 





 



 





  




 




 



 





 



 





 



 



 



 



 

void ADC_DeInit(ADC_TypeDef* ADCx);
void ADC_Init(ADC_TypeDef* ADCx, ADC_InitTypeDef* ADC_InitStruct);
void ADC_StructInit(ADC_InitTypeDef* ADC_InitStruct);
void ADC_Cmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_DMACmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_ITConfig(ADC_TypeDef* ADCx, uint16_t ADC_IT, FunctionalState NewState);
void ADC_SoftwareStartConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
FlagStatus ADC_GetSoftwareStartConvStatus(ADC_TypeDef* ADCx);
void ADC_RegularChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel, uint8_t Rank, uint8_t ADC_SampleTime);
void ADC_ExternalTrigConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
uint16_t ADC_GetConversionValue(ADC_TypeDef* ADCx);
void ADC_ExternalTrigInjectedConvConfig(ADC_TypeDef* ADCx, uint32_t ADC_ExternalTrigInjecConv);
void ADC_ExternalTrigInjectedConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_SoftwareStartInjectedConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);

void ADC_AnalogWatchdogCmd(ADC_TypeDef* ADCx, uint32_t ADC_AnalogWatchdog);
void ADC_AnalogWatchdogThresholdsConfig(ADC_TypeDef* ADCx, uint16_t HighThreshold, uint16_t LowThreshold);
void ADC_AnalogWatchdogSingleChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel);
void ADC_TempSensorVrefintCmd(FunctionalState NewState);
FlagStatus ADC_GetFlagStatus(ADC_TypeDef* ADCx, uint8_t ADC_FLAG);
void ADC_ClearFlag(ADC_TypeDef* ADCx, uint8_t ADC_FLAG);
ITStatus ADC_GetITStatus(ADC_TypeDef* ADCx, uint16_t ADC_IT);
void ADC_ClearITPendingBit(ADC_TypeDef* ADCx, uint16_t ADC_IT);





 



 



 

 
#line 26 "..\\Hal_lib\\inc\\HAL_conf.h"
#line 1 "..\\Hal_lib\\inc\\HAL_dma.h"



















  

 



 
#line 28 "..\\Hal_lib\\inc\\HAL_dma.h"



 



 



 



 

typedef struct
{
  uint32_t DMA_PeripheralBaseAddr;
  uint32_t DMA_MemoryBaseAddr;
  uint32_t DMA_DIR;
  uint32_t DMA_BufferSize;
  uint32_t DMA_PeripheralInc;
  uint32_t DMA_MemoryInc;
  uint32_t DMA_PeripheralDataSize;
  uint32_t DMA_MemoryDataSize;
  uint32_t DMA_Mode;
  uint32_t DMA_Priority;
  uint32_t DMA_M2M;
}DMA_InitTypeDef;



 



 







           



 







 



 







 



 







 



 

#line 122 "..\\Hal_lib\\inc\\HAL_dma.h"


 



 

#line 136 "..\\Hal_lib\\inc\\HAL_dma.h"


 



 






 



 

#line 163 "..\\Hal_lib\\inc\\HAL_dma.h"


 



 







 



 








 

#line 212 "..\\Hal_lib\\inc\\HAL_dma.h"

#line 241 "..\\Hal_lib\\inc\\HAL_dma.h"








#line 259 "..\\Hal_lib\\inc\\HAL_dma.h"




 



 



 

#line 301 "..\\Hal_lib\\inc\\HAL_dma.h"






#line 335 "..\\Hal_lib\\inc\\HAL_dma.h"










#line 355 "..\\Hal_lib\\inc\\HAL_dma.h"
   
      


 



 





 



 



 



 



 

void DMA_DeInit(DMA_Channel_TypeDef* DMAy_Channelx);
void DMA_Init(DMA_Channel_TypeDef* DMAy_Channelx, DMA_InitTypeDef* DMA_InitStruct);
void DMA_StructInit(DMA_InitTypeDef* DMA_InitStruct);
void DMA_Cmd(DMA_Channel_TypeDef* DMAy_Channelx, FunctionalState NewState);
void DMA_ITConfig(DMA_Channel_TypeDef* DMAy_Channelx, uint32_t DMA_IT, FunctionalState NewState);
uint16_t DMA_GetCurrDataCounter(DMA_Channel_TypeDef* DMAy_Channelx);
FlagStatus DMA_GetFlagStatus(uint32_t DMA_FLAG);
void DMA_ClearFlag(uint32_t DMA_FLAG);
ITStatus DMA_GetITStatus(uint32_t DMA_IT);
void DMA_ClearITPendingBit(uint32_t DMA_IT);




 



 



 

 
#line 27 "..\\Hal_lib\\inc\\HAL_conf.h"
#line 1 "..\\Hal_lib\\inc\\HAL_exti.h"



















  

 



 
#line 28 "..\\Hal_lib\\inc\\HAL_exti.h"



 



 



 



 

typedef enum
{
  EXTI_Mode_Interrupt = 0x00,
  EXTI_Mode_Event = 0x04
}EXTIMode_TypeDef;





 

typedef enum
{
  EXTI_Trigger_Rising = 0x08,
  EXTI_Trigger_Falling = 0x0C,  
  EXTI_Trigger_Rising_Falling = 0x10
}EXTITrigger_TypeDef;






 

typedef struct
{
  uint32_t EXTI_Line;
  EXTIMode_TypeDef EXTI_Mode;
  EXTITrigger_TypeDef EXTI_Trigger;
  FunctionalState EXTI_LineCmd;
}EXTI_InitTypeDef;



 



 



 

#line 114 "..\\Hal_lib\\inc\\HAL_exti.h"



#line 127 "..\\Hal_lib\\inc\\HAL_exti.h"



 



 



 



 



 

void EXTI_DeInit(void);
void EXTI_Init(EXTI_InitTypeDef* EXTI_InitStruct);
void EXTI_StructInit(EXTI_InitTypeDef* EXTI_InitStruct);
void EXTI_GenerateSWInterrupt(uint32_t EXTI_Line);
FlagStatus EXTI_GetFlagStatus(uint32_t EXTI_Line);
void EXTI_ClearFlag(uint32_t EXTI_Line);
ITStatus EXTI_GetITStatus(uint32_t EXTI_Line);
void EXTI_ClearITPendingBit(uint32_t EXTI_Line);




 



 



 

 
#line 28 "..\\Hal_lib\\inc\\HAL_conf.h"
#line 1 "..\\Hal_lib\\inc\\HAL_flash.h"



















  

 



 
#line 28 "..\\Hal_lib\\inc\\HAL_flash.h"



 



 



 



 

typedef enum
{ 
  FLASH_BUSY = 1,
  FLASH_ERROR_PG,
  FLASH_ERROR_WRP,
  FLASH_COMPLETE,
  FLASH_TIMEOUT
}FLASH_Status;



 



 



 

#line 74 "..\\Hal_lib\\inc\\HAL_flash.h"


 



 







 



 







 



 


 
#line 140 "..\\Hal_lib\\inc\\HAL_flash.h"


 
#line 176 "..\\Hal_lib\\inc\\HAL_flash.h"









 



 







 



 







 



 







 



 







 



 














 



 



 



 



 

void FLASH_SetLatency(uint32_t FLASH_Latency);
void FLASH_HalfCycleAccessCmd(uint32_t FLASH_HalfCycleAccess);
void FLASH_PrefetchBufferCmd(uint32_t FLASH_PrefetchBuffer);
void FLASH_Unlock(void);
void FLASH_Lock(void);
FLASH_Status FLASH_ErasePage(uint32_t Page_Address);
FLASH_Status FLASH_EraseAllPages(void);
FLASH_Status FLASH_EraseOptionBytes(void);
FLASH_Status FLASH_ProgramWord(uint32_t Address, uint32_t Data);
FLASH_Status FLASH_ProgramHalfWord(uint32_t Address, uint16_t Data);
FLASH_Status FLASH_ProgramOptionByteData(uint32_t Address, uint8_t Data);
FLASH_Status FLASH_EnableWriteProtection(uint32_t FLASH_Pages);
FLASH_Status FLASH_ReadOutProtection(FunctionalState NewState);
FLASH_Status FLASH_UserOptionByteConfig(uint16_t OB_IWDG, uint16_t OB_STOP, uint16_t OB_STDBY);
uint32_t FLASH_GetUserOptionByte(void);
uint32_t FLASH_GetWriteProtectionOptionByte(void);
FlagStatus FLASH_GetReadOutProtectionStatus(void);
FlagStatus FLASH_GetPrefetchBufferStatus(void);
void FLASH_ITConfig(uint16_t FLASH_IT, FunctionalState NewState);
FlagStatus FLASH_GetFlagStatus(uint16_t FLASH_FLAG);
void FLASH_ClearFlag(uint16_t FLASH_FLAG);
FLASH_Status FLASH_GetStatus(void);
FLASH_Status FLASH_WaitForLastOperation(uint32_t Timeout);




 



 



 

 
#line 29 "..\\Hal_lib\\inc\\HAL_conf.h"
#line 1 "..\\Hal_lib\\inc\\HAL_gpio.h"



















  

 



 
#line 28 "..\\Hal_lib\\inc\\HAL_gpio.h"



 



 



 

#line 48 "..\\Hal_lib\\inc\\HAL_gpio.h"



 

typedef enum
{ 
  GPIO_Speed_10MHz = 1,
  GPIO_Speed_2MHz, 
  GPIO_Speed_50MHz
}GPIOSpeed_TypeDef;





 

typedef enum
{ 
GPIO_Mode_AIN = 0x0,  
GPIO_Mode_IN_FLOATING = 0x04, 
GPIO_Mode_IPD = 0x28,  
GPIO_Mode_IPU = 0x48,  
GPIO_Mode_Out_OD = 0x14,
GPIO_Mode_Out_PP = 0x10,
GPIO_Mode_AF_OD = 0x1C, 
GPIO_Mode_AF_PP = 0x18  
}GPIOMode_TypeDef;








 

typedef struct
{
  uint32_t GPIO_Pin;
  GPIOSpeed_TypeDef GPIO_Speed;
  GPIOMode_TypeDef GPIO_Mode;
}GPIO_InitTypeDef;



 

typedef enum
{ Bit_RESET = 0,
  Bit_SET
}BitAction;





 



 



 

#line 133 "..\\Hal_lib\\inc\\HAL_gpio.h"

#line 143 "..\\Hal_lib\\inc\\HAL_gpio.h"



#line 162 "..\\Hal_lib\\inc\\HAL_gpio.h"



 



 






#line 183 "..\\Hal_lib\\inc\\HAL_gpio.h"











#line 203 "..\\Hal_lib\\inc\\HAL_gpio.h"




 


 



 


#line 232 "..\\Hal_lib\\inc\\HAL_gpio.h"









 



 



 



 

void GPIO_DeInit(GPIO_TypeDef* GPIOx);
void GPIO_AFIODeInit(void);
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);
void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct);
uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
uint16_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx);
uint8_t GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
uint16_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx);
void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin);
void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin);
void GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal);
void GPIO_Write(GPIO_TypeDef* GPIOx, uint16_t PortVal);
void GPIO_PinLockConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_PinAFConfig(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin, uint8_t GPIO_AF);



 



 



 

 
#line 30 "..\\Hal_lib\\inc\\HAL_conf.h"
#line 1 "..\\Hal_lib\\inc\\HAL_i2c.h"



















  

 



 
#line 28 "..\\Hal_lib\\inc\\HAL_i2c.h"



 



 



 



 










 
typedef struct
{
  uint16_t I2C_Mode;
  uint16_t I2C_Speed;
  uint16_t I2C_OwnAddress;
  uint32_t I2C_ClockSpeed;
}I2C_InitTypeDef;



  




 





 

#line 84 "..\\Hal_lib\\inc\\HAL_i2c.h"





















 




 







 



 








  



 





  



 

#line 159 "..\\Hal_lib\\inc\\HAL_i2c.h"



#line 168 "..\\Hal_lib\\inc\\HAL_i2c.h"


 



 



#line 190 "..\\Hal_lib\\inc\\HAL_i2c.h"








#line 204 "..\\Hal_lib\\inc\\HAL_i2c.h"




 

#line 217 "..\\Hal_lib\\inc\\HAL_i2c.h"




 



 


#line 240 "..\\Hal_lib\\inc\\HAL_i2c.h"


#line 251 "..\\Hal_lib\\inc\\HAL_i2c.h"



 



 




 



 




 



 



 



 



 

void I2C_DeInit(I2C_TypeDef* I2Cx);
void I2C_Init(I2C_TypeDef* I2Cx, I2C_InitTypeDef* I2C_InitStruct);
void I2C_StructInit(I2C_InitTypeDef* I2C_InitStruct);
void I2C_Cmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_DMACmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_DMALastTransferCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_GenerateSTART(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_GenerateSTOP(I2C_TypeDef* I2Cx, FunctionalState NewState);

void I2C_OwnAddress2Config(I2C_TypeDef* I2Cx, uint8_t Address);
void I2C_DualAddressCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_GeneralCallCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_ITConfig(I2C_TypeDef* I2Cx, uint16_t I2C_IT, FunctionalState NewState);
void I2C_SendData(I2C_TypeDef* I2Cx, uint8_t Data);
uint8_t I2C_ReceiveData(I2C_TypeDef* I2Cx);
void I2C_Send7bitAddress(I2C_TypeDef* I2Cx, uint8_t Address, uint8_t I2C_Direction);
uint16_t I2C_ReadRegister(I2C_TypeDef* I2Cx, uint8_t I2C_Register);

uint32_t I2C_GetLastEvent(I2C_TypeDef* I2Cx);
ErrorStatus I2C_CheckEvent(I2C_TypeDef* I2Cx, uint32_t I2C_EVENT);
FlagStatus I2C_GetFlagStatus(I2C_TypeDef* I2Cx, uint32_t I2C_FLAG);
void I2C_ClearFlag(I2C_TypeDef* I2Cx, uint32_t I2C_FLAG);
ITStatus I2C_GetITStatus(I2C_TypeDef* I2Cx, uint32_t I2C_IT);
void I2C_ClearITPendingBit(I2C_TypeDef* I2Cx, uint32_t I2C_IT);
void I2C_ReadCmd(I2C_TypeDef* I2Cx);





  



  



  

 
#line 31 "..\\Hal_lib\\inc\\HAL_conf.h"
#line 1 "..\\Hal_lib\\inc\\HAL_iwdg.h"



















  

 



 
#line 28 "..\\Hal_lib\\inc\\HAL_iwdg.h"



 



 



 



 



 



 







 



 

#line 79 "..\\Hal_lib\\inc\\HAL_iwdg.h"


 



 







 



 



 



 



 

void IWDG_WriteAccessCmd(uint16_t IWDG_WriteAccess);
void IWDG_SetPrescaler(uint8_t IWDG_Prescaler);
void IWDG_SetReload(uint16_t Reload);
void IWDG_ReloadCounter(void);
void IWDG_Enable(void);
FlagStatus IWDG_GetFlagStatus(uint16_t IWDG_FLAG);




 



 



 

 
#line 32 "..\\Hal_lib\\inc\\HAL_conf.h"
#line 1 "..\\Hal_lib\\inc\\HAL_pwr.h"



















  

 



 
#line 28 "..\\Hal_lib\\inc\\HAL_pwr.h"



 



  



  



  



  



  

#line 70 "..\\Hal_lib\\inc\\HAL_pwr.h"


 



 







 



 







 



 










 



 



 



 



 

void PWR_DeInit(void);
void PWR_BackupAccessCmd(FunctionalState NewState);
void PWR_PVDCmd(FunctionalState NewState);
void PWR_PVDLevelConfig(uint32_t PWR_PVDLevel);
void PWR_WakeUpPinCmd(FunctionalState NewState);
void PWR_EnterSTOPMode(uint32_t PWR_Regulator, uint8_t PWR_STOPEntry);
void PWR_EnterSTANDBYMode(void);
FlagStatus PWR_GetFlagStatus(uint32_t PWR_FLAG);
void PWR_ClearFlag(uint32_t PWR_FLAG);




 



 



 

 
#line 33 "..\\Hal_lib\\inc\\HAL_conf.h"
#line 1 "..\\Hal_lib\\inc\\HAL_rcc.h"



















  

 



 
#line 28 "..\\Hal_lib\\inc\\HAL_rcc.h"



 



 



 

typedef struct
{
  uint32_t SYSCLK_Frequency;
  uint32_t HCLK_Frequency;
  uint32_t PCLK1_Frequency;
  uint32_t PCLK2_Frequency;
  uint32_t ADCCLK_Frequency;
}RCC_ClocksTypeDef;



 



 



 









  



 

#line 82 "..\\Hal_lib\\inc\\HAL_rcc.h"


  




 

#line 97 "..\\Hal_lib\\inc\\HAL_rcc.h"


 



 

#line 119 "..\\Hal_lib\\inc\\HAL_rcc.h"


  



 

#line 135 "..\\Hal_lib\\inc\\HAL_rcc.h"



  



 

#line 182 "..\\Hal_lib\\inc\\HAL_rcc.h"




 



 

#line 202 "..\\Hal_lib\\inc\\HAL_rcc.h"




 



 







 



 

#line 230 "..\\Hal_lib\\inc\\HAL_rcc.h"


 



 








 



 

#line 257 "..\\Hal_lib\\inc\\HAL_rcc.h"


 



 

#line 273 "..\\Hal_lib\\inc\\HAL_rcc.h"










 



 






#line 300 "..\\Hal_lib\\inc\\HAL_rcc.h"

#line 309 "..\\Hal_lib\\inc\\HAL_rcc.h"







  



 


#line 331 "..\\Hal_lib\\inc\\HAL_rcc.h"
























 



 

#line 372 "..\\Hal_lib\\inc\\HAL_rcc.h"


 



 

#line 397 "..\\Hal_lib\\inc\\HAL_rcc.h"




 



 



 



 



 
void SystemClk_HSEInit(uint32_t PLL_DN);
void RCC_DeInit(void);
void RCC_HSEConfig(uint32_t RCC_HSE);
ErrorStatus RCC_WaitForHSEStartUp(void);
void RCC_AdjustHSICalibrationValue(uint8_t HSICalibrationValue);
void RCC_HSICmd(FunctionalState NewState);
void RCC_PLLConfig(uint32_t RCC_PLLSource, uint32_t RCC_PLLMul);
void RCC_PLLCmd(FunctionalState NewState);
void RCC_SYSCLKConfig(uint32_t RCC_SYSCLKSource);
uint8_t RCC_GetSYSCLKSource(void);
void RCC_HCLKConfig(uint32_t RCC_SYSCLK);
void RCC_PCLK1Config(uint32_t RCC_HCLK);
void RCC_PCLK2Config(uint32_t RCC_HCLK);
void RCC_ITConfig(uint8_t RCC_IT, FunctionalState NewState);
void RCC_USBCLKConfig(uint32_t RCC_USBCLKSource);
void RCC_ADCCLKConfig(uint32_t RCC_PCLK2);
void RCC_LSEConfig(uint8_t RCC_LSE);
void RCC_LSICmd(FunctionalState NewState);
void RCC_RTCCLKConfig(uint32_t RCC_RTCCLKSource);
void RCC_RTCCLKCmd(FunctionalState NewState);
void RCC_GetClocksFreq(RCC_ClocksTypeDef* RCC_Clocks);
void RCC_AHBPeriphClockCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState);
void RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);
void RCC_APB1PeriphClockCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);
void RCC_APB2PeriphResetCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);
void RCC_APB1PeriphResetCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);
void RCC_BackupResetCmd(FunctionalState NewState);
void RCC_ClockSecuritySystemCmd(FunctionalState NewState);
void RCC_MCOConfig(uint8_t RCC_MCO);
FlagStatus RCC_GetFlagStatus(uint8_t RCC_FLAG);
void RCC_ClearFlag(void);
ITStatus RCC_GetITStatus(uint8_t RCC_IT);
void RCC_ClearITPendingBit(uint8_t RCC_IT);
void getSystemClock(u32 *sysclk);



 



 



  

 
#line 34 "..\\Hal_lib\\inc\\HAL_conf.h"
#line 1 "..\\Hal_lib\\inc\\HAL_spi.h"



















  

 



 
#line 28 "..\\Hal_lib\\inc\\HAL_spi.h"



 



  



 



 

typedef struct
{
  uint16_t SPI_Mode;
  uint16_t SPI_DataSize;
  uint16_t SPI_DataWidth;
  uint16_t SPI_CPOL;
  uint16_t SPI_CPHA;
  uint16_t SPI_NSS;
  uint16_t SPI_BaudRatePrescaler;
  uint16_t SPI_FirstBit; 
}SPI_InitTypeDef;




 



 









 



 







 



 








 




 







 




 







 



 







 



 









 



 







 



  



 


#line 190 "..\\Hal_lib\\inc\\HAL_spi.h"


  



 









 



 







 



 












 



 

#line 253 "..\\Hal_lib\\inc\\HAL_spi.h"


 




 

#line 270 "..\\Hal_lib\\inc\\HAL_spi.h"


 



 




















 



 










 




 











 



 



 



 

void SPI_DeInit(SPI_TypeDef* SPIx);
void SPI_Init(SPI_TypeDef* SPIx, SPI_InitTypeDef* SPI_InitStruct);
void SPI_StructInit(SPI_InitTypeDef* SPI_InitStruct);
void SPI_Cmd(SPI_TypeDef* SPIx, FunctionalState NewState);
void SPI_ITConfig(SPI_TypeDef* SPIx, uint8_t SPI_IT, FunctionalState NewState);
void SPI_DMACmd(SPI_TypeDef* SPIx, uint16_t SPI_DMAReq, FunctionalState NewState);
void SPI_FifoTrigger(SPI_TypeDef* SPIx, uint16_t SPI_FifoTriggerValue, FunctionalState NewState);
void SPI_SendData(SPI_TypeDef* SPIx, uint16_t Data);
uint16_t SPI_ReceiveData(SPI_TypeDef* SPIx);
void SPI_CSInternalSelected(SPI_TypeDef* SPIx, uint16_t SPI_CSInternalSelected,FunctionalState NewState);
void SPI_NSSInternalSoftwareConfig(SPI_TypeDef* SPIx, uint16_t SPI_NSSInternalSoft);
void SPI_DataSizeConfig(SPI_TypeDef* SPIx, uint16_t SPI_DataSize);
void SPI_BiDirectionalLineConfig(SPI_TypeDef* SPIx, uint16_t SPI_Direction);
FlagStatus SPI_GetFlagStatus(SPI_TypeDef* SPIx, uint16_t SPI_FLAG);
ITStatus SPI_GetITStatus(SPI_TypeDef* SPIx, uint8_t SPI_IT);
void SPI_ClearITPendingBit(SPI_TypeDef* SPIx, uint8_t SPI_IT);
void SPI_RxBytes(SPI_TypeDef* SPIx, uint16_t Number);
void SPI_SlaveAdjust(SPI_TypeDef* SPIx, uint16_t AdjustValue);



 



 



 

 
#line 35 "..\\Hal_lib\\inc\\HAL_conf.h"
#line 1 "..\\Hal_lib\\inc\\HAL_tim.h"



















  

 






  
   
#line 32 "..\\Hal_lib\\inc\\HAL_tim.h"
  
  

 
  
  

  
  
   
  
  


 
  
  typedef struct
  {
    uint16_t TIM_Prescaler;         
 
    
    uint16_t TIM_CounterMode;       
 
    
    uint32_t TIM_Period;
    
  
    
    uint16_t TIM_ClockDivision;     
 
    
    uint8_t TIM_RepetitionCounter;  






 
  } TIM_TimeBaseInitTypeDef;       
  
  

 
  
  typedef struct
  {
    uint16_t TIM_OCMode;        
 
    
    uint16_t TIM_OutputState;   
 
    
    uint16_t TIM_OutputNState;  

 

    uint32_t TIM_Pulse;
    uint16_t TIM_OCPolarity;
    uint16_t TIM_OCNPolarity;
    uint16_t TIM_OCIdleState;
    uint16_t TIM_OCNIdleState;
} TIM_OCInitTypeDef;



 

typedef struct
{
  uint16_t TIM_Channel;
  uint16_t TIM_ICPolarity;
  uint16_t TIM_ICSelection;
  uint16_t TIM_ICPrescaler;
  uint16_t TIM_ICFilter;
} TIM_ICInitTypeDef;



 

typedef struct
{
  uint16_t TIM_OSSRState;
  uint16_t TIM_OSSIState;
  uint16_t TIM_LOCKLevel; 
  uint16_t TIM_DeadTime;
  uint16_t TIM_Break;
  uint16_t TIM_BreakPolarity;
  uint16_t TIM_AutomaticOutput;
} TIM_BDTRInitTypeDef;



 






 
#line 140 "..\\Hal_lib\\inc\\HAL_tim.h"

 






 




 





 





 




 






 





  



 

#line 209 "..\\Hal_lib\\inc\\HAL_tim.h"


 



 







  



 






#line 243 "..\\Hal_lib\\inc\\HAL_tim.h"



  



 

#line 258 "..\\Hal_lib\\inc\\HAL_tim.h"


 



 

#line 276 "..\\Hal_lib\\inc\\HAL_tim.h"


  



 







 



 







 



 







  



 







  



 







  



 







  



 







  



 







  



 







  



 

#line 400 "..\\Hal_lib\\inc\\HAL_tim.h"


  



 







 



 







  



 







  



 







  



 

#line 462 "..\\Hal_lib\\inc\\HAL_tim.h"


  



 

#line 478 "..\\Hal_lib\\inc\\HAL_tim.h"


  



 

#line 494 "..\\Hal_lib\\inc\\HAL_tim.h"


  



 

#line 511 "..\\Hal_lib\\inc\\HAL_tim.h"

#line 520 "..\\Hal_lib\\inc\\HAL_tim.h"


  



 

#line 568 "..\\Hal_lib\\inc\\HAL_tim.h"


  




 

#line 613 "..\\Hal_lib\\inc\\HAL_tim.h"


  



 

#line 629 "..\\Hal_lib\\inc\\HAL_tim.h"



  



 

#line 646 "..\\Hal_lib\\inc\\HAL_tim.h"


  



 

#line 674 "..\\Hal_lib\\inc\\HAL_tim.h"


  



 







  



  






 



 







  



 







  



 

#line 735 "..\\Hal_lib\\inc\\HAL_tim.h"


  




 

#line 753 "..\\Hal_lib\\inc\\HAL_tim.h"



  



 

#line 768 "..\\Hal_lib\\inc\\HAL_tim.h"


  



 







  



 








  



 







  



 

#line 829 "..\\Hal_lib\\inc\\HAL_tim.h"


  



 

#line 845 "..\\Hal_lib\\inc\\HAL_tim.h"


  



 







  



 

#line 889 "..\\Hal_lib\\inc\\HAL_tim.h"





  




 




  



 




 



 







 


 











 



 

#line 964 "..\\Hal_lib\\inc\\HAL_tim.h"


 



 

 
  

 
void TIM_DeInit(TIM_TypeDef* TIMx);
void TIM_TimeBaseInit(TIM_TypeDef* TIMx, TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
void TIM_TimeBaseStructInit(TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
void TIM_PrescalerConfig(TIM_TypeDef* TIMx, uint16_t Prescaler, uint16_t TIM_PSCReloadMode);
void TIM_CounterModeConfig(TIM_TypeDef* TIMx, uint16_t TIM_CounterMode);
void TIM_SetCounter(TIM_TypeDef* TIMx, uint32_t Counter);
void TIM_SetAutoreload(TIM_TypeDef* TIMx, uint32_t Autoreload);
uint32_t TIM_GetCounter(TIM_TypeDef* TIMx);
uint16_t TIM_GetPrescaler(TIM_TypeDef* TIMx);
void TIM_UpdateDisableConfig(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_UpdateRequestConfig(TIM_TypeDef* TIMx, uint16_t TIM_UpdateSource);
void TIM_ARRPreloadConfig(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_SelectOnePulseMode(TIM_TypeDef* TIMx, uint16_t TIM_OPMode);
void TIM_SetClockDivision(TIM_TypeDef* TIMx, uint16_t TIM_CKD);
void TIM_Cmd(TIM_TypeDef* TIMx, FunctionalState NewState);

 
void TIM_BDTRConfig(TIM_TypeDef* TIMx, TIM_BDTRInitTypeDef *TIM_BDTRInitStruct);
void TIM_BDTRStructInit(TIM_BDTRInitTypeDef* TIM_BDTRInitStruct);
void TIM_CtrlPWMOutputs(TIM_TypeDef* TIMx, FunctionalState NewState);

 
void TIM_OC1Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC2Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC3Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC4Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OCStructInit(TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_SelectOCxM(TIM_TypeDef* TIMx, uint16_t TIM_Channel, uint16_t TIM_OCMode);
void TIM_SetCompare1(TIM_TypeDef* TIMx, uint32_t Compare1);
void TIM_SetCompare2(TIM_TypeDef* TIMx, uint32_t Compare2);
void TIM_SetCompare3(TIM_TypeDef* TIMx, uint32_t Compare3);
void TIM_SetCompare4(TIM_TypeDef* TIMx, uint32_t Compare4);
void TIM_ForcedOC1Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
void TIM_ForcedOC2Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
void TIM_ForcedOC3Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
void TIM_ForcedOC4Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
void TIM_CCPreloadControl(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_OC1PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
void TIM_OC2PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
void TIM_OC3PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
void TIM_OC4PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
void TIM_OC1FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
void TIM_OC2FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
void TIM_OC3FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
void TIM_OC4FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
void TIM_ClearOC1Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
void TIM_ClearOC2Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
void TIM_ClearOC3Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
void TIM_ClearOC4Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
void TIM_OC1PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
void TIM_OC1NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);
void TIM_OC2PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
void TIM_OC2NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);
void TIM_OC3PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
void TIM_OC3NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);
void TIM_OC4PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
void TIM_SelectOCREFClear(TIM_TypeDef* TIMx, uint16_t TIM_OCReferenceClear);
void TIM_CCxCmd(TIM_TypeDef* TIMx, uint16_t TIM_Channel, uint16_t TIM_CCx);
void TIM_CCxNCmd(TIM_TypeDef* TIMx, uint16_t TIM_Channel, uint16_t TIM_CCxN);
void TIM_SelectCOM(TIM_TypeDef* TIMx, FunctionalState NewState);

 
void TIM_ICInit(TIM_TypeDef* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct);
void TIM_ICStructInit(TIM_ICInitTypeDef* TIM_ICInitStruct);
void TIM_PWMIConfig(TIM_TypeDef* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct);
uint32_t TIM_GetCapture1(TIM_TypeDef* TIMx);
uint32_t TIM_GetCapture2(TIM_TypeDef* TIMx);
uint32_t TIM_GetCapture3(TIM_TypeDef* TIMx);
uint32_t TIM_GetCapture4(TIM_TypeDef* TIMx);
void TIM_SetIC1Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);
void TIM_SetIC2Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);
void TIM_SetIC3Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);
void TIM_SetIC4Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);

 
void TIM_ITConfig(TIM_TypeDef* TIMx, uint16_t TIM_IT, FunctionalState NewState);
void TIM_GenerateEvent(TIM_TypeDef* TIMx, uint16_t TIM_EventSource);
FlagStatus TIM_GetFlagStatus(TIM_TypeDef* TIMx, uint16_t TIM_FLAG);
void TIM_ClearFlag(TIM_TypeDef* TIMx, uint16_t TIM_FLAG);
ITStatus TIM_GetITStatus(TIM_TypeDef* TIMx, uint16_t TIM_IT);
void TIM_ClearITPendingBit(TIM_TypeDef* TIMx, uint16_t TIM_IT);
void TIM_DMAConfig(TIM_TypeDef* TIMx, uint16_t TIM_DMABase, uint16_t TIM_DMABurstLength);
void TIM_DMACmd(TIM_TypeDef* TIMx, uint16_t TIM_DMASource, FunctionalState NewState);
void TIM_SelectCCDMA(TIM_TypeDef* TIMx, FunctionalState NewState);

 
void TIM_InternalClockConfig(TIM_TypeDef* TIMx);
void TIM_ITRxExternalClockConfig(TIM_TypeDef* TIMx, uint16_t TIM_InputTriggerSource);
void TIM_TIxExternalClockConfig(TIM_TypeDef* TIMx, uint16_t TIM_TIxExternalCLKSource,
                                uint16_t TIM_ICPolarity, uint16_t ICFilter);
void TIM_ETRClockMode1Config(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, uint16_t TIM_ExtTRGPolarity,
                             uint16_t ExtTRGFilter);
void TIM_ETRClockMode2Config(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, 
                             uint16_t TIM_ExtTRGPolarity, uint16_t ExtTRGFilter);


 
void TIM_SelectInputTrigger(TIM_TypeDef* TIMx, uint16_t TIM_InputTriggerSource);
void TIM_SelectOutputTrigger(TIM_TypeDef* TIMx, uint16_t TIM_TRGOSource);
void TIM_SelectSlaveMode(TIM_TypeDef* TIMx, uint16_t TIM_SlaveMode);
void TIM_SelectMasterSlaveMode(TIM_TypeDef* TIMx, uint16_t TIM_MasterSlaveMode);
void TIM_ETRConfig(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, uint16_t TIM_ExtTRGPolarity,
                   uint16_t ExtTRGFilter);

                    
void TIM_EncoderInterfaceConfig(TIM_TypeDef* TIMx, uint16_t TIM_EncoderMode,
                                uint16_t TIM_IC1Polarity, uint16_t TIM_IC2Polarity);
void TIM_SelectHallSensor(TIM_TypeDef* TIMx, FunctionalState NewState);

 
void TIM_RemapConfig(TIM_TypeDef* TIMx, uint16_t TIM_Remap);










  



 

 
#line 36 "..\\Hal_lib\\inc\\HAL_conf.h"
#line 1 "..\\Hal_lib\\inc\\HAL_uart.h"



















  

 



 
#line 28 "..\\Hal_lib\\inc\\HAL_uart.h"



 



  



  



  

typedef struct
{
  uint32_t UART_BaudRate;
  uint16_t UART_WordLength;
  uint16_t UART_StopBits;
  uint16_t UART_Parity;
  uint16_t UART_Mode;
  uint16_t UART_HardwareFlowControl; 
} UART_InitTypeDef;




  



  

#line 70 "..\\Hal_lib\\inc\\HAL_uart.h"



  













  



  









  



  

#line 113 "..\\Hal_lib\\inc\\HAL_uart.h"


  



  









  



  










 


#line 153 "..\\Hal_lib\\inc\\HAL_uart.h"













 



 






  




 




















  



  



  



  



 

void UART_DeInit(UART_TypeDef* UARTx);
void UART_Init(UART_TypeDef* UARTx, UART_InitTypeDef* UART_InitStruct);
void UART_StructInit(UART_InitTypeDef* UART_InitStruct);
void UART_Cmd(UART_TypeDef* UARTx, FunctionalState NewState);
void UART_ITConfig(UART_TypeDef* UARTx, uint16_t UART_IT, FunctionalState NewState);
void UART_DMACmd(UART_TypeDef* UARTx, uint16_t UART_DMAReq, FunctionalState NewState);
void UART_SendData(UART_TypeDef* UARTx, uint16_t Data);
uint16_t UART_ReceiveData(UART_TypeDef* UARTx);
FlagStatus UART_GetFlagStatus(UART_TypeDef* UARTx, uint16_t UART_FLAG);
void UART_ClearFlag(UART_TypeDef* UARTx, uint16_t UART_FLAG);
ITStatus UART_GetITStatus(UART_TypeDef* UARTx, uint16_t UART_IT);
void UART_ClearITPendingBit(UART_TypeDef* UARTx, uint16_t UART_IT);



  



  



  

 
#line 37 "..\\Hal_lib\\inc\\HAL_conf.h"
#line 1 "..\\Hal_lib\\inc\\HAL_wwdg.h"



















  

 



 
#line 28 "..\\Hal_lib\\inc\\HAL_wwdg.h"



 



  



  



  



  



  

#line 63 "..\\Hal_lib\\inc\\HAL_wwdg.h"



  



  



  


  



  

void WWDG_DeInit(void);
void WWDG_SetPrescaler(uint32_t WWDG_Prescaler);
void WWDG_SetWindowValue(uint8_t WindowValue);
void WWDG_EnableIT(void);
void WWDG_SetCounter(uint8_t Counter);
void WWDG_Enable(uint8_t Counter);
FlagStatus WWDG_GetFlagStatus(void);
void WWDG_ClearFlag(void);





  



  



  

 
#line 38 "..\\Hal_lib\\inc\\HAL_conf.h"
#line 1 "..\\Hal_lib\\inc\\HAL_misc.h"



















  

 



 
#line 28 "..\\Hal_lib\\inc\\HAL_misc.h"



 



 



 



 

typedef struct
{
  uint8_t NVIC_IRQChannel;
  uint8_t NVIC_IRQChannelPreemptionPriority;
  uint8_t NVIC_IRQChannelSubPriority;
  FunctionalState NVIC_IRQChannelCmd;
} NVIC_InitTypeDef;



 



 



 







 



 

#line 83 "..\\Hal_lib\\inc\\HAL_misc.h"


 



 

#line 101 "..\\Hal_lib\\inc\\HAL_misc.h"















 



 







 



 



 



 



 

void NVIC_PriorityGroupConfig(uint32_t NVIC_PriorityGroup);
void NVIC_Init(NVIC_InitTypeDef* NVIC_InitStruct);
void NVIC_SetVectorTable(uint32_t NVIC_VectTab, uint32_t Offset);
void NVIC_SystemLPConfig(uint8_t LowPowerMode, FunctionalState NewState);
void SysTick_CLKSourceConfig(uint32_t SysTick_CLKSource);





 



 



 

 
#line 39 "..\\Hal_lib\\inc\\HAL_conf.h"
#line 1 "..\\Hal_lib\\inc\\HAL_syscfg.h"













 

 






  
   
#line 26 "..\\Hal_lib\\inc\\HAL_syscfg.h"
  
  

 
  
  

 
   
   
  
  

  
  
  

  
#line 50 "..\\Hal_lib\\inc\\HAL_syscfg.h"
  
#line 57 "..\\Hal_lib\\inc\\HAL_syscfg.h"


 



  
#line 80 "..\\Hal_lib\\inc\\HAL_syscfg.h"

#line 97 "..\\Hal_lib\\inc\\HAL_syscfg.h"


 



  











 



  






#line 140 "..\\Hal_lib\\inc\\HAL_syscfg.h"




 




 
 

 
void SYSCFG_DeInit(void);

  
void SYSCFG_MemoryRemapConfig(uint32_t SYSCFG_MemoryRemap);
void SYSCFG_DMAChannelRemapConfig(uint32_t SYSCFG_DMARemap, FunctionalState NewState);
void SYSCFG_I2CFastModePlusConfig(uint32_t SYSCFG_I2CFastModePlus, FunctionalState NewState);
void SYSCFG_IRDAEnvSelection(uint32_t SYSCFG_IRDAEnv);
void SYSCFG_EXTILineConfig(uint8_t EXTI_PortSourceGPIOx, uint8_t EXTI_PinSourcex);
uint32_t SYSCFG_GetPendingIT(uint32_t ITSourceLine);
void SYSCFG_BreakConfig(uint32_t SYSCFG_Break);
FlagStatus SYSCFG_GetFlagStatus(uint32_t SYSCFG_Flag);
void SYSCFG_ClearFlag(uint32_t SYSCFG_Flag);









  



  

 
#line 40 "..\\Hal_lib\\inc\\HAL_conf.h"
#line 1 "..\\Hal_lib\\inc\\HAL_can.h"



















  
 



 
#line 27 "..\\Hal_lib\\inc\\HAL_can.h"




 






 





 






 




 






 



 
#line 77 "..\\Hal_lib\\inc\\HAL_can.h"



 



 







 



 
#line 106 "..\\Hal_lib\\inc\\HAL_can.h"



 



 
#line 122 "..\\Hal_lib\\inc\\HAL_can.h"



 



 







 



 
typedef struct
{
  uint8_t SJW;
  uint8_t BRP;
  FlagStatus SAM;
  uint8_t TESG2;
  uint8_t TESG1;
  FunctionalState GTS;
  uint8_t CDCLK;
  uint8_t CLOSE_OPEN_CLK;
  uint8_t RXINTEN;
  uint8_t CBP;
}CAN_Basic_InitTypeDef;



 



 
typedef struct
{
  uint8_t SJW;
  uint8_t BRP;
  FlagStatus SAM;
  uint8_t TESG2;
  uint8_t TESG1;
  FunctionalState LOM;
  FunctionalState STM;
  FunctionalState SM; 
  FunctionalState SRR;
  uint32_t EWLR;
}CAN_Peli_InitTypeDef;



 



 
typedef struct
{
  uint8_t CAN_FilterId;         
 
  
  uint8_t CAN_FilterMaskId;     
 
} CAN_Basic_FilterInitTypeDef;



 



 
typedef struct
{
  uint8_t AFM;
  uint8_t CAN_FilterId0;         
 
  uint8_t CAN_FilterId1;
  uint8_t CAN_FilterId2;
  uint8_t CAN_FilterId3;
  
  uint8_t CAN_FilterMaskId0;     
 
  uint8_t CAN_FilterMaskId1;
  uint8_t CAN_FilterMaskId2;
  uint8_t CAN_FilterMaskId3;
} CAN_Peli_FilterInitTypeDef;



 



 
typedef enum {DataFrame = 0,RemoteFrame = !DataFrame}TransFrame;



 



 
typedef struct
{
  uint8_t IDH;  
 
  uint8_t IDL;  
 
  uint8_t RTR;     
 
  
  uint8_t DLC;     

 
  
  uint8_t Data[8]; 
 
} CanBasicTxMsg;



 



 
typedef struct
{
  uint16_t ID;  
 
  uint8_t RTR;     

 
  
  uint8_t DLC;     
 
  
  uint8_t Data[8]; 
 
  
} CanBasicRxMsg;



 



 
typedef struct
{
  uint8_t IDLL;  
 
  uint8_t IDLH;
  uint8_t IDHL;
  uint8_t IDHH;
  uint8_t FF;     

 
  
  uint8_t RTR;     

 
  
  uint8_t DLC;     

 
  
  uint8_t Data[8]; 
 
} CanPeliTxMsg;



 



 
typedef struct
{
  uint32_t ID;  
 
  uint8_t FF;     

 
  
  uint8_t RTR;     

 
  
  uint8_t DLC;     
 
  
  uint8_t Data[8]; 
 
  
} CanPeliRxMsg;










 

void CAN_Mode_Cmd(CAN_TypeDef* CANx, uint32_t CAN_MODE);
void CAN_ResetMode_Cmd(CAN_TypeDef* CANx,FunctionalState NewState);
void CAN_ClearDataOverflow(CAN_TypeDef* CANx);
void CAN_ClearITPendingBit(CAN_TypeDef* CANx);


 
void CAN_DeInit(CAN_TypeDef* CANx);
uint8_t CAN_Init(CAN_TypeDef* CANx, CAN_Basic_InitTypeDef* CAN_Basic_InitStruct);
void CAN_FilterInit(CAN_Basic_FilterInitTypeDef* CAN_Basic_FilterInitStruct);
void CAN_StructInit(CAN_Basic_InitTypeDef* CAN_Basic_InitStruct);
void CAN_ITConfig(CAN_TypeDef* CANx, uint32_t CAN_IT, FunctionalState Newstate);
uint8_t CAN_Transmit(CAN_TypeDef* CANx,CanBasicTxMsg* BasicTxMessage);
void CAN_CancelTransmit(CAN_TypeDef* CANx);
void CAN_FIFORelease(CAN_TypeDef* CANx);
void CAN_Receive(CAN_TypeDef* CANx,CanBasicRxMsg* BasicRxMessage);
uint8_t CAN_Sleep(CAN_TypeDef* CANx);
uint8_t CAN_WakeUp(CAN_TypeDef* CANx);
FlagStatus CAN_GetFlagStatus(CAN_TypeDef* CANx,uint32_t CAN_FLAG);
ITStatus CAN_GetITStatus(CAN_TypeDef* CANx, uint32_t CAN_IT);


 
void CAN_Peli_SleepMode_Cmd(FunctionalState NewState);
void CAN_Peli_Init(CAN_Peli_InitTypeDef* CAN_InitStruct);
void CAN_Peli_StructInit(CAN_Peli_InitTypeDef* CAN_Peli_InitStruct);
void CAN_Peli_FilterInit(CAN_Peli_FilterInitTypeDef* CAN_Peli_FilterInitStruct);
void CAN_Peli_FilterStructInit(CAN_Peli_FilterInitTypeDef* CAN_Peli_FilterInitStruct);
void CAN_Peli_Transmit(CanPeliTxMsg* PeliTxMessage);
void CAN_Peli_TransmitRepeat(CanPeliTxMsg* PeliTxMessage);
void CAN_Peli_Receive(CanPeliRxMsg* PeliRxMessage);
uint32_t CAN_Peli_GetRxFIFOInfo(void);
uint8_t CAN_Peli_GetLastErrorCode(void);
uint8_t CAN_Peli_GetReceiveErrorCounter(void);
uint8_t CAN_Peli_GetLSBTransmitErrorCounter(void);
void CAN_Peli_ITConfig(uint32_t CAN_IT, FunctionalState NewState);
ITStatus CAN_Peli_GetITStatus(uint32_t CAN_IT);
void CAN_AutoCfg_BaudParam(CAN_Peli_InitTypeDef  *CAN_Peli_InitStruct,unsigned int SrcClk,unsigned int baud );


#line 41 "..\\Hal_lib\\inc\\HAL_conf.h"


 
#line 5 "bsp\\exit\\exit.h"


void EXITLCD_Init(void);
void EXIT_KEY_Init(void);
void EXITLCD_Show(void);
#line 2 "bsp\\exit\\exit.c"

#line 4 "bsp\\exit\\exit.c"
#line 1 "..\\CMSIS_and_startup\\sys.h"
#line 1 "..\\CMSIS_and_startup\\tk499.h"





















 







#line 4689 "..\\CMSIS_and_startup\\tk499.h"



 



 

 
#line 4 "..\\CMSIS_and_startup\\sys.h"
#line 5 "..\\CMSIS_and_startup\\sys.h"







void  RemapVtorTable(void);
void  AI_Responder_enable(void);
void  AI_Responder_disable(void);

void Sys_Soft_Reset(void);      							
void Sys_Standby(void);         							

void TK499_NVIC_Init(u8 NVIC_PreemptionPriority,u8 NVIC_SubPriority,u8 NVIC_Channel,u8 NVIC_Group);	
void Ex_NVIC_Config(u8 GPIOx,u8 BITx,u8 TRIM);				


void WFI_SET(void);		
void INTX_DISABLE(void);
void INTX_ENABLE(void);	

void TIM3_Config(u16 arr,u16 psc);












#line 5 "bsp\\exit\\exit.c"
#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"
 
 
 





 






 







 




  
 








#line 47 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"


  



    typedef unsigned int size_t;    









 
 

 



    typedef struct __va_list __va_list;






   




 




typedef struct __fpos_t_struct {
    unsigned __int64 __pos;
    



 
    struct {
        unsigned int __state1, __state2;
    } __mbstate;
} fpos_t;
   


 


   

 

typedef struct __FILE FILE;
   






 

#line 136 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"


extern FILE __stdin, __stdout, __stderr;
extern FILE *__aeabi_stdin, *__aeabi_stdout, *__aeabi_stderr;

#line 166 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"
    

    

    





     



   


 


   


 

   



 

   


 




   


 





    


 






extern __declspec(__nothrow) int remove(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int rename(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) FILE *tmpfile(void);
   




 
extern __declspec(__nothrow) char *tmpnam(char *  );
   











 

extern __declspec(__nothrow) int fclose(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) int fflush(FILE *  );
   







 
extern __declspec(__nothrow) FILE *fopen(const char * __restrict  ,
                           const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   








































 
extern __declspec(__nothrow) FILE *freopen(const char * __restrict  ,
                    const char * __restrict  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(2,3)));
   








 
extern __declspec(__nothrow) void setbuf(FILE * __restrict  ,
                    char * __restrict  ) __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) int setvbuf(FILE * __restrict  ,
                   char * __restrict  ,
                   int  , size_t  ) __attribute__((__nonnull__(1)));
   















 
#pragma __printf_args
extern __declspec(__nothrow) int fprintf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   


















 
#pragma __printf_args
extern __declspec(__nothrow) int _fprintf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   




 
#pragma __printf_args
extern __declspec(__nothrow) int _printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






 
#pragma __printf_args
extern __declspec(__nothrow) int _sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

#pragma __printf_args
extern __declspec(__nothrow) int __ARM_snprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(3)));


#pragma __printf_args
extern __declspec(__nothrow) int snprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   















 

#pragma __printf_args
extern __declspec(__nothrow) int _snprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int fscanf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






























 
#pragma __scanf_args
extern __declspec(__nothrow) int _fscanf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   






 
#pragma __scanf_args
extern __declspec(__nothrow) int _scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int sscanf(const char * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   








 
#pragma __scanf_args
extern __declspec(__nothrow) int _sscanf(const char * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

 
extern __declspec(__nothrow) int vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int _vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int _vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int _vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int __ARM_vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int _vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int vfprintf(FILE * __restrict  ,
                    const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int vsprintf(char * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int __ARM_vsnprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));

extern __declspec(__nothrow) int vsnprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   







 

extern __declspec(__nothrow) int _vsprintf(char * __restrict  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vfprintf(FILE * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vsnprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   



 

#pragma __printf_args
extern __declspec(__nothrow) int asprintf(char **  , const char * __restrict  , ...) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) int vasprintf(char **  , const char * __restrict  , __va_list  ) __attribute__((__nonnull__(2)));

#pragma __printf_args
extern __declspec(__nothrow) int __ARM_asprintf(char **  , const char * __restrict  , ...) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) int __ARM_vasprintf(char **  , const char * __restrict  , __va_list  ) __attribute__((__nonnull__(2)));
   








 

extern __declspec(__nothrow) int fgetc(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) char *fgets(char * __restrict  , int  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   










 
extern __declspec(__nothrow) int fputc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   







 
extern __declspec(__nothrow) int fputs(const char * __restrict  , FILE * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int getc(FILE *  ) __attribute__((__nonnull__(1)));
   







 




    extern __declspec(__nothrow) int (getchar)(void);

   





 
extern __declspec(__nothrow) char *gets(char *  ) __attribute__((__nonnull__(1)));
   









 
extern __declspec(__nothrow) int putc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   





 




    extern __declspec(__nothrow) int (putchar)(int  );

   



 
extern __declspec(__nothrow) int puts(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int ungetc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   






















 

extern __declspec(__nothrow) size_t fread(void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   











 

extern __declspec(__nothrow) size_t __fread_bytes_avail(void * __restrict  ,
                    size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   











 

extern __declspec(__nothrow) size_t fwrite(const void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   







 

extern __declspec(__nothrow) int fgetpos(FILE * __restrict  , fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) int fseek(FILE *  , long int  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) int fsetpos(FILE * __restrict  , const fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   










 
extern __declspec(__nothrow) long int ftell(FILE *  ) __attribute__((__nonnull__(1)));
   











 
extern __declspec(__nothrow) void rewind(FILE *  ) __attribute__((__nonnull__(1)));
   





 

extern __declspec(__nothrow) void clearerr(FILE *  ) __attribute__((__nonnull__(1)));
   




 

extern __declspec(__nothrow) int feof(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) int ferror(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) void perror(const char *  );
   









 

extern __declspec(__nothrow) int _fisatty(FILE *   ) __attribute__((__nonnull__(1)));
    
 

extern __declspec(__nothrow) void __use_no_semihosting_swi(void);
extern __declspec(__nothrow) void __use_no_semihosting(void);
    





 











#line 1021 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"



 

#line 6 "bsp\\exit\\exit.c"
#line 1 ".\\bsp\\LCD\\LCD.h"
#line 2 ".\\bsp\\LCD\\LCD.h"



extern __align(256) u32 LTDC_Buf[480*800*2];
#line 21 ".\\bsp\\LCD\\LCD.h"











#line 41 ".\\bsp\\LCD\\LCD.h"











						
						

void LCD_Initial(void); 
void Lcd_Initialize(void); 
volatile void LCD_delay(volatile int time);
void WriteComm(unsigned char CMD);
void WriteData(u32 dat);
void LCD_WR_REG(u16 Index,u16 CongfigTemp);
void Lcd_ColorBox(u16 xStart,u16 yStart,u16 xLong,u16 yLong,u32 Color);


void LCD_PutString(unsigned short x, unsigned short y, char *s, unsigned int fColor, unsigned int bColor,unsigned char flag);
void LCD_Fill_Pic(u16 x, u16 y,u16 pic_H, u16 pic_V, u32* pic);
#line 7 "bsp\\exit\\exit.c"


char  EXTI_BUFF[15][40];
volatile unsigned short    EXTI_X;  
volatile unsigned short    EXTI_Y;
volatile unsigned short ie,je;
volatile char ae,be,*pe;

void EXITLCD_Init(void)
{
		char i,j,a;	
	EXTI_X=80;                   
	EXTI_Y=150;
	  ie=je=0;
	  i=j=0;
	a=0x30;
  be=0x3A;
  
	for(i=0;i<15;i++) 
			{
				for(j=0;j<40;j++)
				{ 
					 EXTI_BUFF[i][j]=a;
				 a++;	
					if(a==0x7E)	
					 a=0x30;			
				
				}
		
	    }
}

void EXIT_KEY_Init(void)
{

	NVIC_InitTypeDef   NVIC_InitStructure;														

    
	
	
  Ex_NVIC_Config(0,0,1); 

  NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_Init( & NVIC_InitStructure);


}

void EXITLCD_Show(void)
{
			
		char  BUFF[40+1]={0x39,0};

		int im,jm,jj=0;
		char aa;
		char *pp;
					   pp= &EXTI_BUFF[0][0];
  

								LCD_PutString(80,120,BUFF,0x0000FF,0x00FFFF,1);
    for (im=0; im<15; im++)  
    {		

        for (jm=0; jm<40; jm++)  
        {
					
					  aa=pp[jj];
					  BUFF[jm]=aa;
					  jj++;
		  		  if(jj==(40*15))
		   				jj=0;
					
					
        }
						LCD_PutString(EXTI_X,EXTI_Y,BUFF,0x0000FF,0x00FFFF,1);  
				    if(EXTI_Y<(((15*16)+150)-16))
						{ EXTI_Y=EXTI_Y+16; }
						else 
						{	EXTI_Y=150;  }
		}	

  
}
	



void EXTI0_IRQHandler(void)
{    

     
					
	  LCD_PutString(200,80,"EXIT-in",0x0000FF,0x00FFFF,1);



      
	  if(EXTI_GetITStatus(((uint32_t)0x00001))!=RESET)  
					   EXTI_BUFF[je][ie]=be; 
										ie++;
	
					 	if(ie==40)
						{ ie=0; je++;		}
					      	if(je==15)
								    je=0;				 								 			
        be++;
				if(be==0x5B)
					 be=0x3A;
				LCD_PutString(200,80,"EXIT---out",0x00FFFF,0xFF0000,1);

	    EXTI_ClearITPendingBit(((uint32_t)0x00001)); 
}


