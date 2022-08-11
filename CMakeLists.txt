cmake_minimum_required(VERSION 3.21)
project(ForthInterpreter)

set(CMAKE_CXX_STANDARD 17)

add_executable(ForthInterpreter main.cpp Instruction.h PrimitiveInstructions.h InputHandler.h)
