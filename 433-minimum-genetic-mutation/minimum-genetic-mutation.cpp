class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        if (!st.count(endGene)) return -1;

        queue<pair<string,int>> q; 
        q.push({startGene, 0});

        string chars = "ACGT";

        while (!q.empty()) {
            auto [cur, steps] = q.front();
            q.pop();

            if (cur == endGene) return steps;

            for (int i = 0; i < cur.size(); i++) {
                char old = cur[i];

                for (char c : chars) {
                    if (c == old) continue;

                    cur[i] = c;

                    if (st.count(cur)) {
                        q.push({cur, steps + 1});
                        st.erase(cur);
                    }
                }
                cur[i] = old;
            }
        }

        return -1;
    }
};