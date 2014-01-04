#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

inline int number(vector<int> v, string op) {
	int num = 0, sum = 0, mul = 1;
	for(int i=v.size()-1; i>=0; i--) {
		int n = v[i];
		num += n*mul;
		if(op[i] == '+') {
			sum += num;
			mul = 1;	
			num = 0;
		}
		else if(op[i] == '-') {
			sum -= num;
			mul = 1;
			num = 0;
		}
		else {
			mul *= 10;
		}
	}
	return sum;
}

void getuNums(vector<int> v, int &uNums, int index, string op) {
	if(index == v.size()) {
		int num = number(v, op);
		if(!(num%2 && num%3 && num%5 && num%7)) ++uNums;
		return;
	}
	getuNums(v, uNums, index+1, op+" ");
	getuNums(v, uNums, index+1, op+"+");
	getuNums(v, uNums, index+1, op+"-");
}

int main (int argc, char* argv[]) 
{	
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;
	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0)
			continue; //ignore all empty lines
		else {
			int start = lineBuffer.find_first_not_of("0");
			int mul = 1;
			if(start > 1) {
				lineBuffer = lineBuffer.substr(start-1);
				//去掉一个0结果就要乘以一个3
				for(int i=0; i<start-1; i++) mul *= 3;
			}
			istringstream iss(lineBuffer);
			char ch;
			vector<int> v;
			while(iss >> ch) {
				v.push_back(ch - '0');
			}
			//v save numbers
			int uNums = 0;
			getuNums(v, uNums, 1, "+");
			cout << uNums*mul << endl;
		}
	}
	return 0;
}