int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

   while(low<high)
   {
    int mid=(high+low)/2;
    if(arr[mid]>=x){       //see if the element is just larger 
    //than x then the element that is lower bound will lie before the mid right,so set high as mid-1 to decrease the window
        ans=mid;
        high=mid-1;
    }
    else
    low=mid+1;
   }
    return ans;
}