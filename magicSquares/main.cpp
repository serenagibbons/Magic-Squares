#include <iostream>
using namespace std;

const int SIZE = 3;
void inputMagicSq(int[][SIZE], int);

int main() {

	int array[SIZE][SIZE];

	cout << "Enter the elements of a 3x3 square: \n";
	inputMagicSq(array, SIZE);
	
	system("pause");
	return 0;
}

void inputMagicSq(int arr[SIZE][SIZE], int) {
	for (int row = 0; row < SIZE; row++)
		for (int col = 0; col < SIZE; col++) {
			cout << "Item at (" << row << ", " << col << "): ";
			cin >> arr[row][col];
		}
}