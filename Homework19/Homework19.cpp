#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// Задача 1.
int maxDiv(int n, int m);
// Задача 2.
int  resurveNumber(int num);
// Задача 3.
void showArr(int arr[], int L);
int searchAndShow(int arr[], int L, int key);
// Задача 4.
void emptyArr(int arr[10][10], int r, int c, int x, int y);


int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int a, b;

	// Задача 1.
	cout << "\tЗадача 1.\nВведите два числа: ";
	cin >> a >> b;
	cout << "Максимальный делитель чисел " << a << " и "  << b << " = " << maxDiv(a, b) << "\n\n";

	// Задача 2.
	cout << "\tЗадача 2.\nВведите число: ";
	cin >> a;
	cout << "Отраженное число: " << resurveNumber(a) << "\n\n";

	// Задача 3.
	cout << "\tЗадача 3.\nИзначальный массив: ";
	const int L = 10;
	int array[L];
	for (int i = 0; i < L; i++)
		array[i] = rand() % 101;
	showArr(array, L);
	cout << "Введите число: ";
	cin >> a;
	cout << searchAndShow(array, L, a) << "\n\n";

	// Задача 4.
	cout << "\tЗадача 4.\nВведите начало и конец диапазона: ";
	cin >> a >> b;
	int mas[10][10];
	emptyArr(mas, 10, 10, a, b);

	return 0;
}

// Задача 4.
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

// Задача 3.
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
	cout << "Отсортированный массив  всех элементов справа от " << key << ": [";
	for (int i = 0; i < L; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\nИндекс числа " << key << " в массиве = ";
	return k;
}

// Задача 2.
int  resurveNumber(int num) {
	int flipNumber = 0;
	while (num > 0) {
		flipNumber = flipNumber * 10 + num % 10;
		num /= 10;
	}
	return flipNumber;
}

// Задача 1.
int maxDiv(int n, int m) {
	for (int i = n; i > 0; i--) {
		for (int j = m; j > 0; j--)
			if (n % i == 0 && m % j == 0 && i == j)
				return i;
	}

}