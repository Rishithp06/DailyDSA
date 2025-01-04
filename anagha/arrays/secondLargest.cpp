#include <iostream>
#include <vector>
using namespace std;

int getSecondLargest(vector<int> &arr) {
        // Code Here
        
        int maxi = INT_MIN;
        int sec_max = INT_MIN;
        int n= arr.size();
        
        if(n < 2 )return -1;
        for(int i = 0; i< n; i++){
            if(arr[i] > maxi)
            {
                sec_max = maxi;
                maxi = arr[i];
            }
            else if(arr[i] > sec_max && arr[i] != maxi){
                sec_max = arr[i];
            }
        }
        
        if (sec_max == INT_MIN) return -1;

        return sec_max;
}


int getSecondSmallest(vector<int> &arr) {
        // Code Here
        int mini = INT_MAX;
        int sec_min = INT_MAX;
        int n= arr.size();
        
        if(n < 2 )return -1;
        for(int i = 0; i< n; i++){
            if(arr[i] < mini)
            {
                sec_min = mini;
                mini = arr[i];
            }
            else if(arr[i] < sec_mini && arr[i] != mini){
                sec_mini = arr[i];
            }
        }
        
        if (sec_mini == INT_MAX) return -1;

        return sec_max;
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

    cout<<getSecondLargest(v);

    
    cout << endl;

    return 0;
}
