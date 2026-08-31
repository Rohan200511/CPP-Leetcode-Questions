class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return {-1, -1};

        ListNode* prev = head;
        ListNode* curr = head->next;

        vector<int> temp;
        int i = 2;

        while (curr->next != NULL) {
            ListNode* next = curr->next;

            if ((prev->val < curr->val && next->val < curr->val) ||
                (prev->val > curr->val && next->val > curr->val)) {
                temp.push_back(i);
            }

            prev = curr;
            curr = curr->next;
            i++;
        }

        if (temp.size() < 2)
            return {-1, -1};

        int maxD = temp.back() - temp.front();
        int minD = INT_MAX;

        for (int j = 1; j < temp.size(); j++) {
            minD = min(minD, temp[j] - temp[j - 1]);
        }

        return {minD, maxD};
    }
};