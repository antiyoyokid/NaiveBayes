//
// Created by aishi on 3/24/2018.
//

#include "Main.h"


/*
 * Main method that calls functions from other classes
 */

int main() {
    std::string input;
    std::cout << " Would you like to create a model? Press Y to create model or N to load or any key to exit";
    std::cin >> input;
    if (input == "Y") {
        calculateProbabilityOfClass(createModel());
    } else if (input == "N") {
        calculateProbabilityOfClass(readModel("model.txt"));

    } else {
        exit(1);
    }


}