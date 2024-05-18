#include <iostream>
#include "treeNode.h"
#include <queue>
using namespace std;

TreeNode<int>* takeInput() {
    int data;
    cout << "Enter Root: ";
    cin >> data;
    TreeNode<int>* root = new TreeNode<int>(data);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        int n;
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter Number of Children for " << front->data << " ";
        cin >> n;
        for(int i=0;i<n;i++){
            int ChildData;
            cout << "Enter " << i+1 << "th Child: ";
            cin >> ChildData;
            TreeNode<int>* Child = new TreeNode<int>(ChildData);
            pendingNodes.push(Child);
            front->children.push_back(Child);
        }
    }
    return root;
}
void PrintTree(TreeNode<int>* root){
    if (root == NULL){
        return;
    }
    cout << endl;
    cout << root->data << ": ";
    for(int i=0;i<root->children.size();i++){
        cout << root->children[i]->data << " ";
    }
    for(int i=0;i<root->children.size();i++){
        PrintTree(root->children[i]);
    }
}
void nodeatk(TreeNode<int>*root, int k){
    if (root==NULL){
        return;
    }
    if (k==0){
        cout << root->data << " ";
    } 
    for(int i=0;i<root->children.size();i++){
         nodeatk(root->children[i],k-1);
    }
}
int main(){
    TreeNode<int>* root = takeInput();
    PrintTree(root);
    int k;
    cout << "\nenter depth: ";
    cin >> k;
    cout << "Node at depth " << k << " : ";
    nodeatk(root,k);
    return 0;
}