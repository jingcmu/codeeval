#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

void longestSub(string first, string second, int first_index, 
	            int second_index, string current, string &longest) {
	//终止条件
	if(first_index > first.length() || second_index > second.length()) return;
	//完成条件
	if(first_index == first.length() || second_index == second.length()) {
		if(current.length() > longest.length())
			longest = current;
		return;
	}
	char c = first[first_index];
	int pos = second.find_first_of(c, second_index);
	if(pos != string::npos) {
		//不取这个字符
		longestSub(first, second, first_index+1, second_index, current, longest);
		current.append(1, c); //取这个字符
		longestSub(first, second, first_index+1, pos+1, current, longest);
	}
	else {
		//没找到这个字符
		longestSub(first, second, first_index+1, second_index, current, longest);
	}
}

int main (int argc, char* argv[]) {	
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;
	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0)
			continue; //ignore all empty lines
		else {
			size_t end = lineBuffer.find_first_of(";");
			string first = lineBuffer.substr(0,end);
			string second = lineBuffer.substr(end+1, lineBuffer.length()-end-1);
			string longest = "";
			longestSub(first, second, 0, 0, "", longest);
			cout << longest << endl;
		}
	}
	return 0;
}