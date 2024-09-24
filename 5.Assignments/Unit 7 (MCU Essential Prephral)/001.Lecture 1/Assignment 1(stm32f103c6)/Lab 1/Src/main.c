
#define RCC_BASE    0x40021000
#define RCC_APB2ENR    *((volatile unsigned int*) (RCC_BASE + 0x18))
#define IOPA    2
#define IOPB    3




#define GPIOA_BASE    0x40010800
#define GPIOA_CRL    *((volatile unsigned int*) (GPIOA_BASE + 0x00))
#define GPIOA_CRH    *((volatile unsigned int*) (GPIOA_BASE + 0x04))
#define GPIOA_IDR    *((volatile unsigned int*) (GPIOA_BASE + 0x08))
#define GPIOA_ODR    *((volatile unsigned int*) (GPIOA_BASE + 0x0C))



#define GPIOB_BASE    0x40010C00
#define GPIOB_CRL    *((volatile unsigned int*) (GPIOB_BASE + 0x00))
#define GPIOB_CRH    *((volatile unsigned int*) (GPIOB_BASE + 0x04))
#define GPIOB_IDR    *((volatile unsigned int*) (GPIOB_BASE + 0x08))
#define GPIOB_ODR    *((volatile unsigned int*) (GPIOB_BASE + 0x0C))



void CLOCK_SETUP(){
	RCC_APB2ENR |= (1<<IOPA) | (1<<IOPB);
}

void GPIOx_INIT(){

	GPIOB_CRL &= ~((1<<6)|(1<<7));
	GPIOB_CRL &= ~(1<<5);
	GPIOB_CRL |= (1<<4);
	GPIOB_CRH &= ~((1<<22)|(1<<23));
	GPIOB_CRH &= ~(1<<21);
	GPIOB_CRH |= (1<<20);

	GPIOA_CRL &= ~((1<<5)|(1<<4));
	GPIOA_CRL &= ~(1<<7);
	GPIOA_CRL |= (1<<6);
	GPIOA_CRH &= ~((1<<21)|(1<<20));
	GPIOA_CRH &= ~(1<<23);
	GPIOA_CRH |= (1<<22);
}

void DELAY(int period){
	for(int i = 0 ; i < period ; i++)
		for(int j = 0 ; j < 1000 ; j++);
}
int main(void)
{

	CLOCK_SETUP();
	GPIOx_INIT();

	/* Loop forever */
	while(1){
		if(!((GPIOA_IDR & (1<<1)) & (1<<1))){
			GPIOB_ODR ^= (1<<1);
			while(!((GPIOA_IDR & (1<<1)) & (1<<1)));
		}


		if(((GPIOA_IDR & (1<<13)) & (1<<13))){
			GPIOB_ODR ^= (1<<13);
		}
		DELAY(1);
	}
	return 0;
}
