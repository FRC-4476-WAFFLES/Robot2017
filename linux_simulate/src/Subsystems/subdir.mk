################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Subsystems/DriveSubsystem.cpp \
../src/Subsystems/GearSubsystem.cpp \
../src/Subsystems/IntakeSubsystem.cpp \
../src/Subsystems/ShooterSubsystem.cpp \
../src/Subsystems/TurretSubsystem.cpp 

OBJS += \
./src/Subsystems/DriveSubsystem.o \
./src/Subsystems/GearSubsystem.o \
./src/Subsystems/IntakeSubsystem.o \
./src/Subsystems/ShooterSubsystem.o \
./src/Subsystems/TurretSubsystem.o 

CPP_DEPS += \
./src/Subsystems/DriveSubsystem.d \
./src/Subsystems/GearSubsystem.d \
./src/Subsystems/IntakeSubsystem.d \
./src/Subsystems/ShooterSubsystem.d \
./src/Subsystems/TurretSubsystem.d 


# Each subdirectory must supply rules for building sources it contributes
src/Subsystems/%.o: ../src/Subsystems/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"/home/ben/workspace/Robot2017/src" -I/home/ben/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


