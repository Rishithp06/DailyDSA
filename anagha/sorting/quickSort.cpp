#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>arr, int low, int high){
    int pivot = arr[low];

    int i = low, j = high;

    while(i<j){
        while( arr[i] <= pivot && i <= high - 1){
            i++;
        }

        while( arr[j] >= pivot && j >= low + 1){
            j--;
        }

        if(i<j)
        swap(arr[i], arr[j]);
    }

    swap(arr[low],arr[j]);
    return j;
}

void quickSort(vector<int>&v, int low, int high){
    
    if(low >= high){
        int pInd = partition(arr,low,high);

        quickSort(arr,low,pInd-1);
        quickSort(arr,pInd+1,high);
    }
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

    quickSort(v, 0, size - 1);

    cout << "After sorting: ";
    for (int i = 0; i < size; i++)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}
