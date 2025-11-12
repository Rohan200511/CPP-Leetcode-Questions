class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        unordered_map<char,int>freq;
        for(char& ch : s){
            freq[ch]++;

            if(freq[ch] > ((n+1)/2)) return "";
        }

        priority_queue<pair<int , char>>pq;

        for(auto& [c , f] : freq){
            pq.push({f,c});
        }

        string ans = "";

        while(pq.size() >= 2){
            auto p1 = pq.top();
            pq.pop();

            auto p2 = pq.top();
            pq.pop();

            ans.push_back(p1.second);
            p1.first--;
            ans.push_back(p2.second);
            p2.first--;

            if(p1.first > 0) pq.push(p1);
            if(p2.first > 0) pq.push(p2);
        }

        if(!pq.empty()) ans += pq.top().second; 
        return ans;
    }
};