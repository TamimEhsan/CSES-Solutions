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

int cnt[1000007];

int findMaxGCD(int ara[],int n){
    for(int i=0;i<n;i++){
        for(int j=1;j*j<=ara[i];j++){
            if( ara[i]%j == 0 ){
                cnt[j]++;
                cnt[ara[i]/j]++;
                if( j*j == ara[i] ) cnt[j]--;
            }
        }
    }
    for(int i=ara[n-1];i>=0;i--){
        if( cnt[i]>1 ) return i;
    }

}

int main(){
    int n;
    cin>>n;
    int ara[n];
    for(int i=0;i<n;i++) cin>>ara[i];
    sort(ara,ara+n);
    cout<<findMaxGCD(ara,n);
}

