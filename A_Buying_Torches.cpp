#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int x,y,k;
        cin >> x>>y>>k;

        int t = y*k + k-1;
        if(t%(x-1)==0) cout<<(t/(x-1)+k)<<endl;
        else cout<<(t/(x-1)+1+k)<<endl;
        
    }
    return 0;
}



