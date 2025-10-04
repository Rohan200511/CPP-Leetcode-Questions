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
    private:
    ListNode* reverse(ListNode* node){
        ListNode* prev = NULL;
        ListNode* curr = node;

        while(curr!=NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        //if(!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* firstHalf = head;
        ListNode* secondHalf = reverse(slow->next);
        slow->next = nullptr;

        while(firstHalf != NULL && secondHalf != nullptr){
            ListNode* temp = firstHalf->next;
            firstHalf->next = secondHalf;
            firstHalf = temp;

            temp = secondHalf->next;
            secondHalf->next = firstHalf;
            secondHalf = temp;
        }
    }
};