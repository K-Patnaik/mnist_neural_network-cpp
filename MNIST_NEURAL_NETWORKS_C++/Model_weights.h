#pragma once
# include "Neural_Network.h"
# include <iostream>
# include <fstream>

using namespace std;

void SaveWeights(Neural_Network& nn, const string& filename);
void LoadWeights(Neural_Network& nn, const string& filename);
