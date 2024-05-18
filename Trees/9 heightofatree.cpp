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
int height(TreeNode<int>* root)
{
    if (root==NULL)
        return 0;

    if (root->children.size() == 0) {
        return 1;
    }
    int max_child_height = INT_MIN;
    for (int i = 0; i < root->children.size(); i++) {
        max_child_height = max(max_child_height, height(root->children[i]));
    }
    return 1 + max_child_height;
}
int main(){
    TreeNode<int>* root = takeInput();
    PrintTree(root);
    cout << "\nheight of tree : " << height(root);
    return 0;
}