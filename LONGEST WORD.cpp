#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void split(const string& s, const string& delim, vector<string> &v) {
	if(s.size() == 0) return;
	int last = 0;
	size_t index = s.find_first_of(delim, last);
	while(index != string::npos) {
		v.push_back(s.substr(last, index-last));
		last = index+1;
		index = s.find_first_of(delim, last);
	}
	if(index - last > 0)
		v.push_back(s.substr(last, index-last));
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
			vector<string> v;
			unsigned int maxIndex = 0, maxLen = 0;
			split(lineBuffer, " ", v);
			for(int i=0; i<(int)v.size(); i++) {
				if(v[i].length() > maxLen) {
					maxIndex = i;
					maxLen = v[i].length();
				}
			}
			cout << v[maxIndex] << endl;
		}
	}
	return 0;
}