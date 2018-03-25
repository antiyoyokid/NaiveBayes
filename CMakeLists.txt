cmake_minimum_required(VERSION 3.5)
project(naivebayes)

set(CMAKE_CXX_STANDARD 14)

add_executable(naivebayes src/DataReader.cpp src/Classifier.cpp src/Classifier.h/Model.cpp/ src/Main.cpp src/Main.h)
#add_executable(unit-tests)

