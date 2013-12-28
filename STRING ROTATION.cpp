#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isRotated(string str1, string str2) {
	int size = str1.size();
	if(size != str2.size()) return false;
	for(int i=0; i<size; i++) {
		str1 = str1.substr(1) + str1[0];	
		if(str1 == str2) return true;
	}
	return false;
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
			string str1, str2;			
			size_t start = lineBuffer.find_first_of(","); 
			str1 = lineBuffer.substr(0, start);
			str2 = lineBuffer.substr(start+1);
			if(isRotated(str1, str2))
				cout << "True\n";
			else cout << "False\n";
		}
	}
	return 0;
}