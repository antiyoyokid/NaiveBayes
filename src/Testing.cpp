//
// Created by aishi on 3/27/2018.
//

#include "Main.cpp"
#include "catch.hpp"

#define CATCH_CONFIG_MAIN
//Testing numberReader
TEST_CASE("Check if the reader reads the first element properly") {
    REQUIRE(numberReader("traininglabels.txt").at(0) == 5);
}

TEST_CASE("Check if the reader reads the whole file") {
    REQUIRE(numberReader("traininglabels.txt").size() == 5000);
}


// difficult to actually count the number
TEST_CASE("the number 10 doesn't exist"){
    REQUIRE(foregroundCount(10,100) == 0);
}






