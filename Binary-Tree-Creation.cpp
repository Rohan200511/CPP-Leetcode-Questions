#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaves(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int height(Node* root) {
    if (!root) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return 1 + max(l, r);
}

bool search(Node* root, int val) {
    if (!root) return false;
    if (root->data == val) return true;
    if (val < root->data) return search(root->left, val);
    return search(root->right, val);
}

int main() {
    Node* root = NULL;
    int choice, val;

    while (true) {
        cout << "\n1. Insert Node\n2. Preorder\n3. Inorder\n4. Postorder\n5. Height\n6. Search\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> val;
                root = insert(root, val);
                cout << val << " inserted\n";
                break;
            case 2:
                preorder(root); cout << endl; break;
            case 3:
                inorder(root); cout << endl; break;
            case 4:
                postorder(root); cout << endl; break;
            case 5:
                cout << height(root) << endl; break;
            case 6:
                cin >> val;
                cout << (search(root, val) ? "Found\n" : "Not Found\n");
                break;
            case 7:
                exit(0);
            default:
                cout << "Invalid choice\n";
        }
    }
}
