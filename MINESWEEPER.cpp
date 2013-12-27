#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string convertStr(string str, int m, int n) {
	int num;
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			num = 0;
			if(str[i*n+j] == '*') continue;
			if(i>=1) {
				if(str[(i-1)*n+j] == '*') ++num;
				if(j>=1)
					if(str[(i-1)*n+j-1] == '*') ++num;
				if(j<n-1)
					if(str[(i-1)*n+j+1] == '*') ++num;
			}
			if(i<m-1) {
				if(str[(i+1)*n+j] == '*') ++num;
				if(j<n-1)
					if(str[(i+1)*n+j+1] == '*') ++num;
				if(j>=1)
					if(str[(i+1)*n+j-1] == '*') ++num;
			}
			if(j>=1) {
				if(str[i*n+j-1] == '*') ++num;
			}
			if(j<n-1){
				if(str[i*n+j+1] == '*') ++num;
			}
			str[i*n+j] = num+'0';
		}
	}
	return str;
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
			string str1, str2;
			int M, N;
			int start = lineBuffer.find_first_of(";");
			str1 = lineBuffer.substr(0, start);
			str2 = lineBuffer.substr(start+1);
			sscanf(str1.c_str(), "%d,%d", &M, &N);
			cout << convertStr(str2, M, N) << endl;
		}
	}
	return 0;
}