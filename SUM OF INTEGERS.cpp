#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main (int argc, char* argv[]) 
{	
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;
	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0)
			continue; //ignore all empty lines
		else {
			istringstream iss(lineBuffer);
			int X;			
			vector<int> v;
			iss >> X;
			v.push_back(X);
			char ch;
			iss >> ch;
			while(iss) {
				iss >> X >> ch;
				v.push_back(X);
			}
			int Max = v[0], sum = v[0];
			for(int i=1; i<v.size(); i++) {
				sum = max(sum, 0);
				sum += v[i];
				Max = max(sum, Max);
			}
			cout << Max << endl;
		}
	}
	return 0;
}