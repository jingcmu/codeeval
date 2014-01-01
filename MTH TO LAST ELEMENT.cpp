#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
using namespace std;

int main (int argc, char* argv[]) 
{
	ifstream file;
	string lineBuffer;

	file.open(argv[1]);
	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0)
			continue; //ignore all empty lines
		else {
			istringstream iss(lineBuffer);
			vector<string> v;
			string str;
			int M, size;
			while(iss >> str) v.push_back(str);
			size = v.size();
			M = atoi(v[size-1].c_str());
			if(size-M-1 >= 0)
				cout << v[size - M - 1 ] << endl;
		}
	}
	return 0;
}