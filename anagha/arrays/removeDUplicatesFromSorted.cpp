#include <bits/stdc++.h>
#include <vector>
using namespace std;

void removeDuplicates(vector<int>&arr, int n){
    int k = 0;
    set<int>s;

    for(int i =0; i< n; i++)
    s.insert(arr[i]);

    for(int )
}
int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> v(size);
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++)
        cin >> v[i];


    cout<<isArraySoretd(v, size);

    
    cout << endl;

    return 0;
}
