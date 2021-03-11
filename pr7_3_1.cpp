#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
int Part1_Plus(int** a, const int rowCount, const int colCount, int& count);
void Part2_Null(int** a, const int rowCount, const int colCount);
int main() {
	srand((unsigned)time(NULL));
	int Low = -21;
	int High = 24;
	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++) {
		a[i] = new int[colCount];
	}
	// Create(a, rowCount, colCount, Low, High);
	Input(a, rowCount, colCount);
	Print(a, rowCount, colCount);
	int count = 0;
	Part1_Plus(a, rowCount, colCount, count);
	Part2_Null(a, rowCount, colCount);
	cout << endl;
	for (int i = 0; i < rowCount; i++) {
		delete[] a[i];
	}
	delete[] a;
	return 0;
}
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			a[i][j] = Low + rand() % (High - Low + 1);
		}
	}
}
void Input(int** a, const int rowCount, const int colCount) {
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
		cout << endl;
	}
}
void Print(int** a, const int rowCount, const int colCount) {
	cout << endl;
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
int Part1_Plus(int** a, const int rowCount, const int colCount, int& count) {
	int result = rowCount;
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			if (a[i][j] > 0) {
				if (i < result) {
					result = i;
				}
			}
		}
	}
	cout << result;
	cout << endl;
	cout << endl;
	return result;
}

void Part2_Null(int** a, const int rowCount, const int colCount) {
	for (int n = 0; n < rowCount; n++) {
		int prom = 0;
		for (int k = 0; k < colCount; k++) {
			if (!a[n][k] == 0) {
				break;
			}
			else {
				prom++;
				if (prom == rowCount) {
					delete[] a[n];
					int** tmp = new int* [rowCount - 1];
					int tmpI = 0;
					for (int i = 0; i < rowCount; ++i)
						if (i != n)
							tmp[tmpI++] = a[i];
					delete[] a;
					a = tmp;
					cout << "Array after deleting " << n << "-th row\n";
					cout << endl;
					for (int i = 0; i < rowCount; i++) {
						for (int j = 0; j < colCount; j++)
							cout << setw(4) << a[i][j];
						cout << endl;
					}
					cout << endl;
				}
			}
		}
	}
	for (int k = 0; k < colCount; k++) {
		int prom = 0;
		for (int n = 0; n < rowCount; n++) {
			if (!a[n][k] == 0) {
				break;
			}
			else {
				prom++;
				if (prom == colCount) {

				}
			}
		}
	}
}