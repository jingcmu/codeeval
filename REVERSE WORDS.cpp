#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
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
			while(iss >> str) v.push_back(str);
			cout << v[v.size()-1];
			for(int i=v.size()-2; i>=0; i--)
				cout << " " << v[i];
			cout << endl;
		}
	}
	return 0;
}