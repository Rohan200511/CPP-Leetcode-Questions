class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char , int>mp;

        for(char ch : tasks) mp[ch]++;

        priority_queue<int>pq;

        for(auto& it : mp) pq.push(it.second);

        int time = 0;

        while(!pq.empty()){
            int cycle = n+1;
            vector<int>temp;

            while(cycle > 0 && !pq.empty()){
                int freq = pq.top();
                pq.pop();
                freq--;
                if(freq > 0) temp.push_back(freq);
                cycle--;
                time++;
            }

            for(int f : temp) pq.push(f);

            if(!pq.empty()) time += cycle;
        }
        return time;
    }
};