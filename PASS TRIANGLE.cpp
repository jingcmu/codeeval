#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main (int argc, char* argv[]) 
{
	ifstream file;
	string lineBuffer;
	int line = 1, max_sum = 0;
	vector<int> res, res_copy;
	file.open(argv[1]);
	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0)
			continue; //ignore all empty lines
		else {
			istringstream iss(lineBuffer);
			int num;
			for(int i=0; i<line; ++i) {
				iss >> num;
				if(line == 1) res.push_back(num);
				else {
					if(i == 0) res[0] += num;
					else if(i == line-1) res.push_back(res_copy[line-2]+num);
					else {
						res[i] = num + max(res_copy[i-1], res_copy[i]);
					}
				}
			}
			++line;
			res_copy = res;
		}
	}
	for(int i=0; i<line-1; i++) max_sum = max(max_sum, res[i]);
	cout << max_sum << endl;
	return 0;
}