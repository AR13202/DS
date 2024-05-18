#include<bits/stdc++.h>
using namespace std;
int priority(char a){
    if(a=='+' || a=='-'){
        return 1;
    }else if(a=='*'||a=='/'||a=='%'){
        return 2;
    }else if(a=='^'){
        return 3;
    }
    return 0;
}
void printstack(stack<char> s){
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
string infixtopostfix(string a){
    string w="";
    stack<char>s;
    for(int i=0;i<a.length();i++){
        char b = a[i];
        if((b >= 'a' && b <= 'z') || (b >= 'A' && b<= 'Z')){
            w += b;
        }else if(b=='('){
            s.push(b);
        }else if(b==')'){
            while(s.top()!='('){
                w+=s.top();
                s.pop();
            }
            s.pop();
        }else {
            while(!s.empty() && priority(b)<=priority(s.top())){
                w+=s.top();
                s.pop();
            }
            s.push(b);
        }
    }
    while(!s.empty()){
        w+=s.top();
        s.pop();
    }
    return w;
}
int main(){
    string a = "A+B*C+D";
    cout << infixtopostfix(a) << endl;
}