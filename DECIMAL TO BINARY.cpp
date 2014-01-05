#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
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
			cout << lineBuffer << "*" << endl;
			int X;
			string res = "";
			iss >> X;
			while(X) {
				res += (X%2 + '0');
				X /= 2;
			}
			reverse(res.begin(), res.end());
			//cout << res << endl;
		}
	}
	return 0;
}