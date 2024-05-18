#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int i,int j){
    adj[i].push_back(j);
    adj[j].push_back(i);
}
void bfs(vector<int> adj[],int start,int v){
    queue<int> q;
    vector<bool> visited(v,false);
    q.push(start);
    visited[start]=true;
    while(q.size()>0){
        int front = q.front();
        std::cout << front<<" ";
        q.pop();
        for(auto x: adj[front]){
            if(!visited[x]){
                q.push(x);
                visited[x]=true;
            }
        }
    }
}
void dfs(vector<int> adj[],int start,vector<bool> &visited){
    visited[start]=true;
    std::cout << start << " ";
    for(auto x: adj[start]){
        if(!visited[x]){
            dfs(adj,x,visited);
        }
    }
}
bool cycle(vector<int> adj[],int i,int parent,vector<bool> &visited){
    visited[i]=true;
    for(auto x: adj[i]){
        if(!visited[x]){
            if(cycle(adj,x,i,visited)){
                return true;
            }
        }else if(x!=parent){
            return true;
        }
    }
    return false;
}
bool isCycle(vector<int> adj[],int v){
    vector<bool> visited(v+1,false);
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            if(cycle(adj,i,-1,visited)){
                return true;
            }
        }
    }
    return false;
}
//directed graph
bool check(vector<int> adj[],int i,vector<bool> visited,vector<bool> &s){
    visited[i]=true;
    s[i]=true;
    for(auto x: adj[i]){
        if(!visited[i]){
            if(check(adj,x,visited,s)){
                return true;
            }else if(s[i]){
                return true;
            }
        }
    }
    s[i]=false;
    return false;
}
bool checkcycle(vector<int> adj[],int v){
    vector<bool> visited(v,false);
    vector<bool> s(v,false);
    for(int i=0;i<v;i++){
        if(check(adj,i,visited,s)){
            return true;
        }
    }
    return false;
}
int main(){
    int v,e;
    std::cin >> v >> e;
    vector<int> adj[v];
    while(e--){
        int a,b;
        std:: cin >> a >> b;
        addEdge(adj,a,b);
    }
    std::cout << "bfs: ";
    bfs(adj,0,v);
    std::cout << "\ndfs: ";
    vector<bool> visited(v,false);
    dfs(adj,0,visited);
}