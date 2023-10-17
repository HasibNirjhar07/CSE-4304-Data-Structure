#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
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

void printPaths(TreeNode* root, std::vector<int>& path) {
    if (!root) {
        return;
    }

    path.push_back(root->val);

    if (!root->left && !root->right) {
        std::cout << "Path: ";
        for (int i = 0; i < path.size(); i++) {
            std::cout << path[i];
            if (i < path.size() - 1) {
                std::cout << " -> ";
            }
        }
        std::cout << " (Length: " << path.size() << ")" << std::endl;
    } else {
        printPaths(root->left, path);
        printPaths(root->right, path);
    }

    path.pop_back();
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

    std::vector<int> path;
    printPaths(root, path);

    return 0;
}
