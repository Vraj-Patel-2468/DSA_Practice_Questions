#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& A, int l, int h) {
    int pivot = A[l], i=l+1, j=h;
    while (i <= j) {
        while (i <= j && A[i] <= pivot) i++;
        while (i <= j && A[j] > pivot) j--;
        if (i < j) {
            swap(A[i], A[j]);
        }
    }
    swap(A[l], A[j]);
    return j;
}

void QuickSort(vector<int>& A, int l, int h) {
    if (l < h) {
        int j = partition(A, l, h);
        QuickSort(A, l, j - 1);
        QuickSort(A, j + 1, h);
    }
}

int main() {
    vector<int> A({2, 3, 5, 3, 4, 9, 8, 11, 10, 0, -1});
    cout << "Old A : ";
    for (int i : A) 
        cout << i << ", ";
    cout << endl;
    QuickSort(A, 0, A.size() - 1);
    cout << "New A : ";
    for (int i : A)
        cout << i << ", ";
    cout << endl;    
    return 0;
}
