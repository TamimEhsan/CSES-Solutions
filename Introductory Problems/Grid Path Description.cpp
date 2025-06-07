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
 
string s;
int res = 0;
ll setBit( ll vis,int x,int y ){
    int pos = x*7+y;
    return vis | (ll)1<<pos;
}
bool visited[7][7];
inline bool isVisited(int x,int y ){
    if( x< 0 or y<0 or x>=7 or y>=7  ) return true;
    return visited[x][y];
}
 
// L,R,U,D
void dfs(int x,int y,int pos){
    if( x == 6 and y == 0 and pos!=48 ) return;
    if( x == 6 and y == 0 and pos == 48){
        res++;
        return;
    }
    if( pos>=48 ) return;
    visited[x][y] = true;
    if( s[pos] == 'L' ){
        int tmpx = x;
        int tmpy = y-1;
        if( !isVisited(tmpx,tmpy) ){
            dfs(tmpx,tmpy,pos+1);
        }
    } else if( s[pos] == 'R' ){
        int tmpx = x;
        int tmpy = y+1;
        if( !isVisited(tmpx,tmpy) ){
            dfs(tmpx,tmpy,pos+1);
        }
    } else if( s[pos] == 'U' ){
        int tmpx = x-1;
        int tmpy = y;
        if( !isVisited(tmpx,tmpy) ){
            dfs(tmpx,tmpy,pos+1);
        }
    } else if( s[pos] == 'D' ){
        int tmpx = x+1;
        int tmpy = y;
        if( !isVisited(tmpx,tmpy) ){
            dfs(tmpx,tmpy,pos+1);
        }
    }else{
        if( !isVisited(x+1,y) and !isVisited(x-1,y) and isVisited(x,y+1) and isVisited(x,y-1) ) { visited[x][y] = false;return;}
        if( isVisited(x+1,y) and isVisited(x-1,y) and !isVisited(x,y+1) and !isVisited(x,y-1) ) { visited[x][y] = false;return;}
 
        if( !isVisited(x+1,y) ) dfs( x+1,y,pos+1);
        if( !isVisited(x-1,y) ) dfs( x-1,y,pos+1);
        if( !isVisited(x,y+1) ) dfs( x,y+1,pos+1);
        if( !isVisited(x,y-1) ) dfs( x,y-1,pos+1);
    }
    visited[x][y] = false;
}
 
int main(){
    int t = 1;
    FASTIO;
   // scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
       // s="????????????????????????????????????????????????";
        cin>>s;
        dfs(0,0,0);
        cout<<res<<endl;
    }
}
