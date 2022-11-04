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
string s[8];
int res = 0;
bool H[8],V[8],CX[16],CY[16];
void mark(int x,int y){
    H[y] = V[x] = CX[x+y] = CY[x-y+7] = true;
}
void unMark(int x,int y){
    H[y] = V[x] = CX[x+y] = CY[x-y+7] = false;
}
bool isVisited(int x,int y){
    if( H[y] or V[x] or CX[x+y] or CY[x-y+7] ) return true;
    else return false;
}
void backtrack(int pos){
    if( pos == 8 ){
        res++;
        return;
    }
    for(int i = 0;i<8;i++){
        if( s[pos][i] == '.' and !isVisited(pos,i) ){
            mark(pos,i);
            backtrack(pos+1);
            unMark(pos,i);
        }
    }
}
int main(){
    int t = 1;
    //scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        for(int i=0;i<8;i++){
            cin>>s[i];
        }
        backtrack(0);
        cout<<res;
    }
}
/*
........
........
..*.....
........
........
.....**.
...*....
........
*/
