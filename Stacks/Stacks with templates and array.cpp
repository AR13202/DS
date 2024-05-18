#include <iostream>
#include <climits>
using namespace std;
template <typename T>
class StackusingArray {
	T *data;
	int nextIndex;
	int capacity;
	public:
		StackusingArray(){
			data = new T[4];
			nextIndex = 0;
			capacity = 4;
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
			return nextIndex == 0;
		}
		void push(T element){
			if (nextIndex == capacity){
                T *newData = new T[2 *capacity];
                for (int i = 0;i < capacity; i++){
                    newData[i] = data[i];
                }
                capacity *= 2;
                delete [] data;
                data = newData;
				// cout << "Stack full" << endl;
				// return;
			}
			data[nextIndex] = element;
			nextIndex++; 
		}
		T pop(){
			if (isEmpty()){
				cout << "Stack is Empty" << endl;
				return 0;
			}
			nextIndex--;
			return data[nextIndex];
		}
		T top(){
			if (isEmpty()){
				cout << "Stack is Empty" << endl;
				return 0;
			}
			return data[nextIndex - 1];
		}
};
int main(){
	StackusingArray<int> s;
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