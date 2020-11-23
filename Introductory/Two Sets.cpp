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
    int t = 1;
    //scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        int n;
        cin>>n;
        ll sum = (ll) n*(n+1)/2;
        if( sum%2 != 0 ){
            cout<<"NO"<<endl;
            return 0;
        }
        cout<<"YES"<<endl;
        sum/=2;
        int start = 0;
        for(int i = n;i>=0;i--){
            if( sum-i>=0 ){
                sum-=i;
            } else{
                start = i+1;
                break;
            }
        }
        if( sum ){
            cout<<n-start+2<<endl<<sum<<" ";
        }else{
            cout<<n-start+1<<endl;
        }
        for(int i=start;i<=n;i++){
            cout<<i<<" ";
        }
        if( sum ){
            cout<<endl<<start-2<<endl;
        } else{
            cout<<endl<<start-1<<endl;
        }
        for(int i=1;i<start;i++){
            if( i!=sum ) cout<<i<<" ";
        }
    }
}
