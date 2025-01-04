#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high) {
        // code here
        vector<int>temp;

        int left = low;
        int right = mid + 1;

        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }

        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }

        while(right <= mid){
            temp.push_back(arr[right]);
            right++;
        }

        cout << "After sorting: ";
        for (int i = 0; i < arr.size(); i++)
            cout << temp[i] << " ";
        cout << endl;
        }

void mergeSort(vector<int>v, int low, int high){

    if(left >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(v,low,mid);
    mergeSort(v,mid+1,high);

    merge(v,low,mid,high);
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

    mergeSort(v, 0, size);

    

    return 0;
}
