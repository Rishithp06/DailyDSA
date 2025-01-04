class Solution {
public:

    int countit(vector<int>&arr,int mid)
    {
        int n=arr.size();
        int number=1;  
        int subsum=0;
        for(int i=0;i<n;i++)
        {
            if(subsum+arr[i]<=mid)
            subsum=subsum+arr[i];

            else{
                number++;
                subsum=arr[i];
            }
        }
        return number;
    }
//check painter partition , explained there properly
    int splitArray(vector<int>& arr, int k) {
        int n=arr.size();
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);

        while(low<=high)
        {
            int mid=(low+high)/2;
            int validsum=countit(arr,mid);
            if(validsum>k)
            {
                low=mid+1;
            }
            else high=mid-1;
        }
        return low;
    }
};