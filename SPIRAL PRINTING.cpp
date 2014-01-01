#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

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
			istringstream iss(lineBuffer);
			int m, n;
			char ch;
			iss >> m >> ch >> n >> ch;
			vector<vector<string> > v(m, vector<string>(n));
			for(int i=0; i<m; i++) {
				for(int j=0; j<n; j++) {
					string tmp;
					iss >> tmp;
					v[i][j] = tmp;
				}
			}
			int beginX=0, beginY=0, endX=n-1, endY=m-1;
			string res = "";
			while(true) {
				//from left to right
 				for(int i=beginX; i<=endX; i++) {
					res += (v[beginY][i] + " ");
				}
				if(++beginY > endY) break;
	            //from up to down
				for(int i=beginY; i<=endY; i++) {
					res +=  (v[i][endX]+" ");
				}
				if(--endX < beginX) break;
				//from right to left
				for(int i=endX; i>=beginX; i--)	{
					res +=  (v[endY][i]+" ");
				}
				if(--endY < beginY) break;
				//from down to up
				for(int i=endY; i>=beginY; i--){
					res +=  (v[i][beginX]+" ");
				}
				if(++beginX > endX) break;
			}
			res.erase(res.length()-1, 1);
			cout << res << endl;
		}
	}
	return 0;
}