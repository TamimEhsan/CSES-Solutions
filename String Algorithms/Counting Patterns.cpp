#include<bits/stdc++.h>
using namespace std;
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define pii pair<ll,ll>
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

// Creates a suffix array in nlogn time
// searches for the occurance of a substring of size P in Plogn time
// can be modified for the number of occurance of substring t
// can be modified to find the starting index of the substrings if present

class Substring{
    public:
    string s;
    int n;
    vector<int> suffix_array;
    Substring(string str){
        s = str;
        s+="$";
        n = s.size();
        suffix_array_construction();
    }
    vector<int> sort_cyclic_shifts() {
       // int n = s.size();
        const int alphabet = 256;
        vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
        for (int i = 0; i < n; i++)
            cnt[s[i]]++;
        for (int i = 1; i < alphabet; i++)
            cnt[i] += cnt[i-1];
        for (int i = 0; i < n; i++)
            p[--cnt[s[i]]] = i;
        c[p[0]] = 0;
        int classes = 1;
        for (int i = 1; i < n; i++) {
            if (s[p[i]] != s[p[i-1]])
                classes++;
            c[p[i]] = classes - 1;
        }
        vector<int> pn(n), cn(n);
        for (int h = 0; (1 << h) < n; ++h) {
            for (int i = 0; i < n; i++) {
                pn[i] = p[i] - (1 << h);
                if (pn[i] < 0)
                    pn[i] += n;
            }
            fill(cnt.begin(), cnt.begin() + classes, 0);
            for (int i = 0; i < n; i++)
                cnt[c[pn[i]]]++;
            for (int i = 1; i < classes; i++)
                cnt[i] += cnt[i-1];
            for (int i = n-1; i >= 0; i--)
                p[--cnt[c[pn[i]]]] = pn[i];
            cn[p[0]] = 0;
            classes = 1;
            for (int i = 1; i < n; i++) {
                pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
                pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
                if (cur != prev)
                    ++classes;
                cn[p[i]] = classes - 1;
            }
            c.swap(cn);
        }
        return p;
    }
    void suffix_array_construction() {
        suffix_array = sort_cyclic_shifts();
    }
    vector<int> get_suffix_array(){
        vector<int> sorted_shifts = suffix_array;
        sorted_shifts.erase(sorted_shifts.begin());
        return sorted_shifts;
    }
    int getSubstringNumber(string t){
        int m = t.size();
        int L = 0,R = n-1;
        bool isPres = true;
        for(int i=0;i<m;i++){
            int l = L,r = R;
            int res = R+1;
            // upper bound
            while(l<=r){
                int mid = (l+r)/2;
                if( suffix_array[mid]+i>=n or s[ suffix_array[mid]+i ]<=t[i] ){
                    l = mid+1;
                }else{
                    res = mid;
                    r = mid-1;
                }
            }
            if(  res == 0 or suffix_array[res-1]+i>=n or s[ suffix_array[res-1]+i ] != t[i] ){
                isPres = false;
                break;
            } else{
                R = res-1;
            }
            // lower bound
            l = L; r = R;
            res = -1;
            while(l<=r){
                int mid = (l+r)/2;
                if( suffix_array[mid]+i>=n or s[ suffix_array[mid]+i ]<t[i] ){
                    l = mid+1;
                }else{
                    res = mid;
                    r = mid-1;
                }
            }
            if( res == -1 or suffix_array[res]+i>=n or s[ suffix_array[res]+i ] != t[i] ){

                isPres = false;
                break;
            } else{
                L = res;
            }
        }
        if( isPres ){

            return R-L+1;
        } else{
            return 0;
        }
    }
};

int main(){
    string s = "abaab";
    cin>>s;
    Substring sbstr = Substring(s);
    int tc;
    cin>>tc;
    while(tc--){
        string t;
        cin>>t;
        cout<<sbstr.getSubstringNumber(t)<<endl;
    }
}
