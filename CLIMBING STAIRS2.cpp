#include <iostream>
#include <fstream>
#include <string>
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
			int n;
			string step[3] = {"1", "2"};
			//cout << lineBuffer << endl;
			sscanf(lineBuffer.c_str(), "%d", &n);
			if(n <= 2) {
				cout << step[n-1] << endl;
				continue;
			}
			for(int i=2; i<n; i++) {
				step[2] = step[1] + step[0];
				step[0] = step[1];
				step[1] = step[2];
			}
			
			cout << step[2] << endl;
		}
	}
	return 0;
}