#include "bits/stdc++.h"
using namespace std;

void tower(int pegs,int from,int to){
    if( pegs == 1 ){
        cout<<from<<" "<<to<<endl;
        return;
    }
    tower(pegs-1,from,6-from-to);
    cout<<from<<" "<<to<<endl;
    tower(pegs-1,6-from-to,to);
}

int main(){
    int n;
    cin>>n;
    cout<<(1<<n)-1<<endl;
    tower(n,1,3);
}
