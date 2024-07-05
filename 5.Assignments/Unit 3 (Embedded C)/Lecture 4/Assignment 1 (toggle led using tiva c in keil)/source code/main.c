typedef volatile unsigned int vuint32_t;
#define SYSCTL_BASE              0x400FE000
#define GPIOF_BASE               0x40025000
#define SYSCTL_RCGC2_R           *((vuint32_t*)(SYSCTL_BASE + 0x108))
#define GPIO_PORTF_DATA_R        *((vuint32_t*)(GPIOF_BASE + 0x3FC))
#define GPIO_PORTF_DIR_R         *((vuint32_t*)(GPIOF_BASE + 0x400))
#define GPIO_PORTF_DEN_R         *((vuint32_t*)(GPIOF_BASE + 0x51C))
#define PIN3                     3
int data = 10;
int const rodata = 10;
int bss;
void main()
{
	volatile unsigned int delay;
	SYSCTL_RCGC2_R = 0x00000020;
	for(delay = 0 ; delay<200 ; delay++);
	GPIO_PORTF_DIR_R |= 1<<PIN3;
	GPIO_PORTF_DEN_R |= 1<<PIN3;
	
    /* Loop forever */
	while(1){
		GPIO_PORTF_DATA_R ^= (1<<PIN3);
		for(delay = 0 ; delay<50000 ; delay++);
		GPIO_PORTF_DATA_R &= ~(1<<PIN3);
		for(delay = 0 ; delay<50000 ; delay++);
	}
}
