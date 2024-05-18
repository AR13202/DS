#include<bits/stdc++.h>
using namespace std;
void Recurrence_toh(int n,char s,char a,char d){
    if(n==1){
        cout << "shift Disk" << n << " from " << s << " to " << d << "\n";
    }else{
        Recurrence_toh(n-1,s,d,a);
        cout << "shift Disk" << n << " from " << s << " to " << d << "\n";
        Recurrence_toh(n-1,a,s,d);
    }
}
int main(){
    int n;
    cout << "enter no. of disks: ";
    cin >> n;
    Recurrence_toh(n,'S','A','D');
    return 0;
}