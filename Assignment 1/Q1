#include <iostream>
using namespace std;

#define MAX 100

void createArray(int arr[], int &n) {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << endl << "Array created!";
}

void displayArray(int arr[], int n) {
    if (n == 0) {
        cout << "Array is empty!" << endl;
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement(int arr[], int &n) {
    if (n >= MAX) {
        cout << "Array is full, cannot insert!" << endl;
        return;
    }
    int pos, val;
    cout << "Enter position (1 to " << n + 1 << "): ";
    cin >> pos;
    if (pos < 1 || pos > n + 1) {
        cout << "Invalid position!" << endl;
        return;
    }
    cout << "Enter value: ";
    cin >> val;

    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = val;
    n++;
    cout << endl << "Value Inserted";
}

void deleteElement(int arr[], int &n) {
    if (n == 0) {
        cout << "Array is empty, cannot delete!" << endl;
        return;
    }
    int pos;
    cout << "Enter position (1 to " << n << "): ";
    cin >> pos;
    if (pos < 1 || pos > n) {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << endl << "Value Deleted";
}

void linearSearch(int arr[], int n) {
    if (n == 0) {
        cout << "Array is empty!" << endl;
        return;
    }
    int key;
    cout << "Enter value to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i + 1 << endl;
            return;
        }
    }
    cout << "Element not found!" << endl;
}

int main() {
    int arr[MAX], n = 0;
    int choice;

    while (choice != 6){
        cout << "\n---- MENU ----\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createArray(arr, n); break;
            case 2: displayArray(arr, n); break;
            case 3: insertElement(arr, n); break;
            case 4: deleteElement(arr, n); break;
            case 5: linearSearch(arr, n); break;
            case 6: cout << "Exiting program..." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } 
   

    return 0;
}