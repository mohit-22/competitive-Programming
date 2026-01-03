#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n>>k;
        string s;
        cin>>s;
        int ones=0;
        for(int i=0 ; i<n ; i++){
            if(s[i]=='1') ones++;
        }
        if(ones<=k){
            cout<<"ALICE"<<endl;
        }
        else if(n/2<k) cout<<"ALICE"<<endl;
        else cout<<"BOB"<<endl;
        
    }
    return 0;
}