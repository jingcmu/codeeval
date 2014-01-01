#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

int main (int argc, char* argv[]) 
{
	ifstream file;	
	map<int, bool> prime;
	int begin, end, res, prime_largest = 3;
	string lineBuffer;
	file.open(argv[1]);
	prime[2] = true;
	prime[3] = true;
	
	while(!file.eof()) {
		getline(file, lineBuffer);
		istringstream iss(lineBuffer);
		char ch;
		iss >> begin >> ch >> end; 
		res = 0;		
		if(end > prime_largest) { //generate the prime list
			int i, j;
			for(i=prime_largest+2; i<=end; i+=2) {
				for(j=3; j<=prime_largest; j+=2) {
					if(!prime[j]) continue;
					if(i%j == 0) break;
				}
				if(j == prime_largest+2) {
					prime[i] = true;
					prime_largest = i;
				}
			}
			
			while(true) { //find a prime just larger than end
				for(j=3; j<=prime_largest; j+=2) {
					if(!prime[j]) continue;
					if(i%j == 0) break;
				}				
				if(j == prime_largest+2) {
					prime[i] = true;
					break;
				}
				i+=2;
			}
		}
		for(int i=begin; i<=end; i++) {
			if(prime[i]) res++;
		}
		cout << res << endl;
	}
	return 0;
}