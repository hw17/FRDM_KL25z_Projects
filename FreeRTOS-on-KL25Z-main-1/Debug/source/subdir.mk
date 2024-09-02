################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/MMA8451Q.c \
../source/blinkenlights_utils.c \
../source/freertos_hello.c \
../source/i2c.c \
../source/led.c \
../source/mtb.c \
../source/semihost_hardfault.c 

C_DEPS += \
./source/MMA8451Q.d \
./source/blinkenlights_utils.d \
./source/freertos_hello.d \
./source/i2c.d \
./source/led.d \
./source/mtb.d \
./source/semihost_hardfault.d 

OBJS += \
./source/MMA8451Q.o \
./source/blinkenlights_utils.o \
./source/freertos_hello.o \
./source/i2c.o \
./source/led.o \
./source/mtb.o \
./source/semihost_hardfault.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DDEBUG -DFSL_RTOS_FREE_RTOS -DFRDM_KL25Z -DFREEDOM -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DSDK_OS_FREE_RTOS -D__REDLIB__ -I"C:\Users\hector.torre\Documents\MCUXpressoIDE_11.9.0_2144\workspace\FreeRTOS_KL25z_Project\FreeRTOS-on-KL25Z-main-1\CMSIS" -I"C:\Users\hector.torre\Documents\MCUXpressoIDE_11.9.0_2144\workspace\FreeRTOS_KL25z_Project\FreeRTOS-on-KL25Z-main-1\drivers" -I"C:\Users\hector.torre\Documents\MCUXpressoIDE_11.9.0_2144\workspace\FreeRTOS_KL25z_Project\FreeRTOS-on-KL25Z-main-1\freertos" -I"C:\Users\hector.torre\Documents\MCUXpressoIDE_11.9.0_2144\workspace\FreeRTOS_KL25z_Project\FreeRTOS-on-KL25Z-main-1\utilities" -I"C:\Users\hector.torre\Documents\MCUXpressoIDE_11.9.0_2144\workspace\FreeRTOS_KL25z_Project\FreeRTOS-on-KL25Z-main-1\board" -I"C:\Users\hector.torre\Documents\MCUXpressoIDE_11.9.0_2144\workspace\FreeRTOS_KL25z_Project\FreeRTOS-on-KL25Z-main-1\source" -I"C:\Users\hector.torre\Documents\MCUXpressoIDE_11.9.0_2144\workspace\FreeRTOS_KL25z_Project\FreeRTOS-on-KL25Z-main-1" -I"C:\Users\hector.torre\Documents\MCUXpressoIDE_11.9.0_2144\workspace\FreeRTOS_KL25z_Project\FreeRTOS-on-KL25Z-main-1\startup" -O0 -fno-common -g -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/MMA8451Q.d ./source/MMA8451Q.o ./source/blinkenlights_utils.d ./source/blinkenlights_utils.o ./source/freertos_hello.d ./source/freertos_hello.o ./source/i2c.d ./source/i2c.o ./source/led.d ./source/led.o ./source/mtb.d ./source/mtb.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o

.PHONY: clean-source

