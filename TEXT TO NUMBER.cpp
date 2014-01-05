#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

void init(map<string, int> &m) {
	m["zero"] = 0; m["one"] = 1; m["two"] = 2; m["three"] = 3; m["four"] = 4;
	m["five"] = 5; m["six"] = 6; m["seven"] = 7; m["eight"] = 8; m["nine"] = 9;
	m["ten"] = 10; m["eleven"] = 11; m["twelve"] = 12; m["thirteen"] = 13; m["fourteen"] = 14;
	m["fifteen"] = 15; m["sixteen"] = 16; m["seventeen"] = 17; m["eighteen"] = 18; m["nineteen"] = 19;
	m["twenty"] = 20; m["thirty"] = 30; m["forty"] = 40; m["fifty"] = 50; m["sixty"] = 60;
	m["seventy"] = 70; m["eighty"] = 80; m["ninety"] = 90; m["hundred"] = 100; 
	m["thousand"] = 1000;m["million"] = 1000000;
}

int main (int argc, char* argv[]) 
{	
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;
	map<string, int> m;
	init(m);
	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0)
			continue; //ignore all empty lines
		else {
			istringstream iss(lineBuffer);
			string str;
			int sum = 0, res = 0;
			int isNegative = 1;
			iss >> str;
			if(str == "negative") {
				isNegative = -1;
			}
			else sum = m[str];
			while(iss >> str) {
				if(str == "million" || str == "thousand") {
					res += sum * m[str];
					sum = 0;
				}
				else if(str == "hundred") {
					sum *= m[str];
				}
				else {
					sum += m[str];
				}
			}
			res += sum;
			cout << res*isNegative << endl;
		}
	}
	return 0;
}