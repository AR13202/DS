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
class queue{
	Node *head;
	Node *tail;
	int s;
	public:
	queue(){
		head = NULL;
        tail = NULL;
		s = 0;
	}
	void enqueue(int z){
		Node * temp = new Node(z);
		if (head==NULL){
			head = tail = temp;
		}else{
			tail->next = temp;
			tail = temp;
		}
		s++;
	}
	int front(){
		if (s==0){
			return 0;
		}
		return head->data;
	}
	int dequeue(){
		if (s==0){
			return 0;
		}
		int ans = head->data;
		Node * temp = head;
		head = head->next;
		delete temp;
		s--;
		return ans;
	}
	int getSize(){
		return s;
	}
	int isEmpty(){
		return s==0;
	}
};
int main(){
    queue q;
    q.enqueue(12);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(7);

    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;
    return 0;
}