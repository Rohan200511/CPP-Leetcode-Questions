class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int i = 0 , write = 0;

        while(i < n){
            char c = chars[i];
            int count = 0;
            
            while(i < n && chars[i] == c){
                count++;
                i++;
            }

            chars[write] = c;
            write++;

            if(count > 1){
                string freq = to_string(count);

                for(char ch : freq){
                    chars[write] = ch;
                    write++;
                }
            }
        }
        return write;
    }
};