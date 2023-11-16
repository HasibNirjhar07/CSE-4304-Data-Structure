#include <iostream>
using namespace std;

class Node {
public:
    int value;
    int count;
    Node* left;
    Node* right;

    Node(int val) : value(val), count(0), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* root, int key) {
        if (root == nullptr) {
            return new Node(key);
        }

        if (key < root->value-3) {
            root->left = insert(root->left, key);
            root->count++;  // counting left subtree height
        } 
        else if (key > root->value+3) {
            root->right = insert(root->right, key);
        }

        return root;
    }

    int countReservation(Node* root, int key) {
        if (root == nullptr) {
            return 0;
        }

        if (key < root->value) {
            return countReservation(root->left, key);
        } else if (key > root->value) {
            return 1 + root->count + countReservation(root->right, key); // including right subtree
        } else {
            return root->count;
        }
    }

public:
    BST() : root(nullptr) {
    }
    void insert(int key) {
        root = insert(root, key);
    }

    void countReservation(int key) {
        cout<< countReservation(root, key) << endl;
    }
};

int main() {
    
    BST bst;
    int test;
    int val;

    bst.insert(50);
    bst.insert(75);
    bst.insert(25);
    bst.insert(29);
    bst.insert(45);
    bst.insert(60);
    bst.insert(10);

    cout<< "Enter number of tests: ";
    cin >> test;

    while (test--)
    {
        cout<< "Enter timestamp: ";
        cin >> val;
        bst.countReservation(val);
    }

    return 0;
}
