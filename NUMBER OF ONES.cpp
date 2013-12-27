#include <iostream>
#include <fstream>
using namespace std;

int main (int argc, char* argv[]) 
{
	freopen(argv[1], "r", stdin);
	int n;
	while(cin >> n) {
		int bitNum = 0;
		while(n) {
			if(n & 0x1)
				bitNum++;
			n >>= 1;
		}
		cout << bitNum << endl;
	}
	return 0;
}