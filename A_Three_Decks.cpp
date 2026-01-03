#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int x,y,z;
        cin>>x>>y>>z;
        int w = y-x;
        int m = z-w;
        int p = m-y;
        if(p>=0 && p%3==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}