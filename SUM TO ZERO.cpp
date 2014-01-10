#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main (int argc, char* argv[]) {	
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;
	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0)
			continue; //ignore all empty lines
		else {
			istringstream iss(lineBuffer);
			int x, res = 0;
			char ch;
			vector<int> v;
			iss >> x;
			v.push_back(x);
			while(iss >> ch) {
				iss >> x;
				v.push_back(x);
			}
			int size = v.size();
			sort(v.begin(), v.end());
			for(int i=0; i<size-3; i++){
				for(int j=i+1; j<size-2; j++){
					for(int k=j+1; k<size-1; k++){
						for(int l=k+1; l<size; l++) {
							if(v[i]+v[j]+v[k]+v[l] == 0)
							++res;
						}
					}
				}
			}			
			cout << res << endl;
		}
	}
	return 0;
}