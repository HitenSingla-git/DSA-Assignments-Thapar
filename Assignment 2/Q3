#include <iostream>
using namespace std;

int findMissing(int arr[], int n) {
    int left = 0, right = n - 1;
    int start = arr[0];

    while (left <= right) {
        int mid = left + (right - left) / 2;

        
        int expected = start + mid;

        if (arr[mid] == expected) {
            
            left = mid + 1;
        } else {
            
            right = mid - 1;
        }
    }

    
    return start + left;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8};  
    int n = sizeof(arr) / sizeof(arr[0]);

    int missing = findMissing(arr, n);
    cout << "Missing number is: " << missing << endl;

    return 0;
}
