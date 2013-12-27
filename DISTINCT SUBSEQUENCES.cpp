#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int num;
void findSubstr(string str1, string str2) {
	if(str1.length() < str2.length()) return;
	if(str1 == str2 || str2.length() == 0) {
		++num;
		return;
	}
	if(str1[0] == str2[0]) {  //str1 str2都去掉一个字符
		findSubstr(str1.substr(1, str1.length()-1), 
					str2.substr(1, str2.length()-1));
	}
	//str1都去掉一个字符
	findSubstr(str1.substr(1, str1.length()-1), str2);	
}

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
			string str1, str2;
			int start = lineBuffer.find_first_of(",");
			num = 0;
			str1 = lineBuffer.substr(0, start);
			str2 = lineBuffer.substr(start+1);
			findSubstr(str1, str2);
			cout << num << endl;
		}
	}
	return 0;
}