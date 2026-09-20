cmake_minimum_required(VERSION 3.16)

project(UtilitiesProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(utilities utilities.cpp)