#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,m,l,r;
        cin >> n>>m>>l>>r;

        int x = n-m;
        if(x>r){
            int y = x-r;
            cout<<l+y<<" "<<0<<endl;
        }
        else cout<<l<<" "<<r-x<<endl;
        
        
        
    }
    return 0;
}