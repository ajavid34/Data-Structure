#include <iostream>
#include <vector>

using namespace std;

class BST {
public:
    BST();
    BST(int value);
    BST* Insert(BST* root, int value);
    int max(BST*& root);
    int min(BST*& root);
    int find_min_diff(BST* root, int key);
private:
    int data;
    BST* left, * right;
    BST* delete_min(BST* root, int& min_val);
    BST* delete_max(BST* root, int& max_val);
};

BST::BST()
    : data(0)
    , left(NULL)
    , right(NULL)
{
}

BST::BST(int value)
{
    data = value;
    left = right = NULL;
}

BST* BST::Insert(BST* root, int value)
{
    if (!root)
        return new BST(value);
    if (value > root->data)
        root->right = Insert(root->right, value);
    else
        root->left = Insert(root->left, value);

    return root;
}
int BST::max(BST*& root) {
    int max_val;
    root = delete_max(root, max_val);
    return max_val;
}
BST* BST::delete_max(BST* root, int& max_val) {
    if (root->right == NULL) {
        BST* temp = root->left;
        max_val = root->data;
        free(root);
        return temp;
    }
    root->right = delete_max(root->right, max_val);
    return root;
}
int BST::min(BST*& root) {
    int min_val;
    root = delete_min(root, min_val);
    return min_val;
}
BST* BST::delete_min(BST* root, int& min_val) {
    if (root->left == NULL) {
        BST* temp = root->right;
        min_val = root->data;
        free(root);
        return temp;
    }
    root->left = delete_min(root->left, min_val);
    return root;
}
int BST::find_min_diff(BST* root, int key) {
    BST* current_node = root;
    int min_diff = abs(current_node->data - key);
    while (current_node != NULL) {
        if (abs(current_node->data - key) < min_diff) {
            min_diff = abs(current_node->data - key);
        }
        if (key > current_node->data) {
            current_node = current_node->right;
        }
        else if (key < current_node->data) {
            current_node = current_node->left;
        }
        else {
            break;
        }
    }
    return min_diff;
}
int main() {
    BST b, * root = NULL;
    int n, type, key;
    cin >> n;
    cin >> type >> key;
    root = b.Insert(root, key);
    for (int i = 0; i < n - 1; i++) {
        cin >> type;
        cin >> key;
        if (type == 1)
            root = b.Insert(root, key);
        else if (type == 2) {
            cout << b.find_min_diff(root, key) << endl;
        }
    }
    return 0;
}