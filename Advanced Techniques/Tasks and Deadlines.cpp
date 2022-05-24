#include "bits/stdc++.h"
using namespace std;
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ll long long


int main(){
 //ifstream cin("test_input.txt");
    int n;
    cin>>n;
    pii para[n];
    for(int i=0;i<n;i++)
        cin>>para[i].F>>para[i].S;
    sort(para,para+n);
    ll res = 0,timer = 0;
    for(int i=0;i<n;i++){
        timer+=para[i].F;
        res+=para[i].S-timer;
    }
    cout<<res;
}
