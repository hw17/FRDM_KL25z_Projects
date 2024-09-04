################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/MKL25Z4_Project.c \
../source/MMA8451Q.c \
../source/i2c.c \
../source/mtb.c \
../source/semihost_hardfault.c 

C_DEPS += \
./source/MKL25Z4_Project.d \
./source/MMA8451Q.d \
./source/i2c.d \
./source/mtb.d \
./source/semihost_hardfault.d 

OBJS += \
./source/MKL25Z4_Project.o \
./source/MMA8451Q.o \
./source/i2c.o \
./source/mtb.o \
./source/semihost_hardfault.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL25Z128VLK4_cm0plus -DCPU_MKL25Z128VLK4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DPRINTF_FLOAT_ENABLE=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\hector.torre\Documents\MCUXpressoIDE_11.9.0_2144\workspace\MKL25Z4_Project\board" -I"C:\Users\hector.torre\Documents\MCUXpressoIDE_11.9.0_2144\workspace\MKL25Z4_Project\source" -I"C:\Users\hector.torre\Documents\MCUXpressoIDE_11.9.0_2144\workspace\MKL25Z4_Project" -I"C:\Users\hector.torre\Documents\MCUXpressoIDE_11.9.0_2144\workspace\MKL25Z4_Project\drivers" -I"C:\Users\hector.torre\Documents\MCUXpressoIDE_11.9.0_2144\workspace\MKL25Z4_Project\startup" -I"C:\Users\hector.torre\Documents\MCUXpressoIDE_11.9.0_2144\workspace\MKL25Z4_Project\utilities" -I"C:\Users\hector.torre\Documents\MCUXpressoIDE_11.9.0_2144\workspace\MKL25Z4_Project\CMSIS" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/MKL25Z4_Project.d ./source/MKL25Z4_Project.o ./source/MMA8451Q.d ./source/MMA8451Q.o ./source/i2c.d ./source/i2c.o ./source/mtb.d ./source/mtb.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o

.PHONY: clean-source

