/*  startup for arm-cortex-m4
	credits: Abdullah Eid
	date: 05 / 07 / 2024
*/


MEMORY
{
flash(RX) : ORIGIN = 0x00000000, LENGTH = 512M
sram(RWX) : ORIGIN = 0x20000000, LENGTH = 512M
}

SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text*)
		*(.rodata)
		Etext = .;
	}> flash
	.data : 
	{
		Sdata = .;
		*(.data*)
		. = ALIGN(4);
		Edata = .;
	}> sram AT> flash 
	.bss : 
	{
		Sbss = .;
		*(.bss*)
		Ebss = .;
	}> sram
}

