#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node * right;
    Node(int x){
        data = x;
        left=NULL;
        right=NULL;
    }
};
Node* insert(Node* root,int data){
    if(root==NULL){
        Node * temp = new Node(data);
        return temp;
    }
    if(data > root->data){
        root->right = insert(root->right,data);
    }else{
        root->left = insert(root->left,data);
    }
    return root;
}
void inorder(Node * root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right); 
}
int main(){
    vector<int> arr = {3,6,4,5,1,2};
    Node * root = new Node(arr[0]);
    for(int i=1;i<arr.size();i++){
        root = insert(root,arr[i]);
    }
    inorder(root);
    return 0;
}