class Solution {
public:

    int findmax(vector<int>& arr) {
        int maxi = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            maxi = max(arr[i], maxi);
        }
        return maxi;
    }

     long long tothours(vector<int>& arr, int hourly) {
        long long tothour = 0; // Use long long to prevent overflow
        for (int i = 0; i < arr.size(); i++) {
            tothour =tothour+ (arr[i] + hourly - 1) / hourly; 
        }
        return tothour;
    }

    int minEatingSpeed(vector<int>& arr, int h) {
        int low = 1;                      // Start from 1, as speed cannot be 0
        int high = findmax(arr);          // The maximum speed needed is the size of the largest pile

        while (low <= high) {
            int mid = (low + high) / 2;   // Calculate the mid speed
            long long totalH = tothours(arr, mid); //if you take mid speed , then how much hours antha
            //from above you get totalh, now compare it in range ashte
            if (totalH <= h) {
                high = mid - 1;           // Try a smaller speed
            } else {
                low = mid + 1;            // Try a larger speed
            }
        }
        return low;                       // Minimum valid speed
    }
};
