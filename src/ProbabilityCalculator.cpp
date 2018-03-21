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
double ProbabilityCalculator(){
    std::vector <std::vector<int>> pixelData = ImageReader("testimages");
    std::vector<int> label =  labelReader("traininglabels");
    for(int i = 1; i <= 5000; i++){
        for(int j = 1; j<=784; j++){

        }
    }

}