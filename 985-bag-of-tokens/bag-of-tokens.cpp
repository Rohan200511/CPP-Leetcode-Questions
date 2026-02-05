class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int score = 0 , maxScore = 0;
        int left = 0 , right = n-1;

        sort(tokens.begin() , tokens.end());

        while(left <= right){
            
            if(tokens[left] <= power){
                score++;
                power -= tokens[left];
                left++;
                maxScore = max(maxScore , score);
            }
            else if(score > 0){
                power += tokens[right];
                score--;
                right--;
            } 
            else break;
        }

        return maxScore;
    }
};