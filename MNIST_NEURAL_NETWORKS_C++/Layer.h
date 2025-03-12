#pragma once
#include "matrix.h"
class Layer {
private:
	Matrix weights;
	Matrix outputs;
	Matrix biased;
public:
	//constructors
	Layer();
	Layer(int);

	//methods
	Layer& nextLayer(int);

	Matrix& getOutputs();
	Matrix& getBiased();
	Matrix& getWeights();
};