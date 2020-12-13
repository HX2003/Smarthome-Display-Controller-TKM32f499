#include "exit.h"
//#include "Key.h"
#include "HAL_conf.h"
#include "sys.h"
#include "stdio.h"
#include "LCD.h"
//#include "Tk499.h" ///

char  EXTI_BUFF[YLCD][XLCD];
volatile unsigned short    EXTI_X;  //320240XY,这变量可能会被意想不到地改变,使用時直接存取原始内存地址
volatile unsigned short    EXTI_Y;
volatile unsigned short ie,je;
volatile char ae,be,*pe;

void EXITLCD_Init(void)
{
		char i,j,a;	
	EXTI_X=80;                   //模拟320240左上角XY坐标
	EXTI_Y=150;
	  ie=je=0;
	  i=j=0;
	a=0x30;
  be=0x3A;
  //pe=&a;
	for(i=0;i<YLCD;i++) 
			{
				for(j=0;j<XLCD;j++)
				{ 
					 EXTI_BUFF[i][j]=a;
				 a++;	
					if(a==0x7E)	
					 a=0x30;			
				
				}
		//a++;
	    }
}

void EXIT_KEY_Init(void)
{

	NVIC_InitTypeDef   NVIC_InitStructure;														//调用NVIC定义的结构体

   /* Configure PA0 pin as input floating */
	//KEY_Init();
	
  Ex_NVIC_Config(0,0,1); //参数一：I/O口  参数二：BITx:中断线  参数三 ：TRIM:触发模式,1,下升沿;2,上降沿;3，任意电平触发/0,20,3

  NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_Init( & NVIC_InitStructure);


}

void EXITLCD_Show(void)
{
			//LCD_PutString(80,150,EXTI_BUFF,Red,Yellow,1);   //前台显示EXTI_BUFF内容//二维数组转一维数组
		char  BUFF[XLCD+1]={0x39,0};

		int im,jm,jj=0;
		char aa;
		char *pp;
					   pp= &EXTI_BUFF[0][0];
  

								LCD_PutString(80,120,BUFF,Red,Yellow,1);
    for (im=0; im<YLCD; im++)  //15-1
    {		

        for (jm=0; jm<XLCD; jm++)  //40
        {
					
					  aa=pp[jj];
					  BUFF[jm]=aa;
					  jj++;
		  		  if(jj==(XLCD*YLCD))
		   				jj=0;
					
					
        }
						LCD_PutString(EXTI_X,EXTI_Y,BUFF,Red,Yellow,1);  //80+320,150+240-16 
				    if(EXTI_Y<(((YLCD*16)+150)-16))//    if(EXTI_Y<374)
						{ EXTI_Y=EXTI_Y+16; }
						else 
						{	EXTI_Y=150;  }
		}	

  
}
	


//uint32_t it;
void EXTI0_IRQHandler(void)
{    
//char b=0x41;
     //*p++;
					//for(it=0;it<1000;it++);  //延时
	  LCD_PutString(200,80,"EXIT-in",Red,Yellow,1);



      
	  if(EXTI_GetITStatus(EXTI_Line0)!=RESET)  //进入中断后，不等于0      
					   EXTI_BUFF[je][ie]=be; 
										ie++;
	
					 	if(ie==XLCD)
						{ ie=0; je++;		}
					      	if(je==YLCD)
								    je=0;				 								 			
        be++;
				if(be==0x5B)
					 be=0x3A;
				LCD_PutString(200,80,"EXIT---out",Yellow,Blue,1);

	    EXTI_ClearITPendingBit(EXTI_Line0); //清除LINE0上的中断标志位 
}


