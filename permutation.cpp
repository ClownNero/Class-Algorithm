#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

class Permutation
{
private:
	ifstream readFile;
	ofstream outFile;
	int testcase; // 테스트케이스 갯수
	int n;
public:
	Permutation(string read, string out)
	{
		init(read, out);
	}
	void init(const string& in, const string& out)
	{
		readFile.open(in);
		outFile.open(out);
		readFile >> testcase; // 테스트케이스 갯수
		for (int i = 0; i < testcase; i++)
		{
			readFile >> n;
			int* arr = new int[n]; // 동적 1차원 배열 생성
			int* v = new int[n] {0}; // 깊이 값을 저장할 배열
			for (int j = 0; j < n; j++)
			{
				readFile >> arr[j];
			}
			start(arr, v);
			for (int j = 0; j < n; j++) {
				outFile << v[j];
				outFile << " ";
			}
			outFile << endl;
		}
	}
	void start(int* arr, int* v)
	{
		int low = 0;
		int high = n-1;
		psort(low, high, arr, v);

	}
	void psort(int l, int h, int* arr, int* v)
	{
			int max_idx = max_element(arr+l, arr + h+1) - arr; // arr안 max값 구하기
			for (int i = l; i < h+1; i++)
			{	
				if(i != max_idx){
					v[i] += 1;
				}
			}
			if (max_idx - l >1) {
				int lh = max_idx - 1; // high 재설정
				psort(l,lh,arr,v);// 왼쪽 루트
			}
			if (h - max_idx >1) {
				int rl = max_idx + 1; // low 설정
				psort(rl, h, arr, v);// 오른쪽 루트}
			}
	}
};
int main() {
	Permutation permutation("permutation.inp", "permutation.out");
	return 0;
}
