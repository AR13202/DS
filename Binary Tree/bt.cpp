#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int x){
        this->data = x;
        left=NULL;
        right=NULL;
    }
};

TreeNode* takeInput(){
    int r;
    cout << "enter root: ";
    cin >> r;
    TreeNode*root=new TreeNode(r);
    queue<TreeNode*> q;
    q.push(root);
    while(q.size()!=0){
        TreeNode*front=q.front();
        q.pop();
        cout<<"enter left child of " << front->data << ": ";
        int leftchild;
        cin>>leftchild;
        if(leftchild!=-1){
            TreeNode*left=new TreeNode(leftchild);
            front->left=left;
            q.push(left);
        }
        cout<<"enter right child of " << front->data << ": ";
        int rightchild;
        cin>>rightchild;
        if(rightchild!=-1){
            TreeNode*right=new TreeNode(rightchild);
            front->right=right;
            q.push(right);
        }
    }
    return root;
}
void printtree(TreeNode*root){
    if(root==NULL){
        return;
    }
    cout << root->data << ": ";
    if(root->left!=NULL){
        cout<< root->left->data<<" ";
    }
    if(root->right!=NULL){
        cout<< root->right->data<<" ";
    }
    cout<<endl;
    printtree(root->left);
    printtree(root->right);
}
void levelordertraversal(TreeNode*root){
    queue<TreeNode*> q;
    q.push(root);
    while(q.size()!=0){
        TreeNode*front=q.front();
        q.pop();
        cout<<front->data <<" ";
        if(front->left!=NULL){
            q.push(front->left);
        }
        if(front->right!=NULL){
            q.push(front->right);
        }
    }
}
int numnodes(TreeNode*root){
    int n=0;
    queue<TreeNode*> q;
    q.push(root);
    while(q.size()!=0){
        TreeNode*front=q.front();
        q.pop();
        n++;
        if(front->left!=NULL){
            q.push(front->left);
        }
        if(front->right!=NULL){
            q.push(front->right);
        }
    }
    return n;
    /*
        if (root == NULL){
            return 0;
        }
        return 1 + NumNodes(root->left) + NumNodes(root->right); 
    */
}
void inorder(TreeNode*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(TreeNode*root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data << " ";
}
void preorder(TreeNode*root){
    if(root==NULL){
        return;
    }
    cout<<root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void sumnodes(TreeNode*root,int &sum){
    if(root==NULL){
        return;
    }
    sum+=root->data;
    sumnodes(root->left,sum);
    sumnodes(root->right,sum);
}
void inverttree(TreeNode*root){
    queue<TreeNode*> q;
    q.push(root);
    while(q.size()!=0){
        TreeNode*front=q.front();
        q.pop();
        cout<<front->data <<" ";
        if(front->right!=NULL){
            q.push(front->right);
        }
        if(front->left!=NULL){
            q.push(front->left);
        }
    }
}
int height(TreeNode*root){
    if(root==NULL){
        return 0;
    }
    return 1 + max(height(root->left),height(root->right));
}
void diameter(TreeNode*root, int &d){
    if(root==NULL){
        return;
    }
    int a = height(root->left);
    int b = height(root->right);
    d = max(a+b+1,d);
    diameter(root->left,d);
    diameter(root->right,d);
}

int main(){
    TreeNode*root=takeInput();
    cout << "\nprint tree\n";
    printtree(root);
    cout << "level order tree\n";
    levelordertraversal(root);
    cout<<"\nInverted Tree\n";
    inverttree(root);
    cout << "\nheight of tree: " << height(root)<< endl;
    cout << "number of nodes in the tree: " << numnodes(root)<< endl;
    cout << "inorder: ";
    inorder(root);
    cout<< "\n";
    cout << "postorder: ";
    postorder(root);
    cout<< "\n";
    cout << "preorder: ";
    preorder(root);
    cout<< "\n";
    cout << "sum of nodes: ";
    int sum=0;
    sumnodes(root,sum);
    cout<< sum << "\n";
    int d = 0;
    diameter(root,d);
    cout << "diameter of tree: " << d << "\n";
}
/*
                1
             /     \
            2       3
           / \     / \
         4    5   6    7
         /\  /\  / \  / \
       -1 8 9-1-1 10 -1 11
        / \ /\     /\   /\
       12-1 -1 -1-1-1  -1-1
       /\
      -1-1

input : 1 2 3 4 5 6 7 -1 8 9 -1 -1 10 -1 11 12 -1 -1 -1 -1 -1 -1 -1 -1 -1
height: 4
numnodes: 12
inorder: 4 12 8 2 9 5 1 6 10 3 7 11
postorder: 12 8 4 9 5 2 10 6 11 7 3 1
preorder: 1 2 4 8 12 5 9 3 6 10 7 11
*/