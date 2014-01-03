#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main (int argc, char* argv[]) 
{	
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;
	vector<int> f(20);
	f[0] = 0;
	f[1] = 1;
	for(int i=2; i<20; i++) {
		f[i] = f[i-1] + f[i-2];
	}
	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0)
			continue; //ignore all empty lines
		else {
			istringstream iss(lineBuffer);
			int X;
			iss >> X;
			cout << f[X] << endl;
		}
	}
	return 0;
}