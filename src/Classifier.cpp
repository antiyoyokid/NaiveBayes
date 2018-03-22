//
// Created by aishi on 3/22/2018.
//

#include "Classifier.h"
#include "DataReader.h"
#include "ProbabilityCalculator.cpp"
#include<iostream>
#include<fstream>
#include<string>
#include <limits>
#include <vector>
#include <map>


/**
 * Function takes the data and puts it into a 2D array
 * This 2D array has 5000 slots and each slot inside has another array with a size of 784
 *
 * @param file name
 * @return vector<vector<int>>
 */



double probabilityCalculator(){
    std::vector<std::vector<int>> Images = ImageReader("FilePath");
    std::map<int,double> posteriorProbability;
    for(int i; i < Images.size(); i++){   //goes into each image
        for(int j; j < Images.at(0).size(); j++){
            if(Images.at(i).at(j) == 1){

            }
        }



    }
}

