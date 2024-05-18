#include<bits/stdc++.h>
using namespace std;
int evaluate(string s){
    stack<int> s1;
    int z = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            if(z==0){
                continue;
            }else{
                s1.push(z);
                z=0;
            }
        }else if(s[i]>='1' && s[i]<='9'){
            z = z*10 + (s[i]-48);
        }else{
            if(s1.empty()){
                return 0;
            }
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
    string s = "23 31 45 * + 95 -";
    cout << evaluate(s) << endl;
}
//1323