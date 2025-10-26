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


Node* createTree() {
    int val;
    cout << "Enter data (-1 for NULL): ";
    cin >> val;
    if (val == -1) return NULL;

    Node* root = new Node(val);

    cout << "Enter left child of " << val << endl;
    root->left = createTree();

    cout << "Enter right child of " << val << endl;
    root->right = createTree();

    return root;
}

// Traversals
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int height(Node* root) {
    if (!root) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return 1 + max(l, r);
}

int main() {
    Node* root = NULL;
    int choice;

    while (true) {
        cout << "\n--- Binary Tree Menu ---\n";
        cout << "1. Create Tree\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Height of Tree\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                root = createTree();
                cout << "Tree created successfully!\n";
                break;
            case 2:
                cout << "Preorder: ";
                preorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Inorder: ";
                inorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder: ";
                postorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Height of Tree: " << height(root) << endl;
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}
