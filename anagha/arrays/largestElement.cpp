#include <iostream>
#include <vector>
using namespace std;

int findLargestElement(vector<int>&v, int n){
    int maxi = v[0];
    for(int i =1 ; i<n;i++){
        if(v[i] > maxi)maxi = v[i];
    }

    return maxi;
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

    cout<<findLargestElement(v, size);

    
    cout << endl;

    return 0;
}
