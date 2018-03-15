//
// Created by aishi on 3/14/2018.
//

#include "DataReader.h"
#include<iostream>
#include<fstream>
#include<string>
#include <limits>

vector <vector<int>> DataReader::images(std::string file) {
    std::ifstream imageData;
    imageData.open(file);

    vector <vector<int>> images;
    char current;
    vector<int> image;

    while (imageData.get(current)) {
        if (current == '\n') {
            continue;
        }
        if (current == ' ') {
            image.push_back(0);
        }
        if (current == '#') {
            image.push_back(1);
        }
        if (current == '+') {
            image.push_back(2);
        }

        if (image.size() == 784) {
            images.push_back(image);
            image.clear;
        }
    }
    return images;

}

vector<int> DataReader::label(std::string file) {
    std::ifstream labels;
    labels.open(file);
    char current;
    vector<int> label;

    while (imageData.get(current)) {
        if (current != '\n') {
            int num = (int) current;
            label.push_back(num);
        }

    }
}









