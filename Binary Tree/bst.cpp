#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int x){
            data = x;
            left=NULL;
            right=NULL;
        }
};
Node* sortedArrayToBST(vector<int>& v) {
    if(v.size()==0){
        return NULL;
    }
    if(v.size()==1){
        Node* t = new Node(v[0]);
        return t;
    }
    int mid = v.size()/2;
    Node* root = new Node(v[mid]);
    vector<int> q(v.begin(),v.begin()+mid);
    vector<int> p(v.begin()+mid+1,v.end());
    root->left = sortedArrayToBST(q);
    root->right = sortedArrayToBST(p);
    return root;
}
void printTree(Node * root){
    if(root==NULL){
        return;
    }
    printTree(root->left);
    cout << root->data <<" ";
    printTree(root->right);
}

int main(){
    vector<int> a = {1,2,3,4,5,6,7,8,9,10,11};
    Node* root = sortedArrayToBST(a);
    printTree(root);
}