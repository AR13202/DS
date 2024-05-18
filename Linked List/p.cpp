#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int x){
        data = x;
        next=NULL;
    }
};
Node *takeInput(int n){
    Node*head=NULL;
    Node*end=NULL;
    while(n--){
        int a;
        cin >> a;
        Node*l=new Node(a);
        if(head==NULL){
            head=l;
            end=l;
        }else{
            end->next=l;
            end = l;
        }
    }
    return head;
}
int countll(Node*head){
    int c=0;
    while(head!=NULL){
        c++;
        head=head->next;
    }
    return c;
}
Node*deletell(Node*head,int k){
    k=countll(head)-k+1;
    Node*temp=head;
    int i=1;
    if(k==1){
        return temp->next;
    }
    while((i+1)<k && temp!=NULL){
        temp=temp->next;
        i++;
    }
    temp->next=temp->next->next;
    return head;
}
void printll(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin>>n>>k;
        Node*head=takeInput(n);
        head=deletell(head,k);
        printll(head);
    }
    return 0;
}