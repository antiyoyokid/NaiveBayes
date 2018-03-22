//
// Created by aishi on 3/22/2018.
//

#include "Classifier.h"
#include "DataReader.h"
#include "ProbabilityCalculator.cpp"
#include<iostream>
#include<fstream>
#include<string>
#include <limits>
#include <vector>
#include <map>


/**
 * Function takes the data and puts it into a 2D array
 * This 2D array has 5000 slots and each slot inside has another array with a size of 784
 *
 * @param file name
 * @return vector<vector<int>>
 */



double probabilityCalculator() {
    std::vector<std::vector<int>> Images = ImageReader("FilePath");
    double posteriorProbabilityPixel = 0;
    double posteriorProbabilityClass[Images.size()][10];
    for (int i = 0; i < Images.size(); i++) {   //goes into each image
        for (int p = 0; p < 10; p++) { //class
            for (int j = 0; j < Images.at(0).size(); j++) {  //pixel
                if (Images.at(i).at(j) == 1) {
                    posteriorProbabilityPixel += probabilityMatrix[p][j];
                } else if (Images.at(i).at(j) == 0) {
                    posteriorProbabilityPixel += 1 - probabilityMatrix[p][j];
                }

            }
            posteriorProbabilityClass[i][p] = posteriorProbabilityPixel;
            posteriorProbabilityPixel = 0;
        }

    }
}

