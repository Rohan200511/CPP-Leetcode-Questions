/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
    
    unordered_map<Node*, Node*> m;
    Node* oldTemp = head;
    Node* newTemp = new Node(head->val);
    Node* newHead = newTemp;

    m[oldTemp] = newTemp;
    oldTemp = oldTemp->next;
    
    while(oldTemp != nullptr){
        Node* copyNode = new Node(oldTemp->val);
        m[oldTemp] = copyNode;

        newTemp->next = copyNode;
        newTemp = newTemp->next;
        
        oldTemp = oldTemp->next;
    }

    oldTemp = head;
    newTemp = newHead;
    
    while(oldTemp != nullptr){
        newTemp->random = m[oldTemp->random];
        
        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }
    
    return newHead;

    }
};