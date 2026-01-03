#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >>a>>b;

        if(a==b) cout<<0<<" "<<0<<endl;
        else if(a+1==b || b+1==a) cout<<1<<" "<<0<<endl;
        else{
            int mn = min(a,b);
            int d = abs(a-b);
            int r = mn%d;
            int s = min(r,d-r);
            cout<<d<<" "<<s<<endl;
        }
        
    }
    return 0;
}