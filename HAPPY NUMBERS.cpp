#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int replace(int X) {
	int Y = 0;
	while(X) {
		Y += (X%10)*(X%10);
		X /= 10;
	}
	return Y;
}
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
			map<int, bool> m; 
			iss >> X;
			m[X] = true;
			X = replace(X);
			while(X!=1 && !m[X]) {
				m[X] = true;
				X = replace(X);
			}
			cout << (X==1) << endl;
		}
	}
	return 0;
}