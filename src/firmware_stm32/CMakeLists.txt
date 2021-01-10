cmake_minimum_required(VERSION 3.15)

project(firmware_stm32 LANGUAGES C CXX ASM)

find_bsp(ID com.sysprogs.project_importers.stm32.cubemx
	SOURCE_PROJECT firmware_stm32.ioc)

add_bsp_based_executable(NAME firmware_stm32
	GENERATE_BIN
	GENERATE_MAP
	SOURCES ${BSP_ROOT}/Src/Led.cpp ${BSP_ROOT}/Src/main.cpp ${BSP_ROOT}/Src/UpdatableOnTimer.cpp)
