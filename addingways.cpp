#include<iostream>
#include<fstream>
#include<algorithm>

long long dp[302][22];


using namespace std;
class Add
{
private:
	ifstream readFile;
	ofstream outFile;
	int n,k;
public:
	Add(string read, string out)
	{
		init(read, out);
	}
	void init(const string& in, const string& out)
	{
		dp[1][1] = 1; dp[2][1] = 1; dp[2][2] = 1; dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;
		dp[4][1] = 1; dp[4][2] = 2; dp[4][3] = 1; dp[4][4] = 1; dp[5][1] = 1; dp[5][2] = 2;
		dp[5][3] = 2; dp[5][4] = 1; dp[5][5] = 1;

		for (int i = 6; i < 301; i++) {
			for (int j = 1; j < 21; j++) {
				if (i < j) {
					dp[i][j] = 0;
				}
				else if (i == j || j == 1) {
					dp[i][j] = 1;
				}
				else {
					dp[i][j] = (dp[i - 1][j - 1] + dp[i - j][j]);
				}
			}
		}
/*		for (int i = 1; i < 301; i++) {
			for (int j = 1; j < 21; j++) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		*/
		readFile.open(in);
		outFile.open(out);
		while (1) {
			readFile >> n >> k;
			if (n == 0 && k == 0) break;
			else {
				long long result = dp[n][k] % 1000000007;
				outFile << result << endl;
			}

		}
	}
};
int main() {
	Add add("addingways.inp", "addingways.out");
	return 0;
}
