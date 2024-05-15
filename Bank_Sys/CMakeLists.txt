cmake_minimum_required(VERSION 3.28)
project(Bank_Sys C)

set(CMAKE_C_STANDARD 11)

add_executable(Bank_Sys main.c
        LinkedList.h
        LinkedList.c
        AdminMode.c
        AdminMode.h
        ClientMode.c
        ClientMode.h
        Data.h
        Data.c)
