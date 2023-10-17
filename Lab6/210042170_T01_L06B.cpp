#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void insert(TreeNode*& root, int data, int parent, int child) {
    if (!root) {
        return;
    }

    if (root->val == parent) {
        if (child == 1) {
            root->left = new TreeNode(data);
        } else if (child == 2) {
            root->right = new TreeNode(data);
        }
        return;
    }

    insert(root->left, data, parent, child);
    insert(root->right, data, parent, child);
}

void preorderTraversal(TreeNode* root) {
    if (root) {
        std::cout << root->val << "(";
        if (root->left) {
            std::cout << root->left->val << "(L), ";
        } else {
            std::cout << "null, ";
        }
        if (root->right) {
            std::cout << root->right->val << "(R), ";
        } else {
            std::cout << "null, ";
        }
        std::cout << ") ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

TreeNode* search(TreeNode* root, int data) {
    if (!root) {
        return nullptr;
    }

    if (root->val == data) {
        return root;
    }

    TreeNode* leftResult = search(root->left, data);
    if (leftResult) {
        return leftResult;
    }

    return search(root->right, data);
}

int height(TreeNode* root) {
    if (!root) {
        return -1;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + std::max(leftHeight, rightHeight);
}

void remove(TreeNode*& root, int data) {
    if (!root) {
        return;
    }

    if (root->val == data) {
        delete root;
        root = nullptr;
        return;
    }

    remove(root->left, data);
    remove(root->right, data);
}

int main() {
    TreeNode* root = new TreeNode(1);
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int data, parent, child;
        std::cin >> data >> parent >> child;
        insert(root, data, parent, child);
    }

    std::cout << "Preorder traversal with parent info: ";
    preorderTraversal(root);
    std::cout << std::endl;

    int searchData;
    std::cin >> searchData;
    TreeNode* searchResult = search(root, searchData);

    if (searchResult) {
        std::cout << "Present, ";
        if (searchResult->left) {
            std::cout << "Left(" << searchResult->left->val << "), ";
        } else {
            std::cout << "Left(null), ";
        }
        if (searchResult->right) {
            std::cout << "Right(" << searchResult->right->val << ")" << std::endl;
        } else {
            std::cout << "Right(null)" << std::endl;
        }
    } else {
        std::cout << "Not present" << std::endl;
    }

    int removeData;
    std::cin >> removeData;
    remove(root, removeData);

    std::cout << "Preorder traversal with parent info after removal: ";
    preorderTraversal(root);
    std::cout << std::endl;

    int heightOfTree = height(root);
    std::cout << "Height of the tree: " << heightOfTree << std::endl;

    return 0;
}
