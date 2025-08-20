#include <iostream>
using namespace std;

const int imax = 100;

void matrix_multiply(int arr[][imax], int brr[][imax], int r1, int r2, int c1, int c2) {
    if (c1 != r2) {
        cout << "Multiplication not possible\n";
        return;
    }

    int res[imax][imax] = {0}; 

    
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                res[i][j] += arr[i][k] * brr[k][j];
            }
        }
    }

    
    cout << "\nResult of matrix multiplication:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

void create(int arr[][imax], int r, int c) {
    cout << "Enter matrix elements (" << r << "x" << c << "):\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }
}

int main() {
    int r1, r2, c1, c2;

    cout << "Enter rows for first matrix: ";
    cin >> r1;
    cout << "Enter columns for first matrix: ";
    cin >> c1;

    int arr[imax][imax];

    create(arr, r1, c1);

    cout << "Enter rows for second matrix: ";
    cin >> r2;
    cout << "Enter columns for second matrix: ";
    cin >> c2;

    int brr[imax][imax];

    create(brr, r2, c2);

    matrix_multiply(arr, brr, r1, r2, c1, c2);

    return 0;
}