class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size();
        int mid;
        if(target>nums[high-1]){  If target is greater than the last element, return the array size.
}
            return high;
        }
        while(low<=high){
              mid=(low+high)/2;
            if(nums[mid]==target){  
                return mid;
            }
          
            if(target<nums[mid]){     
            high=mid-1;    
            }else{
            low=mid+1;        
            }
          
        }
         return  low;   
    }
};





Steps to Solve the Problem
Initialization: Start with two pointers, low = 0 and high = size of array.

Early Exit Check: If the target is greater than the largest element in the array, return high (the array size).

Binary Search Loop: While low <= high, calculate the middle index as mid = (low + high) / 2.

Check Target Match: If nums[mid] == target, return mid (target found).

Narrow Search Range:

If nums[mid] > target, set high = mid - 1 (search left half).
If nums[mid] < target, set low = mid + 1 (search right half).
Exit Condition: The loop stops when low > high.

Return Insertion Point: When the loop ends, low points to the correct index to insert the target.

Efficiency: Binary search ensures 
𝑂
(
log
⁡
𝑛
)
O(logn) time complexity.

Handles Edge Cases: Works for empty arrays, single-element arrays, and out-of-range targets.

Output: Either the target index (if found) or the index where it should be inserted to maintain sorted order.