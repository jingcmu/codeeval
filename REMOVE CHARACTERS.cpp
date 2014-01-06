#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
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
			size_t start = lineBuffer.find_first_of(","), end;
			string str1 = lineBuffer.substr(0, start);
			string str2 = lineBuffer.substr(start + 2);
			string res = "";
			start = 0;
			end = str1.find_first_of(str2, start);
			while(end != string::npos) {
				res += str1.substr(start, end-start);
				start = end+1;
				end = str1.find_first_of(str2, start);
			}
			res += str1.substr(start);
			cout << res << endl;
		}
	}
	return 0;
}