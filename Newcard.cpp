#include<iostream>
#include<fstream>
#include<algorithm>

int dp[1005][1005];

using namespace std;
class Card
{
private:
	ifstream readFile;
	ofstream outFile;
	int testcase, cnt;
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
		for (int t = 0; t < testcase; t++) {
			int *arr = new int[cnt];
			readFile >> cnt;
			for (int i = 0; i < cnt; i++) {
				readFile >> arr[i];
			}
			int back = cnt - 1;
			Play(0, back, 1, arr);
			outFile << dp[0][back] << endl;
			for (int i = 0; i <  cnt; i++) {
				for (int j = 0; j < cnt; j++) {
					dp[i][j] = 0;
				}
			}
		}
	}
	int Play(int front, int back, int num,int *arr) {
		int fresult, bresult;
		if (front > back) {
			return 0;
		}
		if (dp[front][back] > 0) {
			return dp[front][back];
		}
		if (num % 2) { // Alice 차례 점수가 더 높은 카드를 갖고 감으로써 점수를 최대로 하는 플레이를 해야 함
			fresult = arr[front] + Play(front + 1, back, num + 1, arr);
			bresult = arr[back] + Play(front, back - 1, num + 1, arr);
			if (fresult >= bresult) {
				return dp[front][back] = fresult;
			}
			else {
				return dp[front][back] = bresult;
			}
		}
		else { // computer차례 점수를 최소로 하는 플레이를 해야 함
			fresult = Play(front + 1, back, num + 1, arr);
			bresult = Play(front, back - 1, num + 1, arr);
			if (fresult < bresult) {
				return dp[front][back] = fresult;
			}
			else {
				return dp[front][back] = bresult;
			}
		}
			
	}
};
int main() {
	Card card("card.inp", "card.out");
	return 0;
}
