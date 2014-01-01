#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
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
			size_t pos_label, pos_num, ID, sum = 0;
			pos_label = lineBuffer.find("label");
			while(pos_label != string::npos) {
				pos_num = lineBuffer.rfind(":", pos_label);
				iss.seekg(pos_num+1, iss.beg);
				iss >> ID;
				sum += ID;
				pos_label = lineBuffer.find("label", pos_label+1);
			}
			cout << sum << endl;
		}
	}
	return 0;
}