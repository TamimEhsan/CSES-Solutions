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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r){return uniform_int_distribution<int>(l,r) (rng);}


long double getAngle(long double x,long double y){
    if( x == 0 and y == 0 ) return 0;
    else if( x == 0 and y>0 ) return pie/2;
    else if( x == 0 and y<0 ) return 3*pie/2;
    else if( y == 0 and x>0 ) return 0;
    else if( y == 0 and x<0 ) return pie;
    else if( x>0 and y>0 )return atan(y/x);
    else if( y>0 and x<0 )return pie - atan(-y/x);
    else if( y<0 and x<0 )return pie + atan(y/x);
    else if( y<0 and x>0 )return 2*pie - atan(-y/x);
    return 0;

}
int main(){
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++){
        pii p1,p2,p3;
        cin>>p1.F>>p1.S>>p2.F>>p2.S>>p3.F>>p3.S;

        p1.F-=p2.F;
        p1.S-=p2.S;
        p3.F-=p2.F;
        p3.S-=p2.S;

        long double angle1 = getAngle(p1.F,p1.S);
        long double angle2 = getAngle(p3.F,p3.S);

        if( angle2 == angle1 or  fabs(fabs(angle1-angle2) - pie) <1e-6 or (p3.F == 0 and p3.S == 0)) {
            cout<<"TOUCH"<<endl;
        }else if( angle2> angle1 and angle2 - angle1 <  pie ){
                cout<<"RIGHT"<<endl;
        }else if( angle2+2*pie-angle1<pie ){
                cout<<"RIGHT"<<endl;
        }else cout<<"LEFT"<<endl;
    }

}
