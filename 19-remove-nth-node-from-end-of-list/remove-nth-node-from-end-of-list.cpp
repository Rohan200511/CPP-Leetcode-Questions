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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* prev = head;

        for(int i = 0 ; i < n ; i++) temp = temp->next;
        if(temp == nullptr) return head->next;
        while(temp->next!=nullptr){
            temp = temp->next;
            prev = prev->next;
        }
        ListNode* toDel = prev->next;
        prev->next = prev->next->next;
        delete(toDel);
        return head;
    }
};