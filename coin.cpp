#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

class Coin
{
private:
	ifstream readFile;
	ofstream outFile;
	int gamecase;
	int a, b, c;

public:
	Coin(string read, string out)
	{
		init(read, out);
	}
	void init(const string& in, const string& out)
	{
		readFile.open(in);
		outFile.open(out);
		readFile >> gamecase; // game ¼ö
		for (int i = 0; i < gamecase; i++)
		{
			readFile >> a >> b >> c; // a , b, c
			start(a, b, c);
		}
	}
	void start(int a, int b, int c) {
		cout << "(" << a << " " << b << " " << c << ") " << " : ";
		outFile << "(" << a << " " << b << " " << c << ") : ";
		a = a % 4;
		b = b % 4;
		c = c % 4;
		int two1=0;
		if (a == 2) two1++;
		if (b == 2) two1++;
		if (c == 2) two1++;
		if (a == 1 && b == 1 && c == 1 || a + b + c ==1) {
			cout << "-1"<< endl;
			outFile << "-1" << endl;
		}
		else if (two1 == 2 && a + b + c == 4 || two1 ==1 && a+b+c ==6 || two1 == 0 && a+b+c==6) {
			cout << "-1" << endl;
			outFile << "-1" << endl;
		}
		else {
			cout << "1" << endl;
			outFile << "1" << endl;
		}
	}
};

int main() {
	Coin coin("coin.inp", "coin.out");
	return 0;
}