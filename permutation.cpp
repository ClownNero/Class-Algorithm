#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

class Permutation
{
private:
	ifstream readFile;
	ofstream outFile;
	int testcase; // �׽�Ʈ���̽� ����
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
		readFile >> testcase; // �׽�Ʈ���̽� ����
		for (int i = 0; i < testcase; i++)
		{
			readFile >> n;
			int* arr = new int[n]; // ���� 1���� �迭 ����
			int* v = new int[n] {0}; // ���� ���� ������ �迭
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
			int max_idx = max_element(arr+l, arr + h+1) - arr; // arr�� max�� ���ϱ�
			for (int i = l; i < h+1; i++)
			{	
				if(i != max_idx){
					v[i] += 1;
				}
			}
			if (max_idx - l >1) {
				int lh = max_idx - 1; // high �缳��
				psort(l,lh,arr,v);// ���� ��Ʈ
			}
			if (h - max_idx >1) {
				int rl = max_idx + 1; // low ����
				psort(rl, h, arr, v);// ������ ��Ʈ}
			}
	}
};
int main() {
	Permutation permutation("permutation.inp", "permutation.out");
	return 0;
}
