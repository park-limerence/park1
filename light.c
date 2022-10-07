#define GPIOB_BASE 0x40010C00BSRR��
//�˿�λ����/ ����Ĵ���(GPIOx_BSRR)���üĴ�����ʵ�Ǽ�ӿ���ODR�Ĵ���
#define GPIOC_BASE 0x40011000
#define GPIOA_BASE 0x40010800

#define RCC_APB2ENR (*(unsigned int *)0x40021018)

#define GPIOA_CRL	*((unsigned volatile int*)0x40010800)
#define	GPIOA_ORD	*((unsigned volatile int*)0x4001080C)

#define GPIOB_CRH	*((unsigned volatile int*)0x40010C04)
#define	GPIOB_ORD	*((unsigned volatile int*)0x40010C0C)

#define GPIOC_CRH	*((unsigned volatile int*)0x40011004)
#define	GPIOC_ORD	*((unsigned volatile int*)0x4001100C)

	
void SystemInit(void);
void Delay_ms(volatile  unsigned  int);
//ʱ�Ӻ���
void Delay_ms( volatile  unsigned  int  t)
{
     unsigned  int  i;
     while(t--)
         for (i=0;i<800;i++);
}


int main(){
	//GPIO�˿�ʱ��ʹ��
	RCC_APB2ENR |= (1<<3); 
	RCC_APB2ENR |= (1<<4); 
	RCC_APB2ENR |= (1<<2); 
	
	GPIOA_CRL&=0xFFFFFFF0;
	GPIOA_CRL|=0x00000002;	//PA5�������	
	GPIOA_ORD|=1<<0;	//���õƳ�ʼΪ��	
	
	GPIOB_CRH&=0xFFFFFF0F;		
	GPIOB_CRH|=0x00000020;		//PB9
	GPIOB_ORD|=1<<9;		//���ó�ʼ��Ϊ��	
	
	GPIOC_CRH&=0xF0FFFFFF;	
	GPIOC_CRH|=0x03000000;   	//PC14
	GPIOC_ORD|=0x1<<14;	//���ó�ʼ��Ϊ��		
	while(1)
	{	
		GPIOA_ORD=0x0<<0;		//PA5�͵�ƽ
		Delay_ms(5000000);
		GPIOA_ORD=0x1<<0;		//PA5�ߵ�ƽ
		Delay_ms(5000000);
		
		GPIOB_ORD=0x0<<9;		//PB9�͵�ƽ
		Delay_ms(5000000);
		GPIOB_ORD=0x1<<9;		//PB9�ߵ�ƽ
		Delay_ms(5000000);
		
		GPIOC_ORD=0x0<<14;		//PC14�͵�ƽ
		Delay_ms(5000000);
		GPIOC_ORD=0x1<<14;		//PC14�ߵ�ƽ
		Delay_ms(5000000);
	}

}