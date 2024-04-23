.PHONY: build clean flash

INC_DIR :=./../Include
SRC_DIR :=./../Sources

INC_FILES := $(foreach INC_DIR,$(INC_DIR),$(wildcard $(INC_DIR)/*h))
SRC_PATH := $(wildcard $(SRC_DIR)/*.c)
SRC_FILES := $(notdir $(SRC_PATH))
OBJ_FILES := $(subst .c,.o,$(SRC_FILES))
OBJ_PATH := $(foreach OBJ_FILES, $(OBJ_FILES), ./../Object/$(OBJ_FILES))

vpath %.c $(SRC_DIR)

%.o: %.c 
	arm-none-eabi-gcc -c $< -mcpu=cortex-m3 -mthumb -std=gnu11 -mfloat-abi=soft -Wall -o ./../Object/$@ -I./../Include 

build:$(OBJ_FILES)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft --specs=nano.specs -T STM32F103_LinkerScript.ld $(OBJ_PATH) -Wl,-Map=./../Output/final.map -o ./../Output/final.elf 
	arm-none-eabi-objcopy -O ihex  ./../Output/final.elf ./../Output/final.hex 
	arm-none-eabi-objcopy -O binary ./../Output/final.elf ./../Output/final.bin
	arm-none-eabi-objdump.exe -D ./../Output/final.elf > ./../Output/finalmap
	
flash:
	openocd -f board/stm32f103c8_blue_pill.cfg

log-%:
	@echo $($(subst log-,,$@))

clean: 
	rm ./../Object/*
	rm ./../Output/*
