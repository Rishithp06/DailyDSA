#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>&v, int n){
    for(int i =0 ; i<n;i++){
        for(int j =0 ; j<n-1-i; j++){
            if(v[j] > v[j+1]){
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}

void bubbleSortRecursive(vector<int>arr, int n){
    if(n == 1) return;
    int didSwap = 0;
    for(int j = 0; j<= n-2; j++){
        if(arr[j] >= arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }

    if(didSwap == 0)return;
    bubbleSortRecursive(arr, n-1);
    
}
int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> v(size);
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++)
        cin >> v[i];

    cout << "Before sorting: ";
    for (int i = 0; i < size; i++)
        cout << v[i] << " ";
    cout << endl;

    bubbleSort(v, size);

    cout << "After sorting: ";
    for (int i = 0; i < size; i++)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}
