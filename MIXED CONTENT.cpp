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
			size_t end = lineBuffer.find_first_of(",");
			size_t start = 0;
			string num, word, str;
			while(end != string::npos) {
				str = lineBuffer.substr(start, end - start);
				if(str[0] <= '9' && str[0] >= '0') {
					if(num.length()) num += ',';
					num += str;
				}
				else {
					if(word.length()) word += ',';
					word += str;
				}
				start = end + 1;
				end = lineBuffer.find_first_of(",", start);
			}
			str = lineBuffer.substr(start, end - start);
			if(str[0] <= '9' && str[0] >= '0') {
				if(num.length()) num += ',';
				num += str;
			}
			else {
				if(word.length()) word += ',';
				word += str;
			}
			if(num.size() == 0) cout << word << endl;
			else if(word.size() == 0) cout << num << endl;
			else cout << word << "|" << num << endl;
		}
	}
	return 0;
}