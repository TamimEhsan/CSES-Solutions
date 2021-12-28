#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r){return uniform_int_distribution<int>(l,r) (rng);}

typedef tree < int,  null_type,  less < int >,  rb_tree_tag,  tree_order_statistics_node_update > o_set;
typedef tree < pair < int, int >,  null_type,  less < pair < int, int > >,  rb_tree_tag,  tree_order_statistics_node_update > o_setp;
 o_setp s;

 /*
 s.insert(1);
 s.find(18))
 *s.find_by_order(1)
 s.order_of_key(4)
 */

/**
the tree supports the same operations as the set
but also there are two new features —
find_by_order() : The first returns an iterator to the k-th largest element (counting from zero)
order_of_key() : The number of items in a set that are strictly smaller than our item.
*/

int main(){
    FASTIO;
    int n,q;
    cin>>n>>q;
    int ara[n+1];
    for(int i=1;i<=n;i++){
        cin>>ara[i];
        s.insert({ara[i],i});
    }
    while(q--){
        char c;
        cin>>c;
        if( c == '?' ){
            int a,b;
            cin>>a>>b;
            cout<<s.order_of_key({b,MOD}) - s.order_of_key({a-1,MOD})<<endl;
        }else{
            int k,x;
            cin>>k>>x;
            s.erase({ara[k],k});
            ara[k] = x;
            s.insert({ara[k],k});
        }
    }
}
