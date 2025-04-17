class Solution {
public:
    void generatestring(int open,int close, string current,vector<string>& result){
        if(open==0 && close==0){
            result.push_back(current);
            return ;
        }
        if(open > 0){
            generatestring(open-1,close,current+"(",result);
        }
        if(close>open){
            generatestring(open,close-1,current+")",result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        generatestring(n ,n, "",result);
        return result;
    }
};