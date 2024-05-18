#include <iostream>
#include "treeNode.h"
#include <queue>
using namespace std;

TreeNode<int>* takeInput(){
    int rootdata;
    cout << "Enter data : ";
    cin >> rootdata;
    TreeNode<int>* root = new TreeNode<int>(rootdata);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter Number of child for Node " << front->data << ": ";
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            int childData;
            cout << "Enter " << i+1 << "th Child: ";
            cin >> childData;
            TreeNode<int>* rootChild = new TreeNode<int>(childData);
            front->children.push_back(rootChild);
            pendingNodes.push(rootChild);
        }
    }
    return root;
}
int sumofNodes(TreeNode<int>* root){
    int sum = 0;
    if(root == NULL){
        return sum;
    }
    sum += root->data;
    for (int i=0;i<root->children.size();i++){
        sum += sumofNodes(root->children[i]); 
    }
    return sum;
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
int main(){
    TreeNode<int>* root = takeInput();
    printTree(root);
    cout << "Sum of Nodes: " << sumofNodes(root) << endl;
    return 0;
}