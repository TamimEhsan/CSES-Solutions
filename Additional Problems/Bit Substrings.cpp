#include<bits/stdc++.h>
using namespace std;
#define INF 2047483647
#define INFL 9223372036854775807
//#define ll long long
#define pii pair<ll,ll>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ull unsigned long long
//#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353
#define endl '\n'




const int N = 200005;
int ara[N];
vector<long long> zeroes,invZeroes;

//<============FFT Starts=============>\\


//typedef complex<double> CD;
struct CD {
    double x, y;
    CD(double x=0, double y=0) :x(x), y(y) {}
    CD operator+(const CD& o) { return {x+o.x, y+o.y};}
    CD operator-(const CD& o) { return {x-o.x, y-o.y};}
    CD operator*(const CD& o) { return {x*o.x-y*o.y, x*o.y+o.x*y};}
    void operator /= (double d) { x/=d; y/=d;}
    double real() {return x;}
    double imag() {return y;}
};
CD conj(const CD &c) {return CD(c.x, -c.y);}

typedef long long LL;
const double PI = acos(-1.0L);

namespace FFT {
    int N;
    vector<int> perm;
    vector<CD> wp[2];

    void precalculate(int n) {
        assert((n & (n-1)) == 0);
        N = n;
        perm = vector<int> (N, 0);
        for (int k=1; k<N; k<<=1) {
            for (int i=0; i<k; i++) {
                perm[i] <<= 1;
                perm[i+k] = 1 + perm[i];
            }
        }

        wp[0] = wp[1] = vector<CD>(N);
        for (int i=0; i<N; i++) {
            wp[0][i] = CD( cos(2*PI*i/N),  sin(2*PI*i/N) );
            wp[1][i] = CD( cos(2*PI*i/N), -sin(2*PI*i/N) );
        }
    }

    void fft(vector<CD> &v, bool invert = false) {
        if (v.size() != perm.size())    precalculate(v.size());

        for (int i=0; i<N; i++)
            if (i < perm[i])
                swap(v[i], v[perm[i]]);

        for (int len = 2; len <= N; len *= 2) {
            for (int i=0, d = N/len; i<N; i+=len) {
                for (int j=0, idx=0; j<len/2; j++, idx += d) {
                    CD x = v[i+j];
                    CD y = wp[invert][idx]*v[i+j+len/2];
                    v[i+j] = x+y;
                    v[i+j+len/2] = x-y;
                }
            }
        }

        if (invert) {
            for (int i=0; i<N; i++) v[i]/=N;
        }
    }

     void pairfft(vector<CD> &a, vector<CD> &b, bool invert = false) {
        int N = a.size();
        vector<CD> p(N);
        for (int i=0; i<N; i++) p[i] = a[i] + b[i] * CD(0, 1);
        fft(p, invert);
        p.push_back(p[0]);

        for (int i=0; i<N; i++) {
            if (invert) {
                a[i] = CD(p[i].real(), 0);
                b[i] = CD(p[i].imag(), 0);
            }
            else {
                a[i] = (p[i]+conj(p[N-i]))*CD(0.5, 0);
                b[i] = (p[i]-conj(p[N-i]))*CD(0, -0.5);
            }
        }
    }

    vector<LL> multiply(const vector<LL> &a, const vector<LL> &b) {
        int n = 1;
        while (n < a.size()+ b.size())  n<<=1;

        vector<CD> fa(a.begin(), a.end()), fb(b.begin(), b.end());
        fa.resize(n); fb.resize(n);

//        fft(fa); fft(fb);
        pairfft(fa, fb);
        for (int i=0; i<n; i++) fa[i] = fa[i] * fb[i];
        fft(fa, true);

        vector<LL> ans(n);
        for (int i=0; i<n; i++)     ans[i] = round(fa[i].real());
        return ans;
    }

    const int M = 13313 , B = sqrt(M)+1;
    vector<LL> anyMod(const vector<LL> &a, const vector<LL> &b) {
        int n = 1;
        while (n < a.size()+ b.size())  n<<=1;
        vector<CD> al(n), ar(n), bl(n), br(n);

        for (int i=0; i<a.size(); i++)  al[i] = a[i]%M/B, ar[i] = a[i]%M%B;
        for (int i=0; i<b.size(); i++)  bl[i] = b[i]%M/B, br[i] = b[i]%M%B;

        pairfft(al, ar); pairfft(bl, br);
//        fft(al); fft(ar); fft(bl); fft(br);

        for (int i=0; i<n; i++) {
            CD ll = (al[i] * bl[i]), lr = (al[i] * br[i]);
            CD rl = (ar[i] * bl[i]), rr = (ar[i] * br[i]);
            al[i] = ll; ar[i] = lr;
            bl[i] = rl; br[i] = rr;
        }

        pairfft(al, ar, true); pairfft(bl, br, true);
//        fft(al, true); fft(ar, true); fft(bl, true); fft(br, true);

        vector<LL> ans(n);
        for (int i=0; i<n; i++) {
            LL right = round(br[i].real()), left = round(al[i].real());;
            LL mid = round(round(bl[i].real()) + round(ar[i].real()));
            ans[i] = ((left%M)*B*B + (mid%M)*B + right)%M;
        }
        return ans;
    }
}

//<============FFT Ends=============>\\


void solve(){

    string s;
    cin>>s;
    int cnt = 0;
    long long zero = 0;
    for(auto c:s){
        if( c == '0' ) cnt++;
        else{
            zeroes.push_back(cnt+1);
            invZeroes.push_back(cnt+1);
            zero+=1LL*cnt*(cnt+1)/2;
            cnt = 0;
        }
    }
    zero+=1LL*cnt*(cnt+1)/2;
    zeroes.push_back(cnt+1);
    invZeroes.push_back(cnt+1);
    reverse(invZeroes.begin(),invZeroes.end());
   // for(auto z:zeroes) cout<<z<<" ";
    auto ret = FFT::multiply(zeroes,invZeroes);

    cout<<zero<<" ";
    for(int i=zeroes.size();i<zeroes.size()+s.size();i++) {
        if( i>=ret.size() ) cout<<0<<" ";
        else cout<<ret[i]<<" ";
    }
}
int main(){
    FASTIO;
    int tc=1;
    //cin>>tc;
    while(tc--)
    solve();



}
