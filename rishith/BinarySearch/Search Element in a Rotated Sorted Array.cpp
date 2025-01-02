array is rotated at some pivot point unknown to you. Find the index at which k is present and if k is not present return -1.



int search(vector<int>arr,int k,int n)
{
int low=0;
int high=n-1

while(low<=high)
{
    int mid=(low+high)/2;
    if (arr[mid] == k) return mid;
    if (arr[low] <= arr[mid]) //to chekc in left part
      {
        if(arr[low]<=k && arr[mid]>=k)
          {
            high=mid-1;     //then it exist in this part antha alva
          }
          else low=mid+1;
      }

    if(arr[mid]<=arr[high])  
    {
         if(arr[mid]<=k && arr[mid]>=k)
          {
            low=mid+1;     //then it exist in this part antha alva
          }
          else high=mid-1;
    }
}
return -1;

}