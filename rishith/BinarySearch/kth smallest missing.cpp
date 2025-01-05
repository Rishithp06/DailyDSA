Problem Statement: You are given a strictly increasing array ‘vec’ and a positive integer 'k'. 
Find the 'kth' positive integer missing from 'vec'.

Example 1:
Input Format:
 vec[]={4,7,9,10}, k = 1
Result:
 1
Explanation:
 The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on. Since 'k' is 1, the first missing element is 1.

 
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();

        int low=0;
        int high=n-1;

        while(low<=high){
            int mid=(low+high)/2;

            int missing=arr[mid]-mid-1;

            if(missing<k)
            {
                low=mid+1;
            }
            else high=mid-1;
        }
        return k+high+1;  //after all iterations the high will point to
                          //number in the range ala , so k+high+1 will give
                          //that number.
    }
};