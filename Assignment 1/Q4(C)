#include <iostream>
using namespace std;

const int imax = 100;

void transpose(int arr[][imax], int r, int c) {
    int t[imax][imax]; 

    
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            t[i][j] = arr[j][i];
        }
    }

    
    cout << "\nTranspose of the matrix:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << t[i][j] << " ";
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
    int r, c;
    cout << "Enter number of rows: ";
    cin >> r;
    cout << "Enter number of columns: ";
    cin >> c;

    if (r > imax || c > imax) {
        cout << "Matrix size exceeds limit of " << imax << "x" << imax << ".";
        return 1;
    }

    int arr[imax][imax]; 

    create(arr, r, c);
    transpose(arr, r, c);

    return 0;
}

