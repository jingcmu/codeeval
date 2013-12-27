#include <iostream>
#include <fstream>
using namespace std;

int main (int argc, char* argv[]) 
{
	freopen(argv[1], "r", stdin);
	int n;
	while(cin >> n) {
		int step[3] = {1, 2};
		if(n <= 2) {
			cout << step[n-1] << endl;
			continue;
		}
		for(int i=1; i<n-1; i++){
			step[2] = step[1] + step[0];
			step[0] = step[1];
			step[1] = step[2];
		}
		cout << step[2] << endl;
	}
	return 0;
}