################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../src/vision/ntcore/CMakeFiles/feature_tests.cxx 

C_SRCS += \
../src/vision/ntcore/CMakeFiles/feature_tests.c 

CXX_DEPS += \
./src/vision/ntcore/CMakeFiles/feature_tests.d 

OBJS += \
./src/vision/ntcore/CMakeFiles/feature_tests.o 

C_DEPS += \
./src/vision/ntcore/CMakeFiles/feature_tests.d 


# Each subdirectory must supply rules for building sources it contributes
src/vision/ntcore/CMakeFiles/%.o: ../src/vision/ntcore/CMakeFiles/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/vision/ntcore/CMakeFiles/%.o: ../src/vision/ntcore/CMakeFiles/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"/home/ben/workspace/Robot2017/src" -I/home/ben/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


