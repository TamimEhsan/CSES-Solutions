#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

string s;
bool check_possibility(int cur, int c, pair<int,int> mode) {
    int rem;
    int cnt;
    if(mode.second == c) {
        rem = s.size() - cur - 2;
        cnt = mode.first-1;
    } else {
        rem = s.size() - cur - 1;
        cnt = mode.first;
    }
    int req = (rem+1)/2;
    if ( cnt > req ) return false;
    return true;
}
void solve() {
    cin>>s; 
    string res = "";
    int n = s.size();
    int freq[26] = {0};
    for(auto c:s) freq[c-'A']++;
    for(int i=0;i<n;i++) {

        pair<int,int> mode = {-1,0};
        pair<int,int> mode_2 = {-1,0};
        for(int j=0;j<26;j++) {
            if(freq[j] == 0) continue;
            if ( make_pair(freq[j], j) > mode ) {
                mode_2 = mode;
                mode = {freq[j],j};
            } else if ( make_pair(freq[j], j) > mode_2 ) {
                mode_2 = {freq[j],j};
            } 
        }

        bool possible = false;
        for(int j=0;j<26;j++) {
            if(freq[j] == 0 or (res.size()!=0 and res.back() == j+'A')) continue;
            // cout<<"checking for "<<(char)(j+'A')<<endl;
            if( !check_possibility(i,j,mode) or !check_possibility(i,j, mode_2) ) continue;
            possible = true;
            res += 'A'+j;
            freq[j]--;
            break;
        }
        if(!possible) {
            cout<<-1;
            return;
        }
    }
    cout<<res;
}

signed main() {
    //FASTIO;
    int tc = 1;
    // cin>>tc;

    for(int i=1;i<=tc;i++) {
        solve();
    }
}
