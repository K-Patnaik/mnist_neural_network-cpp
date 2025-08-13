#include "Model_weights.h"

void SaveWeights(Neural_Network& nn, const string& filename) {
	ofstream file(filename);
	if (!file.is_open()) {
		cerr << "Error opening file for saving weights." << endl;
		return;
	}
	for (int i = 0; i < nn.NN_Layers.size(); i++) {
		Layer& layer = nn.NN_Layers[i];
		file << "Layer " << i << endl;
		file << "Weights:" << endl;
		for (int j = 0; j < layer.getWeights().GetRows(); j++) {
			for (int k = 0; k < layer.getWeights().GetCols(); k++) {
				file << layer.getWeights()(j, k) << " ";
			}
			file << endl;
		}
		file << " Biases:" << endl;
		for (int j = 0; j < layer.getBiased().GetRows(); j++) {
			for (int k = 0; k < layer.getBiased().GetCols(); k++) {
				file << layer.getBiased()(j, k) << " ";
			}
			file << endl;
		}
	}
	file.close();
}