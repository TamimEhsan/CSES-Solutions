#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>


int main(){
    string s;
    cin>>s;
    map<char,int> m;
    char chara[] = {'A','C','G','T'};
    for(int i=0;i<4;i++)
        m[ chara[i] ] = i;
    int first[] = {-1,-1,-1,-1};
    int seen = 0;
    string t;
    for(int i=0;i<s.size();i++){
        int c = m[ s[i] ];
        if( first[c] == -1 ){
            first[c] = 1;
            seen++;
        }
        if( seen == 4 ){
            t+=s[i];
            first[0] = first[1] = first[2] = first[3] = -1;
            seen = 0;
        }
    }
    for(int i=0;i<4;i++){
        if( first[i] == -1 ){
            t+=chara[i];
            break;
        }
    }
    cout<<t<<endl;
}
