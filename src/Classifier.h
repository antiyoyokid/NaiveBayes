//
// Created by aishi on 3/22/2018.
//

#ifndef NAIVEBAYES_CLASSIFIER_H
#define NAIVEBAYES_CLASSIFIER_H
#include "DataReader.h"
#include "Model.cpp"
#include<iostream>
#include<fstream>
#include<string>
#include <limits>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include "DataReader.cpp"
std::vector<int> classifiedImages;
std::vector<int> findMaxProb(double probClass[][10], int numberOfImages);
double** confusionMatrixDivider(double matrix[NUM_CLASS][NUM_CLASS], std::vector<int> values);


#endif //NAIVEBAYES_CLASSIFIER_H
