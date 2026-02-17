class Solution {
public:
    void reverseString(vector<char>& s) {
        int beg=0;
        int e=s.size()-1;
        while(beg<e){
        swap(s[beg++],s[e--]);
    }
    }
};