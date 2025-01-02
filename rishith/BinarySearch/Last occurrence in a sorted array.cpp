Given a sorted array of N integers, write a program to find the index of the last occurrence of the target key. If the target is not found then return -1.


int solve(int n, int key, vector < int > & arr) {
  int low = 0;
  int high = n - 1;
  int res = -1;

  while(low<=high)
  {
    int mid=(low+high)/2
        if(arr[mid]==key)
        {
            res=mid;   //the element may or maynot be last occurance but for now store it as result.
            low=mid+1;           //since its sorted , the element repeating will come after it so shift the low pointer
                       //if it doesnt come after the element it means there isnt one and res=mid will be valid
        }

        else if(arr[mid]<key)
        {
            low=mid+1;
        }
        else high=mid-1;

  }
}
Time Complexity: O(log n)

Space Complexity: O(1)

