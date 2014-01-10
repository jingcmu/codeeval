#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main (int argc, char* argv[]) {	
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;
	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0)
			continue; //ignore all empty lines
		else {
			int len = 0;
			for(int i=0; i<lineBuffer.length(); i++) {
				if(lineBuffer[i] >= 'a' && lineBuffer[i] <= 'j') {
					cout << lineBuffer[i]-'a';
					++len;
				} else if(lineBuffer[i] >= '0' && lineBuffer[i] <= '9') {
					cout << lineBuffer[i];
					++len;
				}
			}
			if(!len) cout << "NONE";
			cout << endl;
		}
	}
	return 0;
}