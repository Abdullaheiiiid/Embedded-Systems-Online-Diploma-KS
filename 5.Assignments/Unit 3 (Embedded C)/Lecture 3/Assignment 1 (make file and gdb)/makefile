#make file for lab 1

CC=arm-none-eabi-
CFLAG=-mcpu=arm926ej-s -g
INCS= -I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
SRCA=$(wildcard *.s)
OBJA=$(SRCA:.s=.o)
projectName=application

all: $(projectName).bin
	@echo "==========built successfully=========="
	
%.o: %.s 
	$(CC)as.exe $(CFLAG) $< -o $@
	
%.o: %.c 
	$(CC)gcc.exe $(CFLAG) $(INCS) -c $< -o $@

$(projectName).elf: $(OBJ) $(OBJA)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(OBJA) -o $@ -Map=mapfile.map
	
$(projectName).bin: $(projectName).elf
	$(CC)objcopy.exe -O binary $< $@
	
cleanall: 
	-rm *.o *.elf *.bin *.map

clean:
	-rm *.elf *.bin *.map
