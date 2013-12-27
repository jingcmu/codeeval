#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<int> product_letter;
vector<int> customer_letter;
vector<int> customer_vowel;
const char* ALPHA = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char* vowels = "aoeiuyAOEIUY";

int count_letter(string str, const char *str_c) {
	int num = 0, last;
	last = str.find_first_of(str_c);
	while(last != string::npos) {
		++num;
		++last;
		last = str.find_first_of(str_c, last); 
	}
	return num;
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
			string customer, product;
			vector<string> customer_v, product_v;
			string::size_type last = 0, start = lineBuffer.find_first_of(";");
			customer = lineBuffer.substr(0, start);
			product = lineBuffer.substr(start+1);
			start = customer.find_first_of(",");
			while(start != string::npos) {
				customer_v.push_back(customer.substr(last, start-last));
				last = start+1;
				start = customer.find_first_of(",", last);
			}
			if(start - last > 0) 
				customer_v.push_back(customer.substr(last,start-last));
			start = product.find_first_of(",");
			last = 0;
			while(start != string::npos) {
				product_v.push_back(product.substr(last, start-last));
				last = start+1;
				start = product.find_first_of(",", last);
			}
			if(start - last > 0) 
				product_v.push_back(product.substr(last,start-last));
			for(int i=0; i<customer_v.size(); i++) {
				customer_letter.push_back(count_letter(customer_v[i], ALPHA));
				customer_vowel.push_back(count_letter(customer_v[i], vowels));
			}
			for(int i=0; i<product_v.size(); i++) 
				product_letter.push_back(count_letter(product_v[i], ALPHA));
			
		}
	}
	return 0;
}