#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,q;
    cin>>n>>q;
    int ara[n+5];
    int pos[n+5];
 
    for(int i=1;i<=n;i++){
        cin>>ara[i];
        pos[ ara[i] ] = i;
    }
    pos[0] = n+1;
    pos[n+1] = n+2;
 
    int cost = 0;
    for(int i=1;i<=n;i++){
        if( pos[i]<pos[i-1] ) cost++;
    }
   // cout<<cost<<endl;
 
    while(q--){
        int posx,posy,x,y;
        cin>>posx>>posy;
        x = ara[posx];
        y = ara[posy];
 
       // cout<<x<<" "<<y<<endl;
 
        if( pos[x]<pos[x-1] ) cost--;
        if( pos[x+1]<pos[x] and x+1!=y ) cost--;
 
        if( pos[y]<pos[y-1] ) cost--;
        if( pos[y+1]<pos[y] and y+1!=x ) cost--;
 
        swap( ara[posx],ara[posy] );
        swap( pos[x],pos[y] );
 
        swap(x,y);
 
      //  for(int i=1;i<=n;i++) cout<<ara[i]<<" "; cout<<endl;
     //   for(int i=1;i<=n;i++) cout<<pos[i]<<" "; cout<<endl;
 
        if( pos[x]<pos[x-1] ) cost++;
        if( pos[x+1]<pos[x] and x+1!=y ) cost++;
 
        if( pos[y]<pos[y-1] ) cost++;
        if( pos[y+1]<pos[y] and y+1!=x ) cost++;
 
        cout<<cost<<endl;
 
    }
 
}
