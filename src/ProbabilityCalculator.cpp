//
// Created by aishi on 3/20/2018.
//

#include "ProbabilityCalculator.h"
#include "DataReader.cpp"

/**
 *First I would want to look at the label and then calculate the probability.So there would be 10
 * from 0-9. But then there's another problem. An image can either be 0 or 1. Then how does that part even work. Like do I add the two?
 * To do this I need -the total number of images with a specific label
 *
 * @return
 */
std::vector<std::vector<int>> pixelData = ImageReader("testimages");
std::vector<int> label = labelReader("traininglabels");

double foregroundCount(int, int);

int totalImagesInClass(int);


// this should technically return a vector right?
std::vector<int> probabilityForeground() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 784; j++) {
            double numberOfRepitions = foregroundCount(i, j);
            int totalRepitionsInClass = totalImagesInClass(i);
            int k = 3;
            double probabilityForBlackPixel =
                    (k + numberOfRepitions) / (2k + totalRepitionsInClass); //probability for finding black pixel
            double probabilityForWhitePixel = 1 - probabilityForBlackPixel;
        }
    }

}

double probabilityOfEachClass() {


    }


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


/**
 *
 * @param numberClass
 * @param pixelNumber
 * @return the number of times a single pixel appears when given a number class.
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


double backgroundCount(int numberClass) {
    int count = 0;
    for (int i = 0; i < label.size(); i++) {
        for (int j = 0; j <= 784; j++) {
            if (label.at(i) == numberClass) {
                if (pixelData.at(i).at(j) == 0) {
                    count++;
                }
            }
        }
    }
    return count;
}