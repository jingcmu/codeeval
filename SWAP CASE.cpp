#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string switchCase(string lineBuffer) {
	int size = lineBuffer.size();
	for(int i=0; i<size; i++) {
		if(lineBuffer[i] >= 'A' && lineBuffer[i] <= 'Z') {
			lineBuffer[i] += 32;
		}
		else if(lineBuffer[i] >= 'a' && lineBuffer[i] <= 'z') {
			lineBuffer[i] -= 32;
		}
	}
	return lineBuffer;
}

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
			cout << switchCase(lineBuffer) << endl;
		}
	}
	return 0;
}