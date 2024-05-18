#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *prev,*next;
};
struct Node*front=NULL;
struct Node*rear=NULL;
int size=0;
bool DQEmpty(){
    return front==NULL;
}
int getfront(){
    if(DQEmpty()){
        return -1;
    }
    return front->data;
}
int Size(){
    return size;
}
int getRear(){
    if(DQEmpty()){
        return -1;
    }
    return rear->data;
}
void insertFront(int data){
    struct Node*new_node=new Node;
    new_node->data=data;
    new_node->next=NULL;
    new_node->prev=NULL;
    if(new_node== NULL){
        cout << "overflow\n";
        return;
    }else{
        if(DQEmpty()){
            front=new_node;
            rear=new_node;
        }else{
            new_node->next=front;
            front->prev=new_node;
            front=new_node;
        }
    }
    size++;
}
void insertRear(int data){
    struct Node*new_node=new Node;
    new_node->data=data;
    new_node->next=NULL;
    new_node->prev=NULL;
    if(new_node== NULL){
        cout << "overflow\n";
        return;
    }else{
        if(DQEmpty()){
            front=new_node;
            rear=new_node;
        }else{
            rear->next=new_node;
            new_node->prev=rear;
            rear=new_node;
        }
    }
    size++;
}
void deleteFront(){
    if(DQEmpty()){
        cout << "underflow\n";
        return;
    }
    front=front->next;
    if(front==NULL){
        rear=NULL;
    }else{
        front->prev=NULL;
    }
    size--;
}
void deleteRear(){
    if(DQEmpty()){
        cout << "underflow\n";
        return;
    }
    rear=rear->prev;
    if(rear==NULL){
        front=NULL;
    }else{
        rear->next=NULL;
    }
    size--;
}

int main(){
    insertFront(3);
    insertRear(4);
    insertFront(2);
    insertFront(1);
    insertRear(5);
    cout << getfront() << endl; 
    cout << getRear() << endl;
    cout << size << endl;
    cout << DQEmpty() << endl;
    deleteFront();
    deleteRear();
    deleteFront();
    deleteRear();
    cout << getfront() << endl; 
    cout << getRear() << endl;
    cout << size << endl;
}