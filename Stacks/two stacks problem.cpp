#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node(int x){
        data = x;
        next = NULL;
    }
};
class stack{
    Node * head;
    int s;
    public:
        stack(){
            Node * head = NULL;
            s = 0;
        }
        Node * push(int a){
            Node * temp = new Node(a);
            temp->next = head;
            head = temp;
            s++;
            return head;
        }
        int top(){
            return head->data;
        }
        bool isEmpty(){
            return s==0;
        }
        Node * pop(){
            if (s==0){
                cout << -1 << endl;
                return 0;
            }
            s--;
            cout << head->data << endl;
            head = head->next;
            return head;
        }
        int size(){
            return s;
        }
        int findmiddle(){
            int a = s/2;
            Node * temp1 = head; 
            for (int i=0;i<a;i++){
                temp1=temp1->next;
            }
            return temp1->data;
        }
};

int main(){
    stack s1;
    stack s2;
    stack s3;
    s1.push(12);
    s2.push(34);
    s1.push(23);
    s1.pop();
    s2.pop();
    s2.pop();
    s3.push(34);
    s3.push(4);
    s3.push(3);
    s3.push(5);
    s3.push(78);
    s3.push(31);
    s3.push(67);
    s3.push(89);
    s3.push(23);
    cout <<s3.size() << endl;
    cout << s3.top() << endl;
    cout << s3.isEmpty() << endl;
    cout << s3.findmiddle() << endl;
    return 0;
}