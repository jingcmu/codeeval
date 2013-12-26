#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string Integer2Roman(int num) {
	const int radix[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	const string symbol[] = {"M", "CM", "D", "CD", "C", "XC",
							"L", "XL", "X", "IX", "V", "IV", "I"};
	string roman;
	for(size_t i=0; num > 0; ++i) {
		int count = num/radix[i];
		for(; count > 0; --count) roman += symbol[i];
		num %= radix[i];
	}
	return roman;
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
			int num;
			sscanf(lineBuffer.c_str(), "%d", &num);
			cout << Integer2Roman(num) << endl;
		}
	}
	return 0;
}