#include <iostream>
#include <vector>
using namespace std;

void shellSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            
            arr[j] = temp;
        }
    }
}

int main() {
    vector<int> arr = {9, 5, 1, 4, 3, 2, 8, 7, 6};
    
    cout << "Vetor original: ";
    for (int num : arr) {
        cout << num << " ";
    }
    
    shellSort(arr);
    
    cout << "\nVetor ordenado: ";
    for (int num : arr) {
        cout << num << " ";
    }
    
    cout << endl;
    
    return 0;
}