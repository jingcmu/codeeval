#include <iostream>
using namespace std;

int main (int argc, char* argv[]) 
{	
	for(int i=997; i>0; i-=2) {
		int j;
		for(j=3; j<=33; j+=2) {
			if(i%j == 0) {
				break;
			}
		}
		if(j == 33 && (i/100 == i%10)) {
			cout<<i<<endl;
			break;
		}
	}
	
	return 0;
}