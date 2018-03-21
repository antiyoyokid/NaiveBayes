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

double probabilityForeground() {


}

double probabilityBackground(){
    
}

double totalImagesInClass(int numberClass) {
    int count = 0;
    for (int i = 0; i < label.size(); i++) {
        if (numberClass == label.at(i)) {
            count++;
        }
    }
    return count;
}

double foregroundCount(int numberClass) {
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

double backgroundCount(int numberClass) {
    int count = 0;
    for (int i = 0; i < label.size(); i++) {
        for (int j = 0; j <= 784; j++) {
            if (label.at(i) == numberClass) {
                if (pixelData.at(i).at(j) == 1) {
                    count++;
                }
            }
        }
    }
    return count;
}