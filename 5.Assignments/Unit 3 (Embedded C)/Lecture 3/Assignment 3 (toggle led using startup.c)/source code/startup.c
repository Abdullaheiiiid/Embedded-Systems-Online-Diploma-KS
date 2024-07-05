
extern void main();
extern unsigned int Etext;
extern unsigned int Sdata;
extern unsigned int Edata;
extern unsigned int Sbss;
extern unsigned int Ebss;
extern unsigned int Stack_Pointer;
void Reset_Handler();
void Default_Handler();
void NMI_Handler() __attribute__ ((weak,alias("Default_Handler")));;
void Hard_Fault_Handler() __attribute__ ((weak,alias("Default_Handler")));;
void MM_Fault_Handler() __attribute__ ((weak,alias("Default_Handler")));;
void Bus_Fault_Handler() __attribute__ ((weak,alias("Default_Handler")));;
void Usage_Fault_Handler() __attribute__ ((weak,alias("Default_Handler")));;



unsigned int vectors[] __attribute__((section(".vectors"))) = {
    (unsigned int) &Stack_Pointer,
    (unsigned int) &Reset_Handler,
    (unsigned int) &NMI_Handler,
    (unsigned int) &Hard_Fault_Handler,
    (unsigned int) &MM_Fault_Handler,
    (unsigned int) &Bus_Fault_Handler,
    (unsigned int) &Usage_Fault_Handler
};

void Reset_Handler(){
    unsigned int datasize = (unsigned char*) &Edata - (unsigned char*) &Sdata;
    unsigned char* datasrc = (unsigned char*) &Etext;
    unsigned char* datadest = (unsigned char*) &Sdata;
    for(int i = 0 ; i < datasize ; i++){
        *((unsigned char*)datadest++) = *((unsigned char*)datasrc++);
    }

    unsigned int bsssize = (unsigned char*) &Ebss - (unsigned char*) &Sbss;
    unsigned char* bssdest = (unsigned char*) &Sbss;
    for(int i = 0 ; i < bsssize ; i++){
        *((unsigned char*)bssdest++) = (unsigned char) 0;
    }

    main();
}

void Default_Handler(){
    Reset_Handler();
}

