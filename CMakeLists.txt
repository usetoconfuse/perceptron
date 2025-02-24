cmake_minimum_required(VERSION 3.30)
project(perceptron C)

set(CMAKE_C_STANDARD 11)

add_executable(perceptron perceptron.c)
add_executable(adaline adaline.c)
