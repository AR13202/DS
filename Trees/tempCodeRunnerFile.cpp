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
void deletetree(TreeNode<int>* root){
    // use this fxn or destructor to delete a tree
    if (root == NULL){
        return;
    }
    for(int i=0;i<root->children.size();i++){
        deletetree(root->children[i]);
    }
    delete root;
}

int main(){
    TreeNode<int>* root = takeInput();
    printTree(root);
    //deletetree(root);
    delete root;
    printTree(root);
    return 0;
}
