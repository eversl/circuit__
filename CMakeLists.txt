cmake_minimum_required(VERSION 3.9)
project(circuit__)

set(CMAKE_CXX_STANDARD 17)

add_executable(run run.cc program.cc module.cc module.hh)
add_executable(print print.cc vec.cc program.cc module.cc module.hh)
target_compile_definitions(print PRIVATE GEN)