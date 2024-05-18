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
void levelordertraversal(Node*root){
    queue<Node*> q;
    q.push(root);
    while(q.size()!=0){
        Node*front=q.front();
        q.pop();
        std::cout<<front->data <<" ";
        if(front->left!=NULL){
            q.push(front->left);
        }
        if(front->right!=NULL){
            q.push(front->right);
        }
    }
}
int main(){
    vector<int> arr = {3,6,4,5,1,2};
    Node * root = NULL;
    for(int i=0;i<arr.size();i++){
        root = insert(root,arr[i]);
    }
    std::cout << "inorder: ";
    inorder(root);
    std::cout << "\nlevelorder: ";
    levelordertraversal(root);
    return 0;
}