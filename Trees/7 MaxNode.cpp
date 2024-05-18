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
int MaxNode(TreeNode<int>* root){
    int a = 0;
    if (a < root->data){
        a = root->data;
    }
    for(int i=0;i<root->children.size();i++){
        int b = MaxNode(root->children[i]);
        if (a < b){
            a = b;
        }
    } 
    return a;
}
// 1 2 2 3 2 4 5 3 6 7 8 0 0 0 0 0
// 1 2 2 4 3 23 54 12 2 45 34 0 0 0 0 0
int main(){
    TreeNode<int>* root = takeInput();
    PrintTree(root);
    cout << "Max Node: " << MaxNode(root);
    return 0;
}