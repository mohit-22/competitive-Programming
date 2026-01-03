#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(a==1 && b==0) cout<<1<<endl;
        else if(a==1 && b==1) cout<<3<<endl;
        else if(a==1 && b!=a) cout<<2<<endl;
        // else if(a>=2 && b==0) cout<<
        
    }
    return 0;
}