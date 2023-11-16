
// Disneyland has built its airport. The airport has only one runway, which results in heavy traffic. So the authority has decided to create a ‘Runway reservation system’ for their only runway, which will take the reservation of any transport desired to use the runway. 

//Before making the entry, the system checks for reservations within the three-minute range of any existing reservation(s). For example, if there is a reservation in the kth minute, it won’t take any reservation in k-1, k-2, k-3, k+1, k+2, (k+3)th minutes.
 
//Your task is to help them build the system using Binary Search Trees(BST). (Take reservations until the user gives ‘-1’ as input.)
//For every reservation, print the existing reservations in a sorted manner.


// Sample Input

// 50
// 75
// 53
// 25
// 60
// 29
// 45
// 42
// 28
// 10
// -1
// Sample Output
// 50
// 50 75
// 50 75 (Reservation failed)
// 25 50 75
// 25 50 60 75
// 25 29 50 60 75
// 25 29 45 50 60 75
// 25 29 45 50 60 75 (Reservation failed)
// 25 29 45 50 60 75 (Reservation failed)
// 10 25 29 45 50 60 75







#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=nullptr;
        right=nullptr;
    }
};

class BST{
private:
Node* root;

Node* insert(Node* root,int key,bool reserve){
    if(root==nullptr){
        return new Node(key);
    }

    if (key<root->data-3){
        root->left=insert(root->left,key,true);
    }

    else if(key>root->data+3){
        root->right=insert(root->right,key,true);
    }

    else if (key>=(root->data-3)||key<=(root->data+3)){
        reserve=false;
        cout<<"(Reservation failed)";
        return root;
    }
    return root;
}

void inOrder(Node* root){
    if(root!=nullptr){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
        cout<<root->data<<" ";

    }
}  

public:
    BST():root(nullptr){

    }

    void insert(int key){
        bool res= true;
        root=insert(root,key,res);
        inOrder(root);
        if(res==false){
            cout<<"(Reservation failed)";
        }
        cout<<"\n";
    }
};

int main(){

    

    BST bst;
    int val;
    while(true){
        cin>>val;
        if(val==-1){
            break;
        }
        bst.insert(val);

    }
    return 0;
}
   




