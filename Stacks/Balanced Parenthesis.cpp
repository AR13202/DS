#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    string s;
    int v=0;
    stack<char> s1;
    cin >> s;
    for (int i = 0;i <s.length();i++){
        if (s[i]=='{' || s[i]=='[' || s[i]=='('){
            s1.push(s[i]);
        }else if(!s1.empty()){
            if ((s[i]=='}' && s1.top() == '{') || (s[i]==']' && s1.top() == '[') || 
            (s[i]==')' && s1.top() == '(')){
                s1.pop();
            }else{
                break;
            }
        }else{
            v=1;
            break;
        } 
    }
    if (s1.empty() && v==0){
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}