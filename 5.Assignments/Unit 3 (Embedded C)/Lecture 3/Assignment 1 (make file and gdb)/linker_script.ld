ENTRY(reset)

MEMORY
{
	Mem (rwx) : ORIGIN = 0x00000000, LENGTH = 64M
}

SECTIONS{

	. = 0x10000;           /*ENTRY POINT*/
	.startup_section . :		
	{
		startup.o(.text)
	} >Mem                 /*VMA @> VLA*/
	.text_section :
	{
		*(.text)
	} >Mem
	.data_section :
	{
		*(.data)
	} >Mem
	.bss_section :
	{
		*(.bss)
	} >Mem 
	
	. = . + 0x1000;        /*4kb of stack*/
	stack_pointer = .;     /*GO TO MAIN WITH STACK POINTER = .*/
}