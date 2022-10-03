#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define aa first
#define bb second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define M_PI acos(-1)

struct pt{
    ll x;
    ll y;
    pt operator+(pt p) {return {x+p.x, y+p.y};}
    pt operator-(pt p) {return {x-p.x, y-p.y};}
    pt operator*(ll d) {return {x*d, y*d};}
    pt operator/(ll d) {return {x/d, y/d};}
};

template<class T>
bool onBoundary(vector<pair<T,T> >&polygon,pair<T,T> pn)
{
    int n=(int)polygon.size();
    for(int i=0;i<n-1;i++)
    {
        T tmp=(polygon[i].first-pn.first)*(polygon[i+1].second-pn.second)
                -(polygon[i+1].first-pn.first)*(polygon[i].second-pn.second);
        if(tmp==0
           &&((pn.first>=polygon[i].first&&pn.first<=polygon[i+1].first)||(pn.first<=polygon[i].first&&pn.first>=polygon[i+1].first))
           &&((pn.second>=polygon[i].second&&pn.second<=polygon[i+1].second)||(pn.second<=polygon[i].second&&pn.second>=polygon[i+1].second)))
        {
            return true;
        }
    }
    return false;
}

template <class T>
inline
T cross(pair<T,T> p0,pair<T,T> p1,pair<T,T> p2)
{
    return (p1.first-p0.first)*(p2.second-p0.second)-(p1.second-p0.second)*(p2.first-p0.first);
}
//winding number from a point,tested on loj timus and cses
template<class T>
int wnPnPolygon(vector<pair<T,T> >& polygon,pair<T,T> pn)
{
    //assuming polygon[n]=polygon[0]
    int n=(int)polygon.size();
    int wn=0;
    for(int i=0;i<n-1;i++)
    {
        if(polygon[i].second<=pn.second)
        {
            if(polygon[i+1].second>pn.second&&cross(pn,polygon[i],polygon[i+1])>0)
            {
                ++wn;
            }
        }
        else if(polygon[i+1].second<=pn.second&&cross(pn,polygon[i],polygon[i+1])<0)
        {
            --wn;
        }
    }
    return wn;
}
int main(){
    //FASTIO;
    int n,m;
   // scanf("%d",&n);
    cin>>n>>m;
    vector<pair<ll,ll>> poly;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        poly.push_back({a,b});
    }
    poly.push_back(poly[0]);

    while(m--){
        int a,b;
        cin>>a>>b;

        bool onEdge = onBoundary(poly,{a,b});
        if( onEdge )
            cout<<"BOUNDARY\n";
        else {
            int windingNumber = wnPnPolygon(poly,{a,b});
            if( windingNumber )
                cout<<"INSIDE\n";
            else
                cout<<"OUTSIDE\n";

        }
    }
}


