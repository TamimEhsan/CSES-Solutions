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

const int N = 1e6+5;
int change[N];
int main(){
    int n;
    cin>>n;
    change[n] = 1;
    for(int i=n;i>0;i--){
        int num = i;
        if( change[i] == 0 ) continue;
        while(num){
            int digit = num%10;
            num/=10;
            if( i-digit<0 ) continue;
            if( change[i-digit] == 0 ) change[i-digit] = change[i]+1;
            else change[i-digit] = min( change[i-digit], change[i]+1 );
            //cout<<i<<" to "<<i-digit<<" in moves "<<change[i-digit]<<endl;
        }
    }
    cout<<change[0]-1;
}

