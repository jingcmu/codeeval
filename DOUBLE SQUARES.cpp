#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

int main (int argc, char* argv[]) 
{
	map<int, bool> m_square;
	for(int i=0; i<=46340; i++) { //sqrt(2147483647) -> 46340
		m_square[i*i] = true;
	}
	
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;
	getline(file, lineBuffer);
	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0)
			continue; //ignore all empty lines
		else {
			istringstream iss(lineBuffer);
			int X, ways = 0;
			iss >> X;
			for(int i=0; i*i <= (X>>1); i++) {
				if(m_square[X-i*i]) ways++;
			}
			cout << ways << endl;
		}
	}
	return 0;
}