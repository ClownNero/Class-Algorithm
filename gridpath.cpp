#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>

using namespace std;

class Gridpath
{
private:
	ifstream readFile;
	ofstream outFile;
	int row, col;
public:
	Gridpath(string read, string out)
	{
		init(read, out);
	}
	void init(const string& in, const string& out)
	{
		readFile.open(in);
		outFile.open(out);
		readFile >> row >> col; // 행과 열 읽기
		int** arr = new int* [row];
		for (int i = 0; i < row; i++) // 동적 2차원 배열 만들기
		{
			arr[i] = new int[col];
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				readFile >> arr[i][j];
			//	cout << arr[i][j] << " ";
			}
		//	cout << endl;
		}
	//	cout << "------------------------------------"<<endl;
		shortest(arr, row, col);
	}
	void shortest(int** arr, int r, int c) { // 가중치로 최단거리 누적계산
		
		for (int i = 1; i < r; i++) { // 행 바깥부분 누적 계산
			if (arr[i][0] != -1) {
				arr[i][0] = arr[i - 1][0] + arr[i][0];
			}
			else {
				if (i + 1 < r) {
					arr[i+1][0] = -1;
				}
			}
		}
		for (int j = 1; j < c; j++) { // 열 바깥부분 누적 계산
			if (arr[0][j] != -1) {
				arr[0][j] = arr[0][j - 1] + arr[0][j];
			}
			else {
				if (j + 1 < c) {
					arr[0][j + 1] = -1;
				}	
			}
		}
		// 안쪽 부분 누적 계산
		for (int i = 1; i < r; i++) {
			for (int j = 1; j < c; j++) {
				if (arr[i][j] != -1) {
					if (arr[i][j - 1] == -1 && arr[i - 1][j] == -1) {
						arr[i][j] = -1; 
					}
					else if (arr[i][j - 1] == -1 && arr[i - 1][j] != -1) {
						arr[i][j] = arr[i - 1][j] + arr[i][j];
					}
					else if (arr[i][j - 1] != -1 && arr[i - 1][j] == -1) {
						arr[i][j] = arr[i][j - 1] + arr[i][j];
					}
					else if (arr[i][j - 1] >= arr[i - 1][j]) {
						arr[i][j] = arr[i - 1][j] + arr[i][j];
					}
					else {
						arr[i][j] = arr[i][j - 1] + arr[i][j];
					}
				}
				else {
					continue;
				}
			}
		}
	/*	for (int i = 0; i < r; i++) { // 
			for (int j = 0; j < c; j++) {
				cout << arr[i][j];
				cout << ' ';
			}
			cout << endl;
		}*/
		int shortcost = arr[r - 1][c - 1]; // 최단경로 가중치
		if (shortcost != -1) {
			vector<int> vr;
			vector<int> vc;
			vr.push_back(r - 1);
			vc.push_back(c - 1);
			r = r - 1;
			c = c - 1;
			while (r != 0 || c != 0) {
				if (r == 0 && c != 0) {
					vr.push_back(0);
					vc.push_back(c - 1);
					c--;
				}
				else if (r != 0 && c == 0) {
					vr.push_back(r - 1);
					r--;
					vc.push_back(0);
				}
				else if (((r + c) == (row + col - 2)) && arr[r][c - 1] == arr[r - 1][c]) {
					vr.push_back(r);
					vc.push_back(c - 1);
					c--;
				}
				else if (arr[r][c - 1] == arr[r - 1][c]) {
					vr.push_back(r - 1);
					r--;
					vc.push_back(c);
				}
				else if (arr[r][c - 1] > arr[r - 1][c]) {
					if (arr[r - 1][c] == -1) {
						vr.push_back(r);
						vc.push_back(c - 1);
						c--;
					}
					else{
						vr.push_back(r - 1);
						r--;
						vc.push_back(c);
					}
				}
				else if (arr[r][c - 1] < arr[r - 1][c]) {
					if (arr[r][c - 1] == -1) {
						vr.push_back(r - 1);
						r--;
						vc.push_back(c);
					}
					else {
						vr.push_back(r);
						vc.push_back(c - 1);
						c--;
					}

				}
			}
			reverse(vr.begin(), vr.end());
			reverse(vc.begin(), vc.end());
		//	cout << shortcost << endl;
			outFile << shortcost << endl;
			for (int i = 0; i < vr.size(); i++) {
				outFile << "(" << vr[i] << " " << vc[i] << ")" << endl;
			}
		}
		else {
			//cout << "No path.";
			outFile << "No path.";
		}
	}
};
int main() {
	Gridpath gridpath("gridpath.inp", "gridpath.out");
	return 0;
}
