#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct point
{
	int x, y;
	point(int a, int b) { x=a,y=b; }
	bool operator == (int a, int b) {return x==a && y==b;}
};

bool check(int x, int y) {
	int sum = 0;
	while(x || y) {
		sum += (x%10 + y%10);
		x/=10, y/=10;
	}
	if(sum <= 19) return true;
	return false;
}

int main (int argc, char* argv[]) {	
	queue<point> q;
	unordered_map<point, bool> m;
	int res = 0;
	point p = new point(0,0), pp;
	q.push(p);
	m[p] = true;
	++res;
	while(!q.empty()) {
		pp.x = p.x+1;
		if(!m.find(pp) && check(pp.x,pp.y)) {
			q.push(pp);
			m[pp] = true;
			++res;
		}
		pp.x = p.x-1;
		if(!m.find(pp) && check(pp.x,pp.y)) {
			q.push(pp);
			m[pp] = true;
			++res;
		}
		pp.x = p.x;
		pp.y = p.y+1;
		if(!m.find(pp) && check(pp.x,pp.y)) {
			q.push(pp);
			m[pp] = true;
			++res;
		}
		pp.y = p.y-1;
		if(!m.find(pp) && check(pp.x,pp.y)) {
			q.push(pp);
			m[pp] = true;
			++res;
		}
	}
	cout << res << endl;
	return 0;
}
