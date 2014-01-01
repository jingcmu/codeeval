//思路：只维持一个prime的list

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main (int argc, char* argv[]) 
{
	ifstream file;	
	vector<int> prime;
	int end;
	string lineBuffer;
	file.open(argv[1]);
	prime.push_back(2);
	prime.push_back(3);
	
	while(!file.eof()) {
		getline(file, lineBuffer);
		istringstream iss(lineBuffer);
		char ch;
		iss >> end; 	
		if(end < 3) continue;
		if(end > prime[prime.size()-1]) { //generate the prime list
			int i, j;
			for(i=prime[prime.size()-1]; i<=end; i+=2) {
				for(j=0; j<prime.size(); j++) {
					if(i%prime[j] == 0) break;
				}
				if(j == prime.size()) {
					prime.push_back(i);
				}
			}
		}
		cout << prime[0];
		for(int i=1; i<prime.size() && prime[i]<end; i++) 
			cout << "," << prime[i];
		cout << endl;
	}
	return 0;
}