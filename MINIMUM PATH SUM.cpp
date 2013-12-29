#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
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
			vector<int> v(line, INT_MAX);
			for(int i=0; i<line; i++) {
				int num;
				getline(file, lineBuffer);
				iss.str(lineBuffer);
				iss >> num;
				if(i == 0) v[0] = num;
				else v[0] += num;
				for(int j=1; j<line; j++) {
					iss.ignore(1);
					iss >> num;
					v[j] = min(v[j], v[j-1]) + num;
				}
				iss.clear(); //reset io state
			}
			cout << v[line-1] << endl;
		}
	}
	
	return 0;
}