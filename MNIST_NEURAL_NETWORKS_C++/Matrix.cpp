#include"Matrix.h"
using namespace std;

//  CONSTRUCTORS from Matrix.h are modified here
Matrix::Matrix(unsigned row_size, unsigned col_size, double val) {
    this->row_size = row_size;
    this->col_size = col_size;
    vector<vector<double> > v(row_size, vector<double>(col_size, val));

    this->matrix = v;

    v.clear();// Removes elements, keeps memory
    v.shrink_to_fit();// Frees extra memory after clear()
}

Matrix::Matrix(vector<vector<double>>matrix) {
    this->row_size = matrix.size();
    this->col_size = matrix[0].size();
    this->matrix = matrix;
}

//  OPERATOR OVERLOADING
Matrix answer(1, 1, 1);

// ADDITION
Matrix& Matrix ::operator+(Matrix& A) {   // here 1st Matrix represents return type of the function 
    Matrix ans(row_size, col_size, 0.0);
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            ans(i, j) = this->matrix[i][j] + A(i, j);
        }
    }
    answer = ans;
    return answer;
}

// SUBTRACTION
Matrix& Matrix :: operator-(Matrix& A) {
    Matrix ans(row_size, col_size, 0.0);
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            ans(i, j) = this->matrix[i][j] - A(i, j);
        }
    }
    answer = ans;
    return answer;
}

// MULTIPLICATION
Matrix& Matrix :: operator*(Matrix& A) {
    Matrix ans(this->row_size, A.col_size, 1);

    if (this->col_size != A.row_size) return A;

    else {
        // multiplying and filing elements in matrix
        for (int i = 0; i < this->row_size; i++) {
            for (int j = 0; j < A.col_size; j++) {

                double sum = 0;
                for (int k = 0; k < this->col_size; k++) {
                    sum += this->matrix[i][k] * A(k, j);
                }
                ans(i, j) = sum;
            }
        }
    }

    answer = ans;
    return answer;
}

Matrix& Matrix ::  operator * (double f) {
    Matrix ans(this->GetRows(), this->GetCols(), 1);
    for (int i = 0; i < ans.GetRows(); i++) {
        for (int j = 0; j < ans.GetCols(); j++) {
            ans(i, j) = this->matrix[i][j] * f;
        }
    }
    answer = ans;
    return answer;
}

Matrix& Matrix::Transpose() {
    Matrix ans(this->GetCols(), this->GetRows(), 1);
    for (int i = 0; i < ans.GetRows(); i++) {
        for (int j = 0; j < ans.GetCols(); j++) {
            ans(i, j) = this->matrix[j][i];
        }
    }
    answer = ans;
    return answer;
}

Matrix& Matrix::Product(Matrix& A) {
    Matrix ans(A.GetRows(), A.GetCols(), 0.1);
    for (int i = 0; i < ans.GetRows(); i++) {
        for (int j = 0; j < ans.GetCols(); j++) {
            ans(i, j) = this->matrix[i][j] * A(i, j);
        }
    }
    answer = ans;
    return answer;
}


void Matrix::fillRandomNormal(double mean, double stddev) {
    std::random_device rd;  // Seed generator
    std::mt19937 gen(rd()); // Mersenne Twister engine
    std::normal_distribution<double> dist(mean, stddev);

    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            matrix[i][j] = dist(gen);
        }
    }
}

double& Matrix:: operator()(const unsigned& row, const unsigned& col) {
    return this->matrix[row][col];
}