#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
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
			map<int, int> m;
			queue<int> q;
			int n,k,a,b,c,r,min_v=0;
			char ch;
			iss >> n >> ch >> k >> ch >> a >> ch;
			iss >> b >> ch >> c >> ch >> r ;
			vector<int> v(n);
			v[0] = a;
			if(v[0] == min_v) ++min_v;
			m[v[0]]++;
			q.push(v[0]);
			for(int i=1; i<k; i++) {
				 v[i] = (b*v[i-1]+c)%r;
				 q.push(v[i]);
				 m[v[i]]++;
				 while(m[min_v]) ++min_v;
			}
			v[k] = min_v++;
			q.push(v[k]);
			m[v[k]]++;
			while(m[min_v]) ++min_v;
			for(int i=k+1; i<n; i++) {
				int tmp = q.front(); 
				q.pop();
				m[tmp]--;
				if(tmp > min_v || m[tmp]) {
					v[i] = min_v++;
					q.push(v[i]);
					m[v[i]]++;
					while(m[min_v]) ++min_v;
				}
				else {
					v[i] = tmp;
					q.push(v[i]);
					m[v[i]]++;
				}
			}	
			cout << v[n-1] << endl;
		}
	}
	
	return 0;
}