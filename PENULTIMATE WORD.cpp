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
			split(lineBuffer, " ", v);
			if(v.size() >= 2)
				cout << v[v.size()-2] << endl;
		}
	}
	return 0;
}