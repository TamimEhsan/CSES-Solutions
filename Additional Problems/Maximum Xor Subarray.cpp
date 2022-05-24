#include <bits/stdc++.h>
using namespace std;


const int N = 2e5+5;
int trie[N*30][2];

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
int invert(int N,int pos){return N=N ^ (1<<pos);}

int counter = 0;
void insert(int n){
    int node = 0;
    for(int i=30;i>=0;i--){
        int d = (n>>i)&1;
        if( trie[node][d] == 0 ) trie[node][d] = ++counter;
        node = trie[node][d];
    }
}

int searchd(int n){
    int node = 0,ans = 0;
    for(int i=30;i>=0;i--){
        int d = (n>>i)&1;
        d = 1 - d;
        if( trie[node][d] != 0 ){
             node = trie[node][d];
             ans+=(1<<i);
        }else {
            node = trie[node][1-d];
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int xorr = 0;
    int mx = 0;
    insert(0);
    while(n--){
        int x;
        cin>>x;
        xorr^=x;
        insert(xorr);
        mx = max( mx,searchd(xorr) );
    }
    cout<<mx;
}
