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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* newNode = new ListNode(0);
        ListNode* head = newNode;
        int carry = 0;
        while(p1 || p2 || carry != 0){
            int sum = carry;

            if(p1 != nullptr){
                sum += p1->val;
                p1 = p1->next;
            }
            if(p2 != nullptr){
                sum += p2->val;
                p2 = p2->next;
            }
            carry = sum/10;
            head->next = new ListNode(sum%10);
            head = head->next;
        }
        return newNode->next;
    }
};