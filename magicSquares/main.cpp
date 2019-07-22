#include <iostream>
using namespace std;

const int SIZE = 3;


void inputMagicSq(int[SIZE][SIZE], int);
void showArray(int[SIZE][SIZE], int);

int main() {

	int array[SIZE][SIZE];

	// Prompt user to enter elements into matrix
	cout << "Enter the elements of a 3x3 square: \n";
	inputMagicSq(array, SIZE);

	// Display elements entered
	cout << "You entered: \n";
	showArray(array, SIZE);
	
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

void showArray(int arr[SIZE][SIZE], int) {
	for (int row = 0; row < SIZE; row++) {
		for (int col = 0; col < SIZE; col++) {
			cout << arr[row][col] << "\t";
		}
		cout << "\n";
	}
}
