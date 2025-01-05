#include <iostream>
#include <vector>
using namespace std;

bool linearSearch(vector<int>arr, int key){
    int n = arr.size();
    for(int i = 0; i< n-1; i++){
        if(arr[i] == key)
        return true;
    }
    return false;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> v(size);
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++)
        cin >> v[i];

    int key;
    cin>>key;
    cout<<linearSearch(v, key);

    
    cout << endl;

    return 0;
}
