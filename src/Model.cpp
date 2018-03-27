//
// Created by aishi on 3/20/2018.
//

#include <tuple>
#include <map>
#include "Model.h"

/**
 * This is also the part that creates my model
 * @return returns an array with the probability of finding a black pixel
 *
 */
void *createModel() {
    for (int i = 0; i < NUM_CLASS; i++) {  //loops through the numberClasses
        for (int j = 0; j < NUM_PIXELS; j++) {  // loops through the pixels

            double numberOfRepetition = foregroundCount(i, j); //# colored pixels at a pixel of each image in same class
            int totalRepetitionsInClass = countImagesInClass(i,
                                                             label); //# of times a class repeats itself in testingimages
            int k = 1; //Laplace number
            double probabilityForBlackPixel =
                    (k + numberOfRepetition) /
                    (2 * k + totalRepetitionsInClass); //probability for finding black pixel at a certain spot
            probabilityMatrix[i][j] = probabilityForBlackPixel; //structure is [class][pixelNumber] = probability
        }

    }

    return probabilityMatrix;
}






/**
 * prints out the matrix to a text file
 * @param matrix - this is the probabilityMatrix
 *
 */
void saveModel(int matrix[NUM_CLASS][NUM_PIXELS]) {

    std::ofstream modelFile;
    modelFile.open("model.txt"); // creates a new file called Model.txt
    for (int i = 0; i < NUM_CLASS; i++) {
        for (int j = 0; j < NUM_PIXELS; j++) {
            modelFile << matrix[i][j] + "/n";
        }
    }
    modelFile.close();
    system("pause");
}

/**
 * https://stackoverflow.com/questions/21708078/reading-in-a-data-file-and-assigning-each-column-to-individual-arrays
 * @param file
 * @return file
 */
double **readModel(std::string file) {
    const int COLUMNS = NUM_CLASS; //gets the first 10 digits of the double
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
        return setupHMM(probabilityVector, 10, 784);
    } else {
        std::cerr << "There was an error opening the input file!\n";
        exit(1);
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
    double probabilityofClass = countImagesInClass(numberClass, label) / label.size();
    return probabilityofClass;
}

/**
 *
 * @param numberClass
 * @return the number of times a numberClass appears in the testingLabel file
 */
int countImagesInClass(int numberClass, std::vector<int> numbersList) {
    int count = 0;
    for (int i = 0; i < numbersList.size(); i++) {
        if (numberClass == numbersList.at(i)) {
            count++;
        }
    }
    return count;
}


/**
 * https://stackoverflow.com/questions/15295677/converting-2d-vector-to-2d-array
 * converts from vector to array
 * @param vals the 2d vector
 * @param N  the size of the array
 * @param M the size of the array
 * @return returns an double 2D array
 */
double **setupHMM(std::vector<std::vector<double> > &vals, int N, int M) {
    double **temp;
    temp = new double *[N];
    for (unsigned i = 0; (i < N); i++) {
        temp[i] = new double[M];
        for (unsigned j = 0; (j < M); j++) {
            temp[i][j] = vals[i][j];
        }
    }
}






