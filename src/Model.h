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

std::vector<std::vector<int>> pixelData = ImageReader("testimages.txt");
std::vector<int> label = labelReader("traininglabels.txt");

double probabilityMatrix[NUM_CLASS][NUM_PIXELS];
std::vector<std::vector<double> > probabilityVector;
/*
 * functions
 *
 */

void * createModel();
double **setupHMM(std::vector<std::vector<double> > &vals, int N, int M);
double foregroundCount(int, int);
int countImagesInClass(int numberClass, std::vector<int> numbersList);

#endif //NAIVEBAYES_PROBABILITYCALCULATOR_H
