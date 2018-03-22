//
// Created by aishi on 3/20/2018.
//

#include "ProbabilityCalculator.h"
#include "DataReader.cpp"
#include <iostream>
#include <

/**
 *First I would want to look at the label and then calculate the probability.So there would be 10
 * from 0-9. But then there's another problem. An image can either be 0 or 1. Then how does that part even work. Like do I add the two?
 * To do this I need -the total number of images with a specific label
 *
 * @return
 */
std::vector<std::vector<int>> pixelData = ImageReader("testimages");
std::vector<int> label = labelReader("traininglabels");
double probabilityMatrix[10][784];

double foregroundCount(int, int);

int totalImagesInClass(int);


/**
 *
 * @return the vector with everytihng in it
 */
std::vector<int> probabilityForeground() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 784; j++) {

            double numberOfRepitions = foregroundCount(i, j);
            int totalRepitionsInClass = totalImagesInClass(i);
            int k = 3;
            double probabilityForBlackPixel =
                    (k + numberOfRepitions) / (2k + totalRepitionsInClass); //probability for finding black pixel at a certain spot
            probabilityMatrix[i][j] = probabilityForBlackPixel;
        }
    }
}

/**
 * @param numberClass
 * @param pixelNumber
 * @return the number of times a single pixel appears black when given a number class.
 */
double foregroundCount(int numberClass, int pixelNumber) {
    int count = 0;
    for (int i = 0; i < label.size(); i++) {
        {
            if (label.at(i) == numberClass) {
                if (pixelData.at(i).at(pixelNumber) ==
                    1) {
                    count++;
                }
            }
        }

    }
    return count;
}

double probabilityOfEachClass(int numberClass) {
    double probabilityofClass = totalImagesInClass(numberClass) / label.size();
    return probabilityofClass;
}


int totalImagesInClass(int numberClass) {
    int count = 0;
    for (int i = 0; i < label.size(); i++) {
        if (numberClass == label.at(i)) {
            count++;
        }
    }
    return count;
}




void saveToFile(int[10][784]){


}

int main(){


}
