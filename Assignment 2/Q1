#include <iostream>
using namespace std;


int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  

        if (arr[mid] == key)
            return mid; 
        else if (arr[mid] < key)
            low = mid + 1; 
        else
            high = mid - 1; 
    }

    return -1; 
}

int main() {
    int n, key;

    cout << "Enter number of elements (sorted in ascending order): ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the key to search: ";
    cin >> key;

    int result = binarySearch(arr, n, key);

    if (result != -1)
        cout << "Key found at index " << result << " (position " << result + 1 << ")\n";
    else
        cout << "Key not found in the array.\n";

    return 0;
}
