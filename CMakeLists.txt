cmake_minimum_required(VERSION 3.17)
project(WOW)

set(CMAKE_CXX_STANDARD 11)

add_executable(WOW main.cpp src/Base.cpp include/Base.h src/Soldier.cpp include/Soldier.h src/Weapon.cpp include/Weapon.h src/City.cpp include/City.h test.cpp test.h)