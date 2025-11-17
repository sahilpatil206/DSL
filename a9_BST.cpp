#include <bits/stdc++.h>
using namespace std;

class BST_Node {
public:
    int data;
    BST_Node* left;
    BST_Node* right;

    BST_Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
public:
    BST_Node* root;

    BinarySearchTree() { root = nullptr; }

    BST_Node* insertNode(BST_Node* root, int data) {
        if (root == nullptr) return new BST_Node(data);

        if (data < root->data)
            root->left = insertNode(root->left, data);
        else if (data > root->data)
            root->right = insertNode(root->right, data);

        return root;
    }

    // ---------- CORRECTED PREORDER ITERATIVE ----------
    void preorderTraversal(BST_Node* root) {
        if (root == NULL) return;

        stack<BST_Node*> st;
        st.push(root);

        while (!st.empty()) {
            BST_Node* curr = st.top();
            st.pop();

            cout << curr->data << " ";

            if (curr->right)
                st.push(curr->right);

            if (curr->left)
                st.push(curr->left);
        }
    }

    void inorderTraversal(BST_Node* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }

    void postorderTraversal(BST_Node* root) {
        if (root != nullptr) {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            cout << root->data << " ";
        }
    }

    void bfsTraversal(BST_Node* root) {
        if (!root) return;

        queue<BST_Node*> q;
        q.push(root);

        while (!q.empty()) {
            BST_Node* curr = q.front();
            q.pop();

            cout << curr->data << " ";

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }

    void dfsTraversal(BST_Node* root) {
        if (!root) return;

        stack<BST_Node*> s;
        s.push(root);

        while (!s.empty()) {
            BST_Node* curr = s.top();
            s.pop();

            cout << curr->data << " ";

            if (curr->right) s.push(curr->right);
            if (curr->left) s.push(curr->left);
        }
    }

    int longestPath(BST_Node* root) {
        if (root == nullptr) return 0;

        int leftDepth = longestPath(root->left);
        int rightDepth = longestPath(root->right);

        return 1 + max(leftDepth, rightDepth);
    }

    BST_Node* findMinNode(BST_Node* root) {
        if (root == nullptr) return nullptr;
        while (root->left != nullptr)
            root = root->left;
        return root;
    }

    BST_Node* findMaxNode(BST_Node* root) {
        if (root == nullptr) return nullptr;
        while (root->right != nullptr)
            root = root->right;
        return root;
    }

    void swapLeftRight(BST_Node* root) {
        if (root == nullptr) return;

        swap(root->left, root->right);

        swapLeftRight(root->left);
        swapLeftRight(root->right);
    }

    BST_Node* searchNode(BST_Node* root, int key) {
        if (!root) return nullptr;
        if (root->data == key) return root;

        if (key < root->data)
            return searchNode(root->left, key);

        return searchNode(root->right, key);
    }
};

int main() {
    BinarySearchTree bst;
    vector<int> values;

    while (true) {
        cout << "Enter a value to insert into BST (-1 to stop): ";
        int x;
        cin >> x;
        if (x == -1) break;
        values.push_back(x);
    }

    for (int val : values)
        bst.root = bst.insertNode(bst.root, val);

    int choice;

    do {
        cout << "\n------ Binary Search Tree Menu ------\n";
        cout << "1. Insert node\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. BFS Traversal\n";
        cout << "6. DFS Traversal\n";
        cout << "7. Height (Longest Path)\n";
        cout << "8. Find Minimum\n";
        cout << "9. Find Maximum\n";
        cout << "10. Swap Left & Right Subtrees\n";
        cout << "11. Search Node\n";
        cout << "12. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int val;
            cout << "Enter value: ";
            cin >> val;
            bst.root = bst.insertNode(bst.root, val);
            break;
        }
        case 2:
            cout << "Preorder: ";
            bst.preorderTraversal(bst.root);
            cout << endl;
            break;
        case 3:
            cout << "Inorder: ";
            bst.inorderTraversal(bst.root);
            cout << endl;
            break;
        case 4:
            cout << "Postorder: ";
            bst.postorderTraversal(bst.root);
            cout << endl;
            break;
        case 5:
            cout << "BFS: ";
            bst.bfsTraversal(bst.root);
            cout << endl;
            break;
        case 6:
            cout << "DFS: ";
            bst.dfsTraversal(bst.root);
            cout << endl;
            break;
        case 7:
            cout << "Height: " << bst.longestPath(bst.root) << endl;
            break;
        case 8: {
            BST_Node* minNode = bst.findMinNode(bst.root);
            if (minNode)
                cout << "Minimum = " << minNode->data << endl;
            break;
        }
        case 9: {
            BST_Node* maxNode = bst.findMaxNode(bst.root);
            if (maxNode)
                cout << "Maximum = " << maxNode->data << endl;
            break;
        }
        case 10:
            bst.swapLeftRight(bst.root);
            cout << "Swapped left & right.\n";
            break;
        case 11: {
            int key;
            cout << "Enter key: ";
            cin >> key;
            BST_Node* found = bst.searchNode(bst.root, key);
            if (found)
                cout << "Node found: " << found->data << endl;
            else
                cout << "Node not found.\n";
            break;
        }
        case 12:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 12);

    return 0;
}
