/*
                1
               / \
              2   3
             / \ / \
            4  5 6  7
                   / \
                  8   9
*/

#include <iostream>
#include "BinarytreeNode.h"
#include <queue>
using namespace std;
void printTree(BinaryTreeNode<int>* root){
    if (root == NULL){
        return;
    }
    cout << root->data << ": " ;
    if (root->left != NULL){
        cout << "L" << root->left->data;
    }
    cout << " ";
    if (root->right != NULL){
        cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}
void printlevel(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> list;
    list.push(root);
    while(list.size() != 0){
        BinaryTreeNode<int>* front = list.front();
        cout << front->data << " ";
        list.pop();
        if (front->left != NULL){
            list.push(front->left);
        }
        if (front->right != NULL){
            list.push(front->right);
        }
    } 
}
int sumatklevel(BinaryTreeNode<int>* root,int k){
    if(root == NULL){
        return -1;
    }
    queue<BinaryTreeNode<int>*> list;
    list.push(root);
    list.push(NULL);
    int a = 0;
    int sum=0;
    while(list.size() != 0){
        BinaryTreeNode<int>* front = list.front();
        list.pop();
        if(front != NULL){
            if(a==k){
                sum+= front->data;
            }
            if (front->left != NULL){
                list.push(front->left);
            }
            if (front->right != NULL){
                list.push(front->right);
            }
        } else if (!list.empty()) {
            list.push(NULL);
            a++;
        }
    } 
    return sum;
}
int search(int arr[], int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return 0;
}
BinaryTreeNode<int>* buildtree(int preorder[], int inorder[],
                            int start,int end){
    static int idx = 0;
    if(start > end){
        return NULL;
    }
    int curr = preorder[idx];
    idx++;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(curr);
    if(start==end){
        return root;
    }
    int pos = search(inorder,start,end,curr);
    root->left = buildtree(preorder,inorder,start,pos-1);
    root->right = buildtree(preorder,inorder,pos+1,end);
    return root;
}

BinaryTreeNode<int>* buildtree2(int postorder[], int inorder[],
                            int start,int end){
    static int idx = end;
    if(start>end){
        return NULL;
    }
    int val = postorder[idx];
    idx--;
    BinaryTreeNode<int>* curr = new BinaryTreeNode<int> (val);
    if(start==end){
        return curr;
    }
    int pos = search(inorder, start, end, val);
    curr->right = buildtree2(postorder,inorder,pos+1,end);
    curr->left = buildtree2(postorder,inorder,start,pos-1);
    return curr;
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 8 9 -1 -1 -1 -1
int main(){
   int inorder[9] = { 4, 2, 5, 1, 6, 3, 8, 7, 9};
   int preorder[9] = {1, 2, 4, 5, 3, 6, 7, 8, 9};
   int postorder[9] = {4, 5, 2, 6, 8, 9, 7, 3, 1};
   int len = sizeof(inorder) / sizeof(inorder[0]);
   BinaryTreeNode<int>* root =  buildtree2(postorder,inorder,0,len-1);
   int k;
   cout << "sum at level: ";
   cin >> k;
   cout << "sum: " << sumatklevel(root,k);
   cout << endl;
   printTree(root);
   cout << endl;
   printlevel(root);
   return 0;
}