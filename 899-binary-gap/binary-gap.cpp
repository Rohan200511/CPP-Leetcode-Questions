class Solution {
public:
    int binaryGap(int n) {
        int gap = 0;
        int maxGap = 0;
        int last = -1;

        while(n > 0){
            if((n & 1) == 1){
                if(last != -1){
                    maxGap = max(maxGap, gap - last);
                }
                last = gap;
            }
            gap++;
            n >>= 1;
        }

        return maxGap;
    }
};