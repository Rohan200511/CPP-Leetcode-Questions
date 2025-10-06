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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp = head;

        ListNode* less = new ListNode(0);
        ListNode* lHead = less;

        ListNode* big = new ListNode(0);
        ListNode* gHead = big;

        while(temp != nullptr){
            if(temp->val < x){
                lHead->next = new ListNode(temp->val);
                lHead = lHead->next;
            }
            else {
                gHead->next = new ListNode(temp->val);
                gHead = gHead->next;
            }
            temp = temp->next;
        }

        lHead->next = big->next;

        return less->next;
    }
};