#include <iostream>
using namespace std;
template <typename T>
class queue{
    T *data;
    int capacity;
    int nextIndex;
    int firstIndex;
    int size;
    public:
    queue(){
        data = new T[4];
        capacity = 4;
        firstIndex = -1;
        nextIndex = 0;
        size = 0;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    void enqueue(T x){
        if (size == capacity){
            cout << "Queue full"<< endl;
            return;
        }
        data[nextIndex] = x;
        nextIndex=(nextIndex+1)%capacity;
        if(firstIndex == -1){
            firstIndex = 0;
        }
        size++;
    }
    T front(){
        if (isEmpty()){
            cout << "queue empty"<< endl;
            return 0;
        }
        return data[firstIndex];
    }
    T dequeue(){
        if (isEmpty()){
            cout << "queue empty"<< endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex++;
        size--;
        return ans;
    }
};
int main(){
    queue<int> q;
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
