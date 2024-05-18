#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node *next = NULL;
    Node(int x){
        data = x;
        next = NULL;
    }
};
class Stackusingll{
    Node *head;
    int s;
    public:
        Stackusingll(){
            Node *head = NULL;
            s = 0;
        }
        Node *push(int m){
            Node *n = new Node(m);
            if (head == NULL){
                head = n;
                s++;
            }
            else {
                n->next = head;
                head = n;
                s++;
            }
            return head;
        }
        int top(){
            return head->data;
        }
        int size(){
            return s;
        }
        bool isEmpty(){
            return s == 0;
        }
        Node *pop(){
            if (s == 0){
                return;
            }
            cout << head->data << endl;
            s--;
            head = head->next;
            return head;
        }
};
int main(){
    Stackusingll s;
    s.push(20);
    s.push(30);
    s.push(10);
    s.push(40);
    s.push(50);

    cout << s.top() << endl;
    s.pop();
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
    cout << s.top() << endl;
    s.pop();
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
    s.pop();
    cout << s.isEmpty() << endl;
    return 0;

}