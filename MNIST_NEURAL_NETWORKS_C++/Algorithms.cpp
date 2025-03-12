#include "Algorithms.h"
#include<math.h>
#include<algorithm>
#include<iostream>

Matrix ReLU(Matrix& matrix) {
	Matrix ans(matrix.GetRows(), matrix.GetCols(), 0);
	for (int i = 0; i < ans.GetRows(); i++) {
		for (int j = 0; j < ans.GetCols(); j++) {
			if (matrix(i, j) > DBL_EPSILON ) ans(i, j) = matrix(i, j);
			else ans(i, j) = 0.01* matrix(i, j);
		}
	}
	return ans;
}


Matrix ReLU_Derivative(Matrix& matrix) {
	Matrix ans(matrix.GetRows(), matrix.GetCols(), 0);
	for (int i = 0; i < ans.GetRows(); i++) {
		for (int j = 0; j < ans.GetCols(); j++) {
			if (matrix(i, j) > 0) ans(i, j) = 1;
			else ans(i, j) = 0.01;
		}
	}
	return ans;
}



Matrix Softmax(Matrix& matrix) {
	Matrix ans(matrix.GetRows(), matrix.GetCols(), 0);
	
	double max = matrix.getMax();

	// subtracting every element with max to maintain stability and compute the exponential;
	for (int i = 0; i < ans.GetRows(); i++) {
		for (int j = 0; j < ans.GetCols(); j++) {
			double x = matrix(i, j) - max;
			ans(i, j) = exp(x);
		}
	}

	// calculating total sum
	double sum = 0;
	for (int i = 0; i < ans.GetRows(); i++) for (int j = 0; j < ans.GetCols(); j++) sum += ans(i, j);

	// softmaxing
	for (int i = 0; i < ans.GetRows(); i++) {
		for (int j = 0; j < ans.GetCols(); j++) {
			ans(i, j) /= sum;
		}
	}

	return ans;
}




void Forward(Layer& current_Layer, Layer& previous_Layer, std::string activation_Function) {

	Matrix Z = previous_Layer.getOutputs() * previous_Layer.getWeights() + current_Layer.getBiased();
	
	if (activation_Function == "ReLU") {
		current_Layer.getOutputs() = ReLU(Z);
	}

	if (activation_Function == "SoftMax") {
		current_Layer.getOutputs() = Softmax(Z);
	}

	
}

void Print(Matrix& matrix) {

	for (int i = 0; i < matrix.GetRows(); i++) {
		for (int j = 0; j < matrix.GetCols(); j++) std::cout << matrix(i, j) << "   ";
		std::cout << std::endl;
	}

}