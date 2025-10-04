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
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        
        if(!head) return false;

        while(head!=nullptr){
            arr.push_back(head->val);
            head = head->next;
        }
        int n = arr.size();
        int left = 0;
        int right = n-1;

        while(left < right){
            if(arr[left++] != arr[right--]) return false;
        }
        return true;
    }
};