#include<bits/stdc++.h>
using namespace std;
#define INF 2147483647
#define INFL 9223372036854775807
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353

int main(){
    int n,x;
    take(x); take(n);
    int ara[n];
    for(int i=0;i<n;i++){
        take(ara[i]);
    }
    multiset<int> ms;
    set<int> s;
    s.insert(0);
    s.insert(x);
    ms.insert(x);
    int res = 0;
    for(int i=0;i<n;i++){
       auto it = s.lower_bound(ara[i]);
       it--;
       auto it2 = s.upper_bound(ara[i]);
       int dif = *it2-*it;
       ms.erase(ms.find(dif));
       ms.insert(*it2-ara[i]);
       ms.insert(ara[i]-*it);
       auto it3 = ms.end();
       it3--;
       printf("%d ",*it3);
       s.insert(ara[i]);
    }

}
