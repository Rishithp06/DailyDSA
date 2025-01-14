#include <bits/stdc++.h>
#include <vector>
using namespace std;
//optimal approach using two pointers
void leftRotate(vector<int>&nums, int k){
    int n = nums.size();
    k = k % n;
    if (k == 0) return;
    reverse(nums.begin(),nums.end() - k);
    reverse(nums.end() - k, nums.end());
    reverse(nums.begin(), nums.end());
}

// void rightRotate(vector<int>&nums, int k){
//     int n = nums.size();
//     k = k % n;
//     if (k == 0) return;
//     reverse(nums.begin(),nums.end() - k);
//     reverse(nums.end() - k, nums.end());
//     reverse(nums.begin(), nums.end());
// }


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
