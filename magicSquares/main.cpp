#include <iostream>
#include <cmath>
using namespace std;

const int SIZE = 3;

// Function prototypes
void inputMagicSq(int[SIZE][SIZE], int);
void showArray(int[SIZE][SIZE], int);
bool isMagicSquare(int[SIZE][SIZE]);

int main() {

	int array[SIZE][SIZE];

	cout << "A magic square is an n x n square matrix of distinct numbers that range from 1 to n^2.\n";
	cout << "This program determines if a matrix is a magic square.\n\n";

	// Prompt user to enter elements into matrix
	cout << "Enter the elements of a 3x3 square: \n";
	inputMagicSq(array, SIZE);
	cout << endl;

	// Display elements entered
	cout << "You entered: \n";
	showArray(array, SIZE);
	cout << endl;
	
	// Check if the square is magic
	bool magic = isMagicSquare(array);

	if (magic)
		cout << "The square is magic.\n";
	else
		cout << "The square is not magic.\n";

	system("pause");
	return 0;
}

void inputMagicSq(int A[SIZE][SIZE], int) {
	for (int row = 0; row < SIZE; row++)
		for (int col = 0; col < SIZE; col++) {
			do {
				cout << "Item at (" << row << ", " << col << "): ";
				cin >> A[row][col];
				if (A[row][col] > pow(SIZE, 2)) {
					cout << "An element cannot be greater than n^2, please enter another number.\n";
				}
			}  while (A[row][col] > pow(SIZE, 2));
		}
}

void showArray(int A[SIZE][SIZE], int) {
	for (int row = 0; row < SIZE; row++) {
		for (int col = 0; col < SIZE; col++) {
			cout << A[row][col] << "\t";
		}
		cout << "\n";
	}
}

bool isMagicSquare(int A[SIZE][SIZE]) {
	int	sum1 = 0, sum2 = 0, sum3 = 0;

	// Check column sums
	for (int row = 0; row < SIZE; row++) {
		// Check each column
		if (row == 0)
			sum1 = A[row][0] + A[row][1] + A[row][2];
		if (row == 1)
			sum2 = A[row][0] + A[row][1] + A[row][2];
		if (row == 2)
			sum3 = A[row][0] + A[row][1] + A[row][2];
	}

	if (!(sum1 == sum2 && sum2 == sum3))
		return	false;

	//	Reinitialize sums to check row sums
	sum1 = sum2 = sum3 = 0;

	// Check row sums
	for (int col = 0; col < SIZE; col++) {
		// Check each row
		if (col == 0)
			sum1 = A[0][col] + A[1][col] + A[2][col];
		if (col == 1)
			sum2 = A[0][col] + A[1][col] + A[2][col];
		if (col == 2)
			sum3 = A[0][col] + A[1][col] + A[2][col];
	}

	if (!(sum1 == sum2 && sum2 == sum3))
		return	false;

	//	Compute the diagonal sums
	sum1 = A[0][0] + A[1][1] + A[2][2];		//	Right	diagonal
	sum2 = A[0][2] + A[1][1] + A[2][0];		//	Left	diagonal

	if (!(sum1 == sum2 && sum2 == sum3))	// sum3 still holds the value the diagonals should equal
		return	false;

	return	true;
}