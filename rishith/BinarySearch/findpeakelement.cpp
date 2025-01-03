class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n=arr.size();
        if(n==1)return 0; // single element andre ade peak
        if(arr[0]>arr[1])return 0; //first element is bigger than next one but adru hinde iro element doesnt exist but still exists
        if(arr[n-1]>arr[n-2])return n-1;//if last element is greater than last but one its peak because adu admele yavdu irolla

        int low=1;//this is because first element is checked so l=1
        int high=n-2;//this is because last element is checked so h=n-2

        while(low<=high)
        {
            int mid=(low+high)/2;

            if(arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1])
            return mid;

            if(arr[mid]>arr[mid-1])//means one part is sorted that is previous element,we gotta check for next element so update low and check in right half
            low=mid+1;

            else //means mid>mid+1 , so search in left part now
            high=mid-1;
        }
        return -1;
    }
};