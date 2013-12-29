#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
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
			int line;			
			istringstream iss(lineBuffer);
			iss >> line;
			iss.clear(); //reset io state
			vector<vector<int> > v(line, vector<int>(line));
			for(int i=0; i<line; i++) {
				getline(file, lineBuffer);
				iss.str(lineBuffer);
			}

		}
	}
	
	return 0;
}