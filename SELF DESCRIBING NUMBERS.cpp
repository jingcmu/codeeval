#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string self_describe(string lineBuffer) {
	string res = "";
	size_t size = lineBuffer.size();
	int b[10] = {0};
	for(size_t i=0; i<size; i++) {
		++b[lineBuffer[i]-'0'];
	}
	for(size_t i=0; i<size; i++) {
		res += (b[i]+'0');
	}
	return res;
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
			if(lineBuffer == self_describe(lineBuffer)) 
				cout << "1\n";
			else
				cout << "0\n";
		}
	}
	return 0;
}