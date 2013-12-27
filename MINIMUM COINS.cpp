#include <iostream>
#include <fstream>
using namespace std;

int main (int argc, char* argv[]) 
{
	freopen(argv[1], "r", stdin);
	int n;
	while(cin >> n) {
		int coinNum = 0;
		coinNum = n/5;
		n %= 5;
		if(n >= 3) {
			++coinNum;
			n -= 3;
		}
		cout << coinNum+n << endl;
	}
	return 0;
}