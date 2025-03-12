#pragma once
#include "Matrix.h"
#include "Layer.h"
#include<string>

Matrix ReLU(Matrix& matrix);

Matrix ReLU_Derivative(Matrix& matrix);

Matrix Softmax(Matrix& matrix);

void Forward(Layer& current_Layer, Layer& previous_Layer, std::string activation_Function);

void Print(Matrix&);