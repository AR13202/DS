#include <iostream>
#include <queue>
#include <vector>
using namespace std;
template <typename T> 
class TreeNode {
    public:
    T data;
    vector<TreeNode<T>*> children;
    TreeNode(T data){
        this->data = data;
    }
    ~TreeNode(){
        for(int i=0;i<children.size();i++){
            delete children[i];
        }
    }
};
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
int NumNodes(TreeNode<int>* root){
    int ans = 1;
    for(int i=0;i<root->children.size();i++){
        ans += NumNodes(root->children[i]);     
    }
    return ans;
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
int height(TreeNode<int>* root){
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