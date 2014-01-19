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
		vector<string> v;
		getline(file, lineBuffer);
		sort(lineBuffer.begin(), lineBuffer.end());
		cout << lineBuffer;
		while (next_permutation(lineBuffer.begin(), lineBuffer.end())) {
			cout << "," << lineBuffer;
		}
		cout << endl;
		v.clear();
	}
	return 0;
}
