class Solution {
public:

    int longestConsecutive(vector<int>& Bars){
        int n = Bars.size();

        int longest = 1;
        int current = 1;
        for(int i = 1; i < n; i++){
            if(Bars[i] == Bars[i-1] + 1){
                current++;
                longest = max(longest , current);
            }
            else current = 1;
        }
        return longest;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin() , hBars.end());
        sort(vBars.begin() , vBars.end());

        int h = longestConsecutive(hBars) + 1;
        int v = longestConsecutive(vBars) + 1;
        cout << h << " "<<v;
        int side = min(h , v);
        return side * side;
    }
};