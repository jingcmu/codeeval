#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
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
			//cout << lineBuffer << endl;
			istringstream iss(lineBuffer);
			vector<int> v, res;
			int tmp;
			while(iss >> tmp) {
				v.push_back(tmp);
			}
			reverse(v.begin(), v.end());
			int len = 1; 
			while(true) {
				int i;
				for(i=0; i<len; i++) 
					if(v[i] != v[i+len]) break;
				if(i == len){
					cout << v[len-1];
					for(int j=len-2; j>=0; --j) 
						cout << " " << v[j];
					cout << endl;
					break;
				}
				++len;
			}
		}
	}
	return 0;
}