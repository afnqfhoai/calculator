cmake_minimum_required(VERSION 3.29)
project(calculator C)

set(CMAKE_C_STANDARD 23)

add_executable(calculator
        main.c
        calculate.c
        preCalculate.c
        screenPrinting.c


        calculator.h

)
