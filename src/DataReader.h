//
// Created by aishi on 3/14/2018.
//

#ifndef NAIVEBAYES_ANTIYOYOKID_DATAREADER_H
#define NAIVEBAYES_ANTIYOYOKID_DATAREADER_H

#include <vector>

#include<iostream>
#include<fstream>
#include<string>
#include <limits>
#include <vector>
const int NUM_CLASS = 10;
const int NUM_PIXELS = 784;
std::vector<std::vector<int>> ImageReader(std::string file);
std::vector<int> labelReader(std::string file);
#endif //NAIVEBAYES_ANTIYOYOKID_DATAREADER_H
