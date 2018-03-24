//
// Created by aishi on 3/22/2018.
//


#include "Classifier.h"


/**
 * Function takes the data and puts it into a 2D array
 * This 2D array has 5000 slots and each slot inside has another array with a size of 784
 *
 * @param file name
 * @return vector<vector<int>>
 */

void probabilityCalculator(int probabilityMatrix[NUM_CLASS][NUM_PIXELS]) {
    std::vector<std::vector<int>> Images = ImageReader("testimages.txt"); //reads the images that need to be classified
    double posteriorProbabilityPixel = 0; //
    double posteriorProbabilityClass[Images.size()][10];
    for (int i = 0; i < Images.size(); i++) {   //goes into each image
        for (int p = 0; p < NUM_CLASS; p++) { //class
            posteriorProbabilityPixel += log(calculateProbabilityOfClass(p));
            for (int j = 0; j < Images.at(0).size(); j++) {  //pixel
                if (Images.at(i).at(j) == 1) {
                    posteriorProbabilityPixel += log(probabilityMatrix[p][j]);
                } else if (Images.at(i).at(j) == 0) {
                    posteriorProbabilityPixel += log(1 - probabilityMatrix[p][j]);
                }
            }
            posteriorProbabilityClass[i][p] = posteriorProbabilityPixel; //probability for each of the 10 classes
            posteriorProbabilityPixel = 0; //reset the sum;
        }

    }
    findMaxProb(posteriorProbabilityClass, Images.size());
}

/**
 *
 * @param probClass Getting the probability of the image being one of the 10 classes
 * @param numberOfImages
 * @return finding which class the number is by finding the class with the highest probability in the picture
 */
std::vector<int> findMaxProb(double probClass[][NUM_CLASS], int numberOfImages) {

    for (int i = 0; i < numberOfImages; i++) {
        double max = *std::max_element(probClass[i], probClass[i] + 10);
        for (int j = 0; j < NUM_CLASS; j++) {
            if (max == probClass[i][j]) {
                classifiedImages.push_back(j);
            }
        }
    }
    return classifiedImages;
}

/**
 * Getting feedback on the overall model and seeing the percentage the model got correct
 * @return percentage model got correct
 */
double evaluationFeedback() {
    int count = 0;
    std::vector<int> trueNumberValue = numberReader("Images.txt");
    std::vector<int> classifiedNumberValue = classifiedImages;
    int totalImages = trueNumberValue.size();
    for (int i = 0; i < totalImages; i++) {
        if (trueNumberValue.at(i) == classifiedNumberValue.at(i)) {
            count++;
        }
        double correctness = (count / totalImages) * 100;
        return correctness;
    }
}

/**
 * Creates a 2D array with the confusion matrix, but so far I haven't divded the count by the number of times the number appears.
 */
void confusionMatrix() {
    std::vector<int> trueNumberValue = numberReader("Images.txt");
    std::vector<int> classifiedNumberValue = classifiedImages;
    double confusionMatrix[NUM_CLASS][NUM_CLASS];
    std::fill(confusionMatrix[NUM_CLASS], confusionMatrix[NUM_CLASS], 0); // fills all the values of the array with 0.
    for (int i = 0; i < trueNumberValue.size(); i++) {
        for (int j = 0; j < trueNumberValue.size(); j++) {
            if (trueNumberValue.at(i) == classifiedNumberValue.at(j) && i == j) {
                confusionMatrix[i][j]++;
                if (trueNumberValue.at(i) != classifiedNumberValue.at(j)) {
                    confusionMatrix[i][j]++;
                }
            }
        }

    }
}

double confusionMatrixDivider(double matrix[NUM_CLASS][NUM_CLASS], std::vector<int> values){

    std::vector<int> trueNumberValue = numberReader("Images.txt");
    for (int i =0; i < NUM_CLASS; i++){
        int numberOfClass = countImagesInClass(i, trueNumberValue);
        for(int j =0; j < NUM_CLASS; j++){
            matrix[i][j] = matrix[i][j] / numberOfClass ;
            numberOfClass = 0;
        }

    }
    return matrix;

}




