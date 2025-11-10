/* Link list Node

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */
class Solution {
  public:
    Node* deleteK(Node* head, int k) {
        // code here
         if (!head || k <= 0) return head;
        if (k == 1) return nullptr; 
        Node* curr = head;
        Node* prev = nullptr;
        int count = 1;
        while (curr != nullptr) {
            if (count % k == 0) {
                prev->next = curr->next;
                delete curr; 
                curr = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
            count++;
        }

        return head;
    }
};