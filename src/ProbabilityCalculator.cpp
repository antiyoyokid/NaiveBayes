//
// Created by aishi on 3/20/2018.
//
#include <unistd.h>

#include <string>
#include "ProbabilityCalculator.h"

/**
 * @return returns an array with the probability of finding a black pixel
 */
void probabilityForeground() {
    for (int i = 0; i < 10; i++) {  //loops through the numberClasses
        for (int j = 0; j < 784; j++) {  // loops through the pixels

            double numberOfRepetition = foregroundCount(i, j); //# colored pixels at a pixel of each image in same class
            int totalRepetionsInClass = countImagesInClass(i); //# of times a class repeats itself in testingimages
            int k = 3; //Laplace number
            double probabilityForBlackPixel =
                    (k + numberOfRepetition) /
                    (2 * k + totalRepetionsInClass); //probability for finding black pixel at a certain spot
            probabilityMatrix[i][j] = probabilityForBlackPixel; //structure is [class][pixelNumber] = probability
        }
    }
}

/**
 * @param numberClass
 * @param pixelNumber
 * @return the number of times a single pixel appears black when given a number class.
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

/**
 *
 * @param numberClass
 * @return number of times an image appears relative to the entire size of testLabel.
 */
double calculateProbabilityOfClass(int numberClass) {
    double probabilityofClass = countImagesInClass(numberClass) / label.size();
    return probabilityofClass;
}

/**
 *
 * @param numberClass
 * @return the number of times a numberClass appears in the testingLabel file
 */
int countImagesInClass(int numberClass) {
    int count = 0;
    for (int i = 0; i < label.size(); i++) {
        if (numberClass == label.at(i)) {
            count++;
        }
    }
    return count;
}

/**
 * prints out the matrix to a text file
 * @param matrix - this is the probabilityMatrix
 *
 */
void saveToFile(int matrix[10][784]) {

    std::ofstream myfile;
    myfile.open("model.txt"); // creates a new file called Model.txt
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 784; j++) {
            myfile << matrix[i][j] + "/n";
        }
    }
    myfile.close();
    system("pause");
}

double** readFromFile(std::string file) {
    const int COLUMNS = 10; //gets the first 10 digits of the double

    std::string filename = "model.txt";

    std::ifstream ifile(filename.c_str());

    if (ifile.is_open()) {
        int num;

        std::vector<double> numbers_in_line;

        while (ifile >> num) {
            numbers_in_line.push_back(num);

            if (numbers_in_line.size() == COLUMNS) {
                probabilityVector.push_back(numbers_in_line);
                numbers_in_line.clear();
            }
        }

       return setupHMM(probabilityVector,10,784);
    } else {
        std::cerr << "There was an error opening the input file!\n";
        exit(1);
    }

}

double** setupHMM(std::vector<std::vector<double> > &vals, int N, int M)
{
    double** temp;
    temp = new double*[N];
    for(unsigned i=0; (i < N); i++)
    {
        temp[i] = new double[M];
        for(unsigned j=0; (j < M); j++)
        {
            temp[i][j] = vals[i][j];
        }
    }
}






