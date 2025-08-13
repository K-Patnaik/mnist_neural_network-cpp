#include "Neural_Network.h"

void Neural_Network::insert(Layer& l1) {
	NN_Layers.push_back(l1);
}

Matrix& Neural_Network::ForwardAlgo(Matrix& input) {
	


	NN_Layers[0].getOutputs() = input;
	for (int i = 1; i <= NN_Layers.size()-2; i++) {
		Layer& current_Layer = NN_Layers[i];
		Layer& previous_Layer = NN_Layers[i - 1];
		Forward(current_Layer, previous_Layer,"ReLU");
	}

	Layer& current_Layer = NN_Layers[NN_Layers.size()-1];
	Layer& previous_Layer = NN_Layers[NN_Layers.size() - 2];

	Forward(current_Layer, previous_Layer, "SoftMax");

	return NN_Layers.back().getOutputs();
}





void Neural_Network::BackPropagation(Matrix expected) {

	//std::cout <<std::endl<< "***************************************************************"<<std::endl;

	Matrix output = NN_Layers.back().getOutputs();
	Matrix delta = output - expected;
	/*std::cout << std::endl << std::endl << "EXPECTED___________" << std::endl;
	Print(expected);*/


	for (int i = NN_Layers.size() - 1; i > 0; i--) {
		Layer& current = NN_Layers[i];
		Layer& previous = NN_Layers[i - 1];

		Matrix gradient_weight = (previous.getOutputs().Transpose()) * delta;
		Matrix gradient_bias = delta;

		Matrix ReLU_derivative = ReLU_Derivative(previous.getOutputs());

		delta = (delta * previous.getWeights().Transpose()).Product(ReLU_derivative);

		/*if (i == NN_Layers.size() - 1) {
			std::cout << std::endl << "*******************_______BEFORE_________********************" << std::endl;
			Print(current.getBiased());
			std::cout << std::endl << "*******************__________________________********************" << std::endl;
		}*/


		previous.getWeights() = previous.getWeights() -  gradient_weight * Learning_Rate;
		current.getBiased() = current.getBiased() - gradient_bias * Learning_Rate;
		

		/*if (i == NN_Layers.size() - 1) {
			std::cout << std::endl << "*******************_______AFTER_________********************" << std::endl;
			Print(current.getBiased());
			std::cout << std::endl << "*******************__________________________********************" << std::endl;
		}*/

	}

}



Layer& Neural_Network::operator()  (int x) {
	return NN_Layers[x];
}