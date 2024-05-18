#include<bits/stdc++.h>
using namespace std;
int evaluate(string s){
    stack<int> s1;
    for(int i=0;i<s.length();i++){
        if(s[i]>='1' && s[i]<='9'){
            s1.push(s[i]-48);
        }else{
            int a=s1.top();
            s1.pop();
            int b = s1.top();
            s1.pop();
            int c;
            switch(s[i]){
                case '*':
                    c = a*b;
                    break;
                case '+':
                    c=a+b;
                    break;
                case '-':
                    c=b-a;   
                    break;
                case '/':
                    c=b/a;
                    break;  
                case '^':
                    c = pow(b,a);
                    break;              
            }
            s1.push(c);
        }
    }
    return s1.top();
}
int main(){
    string s = "231*+9-";
    cout << evaluate(s) << endl;
}