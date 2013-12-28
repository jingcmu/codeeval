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
			int A1x,A1y,A2x,A2y,B1x,B1y,B2x,B2y;
			sscanf(lineBuffer.c_str(), "%d,%d,%d,%d,%d,%d,%d,%d",
				   &A1x, &A1y, &A2x, &A2y, &B1x, &B1y, &B2x, &B2y);
			if(B1x>A2x || B1y<A2y || B2x<A1x || B2y>A1y) 
				cout << "False\n";
			else cout << "True\n";
		}
	}
	return 0;
}