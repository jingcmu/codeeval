#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int height, width;

bool search(vector<vector<char> > &board, int x, int y, string &word, int index, vector<vector<bool> > &visited){
	if(index == word.length()) return true;

	if(x<0 || y<0 || x>=height || 
	   y>=width || visited[x][y] ||
	   board[x][y] != word[index] ) return false;  
	
	visited[x][y] = true;
	if(search(board, x+1, y, word, index+1, visited) ||
	   search(board, x-1, y, word, index+1, visited) ||
	   search(board, x, y+1, word, index+1, visited) ||
	   search(board, x, y-1, word, index+1, visited) ) return true;
	
	visited[x][y] = false;
	return false;
}

bool exist(vector<vector<char> > &board, string word) {
	height = board.size();
	if(!height) return false;
	width = board[0].size();
	vector<vector<bool> > visited(height, vector<bool>(width, false));
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			if(search(board, i, j, word, 0, visited)) {
				return true;
			}
		}
	}
	return false;
}

int main (int argc, char* argv[]) {	
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;
	vector<vector<char> > board(3, vector<char>(4));
	board[0][0] = 'A'; board[0][1] = 'B'; board[0][2] = 'C'; board[0][3] = 'E';
	board[1][0] = 'S'; board[1][1] = 'F'; board[1][2] = 'C'; board[1][3] = 'S';
	board[2][0] = 'A'; board[2][1] = 'D'; board[2][2] = 'E'; board[2][3] = 'E';
	while (!file.eof()) {
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0)
			continue; //ignore all empty lines
		else {
			cout << (exist(board, lineBuffer)? "True" : "False") << endl;
		}
	}
	return 0;
}