#include <iostream>
#include <fstream>

using namespace std;



class Spinslide
{
private:
	ifstream readFile;
	ofstream outFile;
	int count{ 0 }; // �� �׽�Ʈ ��
	int side{ 0 }; // �� ���� ũ��
	int spinslide{ 0 }; // spinslide Ƚ��
public:
	Spinslide(string read, string out)
	{
		init(read, out);
	}

	void init(const string& in, const string& out)
	{
		readFile.open(in);
		outFile.open(out);
		readFile >> count; // �� �׽�Ʈ ��
		for (int i = 0; i < count; i++) {
			readFile >> side; // �� ���� ũ��
			readFile >> spinslide; // spinslide Ƚ��
			outFile << "Case #" << i + 1 << ":" << endl;

			// 2���� �迭 �����Ҵ�
			char** arr = new char* [side];
			for (int i = 0; i < side; i++) {
				arr[i] = new char[side];
			}
			for (int i = 0; i < side; i++) {
				for (int j = 0; j < side; j++) {
					readFile >> arr[i][j];
				}
			}
			for (int k = 0; k < spinslide; k++) {
				// �ӽ� 2���� �迭 �����Ҵ�
				char** temp_arr = new char* [side];
				for (int i = 0; i < side; i++) {
					temp_arr[i] = new char[side];
				}
				// spin
				for (int i = 0; i < side; i++) {
					for (int j = 0; j < side; j++) {
						temp_arr[i][j] = arr[side - j - 1][i];
					}
				}
				// temp_arr�� arr�� ����
				for (int i = 0; i < side; i++) {
					for (int j = 0; j < side; j++) {
						arr[i][j] = temp_arr[i][j];
					}
				}
				// slide
				for (int i = 0; i < side; i++) {
					int c{ 0 };
					for (int j = side - 1; j >= 0; j--) {
						if ('.' == arr[j][i]) {
							c++;
						}
						else if(c>=1 && '.'!= arr[j][i]) {
							arr[j + c][i] = arr[j][i];
							arr[j][i] = '.';
						}
					}
				}
			}
			for (int i = 0; i < side; i++) {
				for (int j = 0; j < side; j++) {
					outFile << arr[i][j];
				}
				outFile << endl;
			}
			outFile << endl;
		}
	}

};

int main() {
	Spinslide ss("spinslide.inp", "spinslide.out");
	return 0;
}