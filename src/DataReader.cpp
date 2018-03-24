//
// Created by aishi on 3/14/2018.
//

#include "DataReader.h"

/**
 * Function takes the data and puts it into a 2D array
 * This 2D array has 5000 slots and each slot inside has another array with a size of 784
 *
 * @param file name
 * @return vector<vector<int>> which are the images
 */


 std::vector<std::vector<int>> ImageReader(std::string file) {
    std::ifstream imageData;
    imageData.open(file); //opens the file and reads the data

    /*
     * Declaring some names
     */
    std::vector<std::vector<int>> images;
    char current;
    std::vector<int> pixelData;

    //converting the entire image into 1s and 0s to make it easy to process
    while (imageData.get(current)) {
        if (current == '\n') {
            continue;
        }
        if (current == ' ') {
            pixelData.push_back(0);
        }
        if (current == '#') {
            pixelData.push_back(1);
        }
        if (current == '+') {
            pixelData.push_back(1);
        }

        if (pixelData.size() == NUM_PIXELS) {
            images.push_back(pixelData);
            pixelData.clear();
        }
    }
    return images;
}

/**
 *
 * @param file - the file to read the label from
 * @return a vector of the labels
 */
std::vector<int> numberReader(std::string file) {
    std::ifstream labels;
    labels.open(file);
    char current;
    std::vector<int> label;

    while (labels.get(current)) {
        if (current != '\n') {
            int num = (int) current;
            label.push_back(num);
        }
    }
    return label;
}









