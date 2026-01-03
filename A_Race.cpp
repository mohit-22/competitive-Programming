#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int a,x,y;
        cin >> a>>x>>y;

        if(x>a && y>a || x<a && y<a) cout<<"YES\n"; 
       
        else cout<<"NO\n"; 
        
    }
    return 0;
}