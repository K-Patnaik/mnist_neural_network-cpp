#pragma once
#include "Algorithms.h"
class Neural_Network {
private:
	vector<Layer> NN_Layers;
	double Learning_Rate = 0.05;
public:
	void insert(Layer& l1);

	void BackPropagation(Matrix);

	Matrix& ForwardAlgo(Matrix& input);



	Layer& operator() (int i);

};