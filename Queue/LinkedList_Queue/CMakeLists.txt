cmake_minimum_required(VERSION 3.28)
project(LinkedList_Queue C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(LinkedList_Queue
        LS_Queue.c
        LS_Queue.h
        main.c)
