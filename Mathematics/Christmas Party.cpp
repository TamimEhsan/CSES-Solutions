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

const int N=1000007;
ll derangement[N];
void calcDerangement(){
    derangement[0] = 1;
    derangement[1] = 0;
    for(int i=2;i<N;i++){
        derangement[i] = ((i-1)*(derangement[i-1]+derangement[i-2])%M)%M;
    }
}

int main(){
    calcDerangement();
    int n;
    cin>>n;
    cout<<derangement[n];
}

/*
!n=(n-1)(!(n-1)+!(n-2))
*/
