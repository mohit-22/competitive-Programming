#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k,x;
        cin >> n>>k>>x;

        int mn = (k*(k+1))/2;
        int mx = (n*(n+1))/2 - ((n-k)*((n-k)+1))/2;
        if(x>=mn && x<=mx) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
        
    }
    return 0;
}