#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstring>

int arr[1000000][7];
using namespace std;

class Coinmove
{
private:
	ifstream readFile;
	ofstream outFile;
	int testcase;
	int P, K, S; 
public:
	Coinmove(string read, string out)
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
			readFile >> P >> K >> S;
			memset(arr, -1, sizeof(arr));
			start(P, K, S, arr);
			
			
		}
	}
	void start(int p, int k, int s, int arr[][7])
	{
		/*
		int** arr = new int* [s];
		for (int i = 0; i < s; i++)
		{
			arr[i] = new int[k];
		}*/
		for (int i = 0; i < s; i++) {
			for (int j = 0; j < k; j++) {
				if (i - j < 0) {
					arr[i][j] = 0;
				}
				else if (i == j) {
					arr[i][j] = 1;
				}
				else if ((i - j) % p == 0) {
					arr[i][j] = 0;
				}
				else {
					check(i, j, p, arr);
				}
			}
		}
		/*for (int i = 0; i < s; i++) {
			for (int j = 0; j < k; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		*/
		/*for (int i = 0; i < k; i++) {
			cout << arr[s - 2][i] << " ";
		}
		cout << endl;
		for (int i = 0; i < k; i++) {
			cout << arr[s - 1][i] << " ";
		}*/
		for (int i = 0; i < k; i++) {
			if (arr[s - 1][i] == 1) {
				outFile << (s - (i + 1));
				outFile << endl;
				break;
			}
			else if (i == (k - 1)) {
				outFile << "-1";
				outFile << endl;
				break;
			}
		}
	}
	void check(int s, int k, int p ,int arr[][7])
	{	
		int a = 0;
		while(a < K){
			if (a == k) a++;
			if (a < K) {
				if (arr[s - k - 1][a] == 1) {
					arr[s][k] = 0;
					break;
				}
				else a++;
			}
			
		}
		if (arr[s][k] !=0) {
			arr[s][k] = 1;
		}
	}
};
int main() {
	Coinmove coinmove("coinmove.inp", "coinmove.out");
	return 0;
}
