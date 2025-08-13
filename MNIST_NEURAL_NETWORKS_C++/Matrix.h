#ifndef __EE_242_Project_2__matrix__
#define __EE_242_Project_2__matrix__

#include <stdio.h>
#include <fstream> // for file access
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <cmath>
#include<random>

using std::vector;
using std::tuple;

class Matrix {
private:
    unsigned row_size;
    unsigned col_size;
    vector<vector<double>> matrix;
public:
    // Constructors; 

    Matrix() {}
    Matrix(unsigned, unsigned, double);
    Matrix(vector<vector<double>>);
    // Matrix(const char *);
    // Matrix(const Matrix&);
     //~Matrix();

    // setters and getters
    int GetRows() {
        return this->row_size;
    }
    int GetCols() {
        return this->col_size;
    }

    // Operations
    Matrix& operator + (Matrix&);
    Matrix& operator - (Matrix&);
    Matrix& operator * (Matrix&);
    Matrix& operator * (double);

    Matrix& Transpose();

    Matrix& Product(Matrix&);

    double getMax() {
        double max = INT_MIN;
        for (int i = 0; i < row_size; i++) {
            for (int j = 0; j < col_size; j++) {
                if (this->matrix[i][j] > max) max= this->matrix[i][j];
            }
        }
        return max;
    }


    void fillRandomNormal(double mean, double stddev);

    double& operator () (const unsigned&, const unsigned&);


};


    
#endif