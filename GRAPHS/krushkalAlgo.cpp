#include<bits/stdc++.h>
using namespace std;

int find(int i,vector<int> &parent){
    if(parent[i]==-1){
        return i;
    }
    return parent[i] = find(parent[i],parent);
}
void unite(int a,int b,vector<int> &rank,vector<int> &parent){
    int s1 = find(a,parent);
    int s2 = find(b,parent);
    if(s1!=s2){
        if(rank[s1]<rank[s2]){
            parent[s1]=s2;
        }else if(rank[s1]>rank[s2]){
            parent[s2]=s1;
        }else{
            parent[s2]=s1;
            rank[s1]++;
        }
    }
}
int krushkalAlgo(int n,vector<vector<int>> v){
    sort(v.begin(),v.end());
    vector<int> parent(n,-1);
    vector<int>rank(n,1);
    int ans = 0;
    for(auto x: v){
        int a = x[1];
        int b = x[2];
        int w = x[0];

        int s1 = find(a,parent);
        int s2 = find(b,parent);
        if(s1!=s2){
            unite(a,b,rank,parent);
            ans+=w;
            std::cout << a << " -- " << b << " == " << w<< endl;
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> v = { {10, 0, 1},{6, 0, 2},{5, 0, 3},{15, 1, 3},{4, 2, 3}};
    std::cout << "cost of mst: " << krushkalAlgo(5,v);
}