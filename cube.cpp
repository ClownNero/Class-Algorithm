#include<iostream>
#include<fstream>
#include<algorithm>
#define A 242532634
using namespace std;

int cube[205][205][205] = { 0, };

class Cube
{
private:
	ifstream readFile;
	ofstream outFile;
	int testcase;
	int w, l, h;
	int line_w, line_l, line_h;
public:
	Cube(string read, string out)
	{
		init(read, out);
	}
	void init(const string& in, const string& out)
	{
		readFile.open(in);
		outFile.open(out);
		readFile >> testcase;
		start();
		for (int i = 0; i < testcase; i++)
		{
			readFile >> w >> l >> h;
			cout << cube[w][l][h] << endl;
			outFile << cube[w][l][h] << endl;
		}
	}
	void start() {
		for (int w = 1; w < 201; w++)
		{
			for (int l = 1; l < 201; l++)
			{
				for (int h = 1; h < 201; h++)
				{ 
					if (cube[w][l][h] != 0) continue;
					else { // 계산되지 않은 큐브
						if (w == l && l == h) {
							cube[w][l][h] = 1;
						}

						else if (w == 1 || l == 1 || h == 1) {
							cube[w][l][h] = w * l * h;
						}
						/*
						else if (w % l == 0 && h % l == 0) {
							cube[w][l][h] = (w / l) * (h / l);
						}
						else if(w%h == 0 && l%h == 0){
							cube[w][l][h] = (w / h) * (l / h);
						}
						else if (l % w == 0 && h % w == 0) {
							cube[w][l][h] = (l / w) * (h / w);
						}
						*/
						else {
							cube[w][l][h] = A; // 고정
							for (int i = 1; i <= w/2; i++) { // 가로
								cube[w][l][h] = min(cube[w][l][h], cube[i][l][h] + cube[w - i][l][h]);
							}
							for (int i = 1; i <= l/2; i++) { // 세로
								cube[w][l][h] = min(cube[w][l][h], cube[w][i][h] + cube[w][l-i][h]);
							}
							for (int i = 1; i <= h/2; i++) { // 높이
								cube[w][l][h] = min(cube[w][l][h], cube[w][l][i] + cube[w][l][h-i]);
							}
						}
						// 욱면체라 다 같음
						cube[w][h][l] =  cube[l][h][w] = cube[l][w][h] = cube[h][w][l] = cube[h][l][w] = cube[w][l][h];
					}
				}
			}
		}
	}

};

int main() {
	Cube cube("1.txt", "cube.out");
	return 0;
}