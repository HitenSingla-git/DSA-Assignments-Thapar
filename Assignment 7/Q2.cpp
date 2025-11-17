#include <iostream>
#include <vector>
using namespace std;

void improvedSelectionSort(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int minIndex = left;
        int maxIndex = left;


        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

       
        swap(arr[left], arr[minIndex]);

        if (maxIndex == left)
            maxIndex = minIndex;
      
        swap(arr[right], arr[maxIndex]);

        left++;
        right--;
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11, 90};

    improvedSelectionSort(arr);

    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
