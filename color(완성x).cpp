#include<iostream>
#include<fstream>
#include<algorithm>

int dp[1005][1005];

using namespace std;
class Color
{
private:
	ifstream readFile;
	ofstream outFile;
	int testcase;
	
public:
	Color(string read, string out)
	{
		init(read, out);
	}
	void init(const string& in, const string& out)
	{	
		readFile.open(in);
		outFile.open(out);
		readFile >> testcase;
		for (int t = 0; t < testcase; t++) {
			string s1, s2;
			readFile >> s1 >> s2;
			cout << s1 << endl << s2 << endl;
		}
	}
};
int main() {
	Color color("1.txt", "color.out");
	return 0;
}
