#include <iostream>
#include <vector>
using namespace std;

bool isArraySoretd(vector<int>arr, int n){
    for(int i = 0; i< n-1; i++){
        if(arr[i] < arr[i+1])
        continue;
        else 
        return false;
    }
    return true;
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
