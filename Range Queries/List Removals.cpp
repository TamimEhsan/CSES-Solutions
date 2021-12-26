#include<bits/stdc++.h>
using namespace std;
//#define INF 2147483647
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

/**
    OST using BIT
    1- indexed
    order_of_key(x):    find the the number of entries lower than or equal to x
    find_by_order(k):   find the kth smallest number
    find(x):            find if a number is present in set
    erase(x):           delete a entry
    insert(x):          enter a entry
*/

class OST{
    int MAX_VAL = 1429450;
    vector<int> BIT;
    void update(int i, int add){
        while (i > 0 && i < BIT.size()){
            BIT[i] += add;
            i = i + (i & (-i));
        }
    }

    int sum(int i){
        int ans = 0;
        while (i > 0){
            ans += BIT[i];
            i = i - (i & (-i));
        }
        return ans;
    }
public:
    OST(int val){
        MAX_VAL = val;
        BIT.resize(MAX_VAL);
    }
    int find_by_order(int k){
        int l = 0;
        int h = BIT.size();
        while (l < h){
            int mid = (l + h) / 2;
            if (k <= sum(mid))
                h = mid;
            else
                l = mid+1;
        }
        return l;
    }

    void insert(int x){
        if( /*find(x) or*/ x<=0 or x>=BIT.size() ) return;
        update(x, 1);
    }

    void erase(int x){
        if( !find(x) ) return;
        update(x, -1);
    }


    int order_of_key(int x){
        if( x<=0 ) return 0;
        if( x>BIT.size() ) return sum( BIT.size()-1 );
        return sum(x);
    }
    bool find(int x){
        if( x<=0 or x>=BIT.size() ) return false;
        return sum(x)-sum(x-1)>0 ;
    }
    int size(){
        return sum( BIT.size()-1 );
    }

};

int main(){
    int n;
    cin>>n;
    OST ost(n);
    int ara[n+1];
    for(int i=1;i<=n;i++){
        cin>>ara[i];
        ost.insert(i);
    }
    int q = n;
    while(q--){
        int k;
        cin>>k;
        int pos = ost.find_by_order(k);
        ost.erase(pos);
        cout<<ara[pos]<<" ";
    }

}
