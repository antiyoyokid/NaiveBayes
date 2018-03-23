//
// Created by aishi on 3/22/2018.
//

#include <cmath>
#include <algorithm>
#include "Classifier.h"
#include "DataReader.cpp"


/**
 * Function takes the data and puts it into a 2D array
 * This 2D array has 5000 slots and each slot inside has another array with a size of 784
 *
 * @param file name
 * @return vector<vector<int>>
 */

void probabilityCalculator(int probabilityMatrix[10][784]) {
    std::vector<std::vector<int>> Images = ImageReader("testimages.txt"); //reads the images that need to be classified
    double posteriorProbabilityPixel = 0; //
    double posteriorProbabilityClass[Images.size()][10];
    for (int i = 0; i < Images.size(); i++) {   //goes into each image
        for (int p = 0; p < 10; p++) { //class
            posteriorProbabilityPixel += log(calculateProbabilityOfClass(p));
            for (int j = 0; j < Images.at(0).size(); j++) {  //pixel
                if (Images.at(i).at(j) == 1) {
                    posteriorProbabilityPixel += log(probabilityMatrix[p][j]);
                } else if (Images.at(i).at(j) == 0) {
                    posteriorProbabilityPixel += log(1 - probabilityMatrix[p][j]);
                }
            }
            posteriorProbabilityClass[i][p] = posteriorProbabilityPixel; //probability for each of the 10 classes
            posteriorProbabilityPixel = 0; //reset the sum;
        }

    }
    findMaxProb(posteriorProbabilityClass, Images.size());
}

std::vector<int> findMaxProb(double probClass[][10], int numberOfImages) {

    for (int i = 0; i < numberOfImages; i++) {
        double max = *std::max_element(probClass[i], probClass[i] + 10);
        for (int j = 0; j < 10; j++) {
            if (max == probClass[i][j]) {
                classifiedImages.push_back(j);
            }
        }
    }
}



void confusionMatrix() {
    std::vector<int> trueNumberValue = numberReader("Images.txt");
    for(int i =0; i < )




}



