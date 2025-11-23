#include <iostream>
using namespace std;

int heapArr[50];
int heapSize = 0;

void heapifyUp(int i) {
    while (i > 0 && heapArr[(i-1)/2] < heapArr[i]) {
        int t = heapArr[i];
        heapArr[i] = heapArr[(i-1)/2];
        heapArr[(i-1)/2] = t;
        i = (i-1)/2;
    }
}

void heapifyDown(int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < heapSize && heapArr[l] > heapArr[largest]) largest = l;
    if (r < heapSize && heapArr[r] > heapArr[largest]) largest = r;

    if (largest != i) {
        int t = heapArr[i];
        heapArr[i] = heapArr[largest];
        heapArr[largest] = t;
        heapifyDown(largest);
    }
}

void insertKey(int x) {
    heapArr[heapSize] = x;
    heapifyUp(heapSize);
    heapSize++;
}

int getMax() {
    if (heapSize == 0) return -1;
    return heapArr[0];
}

int deleteMax() {
    if (heapSize == 0) return -1;
    int max = heapArr[0];
    heapArr[0] = heapArr[heapSize - 1];
    heapSize--;
    heapifyDown(0);
    return max;
}

void display() {
    for (int i = 0; i < heapSize; i++) cout << heapArr[i] << " ";
    cout << endl;
}

int main() {
    int ch, x;
    while (1) {
        cin >> ch;
        if (ch == 1) {
            cin >> x;
            insertKey(x);
        } else if (ch == 2) {
            cout << getMax() << endl;
        } else if (ch == 3) {
            cout << deleteMax() << endl;
        } else if (ch == 4) {
            display();
        } else break;
    }
}
