#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void insert(TreeNode*& root, int data) {
    if (!root) {
        root = new TreeNode(data);
    }
}

bool isSymmetric(TreeNode* leftSubtree, TreeNode* rightSubtree) {
    if (!leftSubtree && !rightSubtree) {
        return true;
    }

    if (!leftSubtree || !rightSubtree) {
        return false;
    }

    return (leftSubtree->val == rightSubtree->val) &&
           isSymmetric(leftSubtree->left, rightSubtree->right) &&
           isSymmetric(leftSubtree->right, rightSubtree->left);
}

int main() {
    TreeNode* root = nullptr;
    int n;
    std::cin >> n;

    std::vector<int> levelOrder(n);
    for (int i = 0; i < n; i++) {
        std::cin >> levelOrder[i];
    }

    for (int i = 0; i < n; i++) {
        if (levelOrder[i] != -1) {
            insert(root, levelOrder[i]);
        }
    }

    if (isSymmetric(root, root)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}