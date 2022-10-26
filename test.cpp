#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector> // ���� ����� ���� �������
#include<string> // ���� ���ڿ� ã�� ���� ������� find()
#include<map>

using namespace std;

struct datas {
	int num;
	string first;
	string last;
};

map<string, int> m1;

class Test
{
private:
	ifstream readFile;
	ofstream outFile;
	vector<datas> input;
	vector<string> last_names;
	int count{ 0 }; // �� �ο���
	string long_name;
	string allofname;
public:
	Test(string read, string out)
	{
		init(read, out);
	}

	static bool cmp1(const datas& x, const datas& y) { // static ����Ͽ� sort �����ε� ���� ����
		return x.num < y.num;
	}

	void init(const string& in, const string& out)
	{
		readFile.open(in);
		outFile.open(out);
		readFile >> count;
		input.resize(count); // count��ŭ vector ������¡;
		for (int i = 0; i < count; ++i) {
			datas data;
			readFile >> data.num;
			readFile >> data.first;
			readFile >> data.last;
			if (long_name.length() < data.first.length()) {
				long_name = data.first;
			}
			/*
						outFile.width(5);
						outFile.fill('0');
						outFile << right << data.num << " ";
						outFile << data.first << " ";
						outFile << data.last << " " << endl;
			*/
			input[i] = data;
		}
	}
	void start() {
		cout << endl;
		sort(input.begin(), input.end(), cmp1); // vector<����ü>�̹Ƿ� cmp ���Լ� ���

		for (int i = 0; i < count; ++i) {
			allofname = allofname + input[i].last + " ";
			outFile.width(5);
			outFile.fill('0');
			outFile << right << input[i].num << " ";
			outFile.width(long_name.length());
			outFile.fill(' ');
			outFile << left << input[i].first << " ";
			outFile << input[i].last << endl;

		}
		for (int j = 0; j < count; j++) {
			int a = 0;
			int pos = 0;
			
			while (allofname.find(input[j].last, pos) != string::npos) {
				++a;
				pos = allofname.find(input[j].last, pos) + input[j].last.length();	// ã�� �Ŀ� ���� Ž�� ���� ��ġ�� ���ϱ� ���� ã�� '����(��)�� ��ġ + ����(��) ����'�� ���Ѵ�.

			}
			if (a > 1) {
				m1.insert(make_pair(input[j].last, a));
			}
		//if(find(r_num.begin(),r_num.end(),r_n.last))
		//	cout << r_n.last << " " << r_n.count << endl;
			
		}
		outFile << endl;
		for (auto iter = m1.begin(); iter != m1.end(); iter++) {
			outFile << iter->first << " " << iter->second << endl;
		}
	}

};

int main() {
	Test test("1.inp", "1.out");
	test.start();
	return 0;
}