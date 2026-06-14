/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        int n = 0;

        ListNode* temp = head;

        while(temp != nullptr){
            n++;
            temp = temp->next;
        }

        stack<int>st;

        temp = head;

        for(int i = 0 ; i < n / 2 ; i++){
            st.push(temp->val);
            temp = temp->next;
        }

        int sum = 0;

        while(temp != nullptr){
            int tempSum = st.top() + temp->val;
            st.pop();
            sum = max(tempSum , sum);
            temp = temp->next;
        }

        return sum;
    }
};