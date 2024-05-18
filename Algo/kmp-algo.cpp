#include<bits/stdc++.h>
using namespace std;
//abcxabcdabcdabcy
//0000123000000000
int* getlps(string pattern){
    int len = pattern.length();
    int *lps = new int[len];
    lps[0] = 0;
    int i=1,j=0;
    while(i<len){
        if(pattern[i]==pattern[j]){
            lps[i] = j+1;
            i++,j++;
        }else{
            if(j!=0){
                j = lps[j-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
    }
    for(int i=0;i<len;i++){
    	cout << lps[i] << " ";
	}
    return lps;
}
bool kmpsearch(string text,string pattern){
    int lentext = text.length();
    int lenpat = pattern.length();
    int *lps = getlps(pattern);
    int i=0,j=0;
    while(i<lentext && j<lenpat){
        if(text[i]==pattern[j]){
            i++,j++;
        }else{
            if(j!=0){
                j = lps[j-1];
            }else{
                i++;
            }
        }
    }
    if(j==lenpat){
        return true;
    }
    return false;  
}
int main(){
    string s = "abcxabcdabcdabcy";
    string a = "abcdabcx";
    cout << kmpsearch(s,a);
}