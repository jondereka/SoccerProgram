cmake_minimum_required(VERSION 3.28)
project(SoccerProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(SoccerProject main.cpp
        PlayerList.cpp
        PlayerList.h
        SoccerProgram.cpp
        SoccerProgram.h
        PlayerEntry.cpp
        PlayerEntry.h)
