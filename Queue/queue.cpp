#include<iostream>
using namespace std;
int queue[5];
int size=5;
int front=-1;
int rear = -1;

void enqueue(int element){
    if(front==0 && rear==(size-1) || (rear==(front-1)%(size-1))){
        cout << "overflow\n";
        return;
    }else if(front==-1){
        front=0;
        rear=0;
        queue[rear]=element;
    }else if(rear==(size-1) & front!=0){
        rear=0;
        queue[rear]=element;
    }else{
        rear++;
        queue[rear]=element;
    }
}

void dequeue(){
    if(front==-1){
        cout << "underflow\n";
        return;
    }
    int del_ele=queue[front];
    if(front==rear){
        front=-1;
        rear=-1;
    }else if(front==size-1){
        front=0;
    }else{
        front++;
    }
    cout << "element deleted is: " << del_ele << endl;
}

void display(){
    if(front==-1){
        cout << "underflow\n";
        return;
    }
    if(front<=rear){
        for(int i=front;i<=rear;i++){
            cout << queue[i];
        }
    }else{
        for(int i=front;i<size-1;i++){
            cout << queue[i];
        }
        for(int i=0;i<=rear;i++){
            cout << queue[i];
        }
    }
    cout << endl;
}

void rev_display(){
    if(front==-1){
        cout << "underflow\n";
        return;
    }
    if(front<=rear){
        for(int i=rear;i>=front;i--){
            cout << queue[i] << " ";
        }
    }else{
        for(int i=rear;i>=0;i--){
            cout << queue[i] << " ";
        }
        for(int i=size-1;i>=front;i--){
            cout << queue[i] << " ";
        }
    }
    cout << endl;
}

int main(){
    int choice;
    int ele;
    do{
        cout <<"1 enqueue\n";
        cout <<"2 dequeue\n";
        cout <<"3 display\n";
        cout <<"4 reverse\n";
        cout <<"5 exit\n";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "enter ele: ";
                cin >> ele;
                enqueue(ele);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                rev_display();
                break;
            case 5:
                exit(0);
            default:
                cout << "invalid value\n";
        }
    }while(choice != 5);
    return 0;
}