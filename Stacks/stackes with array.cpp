#include <iostream>
#include <climits>
using namespace std;
/*
 insert = push
 delete = pop
 stack is an abstract datatype
 we can only access element at the top
 pusk will only insert element at the top
 pop will only delete the element at top
 access top most element we use top()
 top() remains same unless and until push or pop happpen
 size of stack = size()
 isEmpty = if our stack is empty
 we do not give access to the user of our stack
 user can go through the stack with above fxn. mentioned
 recursion also uses stack
 stack = last in first out(LIFO)
*/
// we will create all the remaining datastructure using arrays and linked list only
// implementation of stack using stack
class StackusingArray {
	int *data;
	int nextIndex;
	int capacity;
	public:
		StackusingArray(int totalsize){
			data = new int[totalsize];
			nextIndex = 0;
			capacity = totalsize;
		}
		int size(){
			return nextIndex;
		}
		bool isEmpty(){
		/*	if (nextIndex == 0){
				return 0;
			}
			else{
				return false;
			} 
		*/
			return nextIndex == 0; // doing same work as above
		}
		void push(int element){
			if (nextIndex == capacity){
				cout << "Stack full" << endl;
				return;
			}
			data[nextIndex] = element;
			nextIndex++; 
		}
		int pop(){
			if (isEmpty()){
				cout << "Stack is Empty" << endl;
				return INT_MIN;
			}
			nextIndex--;
			return data[nextIndex];
		}
		int top(){
			if (isEmpty()){
				cout << "Stack is Empty" << endl;
				return INT_MIN;
			}
			return data[nextIndex - 1];
		}
};
int main(){
	StackusingArray	s(4);
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	
	cout << s.top() << endl;
	
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	
	cout << s.size() << endl;
	
	cout << s.isEmpty() << endl;
	return 0;
}