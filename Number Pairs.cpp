#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
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
			int X, N = 0;
			vector<int> v; 
			iss >> X;
			v.push_back(X);
			while(true) {
				char ch;
				iss >> ch;
				iss >> X;
				if(ch == ',') v.push_back(X);
				else break; //;
			}
			for(int i=0, j=v.size()-1; i<j; ) {
				if(v[i]+v[j] == X) {
					if(N) cout << ';';
					cout << v[i] << ',' << v[j];
					++N;
					++i;
					--j;
				}
				else if(v[i]+v[j] > X) --j;
				else i++;					
			}
			if(!N) cout << "NULL";
			cout << endl;
		}
	}
	return 0;
}