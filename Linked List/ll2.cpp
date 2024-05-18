#include<bits/stdc++.h>
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
void printarr(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
}
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
void print(Node * head){
    Node * temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
vector<int> deletell(Node*head){
    Node*temp = head;
    vector<int> arr;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    return arr;
}
/*bool findsame(int a,vector<int>arr){
    for(int i=0;i<arr.size();i++){
        if(abs(arr[i]==a)){
            return true;
        }
    }
    return false;
}
vector<int> removeduplicate(vector<int> arr,vector<int> arr1,vector<int> arr2){
    for(int i=0;i<arr.size();i++){
        if(findsame(abs(arr[i]),arr1)==false){
            arr2.push_back(arr[i]);
        }
    }
    return arr2;
}
vector<int> sep(vector<int>arr){
    vector<int> arr1;
    vector<int> arr2;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<0){
            arr1.push_back(arr[i]);
        }else{
            arr2.push_back(arr[i]);
        }
    }
    printarr(arr1);
    cout << endl;
    printarr(arr2);
    cout << endl;
    vector<int> arr3;
    arr3 = removeduplicate(arr1,arr2,arr3);
    arr3 = removeduplicate(arr2,arr1,arr3);
    //arr3 = remzero(arr2,arr1,arr3);
    return arr3;
}*/
void dup(vector<int>arr,vector<int>arr1){
    //printarr(arr1);
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]+arr[j]==0){
                //arr1.erase(arr1.begin()+i);
                //arr1.erase(arr1.begin()+j);
                int a = arr1.size();
                vector<int>::iterator new_end;
                new_end = remove(arr1.begin(), arr1.end(), arr[i]);
                a--;
                arr1.resize(a);
                vector<int>::iterator new_end1;
                new_end1 = remove(arr1.begin(), arr1.end(), arr[j]);
                a--;
                arr1.resize(a);
            }
        }
    }
    printarr(arr1);
}
vector<int> removezero(vector<int>arr){
    vector<int> arr2;
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=0){
            arr2.push_back(arr[i]);
        }
    }
    return arr2;
}
int main(){
    Node *head=takeInput();
    //print(head);
    vector<int> arr = deletell(head);
    vector<int> arr1 = deletell(head);
    arr1 = removezero(arr1);
    dup(arr,arr1);
    //arr = sep(arr);
   //printarr(arr);
    return 0;
}