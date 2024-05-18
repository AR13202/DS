#include <iostream>
#include "treeNode.h"
#include <queue>
using namespace std;

TreeNode<int>* takeInput(){
    int rootdata;
    cout << "Enter Data: " << endl;
    cin >> rootdata;
    TreeNode<int>* root = new TreeNode<int> (rootdata);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "enter num of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for(int i=0;i<numChild;i++){
            int childData;
            cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int> (childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTree(TreeNode<int>* root){
    if (root == NULL){
        return;
    }
    cout << root->data << ": ";
    for (int i=0;i<root->children.size();i++){
        cout << root->children[i]->data << ", ";
    }
    cout << endl;
    for (int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}
void preorder(TreeNode<int>* root){
    if (root == NULL){
        return;
    }
    cout << root->data << " ";
    for(int i=0;i<root->children.size();i++){
        preorder(root->children[i]);
    }
}
void postorder(TreeNode<int>* root){
    if (root == NULL){
        return;
    }
    for(int i=0;i<root->children.size();i++){
        postorder(root->children[i]);
    }
    cout << root->data << " ";
}
void printlevelwise(TreeNode<int>* root){
    if (root==NULL){
        return;
    }
    queue<TreeNode<int>*> q;
    q.push(root);
    while(q.size() != 0){
        TreeNode<int>* front = q.front();
        cout << front->data << " ";
        q.pop();
        for(int i=0;i<front->children.size();i++){
            q.push(front->children[i]);
        }
    }
}

int main(){
    TreeNode<int>* root = takeInput();
    printTree(root);
    printlevelwise(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    return 0;
}
