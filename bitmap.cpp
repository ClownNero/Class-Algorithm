#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

class Bitmap
{
private:
	ifstream readFile;
	ofstream outFile;
	char form;
	int col, row;
	int count;

public:
	Bitmap(string read, string out)
	{
		init(read, out);
	}

	void init(const string& in, const string& out)
	{
		readFile.open(in);
		outFile.open(out);
		readFile >> form;
		while(form != '#')
		{
			readFile >> row;
			readFile >> col;
			char enter;
			readFile.get(enter); // 한자리씩 읽을 때 개행문자 빼주기 위함
			if (form == 'B') {
				outFile << "D ";
				cout << "D ";
				outFile << row << ' ';
				cout << row << ' ';
				outFile << col << ' ' << endl;
				cout << col << ' ' << endl;
				char c;
				char** arr = new char*[row];
				for (int i = 0; i < row; i++) {
					arr[i] = new char[col];
				}
				for (int i = 0; i < row; i++)
				{
					for (int j = 0; j < col; j++)
					{
						readFile.get(c);
						count++;
						if (count % 50 == 0) {
							char a;
							readFile.get(a);
							count = 0;
						}
						arr[i][j] = c;
				//		cout << arr[i][j] << " ";
					}
				//	cout << endl;
					
				}
				count = 0;
				bsort(arr,0,0,row,col); // 0과 1이 아닐 시 4분할
				readFile >> form;
				for (int i = 0; i < row; i++){
					delete[] arr[i];
				}
				delete[] arr;
				outFile << endl;
				cout << endl;
				continue;
			}
			else if (form == 'D') {
				dsort();
				readFile >> form;
				continue;
			}
		}
	}
	void bsort(char **arr,int rb, int cb,int re, int ce) { // 비트맵 형식이 B일때
		if (rb == re || cb == ce) {
			return;
		}
		bool ok = false;
		if (count % 50 == 0 && count > 0)
		{
			count = 0;
			outFile << endl;
			cout << endl;
		}
		for (int i = rb; i < re; i++)
		{
			if (ok) {
				break;
			}
			for (int j = cb; j < ce; j++)
			{
				if (arr[i][j] != arr[rb][cb]) {
					outFile << 'D';
					count++;
					cout << 'D';
					ok = true;
					break;
				}
			}
		}
		if (ok == false) {
			outFile << arr[rb][cb];
			count++;
			cout << arr[rb][cb];
		}
		else {
			bsort(arr, rb, cb, (rb + re + 1) / 2 , (cb + ce + 1) / 2); // 왼쪽 위
			bsort(arr, rb, (cb + ce + 1) / 2, (rb + re + 1) / 2, ce); // 오른쪽 위
			bsort(arr, (rb + re + 1) / 2, cb, re, (cb + ce + 1) / 2); // 왼쪽 아래
			bsort(arr, (rb + re + 1) / 2, (cb + ce + 1) / 2, re, ce); // 오른쪽 아래
		}
		
	}
	
	void dsort() { // 비트맵 형식이 D일때

	}
};
int main() {
	Bitmap bitmap("1.txt", "2.txt");
	return 0;
}