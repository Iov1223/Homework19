#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// ������ 1.
int maxDiv(int n, int m);
// ������ 2.
int  resurveNumber(int num);
// ������ 3.
void showArr(int arr[], int L);
int searchAndShow(int arr[], int L, int key);
// ������ 4.
void emptyArr(int arr[10][10], int r, int c, int x, int y);


int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int a, b;

	// ������ 1.
	cout << "\t������ 1.\n������� ��� �����: ";
	cin >> a >> b;
	cout << "������������ �������� ����� " << a << " � "  << b << " = " << maxDiv(a, b) << "\n\n";

	// ������ 2.
	cout << "\t������ 2.\n������� �����: ";
	cin >> a;
	cout << "���������� �����: " << resurveNumber(a) << "\n\n";

	// ������ 3.
	cout << "\t������ 3.\n����������� ������: ";
	const int L = 10;
	int array[L];
	for (int i = 0; i < L; i++)
		array[i] = rand() % 101;
	showArr(array, L);
	cout << "������� �����: ";
	cin >> a;
	cout << searchAndShow(array, L, a) << "\n\n";

	// ������ 4.
	cout << "\t������ 4.\n������� ������ � ����� ���������: ";
	cin >> a >> b;
	int mas[10][10];
	emptyArr(mas, 10, 10, a, b);

	return 0;
}

// ������ 4.
void emptyArr(int arr[10][10], int r, int c, int x, int y) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			arr[i][j] = rand() % ((y + 1) - x) + x;
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\n\n";
}

// ������ 3.
void showArr(int arr[], int L) {
	cout << "[";
	for (int i = 0; i < L; i++) {
		cout << arr[i] << ", ";
	}
	cout << "\b\b]\n";
}
int searchAndShow(int arr[], int L, int key) {
	int k;
	for (int i = 0; i < L; i++) {
		if (arr[i] == key) {
			k = i;
			break;
		}
	}
	for (int i = L - 1; i > 0; i--)
		for (int j = k + 1; j < i; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
	cout << "��������������� ������  ���� ��������� ������ �� " << key << ": [";
	for (int i = 0; i < L; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n������ ����� " << key << " � ������� = ";
	return k;
}

// ������ 2.
int  resurveNumber(int num) {
	int flipNumber = 0;
	while (num > 0) {
		flipNumber = flipNumber * 10 + num % 10;
		num /= 10;
	}
	return flipNumber;
}

// ������ 1.
int maxDiv(int n, int m) {
	for (int i = n; i > 0; i--) {
		for (int j = m; j > 0; j--)
			if (n % i == 0 && m % j == 0 && i == j)
				return i;
	}

}