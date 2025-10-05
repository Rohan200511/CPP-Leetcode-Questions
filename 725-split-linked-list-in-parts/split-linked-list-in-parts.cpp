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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int length = 0;

        while(curr != nullptr){
            length++;
            curr = curr->next;
        }
        vector<ListNode*> ans(k,nullptr);
        int partNode = length / k;
        int rem = length % k;

        curr = head;
        ListNode* prev = NULL;
        for(int i = 0 ; curr != NULL && i < k ; i++){
            ans[i] = curr;

            for(int j = 1 ; j <= partNode + (rem > 0 ? 1 : 0) ; j++){
                prev = curr;
                curr = curr->next;
            }
            prev->next = nullptr;
            rem--;
        }
        return ans;
    }
};