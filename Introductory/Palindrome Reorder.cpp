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
        string s;
        cin>>s;
        int n = s.size();
        sort(s.begin(),s.end());
        vector<pair<char,int>> even,odd;
        int lastIndex = 0;
        for(int i=1;i<n;i++){
            if( s[i]!=s[i-1] ){
                if( (i-lastIndex)%2 == 0 ){
                    even.pb(mp(s[i-1],i-lastIndex));
                } else{
                    odd.pb(mp(s[i-1],i-lastIndex));
                }
                lastIndex = i;
            }
        }
        if( (n-lastIndex)%2 == 0 ){
            even.pb(mp(s[n-1],n-lastIndex));
        } else{
            odd.pb(mp(s[n-1],n-lastIndex));
        }
        if( odd.size()>1 or ( odd.size() == 1 and n%2 == 0 )  ){
            cout<<"NO SOLUTION";
            return 0;
        }
        for(int i=0;i<even.size();i++){
            for(int j = 0;j<even[i].S/2;j++){
                cout<<even[i].F;
            }
        }
        for(int i=0;i<odd.size();i++){
            for(int j = 0;j<odd[i].S;j++){
                cout<<odd[i].F;
            }
        }
        for(int i=even.size()-1;i>=0;i--){
            for(int j = 0;j<even[i].S/2;j++){
                cout<<even[i].F;
            }
        }
    }
}


