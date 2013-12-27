#include <iostream>
#include <fstream>
#include <string>
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
			double centerX, centerY, radius, pointX, pointY;
			double x, y;
			sscanf(lineBuffer.c_str(), "Center: (%lf, %lf); Radius: %lf; Point: (%lf, %lf)", 
					&centerX, &centerY, &radius, &pointX, &pointY);
			x = pointX - centerX;
			y = pointY - centerY;
			if(x*x + y*y - radius*radius < 0.01)
				cout << "true" << endl;
			else
				cout << "false" << endl;
		}
	}
	return 0;
}