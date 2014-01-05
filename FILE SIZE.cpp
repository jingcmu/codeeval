#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (int argc, char* argv[]) 
{	
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;
	int size = 0;
	while (!file.eof()) {
		getline(file, lineBuffer);
		size = size + lineBuffer.length() + 1;
	}
	cout << size-1 << endl;
	return 0;
}