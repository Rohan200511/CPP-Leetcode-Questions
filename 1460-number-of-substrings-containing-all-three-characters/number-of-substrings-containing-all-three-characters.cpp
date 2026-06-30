class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();

        int arr[3] = {-1 , -1 , -1};
        int ans  = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == 'a') arr[0] = i;
            else if(s[i] == 'b') arr[1] = i;
            else arr[2] = i;

            if(arr[0] != -1 && arr[1] != -1 && arr[2] != -1){
                ans += min({arr[0] , arr[1] , arr[2]}) + 1;
            }
        }
        return ans;
    }
};