#include <iostream>
#include <bits/stdc++.h>
#include "BinarytreeNode.h"
#include <queue>
using namespace std;

BinaryTreeNode<int>* takeInput(){
    int n;
    cout << "Enter Root Data: ";
    cin >> n;
    if (n == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(n);
    queue<BinaryTreeNode<int>*> list;
    list.push(root);
    while(list.size() != 0){
        BinaryTreeNode<int>* front = list.front();
        list.pop();
        cout << "Enter left Child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int> (leftChildData);
            front->left = child;
            list.push(child);
        }
        cout << "Enter right Child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int> (rightChildData);
            front->right = child;
            list.push(child);
        }
    }
    return root;
}

int NumNodes(BinaryTreeNode<int>* root){
    if (root == NULL){
        return 0;
    }
    return 1 + NumNodes(root->left) + NumNodes(root->right); 
}

void printTree(BinaryTreeNode<int>* root){
    if (root == NULL){
        return;
    }
    cout << root->data << ": " ;
    if (root->left != NULL){
        cout << "L" << root->left->data;
    }
    cout << " ";
    if (root->right != NULL){
        cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}
void printlevelwise(BinaryTreeNode<int>* root){
    if (root == NULL){
        return;
    }
    int countNodes = 0;
    queue<BinaryTreeNode<int>*> list;
    list.push(root);
    while(list.size() != 0){
        BinaryTreeNode<int>* front = list.front();
        cout << front->data << ": ";
        if (front->left != NULL){
            cout << "L" << front->left->data;
        }
        cout << " ";
        if (front->right != NULL){
            cout << "R" << front->right->data;
        }
        list.pop();
        cout << endl;
        if (front->left != NULL){
            list.push(front->left);
        }
        if (front->right != NULL){
            list.push(front->right);
        }
    } 
}
void inorder(BinaryTreeNode<int>* root){
    if (root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(BinaryTreeNode<int>* root){
    if (root==NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(BinaryTreeNode<int>* root){
    if (root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int height(BinaryTreeNode<int>* root){
    if (root==NULL){
        return 0;
    }
    return 1 + std::max(height(root->left), height(root->right));
}
int diameter(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return std::max(std::max(option1,option2),option3);

}
pair<int,int> heightDiameter(BinaryTreeNode<int>*root){
    if(root==NULL){
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int,int> leftAns = heightDiameter(root->left);
    pair<int,int> rightAns = heightDiameter(root->right);
    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;

    int height = 1 + std::max(lh, rh);
    int diameter = std::max(lh + rh, max(ld, rd));
    pair<int,int> p;
    p.first = height;
    p.second = diameter;
    return p;
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 8 9 -1 -1 -1 -1
int main(){
   /* BinaryTreeNode<int>* root = new Bin8aryTreeNode<int>(10);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(20);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(30);
    root->left = node1;
    root->right = node2;
    */
    BinaryTreeNode<int>* root = takeInput();
    //printTree(root);
    //printlevelwise(root);
    //cout << "NumNodes: " << NumNodes(root) << endl;
    cout << "\nInorder: ";
    inorder(root);
    cout << "\nPostOrder: ";
    postorder(root);
    cout << "\nPreorder: ";
    preorder(root);
    pair<int,int> p = heightDiameter(root);
    cout << "\nheight: " << p.first;
    cout << "\ndiameter: " << p.second;
    return 0;
}