################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commands/Shooter/ShooterDefault.cpp \
../src/Commands/Shooter/ShooterPrep.cpp \
../src/Commands/Shooter/ShooterShoot.cpp 

OBJS += \
./src/Commands/Shooter/ShooterDefault.o \
./src/Commands/Shooter/ShooterPrep.o \
./src/Commands/Shooter/ShooterShoot.o 

CPP_DEPS += \
./src/Commands/Shooter/ShooterDefault.d \
./src/Commands/Shooter/ShooterPrep.d \
./src/Commands/Shooter/ShooterShoot.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commands/Shooter/%.o: ../src/Commands/Shooter/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"/home/ben/workspace/Robot2017/src" -I/home/ben/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


