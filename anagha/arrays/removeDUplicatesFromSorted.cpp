#include <bits/stdc++.h>
#include <vector>
using namespace std;
//optimal approach using two pointers
int removeDuplicates(vector<int>arr, int n){
    int i = 0 ;

    for(int j = 1; j < n; j++){
        if(arr[i] != arr[j]){
            i++;
            arr[i] = arr[j];
        }
    }

    return i +1;
}

int removeDupl(vector<int>arr , int n){
    set<int>s;
    for(int i = 0; i < n; i++)
    s.insert(arr[i]);

    
}
int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> v(size);
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++)
        cin >> v[i];


    int k = removeDuplicates(v, size);

    
    cout << "After removing duplicates ";
    for (int i = 0; i < k; i++)
        cout << v[i];

    return 0;
}
