#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'



bool check(string &s,int k){
    int i=0;
    while( s[i] == '0' ) i++; // ignore leading zeros

    for(;i<=k;i++){
        if( s[i] == s[i-1] ) return false;
    }
    return true;
}

ll mul[20];
void prec(){
    mul[0] = 1;
    for(int i=1;i<20;i++) mul[i] = mul[i-1]*9;
}

void solve(){
    string sl,sr;
    cin>>sl>>sr;



    // case 1: l has less digits than r, so we can change each digits of l to any digit
    //  we can pad 0 to the smol number to make them equal
    while(sl.size()<sr.size()) sl = "0"+sl;

    ll res = 0;
    int n = sl.size();
    if(check(sl,n-1)) res++;
    if(check(sr,n-1)) res++;

    // now we have some prefix of l and r to be same, so, those must be same for our answer too
    int firstDif = -1;
    for(int i=0;i<sl.size();i++){
        if( sl[i]!=sr[i] ){
            firstDif = i;
            break;
        }
    }

    // now firstDif has the first index where the digits are different
    // case 2: all are same ie l = r
    if( firstDif == -1 ){
        if( res == 2 ) res = 1; // correct overcount
        cout<<res<<endl;
        return;
    }
    // case 3: first diff,fd position will have digit strictly greater than sl[fd]
    // and strictly less than sr[fd], remaining digits can be anything,
    for(int d=sl[firstDif]-'0'+1;d<sr[firstDif]-'0';d++){
        string tres = sl;
        tres[firstDif] = d+'0';
        if( check(tres,firstDif) ){
            int rem = n-firstDif-1;
            res+=mul[rem];
        }
    }

    // case 4: prefix of tres is same as sl and the next digit is strictly greater than that of sl
    // other digits can be anything,
    for(int i=firstDif+1;i<sl.size();i++){
        for(int d=sl[i]-'0'+1;d<10;d++){
            string tres = sl;
            tres[i] = d+'0';
            if( check(tres,i) ){
                int rem = n-i-1;
                res+=mul[rem];

            }
        }
    }

    // case 5: prefix of tres is same as sr and the next digit is strictly smaller than that of sr
    // other digits can be anything,
    for(int i=firstDif+1;i<sr.size();i++){
        for(int d=sr[i]-'0'-1;d>=0;d--){
            string tres = sr;
            tres[i] = d+'0';
            if( check(tres,i) ){
                int rem = n-i-1;
                res+=mul[rem];
            }
        }
    }


    cout<<res<<endl;
}

int main(){
    FASTIO;
    prec();
   int tc=1;
   //cin>>tc;

    while(tc--){
        solve();
    }
}

// https://cses.fi/problemset/task/2220/
// https://codeforces.com/contest/1808/problem/C
