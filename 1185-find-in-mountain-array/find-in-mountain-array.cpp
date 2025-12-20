/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int findLeft(int target , MountainArray &mountainArr , int low , int high){
        while(low <= high){
            int mid = low + ((high - low) / 2);

            if(mountainArr.get(mid) == target) return mid;
            else if(target > mountainArr.get(mid)) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }

    int findRight(int target , MountainArray &mountainArr, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = mountainArr.get(mid);
            if (val == target) return mid;
            else if (val > target) low = mid + 1; 
            else high = mid - 1;
        }
        return -1;
    }



    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int low = 0;
        int high = n-1;
        int peakIndex;

        while(low < high){
            int mid = low + ((high - low) / 2);
            if(mountainArr.get(mid) < mountainArr.get(mid + 1)) low = mid + 1;
            else high = mid;
        }
        peakIndex = high;

        int leftans = findLeft(target , mountainArr , 0 , peakIndex);
        int rightans = findRight(target , mountainArr , peakIndex + 1 , n-1);

        return (leftans != -1) ? leftans : rightans;
    }
};