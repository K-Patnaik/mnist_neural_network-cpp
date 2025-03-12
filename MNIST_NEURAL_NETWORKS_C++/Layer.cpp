#include "Layer.h";

Layer::Layer() {}

Layer::Layer(int neuron_count) {
	Matrix a(1, neuron_count, 0.5);// (double)rand()/ RAND_MAX ********  chooses random value between 0 - 1; ********
	outputs = biased = a;
}

Layer ans;
Layer& Layer::nextLayer(int neuron_count) {
	Layer next_layer(neuron_count);
	Matrix weight(this->outputs.GetCols(), next_layer.outputs.GetCols(), 0.5);// (double)rand()/ RAND_MAX ********  chooses random value between 0 - 1; ********


	// Get fan_in = number of neurons in the CURRENT layer
	int fan_in = this->outputs.GetCols();

	// He initialization: mean=0, stddev=sqrt(2 / fan_in)
	double he_stddev = sqrt(2.0 / fan_in);

	weight.fillRandomNormal(0.0, he_stddev); // Use your Matrix's fillRandomNormal method


	this->weights = weight;
	ans = next_layer;
	return ans;
}

Matrix& Layer::getOutputs() {
	return this->outputs;
}

Matrix& Layer::getBiased() {
	return this->biased;
}

Matrix& Layer::getWeights() {
	return this->weights;
}
