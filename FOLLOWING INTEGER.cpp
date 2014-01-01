#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
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
			istringstream iss(lineBuffer);
			vector<char> v;
			char ch;
			while(iss >> ch)
				v.push_back(ch);
			bool flag = true;
			for(int i=v.size()-1; i>0; i--) {
				if(v[i] > v[i-1]) {
					for(int j=v.size()-1; j>i-1; j--) {
						if(v[i-1] < v[j]) {
							swap(v[i-1], v[j]);
							break;
						}
					}
					sort(v.begin()+i,v.end());
					flag = false;
					break;
				}
			}
			if(flag) {
				v.push_back('0');
				sort(v.begin(),v.end());
				for(int i=0; i<v.size(); i++) {
					if(v[i] > '0') {
						swap(v[i], v[0]);
						break;
					}
				}
			}			
			for(int i=0; i<v.size(); i++)
				cout << v[i];
			cout << endl;
		}
	}
	return 0;
}