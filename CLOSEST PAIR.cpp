#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;

struct point {
	long long x,y;
	point(int a, int b) {x = a, y = b;}
};

int main (int argc, char* argv[]) {	
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;
	while (!file.eof()) {
		getline(file, lineBuffer);
		istringstream iss(lineBuffer);
		int N, X, Y;
		point P(0,0);
		vector<point> v;
		iss >> N;
		if(N == 0) break;
		for(int i=0; i<N; i++) {
			getline(file, lineBuffer);
			istringstream iss(lineBuffer);
			iss >> X >> Y;
			P.x = X, P.y = Y;
			v.push_back(P);
		}
		int min_dis = INT_MAX;
		for(int i=0; i<N-1; i++) {
			for(int j=i+1; j<N; j++) {
				long long dis = (v[j].x-v[i].x)*(v[j].x-v[i].x)+(v[j].y-v[i].y)*(v[j].y-v[i].y);
				if(min_dis > dis) {
					min_dis = dis;
				}
			}
		}
		if(min_dis >= 100000000) cout << "INFINITY" << endl;
		else cout << setprecision(4) << setiosflags(ios::fixed | ios::showpoint) << sqrt(min_dis) << endl;
		v.clear();
	}
	return 0;
}
