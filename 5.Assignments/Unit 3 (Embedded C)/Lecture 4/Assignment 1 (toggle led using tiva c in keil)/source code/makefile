#make file for lab 1

CC=arm-none-eabi-
CFLAG=-mcpu=cortex-m4 -gdwarf-2 -g
INCS= -I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
SRCA=$(wildcard *.s)
OBJA=$(SRCA:.s=.o)
projectName=tiva_c

all: $(projectName).bin
	@echo "==============================built successfully==============================="
	
#%.o: %.s 
#	$(CC)as.exe $(CFLAG) $< -o $@	

%.o: %.c 
	$(CC)gcc.exe $(CFLAG) $(INCS) -c $< -o $@

$(projectName).elf: $(OBJ) 
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) -o $@ -Map=mapfile.map
	cp $@ $(projectName).axf
	
$(projectName).bin: $(projectName).elf
	$(CC)objcopy.exe -O binary $< $@

$(project_name).hex: $(project_name).elf  
	$(CC)objcopy.exe -O  binary $< $@
	
cleanall: 
	rm -rf *.o *.elf *.bin *.map
	@echo "====================================CLEAN===================================="

clean:
	rm -rf *.elf *.bin *.map
