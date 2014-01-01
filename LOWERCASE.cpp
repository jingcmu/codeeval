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
			for(int i=0; i<lineBuffer.length(); i++) {
				if(lineBuffer[i] <= 'Z' && lineBuffer[i] >= 'A') {
					lineBuffer[i] += 32;
				}
			}
			cout << lineBuffer << endl;
		}
	}
	return 0;
}