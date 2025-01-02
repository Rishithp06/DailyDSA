#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int mpos = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[mpos]) {
                mpos = j;
            }
        }
        swap(arr[i], arr[mpos]); // Simplified swapping
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

    selectionSort(v, size);

    cout << "After sorting: ";
    for (int i = 0; i < size; i++)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}
