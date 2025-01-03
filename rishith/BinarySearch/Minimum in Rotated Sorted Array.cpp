int findMin(vector<int>& arr)
{
   int n=arr.size();
   int low=0;
   int high=n-1;
   int ans=INT_MAX;

   while(low<=high)
   {
     int mid=(low+high)/2;

     if(arr[low]<=arr[mid]) //if left part is roatted arrray is truly sorted or not
     {
        ans=min(ans,arr[low]); //if it is sorted then first most element that is low is the least so keep the min as ans
        low=mid+1;
     }
     else { //checks if the rifght or the seoconod half is truly sorted
        ans=min(ans,arr[mid]);   //if the second part is truly sorted then the last element in the econd half is always the mid 
     }
   }
   return ans;
}