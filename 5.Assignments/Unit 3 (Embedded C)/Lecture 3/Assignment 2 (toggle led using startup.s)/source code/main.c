typedef volatile unsigned int vuint32_t;
#define RCC_BASE     0x40021000
#define PORTA        0x40010800
#define APB2ENR      *((vuint32_t*)(RCC_BASE + 0x18))
#define CRH          *((vuint32_t*)(PORTA + 0x04))
#define ODR          *((vuint32_t*)(PORTA + 0x0C))
#define IOPAEN2      2
#define GPIOA13      13
int data = 10;
int const rodata = 10;
int bss;
void main()
{
	APB2ENR |= (1<<IOPAEN2);
	CRH &= 0xFF0FFFFF;
	CRH |= 0x00200000;
    /* Loop forever */
	while(1){
		ODR |= (1<<GPIOA13);
		for(int i = 0 ; i<50000 ; i++);
		ODR &= ~(1<<GPIOA13);
		for(int i = 0 ; i<50000 ; i++);
	}

}
