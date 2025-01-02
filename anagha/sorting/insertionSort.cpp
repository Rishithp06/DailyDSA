#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        for(int i = 1; i< n ; i++){
            int j = i; 
            
            while(j > 0 && arr[j - 1] > arr[j]){
                
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
                j--;
            }
            
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

    insertionSort(v);

    cout << "After sorting: ";
    for (int i = 0; i < size; i++)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}
