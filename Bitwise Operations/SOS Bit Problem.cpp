#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
const int N = (1<<21);
const int S = 21;
int sosDp[N][S];
int sosDp2[N][S];
int sosDp3[N][S];
 
 
int invert(int n){
   // cout<<"inverting "<<n<<" ";
    for(int i=0;i<S-1;i++)
        n ^= (1<<i);
    //cout<<n<<endl;
    return n;
}
int main(){
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    //ifstream cin("test_input.txt");
    int n;
    cin>>n;
    int ara[n];
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ara[i] = x;
        sosDp[x][0]++;
        sosDp2[x][0]++;
        sosDp3[x][0]++;
    }
    for(int bitmask=0;bitmask< (1<<S-1);bitmask++){
        for(int j=1;j<S;j++){
            if( bitmask & (1<<(j-1)) ){
                sosDp[bitmask][j]+=sosDp[bitmask][j-1];
                sosDp[bitmask][j]+=sosDp[bitmask^(1<<(j-1))][j-1];
            }else{
                sosDp[bitmask][j]+=sosDp[bitmask][j-1];
            }
        }
    }
 
    for(int bitmask=(1<<S-1)-1;bitmask>=0;bitmask--){
        for(int j=1;j<S;j++){
            if( bitmask & (1<<(j-1)) ){
                sosDp2[bitmask][j]+=sosDp2[bitmask][j-1];
 
            }else{
                sosDp2[bitmask][j]+=sosDp2[bitmask][j-1];
                sosDp2[bitmask][j]+=sosDp2[bitmask^(1<<(j-1))][j-1];
            }
        }
    }
 
 
 
    for(int i=0;i<n;i++){
        cout<<sosDp[ ara[i] ][S-1]<<" "<<sosDp2[ ara[i] ][S-1]<<" "<<n-sosDp[ invert( ara[i] )][S-1]<<endl;
 
    }
}