/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return nullptr;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        unordered_set<ListNode*>st;
        while(temp1!=nullptr){
            st.insert(temp1);
            temp1 = temp1->next;
        }

        while(temp2!=nullptr){

            if(st.count(temp2)) return temp2;
            temp2 = temp2->next;
        }
        return nullptr;
    }
};