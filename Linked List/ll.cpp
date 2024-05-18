#include<iostream>
#include<stack>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};
Node *takeInput(){
    int n;
    cin >>n;
    Node *head = NULL;
    Node *tail = NULL;
    while(n != -1){
        Node *n1 = new Node(n);
        if(head == NULL){
            head = n1;
            tail = n1;
        }
        else {
            tail -> next = n1;
			tail = n1; 
        }
        cin >> n;
    }
    return head;
}
/*Node *swapPairs(Node* head) {
    if(head==NULL||head->next==NULL){
        return head;
    }//1 2 3 4
    Node*temp=NULL;
    Node*prev=NULL;
    while(head!=NULL && head->next!=NULL){
        Node*t=head->next;
        head->next = head->next->next;
        t->next = head;
        if(temp==NULL){
            temp = t;
        }
        if(prev==NULL){
            prev = head;
        }else{
            prev->next = t;
            prev = prev->next->next;
        }
        head = head->next;
    }
    return temp;
}*/
void print(Node * head){
    Node * temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int count(Node*head){
    int c=0;
    while(head!=NULL){
        c++;
        head=head->next;
    }
    return c;
}
Node* reverseKGroup(Node* head, int k) {
    Node*temp = head;
    Node*temp1=head;
    int c = count(temp1);
    c=c/k;
    while(c>0){
        int a=0;
        stack<int> s;
        Node*t=temp;
        while(a<k){
            int x = t->data;
            s.push(x);
            t=t->next;
            a++;
        }
        while(s.size()!=0){
            temp->data = s.top();
            temp=temp->next;
            s.pop();
        }
        c--;
    }
    return head;     
}
Node* rotateRight(Node* head, int k) {
        if(k==0){
            return head;
        }
        Node*temp=head;
        int c = count(temp);
        if(k>=c){
            c=k%c;
        }else if(k<c){
            c-=k;
        }
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = head;
        Node*ptr = head;
        while(c>1){
            ptr=ptr->next;
        }
        head = ptr->next;
        ptr->next=NULL;
        return head;
    }
int main(){
    Node *head=takeInput();
    //Node *head1 = swapPairs(head);
    //print(head1);
    print(head);
   // Node *t=reverseKGroup(head,3);
    Node*s=rotateRight(head,2);
   // print(t);
    print(s);
    return 0;
}