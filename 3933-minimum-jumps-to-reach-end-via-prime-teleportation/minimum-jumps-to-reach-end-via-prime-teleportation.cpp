class Solution {
public:
    vector<bool>isPrime;
    
    void buildPrime(int maxEl){
        isPrime.resize(maxEl+1 , true);

        isPrime[0] = isPrime[1] = false;

        for(int i = 2 ; i * i <= maxEl ; i++){
            if(isPrime[i]){
                for(int j = i * i ; j <= maxEl ; j += i){
                    isPrime[j] = false;
                }
            }
        }
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , vector<int>>mp;
        int maxEl = INT_MIN;

        for(int i = 0 ; i < n ; i++){
            mp[nums[i]].push_back(i);
            maxEl = max(maxEl , nums[i]);
        }

        buildPrime(maxEl);

        vector<bool>visited(n , false);
        queue<int>q;

        q.push(0);
        visited[0] = true;

        unordered_set<int>seen;
        int steps = 0;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                int idx = q.front();
                q.pop();

                if(idx == n-1) return steps;

                if(idx - 1 >= 0 && !visited[idx - 1]){
                    q.push(idx - 1);
                    visited[idx-1] = true;
                }

                if(idx + 1 < n  && !visited[idx + 1]){
                    q.push(idx + 1);
                    visited[idx + 1] = true;
                }

                if(!isPrime[nums[idx]] || seen.count(nums[idx])) continue;

                for(int multiple = nums[idx] ; multiple <= maxEl ; multiple += nums[idx]){
                    if(!mp.contains(multiple)) continue;

                    for(int & j : mp[multiple]){
                        if(!visited[j]){
                            q.push(j);
                            visited[j] = true;
                        }
                    }
                    seen.insert(multiple);
                }
            }

            steps++;
        }
        return steps;
    }
};