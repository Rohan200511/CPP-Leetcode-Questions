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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>mat(m , vector<int>(n , -1));
        ListNode* curr = head;
        int left = 0 , top = 0;
        int right = n - 1 , bottom = m - 1;

        while(top <= bottom && left <= right && curr){
            
            for(int i = left ; i <= right && curr ; i++){
                int val = curr->val;
                curr = curr->next;
                mat[top][i] = val;
            }
            top++;

            for(int i = top ; i <= bottom && curr ; i++){
                int val = curr->val;
                curr = curr->next;
                mat[i][right] = val;
            }
            right--;

            for(int i = right ; i >= left && curr ; i--){
                int val = curr->val;
                curr = curr->next;
                mat[bottom][i] = val;
            }
            bottom--;

            for(int i = bottom ; i >= top && curr ; i--){
                int val = curr->val;
                curr = curr->next;
                mat[i][left] = val;
            }
            left++;

        } 
        return mat;
    }
};