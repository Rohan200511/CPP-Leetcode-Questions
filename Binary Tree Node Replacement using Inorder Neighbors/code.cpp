#include <bits/stdc++.h>
using namespace std;

vector<int> inorderVals;

struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int val){
        this->val = val;
        left = right = nullptr;
    }
};

Node* build(vector<int> &arr, int i){
    if (i >= arr.size()) return nullptr;

    Node* root = new Node(arr[i]);

    root->left = build(arr, 2*i + 1);
    root->right = build(arr, 2*i + 2);

    return root;
}

void inorder(Node *root){
    if (!root) return;

    inorder(root->left);
    inorderVals.push_back(root->val);
    cout << root->val << " ";
    inorder(root->right);
}

int main(){
    int n;
    cout << "Enter the size of Elements: ";
    cin >> n;

    int rootV;
    cout << "Enter the value of Root: ";
    cin >> rootV;

    vector<int> arr;
    arr.push_back(rootV);

    cout << "Enter the Elements of tree: ";
    for (int i = 1; i <= n; i++){
        int val;
        cin >> val;
        arr.push_back(val);
    }

    Node* root = build(arr, 0);

    cout << "\nBefore Modification: ";
    inorderVals.clear();
    inorder(root);
    cout << endl;

    // Modify
    vector<int> modified;

    for(int i = 0 ; i < inorderVals.size() ; i++){
        int pred = (i == 0) ? 0 : inorderVals[i-1];
        int succ = (i == inorderVals.size() - 1) ? 0 : inorderVals[i+1];

        int val = pred + succ;
        modified.push_back(val);
    }

    Node* newRoot = build(modified, 0);

    cout << "\nAfter Modification: ";
    inorderVals.clear();
    inorder(newRoot);

    return 0;
}
