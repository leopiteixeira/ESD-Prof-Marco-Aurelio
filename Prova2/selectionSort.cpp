#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        swap(arr[minIndex], arr[i]);
    }
}

int main() {
    vector<int> arr = {9, 5, 1, 4, 3, 2, 8, 7, 6};
    
    cout << "Vetor original: ";
    for (int num : arr) {
        cout << num << " ";
    }
    
    selectionSort(arr);
    
    cout << "\nVetor ordenado: ";
    for (int num : arr) {
        cout << num << " ";
    }
    
    cout << endl;
    
    return 0;
}