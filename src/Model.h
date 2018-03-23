//
// Created by aishi on 3/20/2018.
//

#ifndef NAIVEBAYES_PROBABILITYCALCULATOR_H
#define NAIVEBAYES_PROBABILITYCALCULATOR_H

#include <iostream>
#include "DataReader.cpp"
#include <fstream>
#include <unistd.h>
#include <string>


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
std::vector<std::vector<double> > probabilityVector;

double** setupHMM(std::vector<std::vector<double> > &vals, int N, int M);
double foregroundCount(int, int);
int countImagesInClass(int);

#endif //NAIVEBAYES_PROBABILITYCALCULATOR_H
