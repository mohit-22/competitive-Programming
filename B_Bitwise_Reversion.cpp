#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int a,b,c;
        cin >> a>>b>>c;
        bool flag=true;
        for(int i=31 ; i>=0 ; i--){
            int ct=0;
            if(((a>>i) & 1)==1) ct++;
            if(((b>>i) & 1)==1) ct++;
            if(((c>>i) & 1)==1) ct++;
            if(ct==2){
                flag=false;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    return 0;
}