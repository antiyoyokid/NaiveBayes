//
// Created by aishi on 3/20/2018.
//
#include <unistd.h>
#include "ProbabilityCalculator.h"

/**
 * @return returns an array with the probability of finding a black pixel
 */
void probabilityForeground() {
    for (int i = 0; i < 10; i++) {  //loops through the numberClasses
        for (int j = 0; j < 784; j++) {  // loops through the pixels

            double numberOfRepetition = foregroundCount(i, j); //# colored pixels at a pixel of each image in same class
            int totalRepetionsInClass = countImagesInClass(i); //# of times a class repeats itself in testingimages
            int k = 3; //Laplace number
            double probabilityForBlackPixel =
                    (k + numberOfRepetition) /
                    (2 * k + totalRepetionsInClass); //probability for finding black pixel at a certain spot
            probabilityMatrix[i][j] = probabilityForBlackPixel; //structure is [class][pixelNumber] = probability
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

/**
 *
 * @param numberClass
 * @return number of times an image appears relative to the entire size of testLabel.
 */
double calculateProbabilityOfClass(int numberClass) {
    double probabilityofClass = countImagesInClass(numberClass) / label.size();
    return probabilityofClass;
}

/**
 *
 * @param numberClass
 * @return the number of times a numberClass appears in the testingLabel file
 */
int countImagesInClass(int numberClass) {
    int count = 0;
    for (int i = 0; i < label.size(); i++) {
        if (numberClass == label.at(i)) {
            count++;
        }
    }
    return count;
}

/**
 * prints out the matrix to a text file
 * @param matrix - this is the probabilityMatrix
 *
 */
void saveToFile(int matrix[10][784]) {

    std::ofstream myfile;
    myfile.open("model.txt");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 784; j++) {
            myfile << matrix[i][j];
        }
    }
    myfile.close();
    system("pause");
}


