/*******************************************************************************
*  标题:                  试验数码管上如何显示数字(共阳极)                     *
*																			   *
*  连接方法：P0 与JP3 用8PIN排线连接	                                       *
********************************************************************************
*                         	       										       *
* 请学员认真消化本例程，用单片机脚直接控制数码管                               *
********************************************************************************/


#include <reg51.h> 
#include <intrins.h>
#define  NOP() _nop_()  /* 定义空指令 */


void delay(unsigned int i);      //函数声名

 
// 此表为 LED 的字模          
unsigned char code LED7Code[] = {~0x3F,~0x06,~0x5B,~0x4F,~0x66,~0x6D,~0x7D,~0x07,~0x7F,~0x6F,~0x77,~0x7C,~0x39,~0x5E,~0x79,~0x71};

 
main()
{  
   unsigned int LedNumVal=1 ,C ;  //定义变量
   
  while(1)
  {	 
	   if (++C>= 300) 
	  	{ LedNumVal++ ;	 //每隔300个扫描周期加一次
		  C =0;	         //每隔300个扫描清零
		 }	
	   // 将字模送到P0口显示	 
		P0 = LED7Code[LedNumVal%10]&0x7f;     //LED7 0x7f为小数点 共阴和共阳此处也是不一样;
	  	
  	  		 
		delay(150);	  //调用延时程序
	 
  }   
}
	
/*****************************************************************
*																 *
*             延时程序											 *
*																 *
*****************************************************************/
void delay(unsigned int i)
{
    char j;
    for(i; i > 0; i--)
        for(j = 200; j > 0; j--);
}

