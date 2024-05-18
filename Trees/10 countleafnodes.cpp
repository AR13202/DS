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
void printleafnodes(TreeNode<int>* root){
    if (root->children.size() == 0){
        cout << root->data << " ";
    }
    for(int i=0;i<root->children.size();i++){
        printleafnodes(root->children[i]);
    }
}
int countleafnodes(TreeNode<int>* root){
    int count=0;
    if (root->children.size() == 0){
        count++;
    }
    for(int i=0;i<root->children.size();i++){
        count += countleafnodes(root->children[i]);
    }
    return count;
}
int main(){
    TreeNode<int>* root = takeInput();
    PrintTree(root);
    cout << "\nleaf nodes of tree : ";
    printleafnodes(root);
    cout << "\ncount leaf nodes: " << countleafnodes(root);
    return 0;
}