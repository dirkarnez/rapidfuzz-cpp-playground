cmake_minimum_required(VERSION 3.14)

project(rapidfuzz-cpp-playground)

# Required: INTERFACE_COMPILE_FEATURES "cxx_std_17"
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(rapidfuzz EXACT 1.10.1 REQUIRED) 
if (rapidfuzz_FOUND)
    message("rapidfuzz found")
else (rapidfuzz_FOUND)
    message("rapidfuzz not found")
endif()

SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

add_executable(${PROJECT_NAME}
    "src/main.cpp"
)

target_link_libraries(${PROJECT_NAME} rapidfuzz::rapidfuzz)