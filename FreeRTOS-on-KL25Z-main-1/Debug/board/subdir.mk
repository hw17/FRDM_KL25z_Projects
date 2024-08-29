################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../board/board.c \
../board/clock_config.c \
../board/pin_mux.c 

C_DEPS += \
./board/board.d \
./board/clock_config.d \
./board/pin_mux.d 

OBJS += \
./board/board.o \
./board/clock_config.o \
./board/pin_mux.o 


# Each subdirectory must supply rules for building sources it contributes
board/%.o: ../board/%.c board/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DDEBUG -DFSL_RTOS_FREE_RTOS -DFRDM_KL25Z -DFREEDOM -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -I"/Users/hectorguarneros/Documents/MCUXpressoIDE_11.9.0_2144/workspace/FreeRTOS_KL25z_Project/FreeRTOS-on-KL25Z-main-1/board" -I"/Users/hectorguarneros/Documents/MCUXpressoIDE_11.9.0_2144/workspace/FreeRTOS_KL25z_Project/FreeRTOS-on-KL25Z-main-1/source" -I"/Users/hectorguarneros/Documents/MCUXpressoIDE_11.9.0_2144/workspace/FreeRTOS_KL25z_Project/FreeRTOS-on-KL25Z-main-1" -I"/Users/hectorguarneros/Documents/MCUXpressoIDE_11.9.0_2144/workspace/FreeRTOS_KL25z_Project/FreeRTOS-on-KL25Z-main-1/CMSIS" -I"/Users/hectorguarneros/Documents/MCUXpressoIDE_11.9.0_2144/workspace/FreeRTOS_KL25z_Project/FreeRTOS-on-KL25Z-main-1/drivers" -I"/Users/hectorguarneros/Documents/MCUXpressoIDE_11.9.0_2144/workspace/FreeRTOS_KL25z_Project/FreeRTOS-on-KL25Z-main-1/utilities" -I"/Users/hectorguarneros/Documents/MCUXpressoIDE_11.9.0_2144/workspace/FreeRTOS_KL25z_Project/FreeRTOS-on-KL25Z-main-1/freertos" -I"/Users/hectorguarneros/Documents/MCUXpressoIDE_11.9.0_2144/workspace/FreeRTOS_KL25z_Project/FreeRTOS-on-KL25Z-main-1/startup" -O0 -fno-common -g -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-board

clean-board:
	-$(RM) ./board/board.d ./board/board.o ./board/clock_config.d ./board/clock_config.o ./board/pin_mux.d ./board/pin_mux.o

.PHONY: clean-board

