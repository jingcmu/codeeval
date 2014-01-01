#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

struct strShort
{
	bool operator() (const string s1, const string s2) const
	{
		return s1.length() > s2.length();
	}
};

int main (int argc, char* argv[]) 
{
	ifstream file;
	string lineBuffer;

	file.open(argv[1]);
	set<string,strShort> s;
	int N;
	file >> N;
	getline(file, lineBuffer);
	while(!file.eof()) {
		getline(file, lineBuffer);
		if(s.size() < N) {
			s.insert(lineBuffer);
		}
		else if(lineBuffer.length() > (*s.rbegin()).length()) {
			s.erase(*s.rbegin()); //erase last element
			s.insert(lineBuffer);
		}
	}
	for(set<string>::iterator it=s.begin(); it!=s.end(); it++) {
		cout << (*it) << endl;
	}
	return 0;
}