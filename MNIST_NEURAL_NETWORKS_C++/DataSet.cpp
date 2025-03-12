#include"DataSet.h"


vector< vector<double> > DataSet(string& file_name) {
	vector<vector<double>> Data;
	ifstream file(file_name);
	string line;

	getline(file, line);
	int i = 0;

	while (getline(file, line)) {
		vector<double> data;
		stringstream ss(line);
		string data_val;
		while (getline(ss, data_val, ',')) {

			data.push_back(stod(data_val) / 255.0);
			//cout << data_val<<" ";
			
		}
		Data.push_back(data);
		cout << i++<<" ";
	}
	return Data;
}