class Solution {
public:
    int minOperations(string s) {
        int n = s.length();

        string s1 = s;
        string s2 = s;

        int count1 = 0;
        int count2 = 0;

        if(s1[0] == '1'){
            s1[0] = '0';
            count1++;
        }

        if(s2[0] == '0'){
            s2[0] = '1';
            count2++;
        }

        for(int i = 1; i < n; i++){
            if(s1[i-1] == '1'){
                if(s1[i] == '1'){
                    s1[i] = '0';
                    count1++;
                }
            }
            else{
                if(s1[i] == '0'){
                    s1[i] = '1';
                    count1++;
                }
            }
        }

        for(int i = 1; i < n; i++){
            if(s2[i-1] == '1'){
                if(s2[i] == '1'){
                    s2[i] = '0';
                    count2++;
                }
            }
            else{
                if(s2[i] == '0'){
                    s2[i] = '1';
                    count2++;
                }
            }
        }

        return min(count1, count2);
    }
};