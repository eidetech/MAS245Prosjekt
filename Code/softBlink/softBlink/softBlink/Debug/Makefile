################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../src/ \
../src/ASF/ \
../src/ASF/common/ \
../src/ASF/common/boards/ \
../src/ASF/common/boards/user_board/ \
../src/ASF/common/services/ \
../src/ASF/common/services/calendar/ \
../src/ASF/common/services/clock/ \
../src/ASF/common/services/clock/mega/ \
../src/ASF/common/services/delay/ \
../src/ASF/common/services/delay/mega/ \
../src/ASF/common/services/gpio/ \
../src/ASF/common/services/gpio/mega_gpio/ \
../src/ASF/common/services/ioport/ \
../src/ASF/common/services/ioport/mega/ \
../src/ASF/common/utils/ \
../src/ASF/common/utils/interrupt/ \
../src/ASF/common/utils/make/ \
../src/ASF/common/utils/stdio/ \
../src/ASF/common/utils/unit_test/ \
../src/ASF/mega/ \
../src/ASF/mega/drivers/ \
../src/ASF/mega/drivers/adc/ \
../src/ASF/mega/drivers/cpu/ \
../src/ASF/mega/drivers/usart/ \
../src/ASF/mega/utils/ \
../src/ASF/mega/utils/assembler/ \
../src/ASF/mega/utils/preprocessor/ \
../src/config/


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../main.cpp \
../src/ASF/common/boards/user_board/init.c \
../src/ASF/common/services/calendar/calendar.c \
../src/ASF/common/services/clock/mega/sysclk.c \
../src/ASF/common/utils/stdio/read.c \
../src/ASF/common/utils/stdio/write.c \
../src/ASF/common/utils/unit_test/suite.c \
../src/ASF/mega/drivers/usart/usart_mega.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
main.o \
src/ASF/common/boards/user_board/init.o \
src/ASF/common/services/calendar/calendar.o \
src/ASF/common/services/clock/mega/sysclk.o \
src/ASF/common/utils/stdio/read.o \
src/ASF/common/utils/stdio/write.o \
src/ASF/common/utils/unit_test/suite.o \
src/ASF/mega/drivers/usart/usart_mega.o

OBJS_AS_ARGS +=  \
main.o \
src/ASF/common/boards/user_board/init.o \
src/ASF/common/services/calendar/calendar.o \
src/ASF/common/services/clock/mega/sysclk.o \
src/ASF/common/utils/stdio/read.o \
src/ASF/common/utils/stdio/write.o \
src/ASF/common/utils/unit_test/suite.o \
src/ASF/mega/drivers/usart/usart_mega.o

C_DEPS +=  \
main.d \
src/ASF/common/boards/user_board/init.d \
src/ASF/common/services/calendar/calendar.d \
src/ASF/common/services/clock/mega/sysclk.d \
src/ASF/common/utils/stdio/read.d \
src/ASF/common/utils/stdio/write.d \
src/ASF/common/utils/unit_test/suite.d \
src/ASF/mega/drivers/usart/usart_mega.d

C_DEPS_AS_ARGS +=  \
main.d \
src/ASF/common/boards/user_board/init.d \
src/ASF/common/services/calendar/calendar.d \
src/ASF/common/services/clock/mega/sysclk.d \
src/ASF/common/utils/stdio/read.d \
src/ASF/common/utils/stdio/write.d \
src/ASF/common/utils/unit_test/suite.d \
src/ASF/mega/drivers/usart/usart_mega.d

OUTPUT_FILE_PATH +=softBlink.elf

OUTPUT_FILE_PATH_AS_ARGS +=softBlink.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
./main.o: .././main.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)A:\Software\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG -DBOARD=USER_BOARD -DTEST_SUITE_DEFINE_ASSERT_MACRO -D_ASSERT_ENABLE_  -I"A:\Software\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\include" -I"../src/ASF/common/boards/user_board" -I"../src/ASF/common/boards" -I"../src/ASF/mega/utils/preprocessor" -I"../src/ASF/mega/utils" -I"../src/ASF/common/utils" -I"../src" -I"../src/config" -I"../src/ASF/common/services/calendar" -I"../src/ASF/mega/drivers/cpu" -I"../src/ASF/common/services/clock" -I"../src/ASF/common/services/delay" -I"../src/ASF/common/services/gpio" -I"../src/ASF/common/services/ioport" -I"../src/ASF/mega/drivers/adc" -I"../src/ASF/mega/drivers/usart"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega168 -B "A:\Software\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega168" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/common/boards/user_board/init.o: ../src/ASF/common/boards/user_board/init.c
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)A:\Software\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -DDEBUG -DBOARD=USER_BOARD -DTEST_SUITE_DEFINE_ASSERT_MACRO -D_ASSERT_ENABLE_  -I"A:\Software\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\include" -I"../src/ASF/common/boards/user_board" -I"../src/ASF/common/boards" -I"../src/ASF/mega/utils/preprocessor" -I"../src/ASF/mega/utils" -I"../src/ASF/common/utils" -I"../src" -I"../src/config" -I"../src/ASF/common/services/calendar" -I"../src/ASF/mega/drivers/cpu" -I"../src/ASF/common/services/clock" -I"../src/ASF/common/services/delay" -I"../src/ASF/common/services/gpio" -I"../src/ASF/common/services/ioport" -I"../src/ASF/mega/drivers/adc" -I"../src/ASF/mega/drivers/usart"  -O1 -fdata-sections -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g3 -Wall -mmcu=atmega168 -B "A:\Software\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega168" -c -std=gnu99 -fno-strict-aliasing -Wstrict-prototypes -Wmissing-prototypes -Werror-implicit-function-declaration -Wpointer-arith -mrelax -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/common/services/calendar/calendar.o: ../src/ASF/common/services/calendar/calendar.c
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)A:\Software\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -DDEBUG -DBOARD=USER_BOARD -DTEST_SUITE_DEFINE_ASSERT_MACRO -D_ASSERT_ENABLE_  -I"A:\Software\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\include" -I"../src/ASF/common/boards/user_board" -I"../src/ASF/common/boards" -I"../src/ASF/mega/utils/preprocessor" -I"../src/ASF/mega/utils" -I"../src/ASF/common/utils" -I"../src" -I"../src/config" -I"../src/ASF/common/services/calendar" -I"../src/ASF/mega/drivers/cpu" -I"../src/ASF/common/services/clock" -I"../src/ASF/common/services/delay" -I"../src/ASF/common/services/gpio" -I"../src/ASF/common/services/ioport" -I"../src/ASF/mega/drivers/adc" -I"../src/ASF/mega/drivers/usart"  -O1 -fdata-sections -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g3 -Wall -mmcu=atmega168 -B "A:\Software\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega168" -c -std=gnu99 -fno-strict-aliasing -Wstrict-prototypes -Wmissing-prototypes -Werror-implicit-function-declaration -Wpointer-arith -mrelax -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/common/services/clock/mega/sysclk.o: ../src/ASF/common/services/clock/mega/sysclk.c
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)A:\Software\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -DDEBUG -DBOARD=USER_BOARD -DTEST_SUITE_DEFINE_ASSERT_MACRO -D_ASSERT_ENABLE_  -I"A:\Software\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\include" -I"../src/ASF/common/boards/user_board" -I"../src/ASF/common/boards" -I"../src/ASF/mega/utils/preprocessor" -I"../src/ASF/mega/utils" -I"../src/ASF/common/utils" -I"../src" -I"../src/config" -I"../src/ASF/common/services/calendar" -I"../src/ASF/mega/drivers/cpu" -I"../src/ASF/common/services/clock" -I"../src/ASF/common/services/delay" -I"../src/ASF/common/services/gpio" -I"../src/ASF/common/services/ioport" -I"../src/ASF/mega/drivers/adc" -I"../src/ASF/mega/drivers/usart"  -O1 -fdata-sections -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g3 -Wall -mmcu=atmega168 -B "A:\Software\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega168" -c -std=gnu99 -fno-strict-aliasing -Wstrict-prototypes -Wmissing-prototypes -Werror-implicit-function-declaration -Wpointer-arith -mrelax -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/common/utils/stdio/read.o: ../src/ASF/common/utils/stdio/read.c
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)A:\Software\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -DDEBUG -DBOARD=USER_BOARD -DTEST_SUITE_DEFINE_ASSERT_MACRO -D_ASSERT_ENABLE_  -I"A:\Software\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\include" -I"../src/ASF/common/boards/user_board" -I"../src/ASF/common/boards" -I"../src/ASF/mega/utils/preprocessor" -I"../src/ASF/mega/utils" -I"../src/ASF/common/utils" -I"../src" -I"../src/config" -I"../src/ASF/common/services/calendar" -I"../src/ASF/mega/drivers/cpu" -I"../src/ASF/common/services/clock" -I"../src/ASF/common/services/delay" -I"../src/ASF/common/services/gpio" -I"../src/ASF/common/services/ioport" -I"../src/ASF/mega/drivers/adc" -I"../src/ASF/mega/drivers/usart"  -O1 -fdata-sections -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g3 -Wall -mmcu=atmega168 -B "A:\Software\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega168" -c -std=gnu99 -fno-strict-aliasing -Wstrict-prototypes -Wmissing-prototypes -Werror-implicit-function-declaration -Wpointer-arith -mrelax -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/common/utils/stdio/write.o: ../src/ASF/common/utils/stdio/write.c
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)A:\Software\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -DDEBUG -DBOARD=USER_BOARD -DTEST_SUITE_DEFINE_ASSERT_MACRO -D_ASSERT_ENABLE_  -I"A:\Software\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\include" -I"../src/ASF/common/boards/user_board" -I"../src/ASF/common/boards" -I"../src/ASF/mega/utils/preprocessor" -I"../src/ASF/mega/utils" -I"../src/ASF/common/utils" -I"../src" -I"../src/config" -I"../src/ASF/common/services/calendar" -I"../src/ASF/mega/drivers/cpu" -I"../src/ASF/common/services/clock" -I"../src/ASF/common/services/delay" -I"../src/ASF/common/services/gpio" -I"../src/ASF/common/services/ioport" -I"../src/ASF/mega/drivers/adc" -I"../src/ASF/mega/drivers/usart"  -O1 -fdata-sections -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g3 -Wall -mmcu=atmega168 -B "A:\Software\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega168" -c -std=gnu99 -fno-strict-aliasing -Wstrict-prototypes -Wmissing-prototypes -Werror-implicit-function-declaration -Wpointer-arith -mrelax -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/common/utils/unit_test/suite.o: ../src/ASF/common/utils/unit_test/suite.c
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)A:\Software\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -DDEBUG -DBOARD=USER_BOARD -DTEST_SUITE_DEFINE_ASSERT_MACRO -D_ASSERT_ENABLE_  -I"A:\Software\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\include" -I"../src/ASF/common/boards/user_board" -I"../src/ASF/common/boards" -I"../src/ASF/mega/utils/preprocessor" -I"../src/ASF/mega/utils" -I"../src/ASF/common/utils" -I"../src" -I"../src/config" -I"../src/ASF/common/services/calendar" -I"../src/ASF/mega/drivers/cpu" -I"../src/ASF/common/services/clock" -I"../src/ASF/common/services/delay" -I"../src/ASF/common/services/gpio" -I"../src/ASF/common/services/ioport" -I"../src/ASF/mega/drivers/adc" -I"../src/ASF/mega/drivers/usart"  -O1 -fdata-sections -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g3 -Wall -mmcu=atmega168 -B "A:\Software\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega168" -c -std=gnu99 -fno-strict-aliasing -Wstrict-prototypes -Wmissing-prototypes -Werror-implicit-function-declaration -Wpointer-arith -mrelax -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/mega/drivers/usart/usart_mega.o: ../src/ASF/mega/drivers/usart/usart_mega.c
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)A:\Software\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -DDEBUG -DBOARD=USER_BOARD -DTEST_SUITE_DEFINE_ASSERT_MACRO -D_ASSERT_ENABLE_  -I"A:\Software\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\include" -I"../src/ASF/common/boards/user_board" -I"../src/ASF/common/boards" -I"../src/ASF/mega/utils/preprocessor" -I"../src/ASF/mega/utils" -I"../src/ASF/common/utils" -I"../src" -I"../src/config" -I"../src/ASF/common/services/calendar" -I"../src/ASF/mega/drivers/cpu" -I"../src/ASF/common/services/clock" -I"../src/ASF/common/services/delay" -I"../src/ASF/common/services/gpio" -I"../src/ASF/common/services/ioport" -I"../src/ASF/mega/drivers/adc" -I"../src/ASF/mega/drivers/usart"  -O1 -fdata-sections -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g3 -Wall -mmcu=atmega168 -B "A:\Software\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega168" -c -std=gnu99 -fno-strict-aliasing -Wstrict-prototypes -Wmissing-prototypes -Werror-implicit-function-declaration -Wpointer-arith -mrelax -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	




# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR8/GNU Linker : 5.4.0
	$(QUOTE)A:\Software\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="softBlink.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega168 -B "A:\Software\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega168"  
	@echo Finished building target: $@
	"A:\Software\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "softBlink.elf" "softBlink.hex"
	"A:\Software\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "softBlink.elf" "softBlink.eep" || exit 0
	"A:\Software\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "softBlink.elf" > "softBlink.lss"
	"A:\Software\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "softBlink.elf" "softBlink.srec"
	"A:\Software\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "softBlink.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "softBlink.elf" "softBlink.a" "softBlink.hex" "softBlink.lss" "softBlink.eep" "softBlink.map" "softBlink.srec" "softBlink.usersignatures"
	