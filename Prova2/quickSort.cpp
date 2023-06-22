#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i + 1], arr[high]);
    
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main() {
    vector<int> arr = {9, 5, 1, 4, 3, 2, 8, 7, 6};
    
    cout << "Vetor original: ";
    for (int num : arr) {
        cout << num << " ";
    }
    
    quickSort(arr, 0, arr.size() - 1);
    
    cout << "\nVetor ordenado: ";
    for (int num : arr) {
		cout << num << " ";
    }
    
    cout << endl;
    
    return 0;
}