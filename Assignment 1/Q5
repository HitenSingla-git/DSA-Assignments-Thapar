#include <iostream>
using namespace std;

const int imax = 100;

void create(int arr[][imax], int r, int c) {
    cout << "Enter matrix elements (" << r << "x" << c << "):\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }
}

void sumRows(int arr[][imax], int rows, int cols) {
    cout << "\nSum of each row:\n";
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += arr[i][j];
        }
        cout << "Row " << i + 1 << " sum = " << rowSum << endl;
    }
}

void sumCols(int arr[][imax], int rows, int cols) {
    cout << "\nSum of each column:\n";
    for (int j = 0; j < cols; j++) {
        int colSum = 0;
        for (int i = 0; i < rows; i++) {
            colSum += arr[i][j];
        }
        cout << "Column " << j + 1 << " sum = " << colSum << endl;
    }
}

int main() {
    int rows, cols;
    int arr[imax][imax];

    cout << "Enter number of rows (max " << imax << "): ";
    cin >> rows;
    cout << "Enter number of columns (max " << imax << "): ";
    cin >> cols;

    if (rows > imax || cols > imax || rows <= 0 || cols <= 0) {
        cout << "Invalid matrix size. Please use values between 1 and " << imax << ".\n";
        return 1;
    }

    create(arr, rows, cols);
    sumRows(arr, rows, cols);
    sumCols(arr, rows, cols);

    return 0;
}