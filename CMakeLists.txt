cmake_minimum_required(VERSION 3.5)
project(naivebayes)

set(CMAKE_CXX_STANDARD 14)

add_executable(naivebayes src/DataReader.cpp src/Classifier.cpp src/Classifier.h/ProbabilityCalculator.cpp/)
#add_executable(unit-tests)

