################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../freertos/croutine.c \
../freertos/event_groups.c \
../freertos/fsl_tickless_lptmr.c \
../freertos/fsl_tickless_systick.c \
../freertos/heap_4.c \
../freertos/list.c \
../freertos/port.c \
../freertos/queue.c \
../freertos/tasks.c \
../freertos/timers.c 

C_DEPS += \
./freertos/croutine.d \
./freertos/event_groups.d \
./freertos/fsl_tickless_lptmr.d \
./freertos/fsl_tickless_systick.d \
./freertos/heap_4.d \
./freertos/list.d \
./freertos/port.d \
./freertos/queue.d \
./freertos/tasks.d \
./freertos/timers.d 

OBJS += \
./freertos/croutine.o \
./freertos/event_groups.o \
./freertos/fsl_tickless_lptmr.o \
./freertos/fsl_tickless_systick.o \
./freertos/heap_4.o \
./freertos/list.o \
./freertos/port.o \
./freertos/queue.o \
./freertos/tasks.o \
./freertos/timers.o 


# Each subdirectory must supply rules for building sources it contributes
freertos/%.o: ../freertos/%.c freertos/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DDEBUG -DFSL_RTOS_FREE_RTOS -DFRDM_KL25Z -DFREEDOM -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DSDK_OS_FREE_RTOS -D__REDLIB__ -I"C:\Users\hector.torre\Documents\MCUXpressoIDE_11.9.0_2144\workspace\FreeRTOS_KL25z_Project\FreeRTOS-on-KL25Z-main-1\CMSIS" -I"C:\Users\hector.torre\Documents\MCUXpressoIDE_11.9.0_2144\workspace\FreeRTOS_KL25z_Project\FreeRTOS-on-KL25Z-main-1\drivers" -I"C:\Users\hector.torre\Documents\MCUXpressoIDE_11.9.0_2144\workspace\FreeRTOS_KL25z_Project\FreeRTOS-on-KL25Z-main-1\freertos" -I"C:\Users\hector.torre\Documents\MCUXpressoIDE_11.9.0_2144\workspace\FreeRTOS_KL25z_Project\FreeRTOS-on-KL25Z-main-1\utilities" -I"C:\Users\hector.torre\Documents\MCUXpressoIDE_11.9.0_2144\workspace\FreeRTOS_KL25z_Project\FreeRTOS-on-KL25Z-main-1\board" -I"C:\Users\hector.torre\Documents\MCUXpressoIDE_11.9.0_2144\workspace\FreeRTOS_KL25z_Project\FreeRTOS-on-KL25Z-main-1\source" -I"C:\Users\hector.torre\Documents\MCUXpressoIDE_11.9.0_2144\workspace\FreeRTOS_KL25z_Project\FreeRTOS-on-KL25Z-main-1" -I"C:\Users\hector.torre\Documents\MCUXpressoIDE_11.9.0_2144\workspace\FreeRTOS_KL25z_Project\FreeRTOS-on-KL25Z-main-1\startup" -O0 -fno-common -g -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-freertos

clean-freertos:
	-$(RM) ./freertos/croutine.d ./freertos/croutine.o ./freertos/event_groups.d ./freertos/event_groups.o ./freertos/fsl_tickless_lptmr.d ./freertos/fsl_tickless_lptmr.o ./freertos/fsl_tickless_systick.d ./freertos/fsl_tickless_systick.o ./freertos/heap_4.d ./freertos/heap_4.o ./freertos/list.d ./freertos/list.o ./freertos/port.d ./freertos/port.o ./freertos/queue.d ./freertos/queue.o ./freertos/tasks.d ./freertos/tasks.o ./freertos/timers.d ./freertos/timers.o

.PHONY: clean-freertos

