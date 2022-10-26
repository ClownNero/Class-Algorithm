#include<iostream>
#include<fstream>
#include<algorithm>

int max_arr[1005][5]{ 0, };
using namespace std;
class Card
{
private:
	ifstream readFile;
	ofstream outFile;
	int testcase;
	int n;
public:
	Card(string read, string out)
	{
		init(read, out);
	}
	void init(const string& in, const string& out)
	{
		readFile.open(in);
		outFile.open(out);
		readFile >> testcase;
		for (int i = 0; i < testcase; i++)
		{
			readFile >> n; // 배열 크기
			int* arr = new int[n];
			for (int j = 0; j < n; j++)
			{
				int a;
				readFile >> a;
				arr[j] = a;
			}
			for (int i = 0; i < 1005; i++) {
				for (int j = 2; j < 5; j++) {
					max_arr[i][j] = -1124141;
				}
			}
			max_arr[0][2] = arr[0];
			max_arr[1][2] = arr[1];
			max_arr[2][2] = arr[2];
			max_arr[3][3] = arr[3] + arr[0];
			max_arr[3][4] = arr[3] + arr[1];
			outFile << select(arr) << endl;
		}
	}
	int select(int* arr) {
		for (int i = 4; i < n; i++)
		{
			int max_value;
			/*if (max_arr[i - 4][2] == max(max_arr[i - 4][2], max(max_arr[i - 4][3], max_arr[i - 4][4]))) {
				max_value = max_arr[i - 4][2];
			}
			else if (max_arr[i - 4][3] == max(max_arr[i - 4][2], max(max_arr[i - 4][3], max_arr[i - 4][4]))) {
				max_value = max_arr[i - 4][3];
			}
			else {
				max_value = max_arr[i - 4][4];
			}
			*/
			max_value = max(max_arr[i - 4][2], max(max_arr[i - 4][3], max_arr[i - 4][4]));
			max_arr[i][2] = arr[i] + max_value;
			/*if (max_arr[i - 3][2] == max(max_arr[i - 3][2], max(max_arr[i - 3][3], max_arr[i - 3][4]))) {
				max_value = max_arr[i - 3][2];
			}
			else if (max_arr[i - 3][3] == max(max_arr[i - 3][2], max(max_arr[i - 3][3], max_arr[i - 3][4]))) {
				max_value = max_arr[i - 3][3];
			}
			else {
				max_value = max_arr[i - 3][4];
			}
			*/
			max_value = max(max_arr[i - 3][2], max(max_arr[i - 3][3], max_arr[i - 3][4]));
			max_arr[i][3] = arr[i] + max_value;
			/*if (max_arr[i - 2][2] == max(max_arr[i - 2][2], max_arr[i - 2][3])) {
				max_value = max_arr[i - 2][2];
			}
			else {
				max_value = max_arr[i - 2][3];
			}
			*/
			max_value = max(max_arr[i - 2][2], max_arr[i - 2][3]);
			max_arr[i][4] = arr[i] + max_value;
		}
		return max(max_arr[n - 1][2], max(max_arr[n - 1][3], max_arr[n - 1][4]));
	}

};
int main() {
	Card card("2.inp", "card.out");
	return 0;
}
/*
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
int max_arr[1005][5]{ 0, };
int ok_arr[1005][5]{ 0, };
int max_result[1005]{ 0, };
using namespace std;
class Card
{
private:
	ifstream readFile;
	ofstream outFile;
	int testcase;
	int n;
public:
	Card(string read, string out)
	{
		init(read, out);
	}
	void init(const string& in, const string& out)
	{
		readFile.open(in);
		outFile.open(out);
		readFile >> testcase;
		for (int i = 0; i < testcase; i++)
		{
			readFile >> n; // 배열 크기
			int* arr = new int[n];
			for (int j = 0; j < n; j++)
			{
				int a;
				readFile >> a;
				arr[j] = a;
			}
			int a = select(n - 1, 0, arr);
			outFile << a << endl;
			for (int i = 0; i < 1005; i++) {
				max_result[i] = -21151521;
				for (int j = 2; j < 5; j++) {
					ok_arr[i][j] = 0;
				}
			}
		}
	}
	int select(int idx, int count, int* arr)
	{
		if (idx < 3) {
			return arr[idx];
		}
		else if (count == 0 && (ok_arr[idx][3] != 0) && (ok_arr[idx][4] != 0)) {
			max_result[idx] = max(max_arr[idx][3], max_arr[idx][4]);
			return max_result[idx];
		}
		else if ((ok_arr[idx][2] != 0) && (ok_arr[idx][3] != 0) && (ok_arr[idx][4] != 0)) {
			max_result[idx] = max(max_arr[idx][2], max(max_arr[idx][3], max_arr[idx][4]));
			return max_result[idx];
		}
		else
		{
			if (idx == 3) {
				if (idx == n - 1) {
					max_arr[idx][2] = arr[idx] + select(idx - 2, 0, arr);
					max_arr[idx][3] = arr[idx] + select(idx - 3, 1, arr);
					ok_arr[idx][2] = 1;
					ok_arr[idx][3] = 1;
					max_result[idx] = max(max_arr[idx][2], max_arr[idx][3]);
					return max_result[idx];
				}
				if (count == 0) {
					max_arr[idx][3] = arr[idx] + select(idx - 3, 1, arr);
					ok_arr[idx][3] = 1;
					max_result[idx] = max_arr[idx][3];
					return max_result[idx];
				}
				max_arr[idx][2] = arr[idx] + select(idx - 2, 0, arr);
				max_arr[idx][3] = arr[idx] + select(idx - 3, 1, arr);
				ok_arr[idx][2] = 1;
				ok_arr[idx][3] = 1;
				max_result[idx] = max(max_arr[idx][2], max_arr[idx][3]);
				return max_result[idx];
			}
			else if (idx == 4) {
				if (count == 0)
				{
					max_arr[idx][3] = arr[idx] + select(idx - 3, 1, arr);
					max_arr[idx][4] = arr[idx] + select(idx - 4, 2, arr);
					ok_arr[idx][4] = 1;
					ok_arr[idx][3] = 1;
					max_result[idx] = max(max_arr[idx][3], max_arr[idx][4]);
					return max_result[idx];
				}
				else
				{
					max_arr[idx][2] = arr[idx] + select(idx - 2, 0, arr);
					max_arr[idx][3] = arr[idx] + select(idx - 3, 1, arr);
					max_arr[idx][4] = arr[idx] + select(idx - 4, 2, arr);
					ok_arr[idx][2] = 1;
					ok_arr[idx][3] = 1;
					ok_arr[idx][4] = 1;
					max_result[idx] = max(max_arr[idx][2], max(max_arr[idx][3], max_arr[idx][4]));
					return max_result[idx];
				}


			}
			else if (idx > 4)
			{
				if (idx == n - 1) {
					max_arr[idx][2] = arr[idx] + select(idx - 2, 0, arr);
					max_arr[idx][3] = arr[idx] + select(idx - 3, 1, arr);
					max_arr[idx][4] = arr[idx] + select(idx - 4, 2, arr);
					ok_arr[idx][2] = 1;
					ok_arr[idx][3] = 1;
					ok_arr[idx][4] = 1;
					max_result[idx] = max(max_arr[idx][2], max(max_arr[idx][3], max_arr[idx][4]));
					return max_result[idx];
				}
				if (count == 0) {
					max_arr[idx][3] = arr[idx] + select(idx - 3, 1, arr);
					max_arr[idx][4] = arr[idx] + select(idx - 4, 2, arr);
					ok_arr[idx][3] = 1;
					ok_arr[idx][4] = 1;
					max_result[idx] = max(max_arr[idx][3], max_arr[idx][4]);
					return max_result[idx];
				}
				max_arr[idx][2] = arr[idx] + select(idx - 2, 0, arr);
				max_arr[idx][3] = arr[idx] + select(idx - 3, 1, arr);
				max_arr[idx][4] = arr[idx] + select(idx - 4, 2, arr);
				ok_arr[idx][2] = 1;
				ok_arr[idx][3] = 1;
				ok_arr[idx][4] = 1;
				max_result[idx] = max(max_arr[idx][2], max(max_arr[idx][3], max_arr[idx][4]));
				return max_result[idx];
			}
		}
	}
};

int main() {
	Card card("1.txt", "card.out");
	return 0;
}*/