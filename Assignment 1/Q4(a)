#include <iostream>
using namespace std;

void rev_array(int arr[],int n){

    for (int i = 0,j = n-1; i < n/2; i++,j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

    }
}
void display(int arr[], int n){
    for (int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    rev_array(arr,n);
    display (arr,n);
}