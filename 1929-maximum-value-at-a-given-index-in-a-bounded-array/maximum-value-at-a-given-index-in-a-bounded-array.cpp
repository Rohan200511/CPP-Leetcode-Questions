class Solution {
public: 

    long long calc(int len, int val) {
        if (val > len) {
            
            return (long long)(val - 1 + val - len) * len / 2;
        } else {
        
            return (long long)(val - 1) * val / 2 + (len - (val - 1));
        }
    }

    bool safe(int n, int index, int maxSum, int val) {
        int L = index;
        int R = n - index - 1;

        long long sum = val;
        sum += calc(L, val);
        sum += calc(R, val);

        return sum <= maxSum;
    }


    int maxValue(int n, int index, int maxSum) {
        int low = 1;
        int high = maxSum;
        int ans = 0;

        while(low <= high){
            int mid = low + ((high - low) / 2);

            if(safe(n , index , maxSum , mid)){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};