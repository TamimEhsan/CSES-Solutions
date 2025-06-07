#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
unordered_map<string,int> vis;
string initial = "123456789";
 
void dfs(){
 
    queue<string> q;
    q.push(initial);
    vis[initial] = 1;
    while(!q.empty()){
        string u = q.front();
        q.pop();
        int costu = vis[u];
        for(int i=0;i<9;i++){
            if( i%3 !=2  ){
                swap(u[i],u[i+1]);
                if( vis[u] == 0 ){
                    vis[u] = costu+1;
                    q.push(u);
                }
                swap(u[i],u[i+1]);
            }
            if( i<6 ){
                swap(u[i],u[i+3]);
                if( vis[u] == 0 ){
                    vis[u] = costu+1;
                    q.push(u);
                }
                swap(u[i],u[i+3]);
            }
        }
    }
}
 
 
int main(){
    dfs();
    string s;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int a;
            cin>>a;
            s+=a+'0';
        }
    }
    cout<<vis[s]-1;
}