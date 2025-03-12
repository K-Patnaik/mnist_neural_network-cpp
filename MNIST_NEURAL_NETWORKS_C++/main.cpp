#include "Matrix.h"
#include "Layer.h"
#include "Neural_Network.h"
#include "DataSet.h"

int main() {

	string Train_File_Path = "C:\\Users\\AMATYA\\OneDrive\\Desktop\\DataSet\\mnist_train.csv";
	cout << endl << "___________________________________TRAINING DATA IS BEING LOADED________________________________________" << endl << endl;
	vector<vector<double>>train_dataset = DataSet(Train_File_Path);
	cout << endl << "________________________________TRAINING DATA IS SUCCESFULLY LOADED_____________________________________" << endl << endl;

	string Test_File_Path = "C:\\Users\\AMATYA\\OneDrive\\Desktop\\DataSet\\mnist_test.csv";
	cout << endl << "___________________________________TESTING DATA IS BEING LOADED________________________________________" << endl << endl;
	vector<vector<double>>test_dataset = DataSet(Test_File_Path);
	cout << endl << "________________________________TESTING DATA IS SUCCESFULLY LOADED_____________________________________" << endl << endl;

	Layer input(784);
	Layer hidden1=input.nextLayer(256);
	Layer hidden2 = hidden1.nextLayer(128);
	Layer output = hidden2.nextLayer(10);

	

	Neural_Network neura;
	neura.insert(input);
	neura.insert(hidden1);
	neura.insert(hidden2);
	neura.insert(output);
	
	cout << "_______________________________________________________________"<<endl;
	Print(output.getBiased());

	cout << endl << endl<< "TRAINING___________"<<endl;
	for (int i = 0; i < 10000; i++) {
		cout << i << " ";
		vector<double> inp(train_dataset[i].begin()+1, train_dataset[i].end());
		vector<vector<double>>input(1, inp);
		Matrix Input(input);

		double label =train_dataset[i][0]*255.0;

		Matrix expected(1, 10, 0);

		expected(0, label) = 1;

		neura.ForwardAlgo(Input);
		neura.BackPropagation(expected);
	}

	/*Print(neura(2).getWeights());*/

	cout << endl << endl << "TESTING________________" << endl;



	cout << "_______________________________________________________________" << endl;
	Print(output.getBiased());

	double count = 0;
	for (int i = 0; i < 25; i++) {
		cout << i << " ";
		vector<double> inp(test_dataset[i].begin() + 1, test_dataset[i].end());
		vector<vector<double>>input(1, inp);
		Matrix Input(input);

		double label = train_dataset[i][0]*255.0;

		Matrix ans = neura.ForwardAlgo(Input);
		
		int expected = -1;
		double max = INT_MIN;

		cout << "_______________________________________________________________";
		Print(ans);

		for (int j = 0; j < 10; j++) {
			if (ans(0, j) > max) {
				max = ans(0, j);
				expected = j;
			}
		}
		if (label == expected) {
			count++;
			cout << "   ******   ";
		}

		cout <<label << "  ----- ----- -----  " << expected<<endl<<endl;

	}

	cout << endl << "ACCURACY  " << count / 1000;
	
	cout << "_______________________________________________________________" << endl;
	Print(neura(3).getBiased());

	cout << "_______________________________________________________________" << endl;
	/*Print(hidden2.getBiased());*/

}