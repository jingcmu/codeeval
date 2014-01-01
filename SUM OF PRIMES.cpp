#include <iostream>
#include <vector>
using namespace std;

int main (int argc, char* argv[]) 
{
	int sum = 0, candidate = 4;
	vector<int> prime;
	prime.push_back(2);
	prime.push_back(3);
	while(prime.size() < 1000) {
		while(candidate++) {
			int i;
			for(i=0; i < prime.size(); i++)
				if(candidate % prime[i] == 0) break;
			if(i == prime.size()) {
				prime.push_back(candidate++);
				break;
			}
		}
	}
	for(int i=0; i<prime.size(); i++) 
		sum += prime[i];
	cout << sum << endl;
	return 0;
}